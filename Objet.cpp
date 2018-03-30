#include"Objet.hpp"

using namespace std;


Objet::Objet(Position*pos,char c,string n,int aat,int asa,int aa):positionObj(pos),symbol(c),nom(n),ajoutAtack(aat),ajoutSanter(asa),ajoutArmur(aa){

}

Objet::Objet(Position* p,char c){
    int i=rand()%3+8;
    switch(c){
      case 'W':
        new (this) Objet(p,c,"Sword",i,0,0);
        break;
      case 'M':
        new (this) Objet(p,c,"Medicament",0,i,0);
        break;
      case 'O':
        new (this) Objet(p,c,"Potion",0,i,0);
        break;
      case 'R':
        new (this) Objet(p,c,"Armure",0,0,i);
        break;

    }
}

void Objet::setNom(string s){
    this->nom = s;
}

void Objet::setAjoutAtack(int aa){
    this->ajoutAtack=aa;
}

void Objet::setAjoutSanter(int as){
    this->ajoutSanter=as;
}

void Objet::setAjoutArmur(int ar){
    this->ajoutArmur=ar;
}

void Objet::setPosition(Position* p){
    this->positionObj=p;
}

void Objet::setSymbol(char c){
    this->symbol = c;
}