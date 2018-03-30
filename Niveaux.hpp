#ifndef NIVEAUX_H
#define NIVEAUX_H
#include"Position.hpp"
#include<iostream>
#include<string>
#include<ostream>
#include <vector>
#include"Room.hpp"
#include<ncurses.h>
#include<stdlib.h>
#include"Monstre.hpp"
#include"Player.hpp"
#include<vector>
class Monstre;
class Player;

using namespace std;

class Niveaux {
private :
int numNiveaux;
char ** save;//elle contient les salle et couloire et portes 
char ** zeeMatrice;//elle contient salle et couloire et portes et monstres 
int numSalle;
int numMonstre;
int nombreMonstre;
Room ** rooms;
Room * roomTest;
int nivSuivExp;
Position * escalierSui;
Position * escalierPre;
int NumRoomDescalierSui;
Position * player;
int choix;
vector <Monstre *> monstres ; 

public :
Niveaux(int,int,int);
Room ** dessineCarteAutomatique();
Room * dessineCarteManuelle(int,int,int,int);
void enregistreNiveau();
void setSave(char**);
void setNumSalle(int);
void setNumMonstre(int);
void setNumNiveaux(int);
void setNivSuivExp(int);
void setEscalierSui();
void setRoomTest(Room*);
void setPlayer(Position *);
Position * getPlayer(){return this->player;}
Room* getRoomTest(){return this->roomTest;}
void setNumRoomDescalierSui(int );
Position * getEscalierSui(){return this->escalierSui;}
Position * getEscalierPre(){return this->escalierPre;}
int getNivSuivExp(){return this->nivSuivExp;}
int getNumRoomDecalierSui(){return this->NumRoomDescalierSui;}
void setNombreMonstre(int);
int getNombreMonstre(){return this->nombreMonstre;}//nombre de monstre
int getNumMonstre(){return this->numMonstre;}//numero du monstre
int getNumSalle(){return this->numSalle;}
int getNumNiveaux(){return this->numNiveaux;}
Room ** getRooms(){return this->rooms;}
void setRooms(Room **);
char ** getSave(){return this->save;}
void ajoutMonstre();
void putMonstre(Monstre*);
Monstre * selectioneMonstre(int);
void startMoveMonstre(Player*);
void editCaseSave(int,int,char);
Position * setJoueur();
void setEscalierPre(Niveaux*);
void dessineNiveaux();
void ajoutCouloireAutomatique();
void ajoutCouloireManuelle(int ,int);
void setZeeMatrice(char**);
void editCaseZeeMatrice(int,int,char);
char ** getZeeMatrice(){return this->zeeMatrice;}
void remplirSave(char **);
int getNumeroSalle(Position *);
void supprimeDuVector(int);
void setMonstres(vector<Monstre*>);
void putNivSuivExp();
vector<string> splitter(const string &,char );
void obtienLesValeurs();
int getChoix(){return this->choix;}
vector<Monstre*> getMonstres(){return this->monstres;}

friend ostream &operator<<(ostream &o,Niveaux *niv);

virtual ~Niveaux(){
    delete save;
    delete rooms;
    delete escalierSui;
    delete zeeMatrice;
    delete roomTest;
    delete player;
    delete escalierPre;
}



};
#endif
