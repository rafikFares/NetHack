#ifndef CREATURE_H
#define CREATURE_H
#include"Position.hpp"
#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>
#include"Objet.hpp"

class Niveaux;
using namespace std;

class Creature {
protected:
Position *position;
int santer;
char symbol;
int atack;
int rapide;
int defance;

public:
Creature(Position*,int,int,char,int,int);
Creature();
void setSymbol(char);
void setRapide(int);
void setDefance(int);
int getRapide(){return this->rapide;}
int getDefance(){return this->defance;}
char getSymbol(){return this->symbol;}
Position *getPosition(){return this->position;}
int getSanter(){return this->santer;}
void setPosition(Position *);
void setSanter(int);
void setAtack(int);
int getAtack(){return this->atack;}
void putCreature(Niveaux *);
virtual void kungFu();


int operator-(const Creature *n) const ;
void operator+(Objet *);

virtual ~Creature(){
    delete position;
}

};
#endif
