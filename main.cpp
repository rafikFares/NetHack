#include<iostream>
#include<string>
#include<ostream>
#include<stdlib.h>
#include<ncurses.h>
#include <curses.h>
#include <ctype.h>
#include <stdio.h>
#include"Couloire.hpp"
#include"Player.hpp"
#include"Room.hpp"
#include"Position.hpp"
#include <chrono>
#include"Ecrand.hpp"
#include"Niveaux.hpp"
#include"Creature.hpp"
#include"Jeu.hpp"

using namespace std;



int main(){
    char c='5';
    int choix;
    int nombreSalle=5;
    cout<<"methode automatique = 0"<<endl;
    cout<<"methode manuelle = 1"<<endl;
    cout<<"votre choix : "<<endl;
    cin>>choix;

    Ecrand * e=new Ecrand();
    Jeu * jeu = new Jeu(5,nombreSalle,choix);//nombre de niveau et nombre de salle dans chaque niveau 
    int cur=0;//commencer par niveaux 1 cur->current niveaux
    jeu->getLevels()[jeu->getCurrent()]->dessineNiveaux();//0 est automatique et 1 est manuelle 
    Player * p= new Player(jeu->getLevels()[jeu->getCurrent()]->setJoueur(),1000,1,'>',5,4,15);

    jeu->getLevels()[jeu->getCurrent()]->startMoveMonstre(p);
    jeu->getLevels()[jeu->getCurrent()]->editCaseZeeMatrice(p->getPosition()->getX(),p->getPosition()->getY(),'>');

    e->EcrandMaj(p,jeu->getLevels()[jeu->getCurrent()]);
    e->afficheMatricePourJouer(jeu->getLevels()[jeu->getCurrent()]->getZeeMatrice());

    while(c!='q'){
        jeu->getLevels()[jeu->getCurrent()]->setPlayer(p->getPosition());    
        c=getch();
        clear();
        p->lireClavier(c,jeu);
        jeu->getLevels()[jeu->getCurrent()]->startMoveMonstre(p);
        move(p->getPosition()->getY(),p->getPosition()->getX());
        if(p->getExperience()>=Jeu::expTotal){
        e->detruireEcrand("Vous avez gagné!!");
        break;
            }
        if(p->getSanter()<=0){
            e->detruireEcrand("GAME OVER !!");
            break;
            }
        e->EcrandMaj(p,jeu->getLevels()[jeu->getCurrent()]);
        e->afficheMatricePourJouer(jeu->getLevels()[jeu->getCurrent()]->getZeeMatrice());
    }

    e->detruireEcrand("Quit");
    cout<<"affichage de la matrice save :"<<endl;
    e->afficheMatricePourTest(jeu->getLevels()[jeu->getCurrent()]->getSave());
    cout<<"affichage de la matrice zee "<<endl;
    cout<<jeu->getLevels()[jeu->getCurrent()];

    return 0;
}

