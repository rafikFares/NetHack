#include"Inventaire.hpp"

using namespace std;

Inventaire::Inventaire(int t):tailleMax(t),numObjets(0){

}

void Inventaire::setNumObjets(int x){
    this->numObjets=x;
}

void Inventaire::ajoutObjet(Objet *obj){

    this->objets.push_back(obj);
    this->numObjets=this->objets.size();
}

void Inventaire::supprimeObjet(int index){
  vector<Objet*>::iterator it = this->objets.begin();
  this->objets.erase(it);
  this->numObjets=this->objets.size();
}