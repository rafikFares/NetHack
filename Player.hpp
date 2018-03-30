#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>
#include"Niveaux.hpp"
#include"Creature.hpp"
#include"Position.hpp"
#include"Jeu.hpp"
#include"Inventaire.hpp"

using namespace std;

class Monstre;
class Jeu;

class Player : public Creature{
private :
int experience;
Inventaire * inv;
char objs[4] = {'W','M','O','R'};

public:
Player(Position*,int,int,char,int,int,int);
void putPlayer();
virtual void kungFu(Monstre*,Niveaux*,int);
void possibleMove(Position*,char,Jeu *);
void lireClavier(int,Jeu *);
void setExperience(int);
int getExperience(){return this->experience;}
Inventaire * getInventaire(){return this->inv;}
bool isContains(char,char*);
bool isSameObjet(char);
void afficherObjets();
char* getObjs(){return this->objs;}
void supprimeObjet(int);

virtual ~Player(){
    delete inv;
}



};
#endif
