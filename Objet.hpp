#ifndef OBJET_H
#define OBJET_H
#include<iostream>
#include"Position.hpp"
#include<stdio.h>
using namespace std;

class Objet{
private :
string nom;
char symbol;
int ajoutAtack;
int ajoutSanter;
int ajoutArmur;
Position * positionObj;


public :
Objet(Position *,char);
Objet(Position*,char,string,int,int,int);
int getAjoutAtack(){return this->ajoutAtack;}
int getAjoutSanter(){return this->ajoutSanter;}
int getAjoutArmur(){return this->ajoutArmur;}
char getSymbol(){return this->symbol;}
Position * getPosition(){return this->positionObj;}
string getNom(){return this->nom;}
void setNom(string);
void setAjoutAtack(int);
void setAjoutSanter(int);
void setSymbol(char);
void setAjoutArmur(int);
void setPosition(Position*);

virtual ~Objet(){
    delete positionObj;
}



};
#endif