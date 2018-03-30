#ifndef INVENTAIRE_H
#define INVENTAIRE_H
#include<iostream>
#include<stdio.h>
#include<vector>
#include"Objet.hpp"
using namespace std;

class Inventaire{
private :
int tailleMax;
int numObjets;
vector<Objet*> objets;


public :
Inventaire(int);
int getTailleMax(){return this->tailleMax;}
int getNumObjets(){return this->numObjets;}
void setNumObjets(int);
vector<Objet*> getObjets(){return this->objets;}
void ajoutObjet(Objet*);
void supprimeObjet(int);

virtual ~Inventaire(){

    }

};
#endif
