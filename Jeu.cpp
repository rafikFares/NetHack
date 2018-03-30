#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>
#include"Jeu.hpp"


using namespace std;

int Jeu::expTotal = 0;

Jeu::Jeu(int nombreNiv,int nums,int choix){

  this->levels = new Niveaux*[nombreNiv];
  for(int k=0; k<nombreNiv; k++){
    nums = rand() % 2 + 5;
    this->levels[k] = new Niveaux(k+1,nums,choix);
  }
  this->setCurrent(0);
}

void Jeu::setNombreNiv(int a){
  this->nombreNiv = a;
}

void Jeu::setCurrent(int a){
  this->current = a;
}

