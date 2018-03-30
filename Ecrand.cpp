#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>
#include"Player.hpp"
#include"Ecrand.hpp"

using namespace std;

Ecrand::Ecrand(){
   initscr();
    noecho();
    refresh();
    srand(time(NULL));
}

void Ecrand::EcrandMaj(Player * p,Niveaux * niv){
    int k = 0, a = 0 , b = 0;
    for(int i=0; i<niv->getNombreMonstre(); i++){
    if(niv->getMonstres()[i]->getSanter()>0){
        switch (niv->getMonstres()[i]->getSymbol()) {
            case 'K':
            k++;
            break;
            case 'A':
            a++;
            break;
            case 'B':
            b++;
            break;
        }
    }
    }
    // aliveMonster = k + a + b;
    mvprintw(0,0,"Niveaux : %d  K : %d A : %d B : %d Santer : %d Power : %d EXP : %d Max :%d Objet : %d",niv->getNumNiveaux(),k,a,b,p->getSanter(),p->getAtack(),p->getExperience(),p->getInventaire()->getTailleMax(),p->getInventaire()->getNumObjets());
    p->afficherObjets();
    move(p->getPosition()->getY(),p->getPosition()->getX());
    //si lexperience du joueur get exp supp a nive get exp alors mvprintw(nive get position porte , E)
    if(p->getExperience()>=niv->getNivSuivExp()){
    niv->editCaseZeeMatrice(niv->getEscalierSui()->getX(),niv->getEscalierSui()->getY(),'S');
    niv->editCaseSave(niv->getEscalierSui()->getX(),niv->getEscalierSui()->getY(),'S');
    }
            
          
}


void Ecrand::detruireEcrand(string ss){
    endwin();
    cout<<ss<<endl;
}

void Ecrand::afficheMatricePourJouer(char ** c){
   
    for (int i=3;i<35;i++){//35//commence 3
        for (int j=0;j<120;j++){//80
            //cout<<c[i][j];
            mvprintw(i,j,"%c",c[i][j]);
        }
    }
}

void Ecrand::afficheMatricePourTest(char ** c){
    for (int i=0;i<35;i++){//35
        for (int j=0;j<120;j++){//80
            cout<<c[i][j];
            //mvprintw(i,j,"%c",c[i][j]);
        }
        cout<<endl;
    }
}


