#ifndef COULOIRE_H
#define COULOIRE_H
#include"Position.hpp"

class Couloire{
private:
int height;
int width;
Position ** voisin;
Position *** route;
int compteur;
int index;
Position * porte1;
Position * porte2;
char ** grid;

public:
Couloire(char **,Position *,Position *);
bool isValid(int , int );
int getHeight(){return this->height;}
int getWidth(){return this->width;}
void setWidth(int );
void setHeight(int );
Position ** getVoisin(){return this->voisin;}
Position *** getRoute(){return this->route;}
void setVoisin(Position **);
void setRoute(Position ***);
void setGrid(char**);
void modifierGrid(int,int,char);
char ** getGrid(){return this->grid;}
int getIndex(){return this->index;}
int getCompteur(){return this->compteur;}
void setIndex(int);
void setCompteur(int);
void addToVoisin(Position *);
void addToRoute(Position *, Position *);
void ajoutMesVoisins(Position *);
void start();
bool possiblePosition(Position *);
bool isBlocked(Position *);
void ajoutNouveauCouloire(Position *,Position *);

virtual ~Couloire(){
    delete porte1;
    delete porte2;
    delete voisin;
    delete route;
    delete grid;
}


};
#endif
