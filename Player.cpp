#include<iostream>
#include<string>
#include<ostream>
#include<stdlib.h>
#include <curses.h>
#include"Jeu.hpp"
#include<ncurses.h>
#include"Objet.hpp"
#include <stdio.h>
#include <string.h>
#include"Player.hpp"
#include"Inventaire.hpp"
#include"Ecrand.hpp"
#include"Niveaux.hpp"
#include<vector>

using namespace std;

Player::Player(Position *a,int sant,int atak,char sym,int rap,int def,int sizeInv):Creature(a,sant,atak,sym,rap,def){
    this->experience = 0;
    this->inv = new Inventaire(sizeInv);

}



void Player::kungFu(Monstre * m,Niveaux * niveaux,int nan) {

    m->setSanter(m->operator-(this));
     
    if(m->getSanter() <= 0){
  
        int i=rand()%4;
        niveaux->editCaseZeeMatrice(m->getPosition()->getX(),m->getPosition()->getY(),this->getObjs()[i]);   
          
        
    if(m->getSymbol()=='B'){
        this->setExperience(this->getExperience()+10);
    }else if(m->getSymbol()=='K'){
        this->setExperience(this->getExperience()+2);
    }else if(m->getSymbol()=='A'){
        this->setExperience(this->getExperience()+5);
    }
    niveaux->supprimeDuVector(nan);       
    }

}

void Player::putPlayer(){//player setup
    mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),">");

    move(this->getPosition()->getY(),this->getPosition()->getX());
}



void Player::setExperience(int e){
    this->experience = e;
}

void Player::possibleMove(Position* pos,char m,Jeu * jeu){//check position il faut changer ca et utilisé la matrice
    
    int cur = jeu->getCurrent();
    char next=jeu->getLevels()[cur]->getZeeMatrice()[pos->getX()][pos->getY()];
    
    if (next=='.' || next=='@' || next=='#'){//espace
        
        jeu->getLevels()[cur]->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(), jeu->getLevels()[cur]->getSave()[this->getPosition()->getX()][this->getPosition()->getY()]);
        this->getPosition()->setY(pos->getY());
        this->getPosition()->setX(pos->getX());
        this->setSymbol(m);
        
        this->putCreature(jeu->getLevels()[cur]);
       
  
    }else if (next=='K' || next=='A' || next=='B'){//monstre

        //ici juste la boucle 
        for(int i=0; i<jeu->getLevels()[cur]->getMonstres().size(); i++){
        
        if((pos->getY() == jeu->getLevels()[cur]->getMonstres()[i]->getPosition()->getY()) && (pos->getX() == jeu->getLevels()[cur]->getMonstres()[i]->getPosition()->getX())){
            this->kungFu(jeu->getLevels()[cur]->getMonstres()[i],jeu->getLevels()[cur],i);
             
          }
        this->setSymbol(m);
        
      }
    }else if(next =='S'){
        erase();
        jeu->getLevels()[cur]->setPlayer(new Position(this->getPosition()->getX(),this->getPosition()->getY()));
        
        this->putCreature(jeu->getLevels()[cur]);
        if(jeu->getLevels()[cur+1]->getNumMonstre()==0){
          //la premier fois , dessiner le niveaux , mettre l'escalier precedent et enregister les positions
          jeu->getLevels()[cur+1]->dessineNiveaux();
          jeu->getLevels()[cur+1]->setEscalierPre(jeu->getLevels()[cur]);

          jeu->getLevels()[cur+1]->editCaseZeeMatrice(jeu->getLevels()[cur+1]->getEscalierPre()->getX(), jeu->getLevels()[cur+1]->getEscalierPre()->getY(), 'P');
          jeu->getLevels()[cur+1]->editCaseSave(jeu->getLevels()[cur+1]->getEscalierPre()->getX(), jeu->getLevels()[cur+1]->getEscalierPre()->getY(), 'P');
          int x = jeu->getLevels()[cur+1]->getEscalierPre()->getX()+1;
          int y = jeu->getLevels()[cur+1]->getEscalierPre()->getY();
          jeu->getLevels()[cur+1]->setPlayer(new Position(x,y));
          jeu->getLevels()[cur+1]->editCaseZeeMatrice(x,y, this->getSymbol());
        }
      this->getPosition()->setX(jeu->getLevels()[cur+1]->getPlayer()->getX());
      this->getPosition()->setY(jeu->getLevels()[cur+1]->getPlayer()->getY());

      jeu->setCurrent(cur+1);
    }else if(next =='P'){
        erase();
        //afficher toutes les positions de niveaux precedent
        this->putCreature(jeu->getLevels()[cur]);
        this->setPosition(jeu->getLevels()[cur-1]->getPlayer());
        
        jeu->getLevels()[cur-1]->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(), this->getSymbol());
        
        jeu->setCurrent(cur-1);
    }else if(isContains(next,this->getObjs()) && !isSameObjet(next) && (this->getInventaire()->getTailleMax()>this->getInventaire()->getNumObjets())){
        Objet *o = new Objet(pos,next);
        this->getInventaire()->ajoutObjet(o);

        jeu->getLevels()[cur]->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),jeu->getLevels()[cur]->getSave()[this->getPosition()->getX()][this->getPosition()->getY()]);
        this->getPosition()->setY(pos->getY());
        this->getPosition()->setX(pos->getX());
        this->setSymbol(m);
              
        this->putCreature(jeu->getLevels()[cur]);

        afficherObjets();

    }
    //mur ou monstre

}


void Player::lireClavier(int c,Jeu * niveaux){//handle input
   char m;//pour faire la forme du joueur < > v ^
    if (c=='w'){ //haut
        m='^';
        possibleMove(new Position(this->getPosition()->getX()-1,this->getPosition()->getY()),m,niveaux);
        //possible(p->getPosition()->getY()-1,p->getPosition()->getX(),p,m);
    
    }else if (c=='s'){ //bas
        m='v';
        possibleMove(new Position(this->getPosition()->getX()+1,this->getPosition()->getY()),m,niveaux);
        //possible(p->getPosition()->getY()+1,p->getPosition()->getX(),p,m);
        
    }else if(c=='a'){//gauche
        m='<';
        possibleMove(new Position(this->getPosition()->getX(),this->getPosition()->getY()-1),m,niveaux);
        //possible(p->getPosition()->getY(),p->getPosition()->getX()-1,p,m);
        
    }else if(c=='d'){//droite
        m='>';
        possibleMove(new Position(this->getPosition()->getX(),this->getPosition()->getY()+1),m,niveaux);
        //possible(p->getPosition()->getY(),p->getPosition()->getX()+1,p,m);
        
     }else if(c=='i'){
      //Ecrand *e = new Ecrand();
      Ecrand::EcrandMaj(this,niveaux->getLevels()[niveaux->getCurrent()]);
      //e->afficheMatricePourTest(niveaux->getSave());
      Ecrand::afficheMatricePourJouer(niveaux->getLevels()[niveaux->getCurrent()]->getZeeMatrice());

        if(this->getInventaire()->getNumObjets()!=0)
        {
          this->afficherObjets();
          char n;
          int j=12;//la position de afficher le premier objet de x
          int index=0;//index de objets
          move(1,12);
          while(!((this->getInventaire()->getNumObjets()==0) || (n=getch())=='i')){// cliquer i une 2 eme foi pour quittez linventaire
            if(n=='n'){//next 
              if(this->getInventaire()->getNumObjets()!=1){
                if(index<this->getInventaire()->getNumObjets()-1){
                  index++;
                  j=12+2*index;
                }else {//retourner le premier objet
                  index=0;
                  j=12;
                }
              }
              move(1,j);
            }
            if(n=='u'){//utiliser
              this->operator+(this->getInventaire()->getObjets()[index]);
              this->supprimeObjet(index);
              if(j!=12){
                  j-=2;
                  index--;
              }
              Ecrand::EcrandMaj(this,niveaux->getLevels()[niveaux->getCurrent()]);
              move(1,j);
            }else if(n=='s'){//supprimer l'objet
                this->supprimeObjet(index);
              if(j!=12){
                  j-=2;
                  index--;
              }
              Ecrand::EcrandMaj(this,niveaux->getLevels()[niveaux->getCurrent()]);
              move(1,j);
            }
          }
         } 
      
      
      
      
      
     }

}

void Player::supprimeObjet(int index){
    this->getInventaire()->supprimeObjet(index);
    this->afficherObjets();
}

bool Player::isContains(char c, char* cs){
     bool res = false;
     for(int i = 0; i<strlen(cs); i++){
       if(c==cs[i]) return true;
     }
     return res;
}

bool Player::isSameObjet(char s){
  bool res=false;
  for(int i=0; i<this->getInventaire()->getNumObjets();i++){
    if(s==this->getInventaire()->getObjets()[i]->getSymbol()){
      res=false;//true ici jai modifier pour que le joueur peus prendre 2 objet pareil
    }
  }
  return res;
}

void Player::afficherObjets(){
  move(1,0);
  clrtoeol();
  mvprintw(1,0,"Mes objets: ");
  int k = 0;
  for(int i=0;i<this->getInventaire()->getNumObjets();i++){
     mvprintw(1,k+12,"%c",this->getInventaire()->getObjets()[i]->getSymbol());
     k+=2;
  }
}