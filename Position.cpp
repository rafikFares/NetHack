#include<iostream>
#include<string>
#include<ostream>
#include<stdlib.h>
#include <curses.h>
#include<ncurses.h>
#include "Position.hpp"

using namespace std;

Position::Position(int a,int b):x(a),y(b){
}


Position::Position(){
    
}


void Position::setX(int x){
    this->x=x;
}

void Position::setY(int x){
    this->y=x;
}



