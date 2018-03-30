#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>
#include<time.h>
#include "Position.hpp"

using namespace std;

class Room {
    private :
    Position *position;
    int height;
    int width;
    Position *doors[3];
    char ** sauve;
    Room ** nr;

    
public:
    Room(Position *,int,int);
    Room(Room**,int,int);
    Room(Room**,int);
    Position *getPosition(){return this->position;}
    int getHeight(){return this->height;}
    int getWidth(){return this->width;}
    void setPosition(Position *);
    void setHeight(int);
    void setWidth(int);
    void modifierSauve(int,int,char);
    char ** getSauve(){return this->sauve;}
    void drawRoom(int);
    void putDoors(int);
    void initialiserSauve();
    void setFirstDoor(Position *);
    void setSecondeDoor(Position *);
    void setThirdDoor(Position *);
    Position * getFirstDoor(){return this->doors[0];}
    Position * getSecondDoor(){return this->doors[1];}
    Position * getThirdDoor(){return this->doors[2];}
    
    void connexionEntrePorte(Position* ,Position* );

    virtual ~Room(){
        delete sauve;
        delete nr;
        delete position;
        delete doors[0];
        delete doors[1];
        delete doors[2];
    }
    
};
#endif
