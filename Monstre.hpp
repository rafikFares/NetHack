#ifndef MONSTRE_H
#define MONSTRE_H
#include"Position.hpp"
#include<iostream>
//#include"Jeu.hpp"
#include<string>
#include<ostream>
#include"Creature.hpp"
#include<ncurses.h>
#include<stdlib.h>

class Niveaux;

using namespace std;

class Monstre:public Creature{
private:
int chemin;
int mySalle;
int afficher;//1 = afficher

public:
Monstre(Position*,int,char,int,int,int,int);
Monstre();
void setChemin(int);
int getChemin(){return this->chemin;}
void moveMonstre(Position * ,Niveaux *);
void moveAleatoire(Niveaux *);
void moveTeleport(Niveaux *);
void suiviJoueur(Position *, Niveaux *);
int isClose(Position*);
int getMySalle(){return this->mySalle;}
void setMySalle(int);
int getAfficher(){return this->afficher;}
void setAfficher(int);


virtual void kungFu();





};
#endif
