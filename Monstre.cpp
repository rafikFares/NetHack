#include"Position.hpp"
#include<iostream>
#include<string>
#include"Monstre.hpp"
#include<ostream>
#include"Niveaux.hpp"
#include<ncurses.h>
#include<stdlib.h>


using namespace std;
Monstre::Monstre(Position* p,int santer,char sym,int atak,int rap,int def,int chem):Creature(p,santer,atak,sym,rap,def){
this->chemin=chem;
this->afficher = 0;

}

Monstre::Monstre():Creature(){}

void Monstre::kungFu() {
   
}

void Monstre::setAfficher(int b){
    this->afficher=b;
}


void Monstre::setMySalle(int sa){
    this->mySalle=sa;
}

void Monstre::setChemin(int k){
    this->chemin=k;
}

int Monstre::isClose(Position * play){
    int dx = abs(this->getPosition()->getX()-play->getX());
    int dy = abs(this->getPosition()->getY()-play->getY());
    return (dx+dy);
}

void Monstre::moveMonstre(Position * p,Niveaux * niveaux){
  
        if(this->afficher){
       
        if(this->getSymbol() == 'B' && niveaux->getNumeroSalle(p) == niveaux->getNumeroSalle(this->getPosition())){
         
         this->setChemin(3);
        }
        if (this->getChemin() == 1){
         
            this->moveAleatoire(niveaux);
        
        }else if(getChemin() == 2){
           
            this->moveTeleport(niveaux);
        
        }else{
            this->suiviJoueur(p,niveaux);
        }

        this->putCreature(niveaux);
        }
    
}




void Monstre::moveAleatoire(Niveaux * niveaux){
   // cout<<"333333"<<std::flush;
   // cout<<"8888"<<std::flush<<this->getSymbol()<<std::flush;
    int newPo;
   // while (1){//santer du monstre existe toujours
    //getch();
      newPo=rand() % 4;//1 = haut / 2 = bas / 3 = gauche / 4 = droite
      //newPo = 1;
      if ((newPo == 0) && (niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()-1]=='.')){//espace

       // mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        this->getPosition()->setY(this->getPosition()->getY()-1);
        //this->getPosition()->setX(pos->getX());
       // mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //this->putCreature();
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);

      }else if ((newPo == 1 && niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()+1]=='.')){//espace

        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        this->getPosition()->setY(this->getPosition()->getY()+1);
        //this->getPosition()->setX(pos->getX());
        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //this->putCreature();
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);
      }else if ((newPo == 2 && niveaux->getZeeMatrice()[this->getPosition()->getX()-1][this->getPosition()->getY()]=='.')){//espace

        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        //this->getPosition()->setY(pos->getY());
        this->getPosition()->setX(this->getPosition()->getX()-1);
        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //this->putCreature();
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);
      }else if ((newPo == 3) && (niveaux->getZeeMatrice()[this->getPosition()->getX()+1][this->getPosition()->getY()]=='.')){//espace

        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        //this->getPosition()->setY(pos->getY());
        this->getPosition()->setX(this->getPosition()->getX()+1);
        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //this->putCreature();
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);
        }
        //getch();
    //}//fin while
}

void Monstre::moveTeleport(Niveaux * niveaux){
  int newPo;
  int h;
   // while (1){//santer du monstre existe toujours
    //getch();
      newPo=rand() % 4;//1 = haut / 2 = bas / 3 = gauche / 4 = droite
      h =rand()%3;
      //newPo = 1;
      
      if ((newPo == 0) && (niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()-3]=='.')){//espace
        
        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        this->getPosition()->setY(this->getPosition()->getY()-3);
        //this->getPosition()->setX(pos->getX());
       // mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);
        }else if ((newPo == 1 && niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()+3]=='.')){//espace
       
       // mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        this->getPosition()->setY(this->getPosition()->getY()+3);
        //this->getPosition()->setX(pos->getX());
       // mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);

        }else if ((newPo == 2 && niveaux->getZeeMatrice()[this->getPosition()->getX()-3][this->getPosition()->getY()]=='.')){//espace
       
       // mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        //this->getPosition()->setY(pos->getY());
        this->getPosition()->setX(this->getPosition()->getX()-3);
        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);
        

        }else if ((newPo == 3) && (niveaux->getZeeMatrice()[this->getPosition()->getX()+3][this->getPosition()->getY()]=='.')){//espace
        
       // mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),".");
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),'.');
        //this->getPosition()->setY(pos->getY());
        this->getPosition()->setX(this->getPosition()->getX()+3);
        //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",this->getSymbol());
        //ici
        //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
        //this->putCreature(niveaux);  
        
       
        }
}

void Monstre::suiviJoueur(Position *d, Niveaux * niveaux){
  // Position m(this->getPosition()->getX(),this->getPosition()->getY());
  int x = this->getPosition()->getX();
  int y = this->getPosition()->getY();
  char o = niveaux->getSave()[this->getPosition()->getX()][this->getPosition()->getY()];//origine
  //voir guache
  if( (abs((this->getPosition()->getX()-1) - d->getX()) < abs(this->getPosition()->getX() - d->getX()))
       &&(niveaux->getZeeMatrice()[this->getPosition()->getX()-1][this->getPosition()->getY()]== '.' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()-1][this->getPosition()->getY()]== '#' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()-1][this->getPosition()->getY()]== '@')){
       //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",o);
       // niveaux->editCaseSave(this->getPosition()->getY(),this->getPosition()->getX(),o);
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),niveaux->getSave()[this->getPosition()->getX()][this->getPosition()->getY()]);
       this->getPosition()->setX(this->getPosition()->getX()-1);
       //this->putMonstre();
       //ici
       //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
       //this->putCreature(niveaux);  
  } //voir droite
  else if((abs((this->getPosition()->getX()+1) - d->getX()) < abs(this->getPosition()->getX() - d->getX()))
       &&(niveaux->getZeeMatrice()[this->getPosition()->getX()+1][this->getPosition()->getY()]== '.' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()+1][this->getPosition()->getY()]== '#' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()+1][this->getPosition()->getY()]== '@')){
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),niveaux->getSave()[this->getPosition()->getX()][this->getPosition()->getY()]);

      //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",o);
      // niveaux->editCaseSave(this->getPosition()->getY(),this->getPosition()->getX(),o);
       this->getPosition()->setX(this->getPosition()->getX()+1);
       //this->putMonstre();
       //ici
       //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());
       //this->putCreature(niveaux);  
  } //voir haut
  else if((abs((this->getPosition()->getY()-1) - d->getY()) < abs(this->getPosition()->getY() - d->getY()))
       &&(niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()-1]== '.' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()-1]== '#' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()-1]== '@')){
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),niveaux->getSave()[this->getPosition()->getX()][this->getPosition()->getY()]);

      //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",o);
      // niveaux->editCaseSave(this->getPosition()->getY(),this->getPosition()->getX(),o);
      this->getPosition()->setY(this->getPosition()->getY()-1);
      //this->putMonstre();
      //ici
      // niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());  
       //this->putCreature(niveaux);      
      // niveaux->editCaseSave(this->getPosition()->getY(),this->getPosition()->getX(),this->getSymbol());
  } //voir bas
  else if((abs((this->getPosition()->getY()+1) - d->getY()) < abs(this->getPosition()->getY() - d->getY()))
       &&(niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()+1]== '.' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()+1]== '#' 
       || niveaux->getZeeMatrice()[this->getPosition()->getX()][this->getPosition()->getY()+1]== '@')){
        niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),niveaux->getSave()[this->getPosition()->getX()][this->getPosition()->getY()]);

      //mvprintw(this->getPosition()->getY(),this->getPosition()->getX(),"%c",o);
      // niveaux->editCaseSave(this->getPosition()->getY(),this->getPosition()->getX(),o);
      this->getPosition()->setY(this->getPosition()->getY()+1);
      //this->putMonstre();
      //ici
       //niveaux->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());    
       //this->putCreature(niveaux);
      // niveaux->editCaseSave(this->getPosition()->getY(),this->getPosition()->getX(),this->getSymbol());

  }
}




/*K for Kabile 
     santer 2
     atack 1
     defance 1
     vitesse 1
     chemin 1// aleatoire

**A for Arabs 
     santer 3
     atack 2
     defence 2
     vitesse 2
     chemin 1 // aleatoir
    
**B for Bouteflika
     santer illimiter 
     atack 3
     defence 4
     vitesse 3
     chemin 3 (teleport)
               */

