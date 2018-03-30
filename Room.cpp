#include<iostream>
#include<string>
#include<ostream>
#include<stdlib.h>
#include <curses.h>
#include<ncurses.h>
#include"Room.hpp"
#include"Position.hpp"


using namespace std;

Room::Room(Position *a,int b, int c):position(a),height(b), width(c){

}

Room::Room(Room ** nrs,int numr,int meth):nr(nrs){
    this->initialiserSauve();
    for(int i=0;i<numr;i++){
        this->drawRoom(i);
        
        this->modifierSauve(this->nr[i]->doors[1]->getX(),this->nr[i]->doors[1]->getY(),'@');
        this->modifierSauve(this->nr[i]->doors[0]->getX(),this->nr[i]->doors[0]->getY(),'@'); 
        if(numr==6 && (i==2||i==3)){
           this->modifierSauve(this->nr[i]->doors[2]->getX(),this->nr[i]->doors[2]->getY(),'@');
        }
    }
}

Room::Room(Room ** nrs,int numr):nr(nrs){
    this->initialiserSauve();
    for(int i=0;i<numr;i++){
        this->drawRoom(i);
        this->putDoors(i);
    }
}

void Room::modifierSauve(int x,int y,char c){
    this->sauve[x][y]=c;
}

void Room::initialiserSauve(){
    this->sauve = new char*[40];
    for(int i=0;i<40;i++){
        this->sauve[i] = new char[120];
        for(int j=0;j<120;j++){
            this->sauve[i][j]=' ';
        }
    }
}

void Room::setFirstDoor(Position * pp){
    this->doors[0]= pp;
}

void Room::setSecondeDoor(Position * pp){
    this->doors[1]=pp;
}

void Room::setThirdDoor(Position * pp){
    this->doors[2]=pp;
}

void Room::setPosition(Position *x){
    this->position=x;
}

void Room::setHeight(int x){
    this->height=x;
}

void Room::setWidth(int x){
    this->width=x;
}


void Room::connexionEntrePorte(Position * d2,Position * d){
    Position p(d2->getX(),d2->getY());
    int cou=0;
    Position p2=p;
    int k=0;
    while(k==0){
        //voir agauche
        if((abs((p.getX()-1) - d->getX()) < abs(p.getX() - d->getX())) && (mvinch(p.getY(),p.getX()-1) == ' ')){
           // p2.setX(p.getX());
            mvprintw(p.getY(),p.getX()-1,"#");
            p.setX(p.getX()-1);
        } //voir droite
        else if((abs((p.getX()+1) - d->getX()) < abs(p.getX() - d->getX())) && (mvinch(p.getY(),p.getX()+1) == ' ')){
           // p2.setX(p.getX());
            mvprintw(p.getY(),p.getX()+1,"#");
            p.setX(p.getX()+1);
        } //voir haut
        else if((abs((p.getY()-1) - d->getY()) < abs(p.getY() - d->getY())) && (mvinch(p.getY()-1,p.getX()) == ' ')){
            //p2.setY(p.getY());
            mvprintw(p.getY()-1,p.getX(),"#");
            p.setY(p.getY()-1);
        } //voir bas
        else if((abs((p.getY()+1) - d->getY()) < abs(p.getY() - d->getY())) && (mvinch(p.getY()+1,p.getX()) == ' ')){
          // p2.setY(p.getY());
            mvprintw(p.getY()+1,p.getX(),"#");
            p.setY(p.getY()+1);
        }
        else {

                k=1;
            
        }
    }

}


void Room::drawRoom(int i){
    for(int x = this->nr[i]->getPosition()->getX()+1; x < this->nr[i]->getPosition()->getX()+ this->nr[i]->getHeight()-1; x++){
        
        this->modifierSauve(x,this->nr[i]->getPosition()->getY(),'|');
        this->modifierSauve(x, this->nr[i]->getPosition()->getY()+ this->nr[i]->getWidth() - 1, '|');//bottom
        for(int y = this->nr[i]->getPosition()->getY() + 1; y < this->nr[i]->getPosition()->getY() +this->nr[i]->getWidth() - 1; y++){
           this->modifierSauve(x,y,'.');
        }
    }
    //draw floors and side walls
    for(int y = this->nr[i] ->getPosition()->getY(); y < this->nr[i]->getPosition()->getY() + this->nr[i]->getWidth(); y++){
       
        this->modifierSauve(this->nr[i]->getPosition()->getX(),y, '-'); //side walls
        this->modifierSauve(this->nr[i]->getPosition()->getX()+ this->nr[i]->getHeight()-1, y, '-');
        
    }   
  
}


void Room::putDoors(int i){

    switch (i) {
      case 0:
      //bottom and right
    this->nr[i]->doors[1] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY() + this->nr[i]->getWidth() - 1);
    this->nr[i]->doors[0] =new Position(this->nr[i]->getPosition()->getX() + this->nr[i]->getHeight() - 1,rand() % (this->nr[i]->getWidth() - 2) + this->nr[i]->getPosition()->getY() + 1);      
     
      break;
      case 1:
      //left and bottom
    this->nr[i]->doors[1] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY() + this->nr[i]->getWidth() - 1);
    this->nr[i]->doors[0] =new Position(this->nr[i]->getPosition()->getX(),rand() % (this->nr[i]->getWidth() - 2) + this->nr[i]->getPosition()->getY() + 1);
      
    
      break;
      case 2:
      //top and right
    this->nr[i]->doors[0] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY());
    this->nr[i]->doors[1] =new Position(this->nr[i]->getPosition()->getX() + this->nr[i]->getHeight() - 1,rand() % (this->nr[i]->getWidth() - 2) + this->nr[i]->getPosition()->getY() + 1);
    this->nr[i]->doors[2] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY() + this->nr[i]->getWidth() - 1);
    this->modifierSauve(this->nr[i]->doors[2]->getX(),this->nr[i]->doors[2]->getY(),'@');
    
      break;
      case 3:
      //top and left
    this->nr[i]->doors[0] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY());
    this->nr[i]->doors[1] =new Position(this->nr[i]->getPosition()->getX(),rand() % (this->nr[i]->getWidth() - 2) + this->nr[i]->getPosition()->getY() + 1);
    this->nr[i]->doors[2] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY() + this->nr[i]->getWidth() - 1);
    this->modifierSauve(this->nr[i]->doors[2]->getX(),this->nr[i]->doors[2]->getY(),'@');
    
    
      break;
      case 4:
      //bottom and right
    this->nr[i]->doors[0] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY());
    this->nr[i]->doors[1] =new Position(this->nr[i]->getPosition()->getX() + this->nr[i]->getHeight() - 1,rand() % (this->nr[i]->getWidth() - 2) + this->nr[i]->getPosition()->getY() + 1);
      
   
      break;
      case 5:
      //bottom and right
    this->nr[i]->doors[0] =new Position(rand() % (this->nr[i]->getHeight() - 2) + this->nr[i]->getPosition()->getX() + 1,this->nr[i]->getPosition()->getY());
    this->nr[i]->doors[1] =new Position(this->nr[i]->getPosition()->getX(),rand() % (this->nr[i]->getWidth() - 2) + this->nr[i]->getPosition()->getY() + 1);
     
      break;
    
    }

    this->modifierSauve(this->nr[i]->doors[1]->getX(),this->nr[i]->doors[1]->getY(),'@');
    this->modifierSauve(this->nr[i]->doors[0]->getX(),this->nr[i]->doors[0]->getY(),'@');

}