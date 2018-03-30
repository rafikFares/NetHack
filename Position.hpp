#ifndef POSITION_H
#define POSITION_H
#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>

using namespace std;


class Position {
    private :
    int x;
    int y;
    
public:
    Position(int,int);
    Position();
    Position(int,Position*);
    int getX(){return this->x;}
    int getY(){return this->y;}
    void setX(int);
    void setY(int);
    void connexionEntrePorte(Position*);
    
};
#endif

