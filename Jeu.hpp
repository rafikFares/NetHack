#ifndef JEU_H
#define JEU_H
#include<iostream>
#include<string>
#include<ostream>
#include"Niveaux.hpp"
#include"Player.hpp"
#include<ncurses.h>
#include<stdlib.h>

class Jeu{
private:
  int nombreNiv;
  int current;
  Niveaux ** levels;
  


public:
  Jeu(int,int,int);
  void setCurrent(int);
  int getCurrent(){return this->current;}
  void setNombreNiv(int);
  int getNombreNiv(){return this->nombreNiv;}
  Niveaux ** getLevels(){return this->levels;}
  static int expTotal;
  

  

  virtual ~Jeu(){
        delete levels;
    
    }
    


};
#endif
