#include"Couloire.hpp"
#include<stdio.h>
#include<iostream>
using namespace std;


Couloire::Couloire(char ** gri,Position * porte1,Position * porte2):porte1(porte1),porte2(porte2){
    this->index=0;
    this->compteur=0;
    this->height=40;
    this->width=120;
    this->grid=gri;

    this->start();
}

void Couloire::ajoutNouveauCouloire(Position * porte1,Position * porte2){
    this->porte1=porte1;
    this->porte2=porte2;
    this->index=0;
    this->compteur=0;
    this->height=40;
    this->width=120;

    this->start();
}

void Couloire::setGrid(char** gr){
    this->grid=gr;
}

void Couloire::modifierGrid(int x,int y,char c){
    this->grid[x][y]=c;
}

void Couloire::setWidth(int w){
    this->width=w;
}

void Couloire::setHeight(int h){
    this->height=h;
}

void Couloire::setVoisin(Position ** p){
    this->voisin=p;
}

void Couloire::setRoute(Position *** pp){
    this->route=pp;
}

void Couloire::setIndex(int i){
    this->index=i;
}

void Couloire::setCompteur(int c){
    this->compteur=c;
}

void Couloire::addToVoisin(Position * pos){
    this->voisin[this->getCompteur()] = new Position(pos->getX(),pos->getY());
    this->setCompteur(this->getCompteur()+1);
}

void Couloire::addToRoute(Position * avant, Position * apres){
    this->route[apres->getX()][apres->getY()]= avant;

}

void Couloire::start(){

    int w = this->getWidth();
    int h = this->getHeight();
    int i,j;

    this->route=new Position**[h];
    this->voisin=new Position*[w*h];

    for (i=0;i<h;i++){
        this->route[i]=new Position*[w];
        for(j=0;j<w;j++){
            this->route[i][j]= NULL;
        }
    }// fin de l'éssai

    this->addToVoisin(this->porte1);

    int arriver =0;
    int x,y;
    while(this->getIndex() < this->getCompteur() && arriver ==0){

        x = this->getVoisin()[this->getIndex()]->getX();
        y = this->getVoisin()[this->getIndex()]->getY();
        this->setIndex(this->getIndex()+1);  
           
        if (x == this->porte2->getX() && y == this->porte2->getY()){// arriver a la fin a la porte 2
          arriver=1;
        //  break;
        }
        this->ajoutMesVoisins(new Position(x,y));   
        this->setCompteur(this->getCompteur());
        
    }

    y = this->porte2->getY();
    x = this->porte2->getX();

    int tempx;

    while(x != this->porte1->getX() || y != this->porte1->getY()){//dessiner le parcours
        tempx=x;
        x = this->getRoute()[x][y]->getX();
        y = this->getRoute()[tempx][y]->getY();
        if (x != this->porte1->getX() || y != this->porte1->getY()){
        modifierGrid(x,y,'#');
        }

    }
}

bool Couloire::possiblePosition(Position * pnext){
  if(this->grid[pnext->getX()][pnext->getY()] == '|' || this->grid[pnext->getX()][pnext->getY()] == '-' || this->grid[pnext->getX()][pnext->getY()] == '.')
   {
       return false;
   } else {return true;}

}

bool Couloire::isBlocked(Position * p){
    return (this->getRoute()[p->getX()][p->getY()] == NULL);
}

bool Couloire::isValid(int xy,int direction){
    // Returns true if y et x is in range
    if (direction == 2){//haut
        return (xy > 0);
    }else if (direction == 3){//bas
        return (xy < this->getHeight()-1);
    }else if (direction == 0){//gauche
        return (xy > 0);
    }else if (direction == 1){//droite
        return (xy < this->getWidth()-1);
    }
}


void Couloire::ajoutMesVoisins(Position * moi){
    //gauche
    if (isValid(moi->getY()-1,0) && (isBlocked(new Position(moi->getX(),moi->getY()-1)))){
        if(possiblePosition(new Position(moi->getX(),moi->getY()-1))){
      
        addToVoisin(new Position(moi->getX(),moi->getY()-1));
        addToRoute(moi,new Position(moi->getX(),moi->getY()-1));
       
        } 
    }
    //droite
    if (isValid(moi->getY()+1,1) && (isBlocked(new Position(moi->getX(),moi->getY()+1)))){
       if(possiblePosition(new Position(moi->getX(),moi->getY()+1))){
       
        addToVoisin(new Position(moi->getX(),moi->getY()+1));
        addToRoute(moi,new Position(moi->getX(),moi->getY()+1));
      
       }
    }
    //haut
    if (isValid(moi->getX()-1,2) && (isBlocked(new Position(moi->getX()-1,moi->getY())))){
      if( possiblePosition(new Position(moi->getX()-1,moi->getY()))){
        
        addToVoisin(new Position(moi->getX()-1,moi->getY()));
        addToRoute(moi,new Position(moi->getX()-1,moi->getY()));
     
      }
    }
    //bas
    if (isValid(moi->getX()+1,3) && (isBlocked(new Position(moi->getX()+1,moi->getY())))){
     if( possiblePosition(new Position(moi->getX()+1,moi->getY()))){
       
        addToVoisin(new Position(moi->getX()+1,moi->getY()));
        addToRoute(moi,new Position(moi->getX()+1,moi->getY()));
       
     }
    }

}