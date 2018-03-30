#include"Position.hpp"
#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>
#include"Creature.hpp"
#include "Niveaux.hpp"
#include "Objet.hpp"

using namespace std;

Creature::Creature(Position *a,int b,int t,char sym,int rap,int def):position(a),santer(b),atack(t),symbol(sym),rapide(rap),defance(def){

}

Creature::Creature(){

}

void Creature::kungFu() {

}

void Creature::setPosition(Position *x){
    this->position=x;
}

void Creature::setSanter(int x){
   
        this->santer=x;
    
      
}

void Creature::setAtack(int x){
    this->atack=x;  
}

void Creature::setSymbol(char x){
    this->symbol=x;  
}

void Creature::setRapide(int x){
    this->rapide=x;  
}

void Creature::setDefance(int x){
    this->defance=x;  
}

void Creature::putCreature(Niveaux * niv){
    niv->editCaseZeeMatrice(this->getPosition()->getX(),this->getPosition()->getY(),this->getSymbol());

}



void Creature::operator+(Objet *o) {
    this->setAtack(this->getAtack()+ o->getAjoutAtack());
    this->setSanter(this->getSanter()+ o->getAjoutSanter());
}

int Creature::operator-(const Creature *b) const {
return (this->santer-b->atack);

}