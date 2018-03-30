#include"Niveaux.hpp"
#include"Position.hpp"
#include"Room.hpp"
#include<iostream>
#include<string>
#include"Couloire.hpp"
#include<ostream>
#include<ncurses.h>
#include<stdlib.h>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

Niveaux::Niveaux(int numniv,int nums,int choix):numNiveaux(numniv),numMonstre(0),numSalle(nums),choix(choix){

}

void Niveaux::putNivSuivExp(){

    if (this->getNumNiveaux() == 5){
    this->nivSuivExp = Jeu::expTotal;
    }else { 
    this->nivSuivExp = Jeu::expTotal/2;
    }
}

void Niveaux::setRoomTest(Room* r){
    this->roomTest = r;
}

void Niveaux::setRooms(Room ** rr){
    this->rooms = rr;
}


void Niveaux::dessineNiveaux(){
    if(this->getChoix() == 0){//automatique
    this->rooms=dessineCarteAutomatique();
    this->setZeeMatrice(this->getRoomTest()->getSauve());
    this->ajoutCouloireAutomatique();
    
    }else{//manuelle
    obtienLesValeurs();    
    }

    this->remplirSave(this->getZeeMatrice());
    this->setEscalierSui();
    this->ajoutMonstre();
}

void Niveaux::setEscalierSui(){ //l'escalier suivant est dans une salle au hasard sauf la salle ou on met le joueur
    int i = rand()%5 ;
    //dans le coin droite et en bas de salle choisi, en debut, c'est fermé
    int x = this->getRooms()[i]->getPosition()->getX() + this->getRooms()[i]->getHeight() - 2;
    int y = this->getRooms()[i]->getPosition()->getY() + this->getRooms()[i]->getWidth() - 2;
    this->editCaseZeeMatrice(x,y,'F');
    this->editCaseSave(x,y,'F');
    this->escalierSui = new Position(x,y);
    this->setNumRoomDescalierSui(i);
}

void Niveaux::setEscalierPre(Niveaux *niveauxPre){
    //l'escalier suivant de niveaux precedent decide la position de l'escalier precedent de current niveaux
    int i = niveauxPre->getNumRoomDecalierSui();
    //dans le coin gauche et en haut de salle choisi, en debut, c'est fermé
    int x = this->getRooms()[i]->getPosition()->getX()+1;
    int y = this->getRooms()[i]->getPosition()->getY()+1;
    this->editCaseZeeMatrice(x,y,'F');
    this->editCaseSave(x,y,'F');    
    this->escalierPre = new Position(x,y);

}

void Niveaux::setNumRoomDescalierSui(int i){
    this->NumRoomDescalierSui = i;
}

void Niveaux::setSave(char ** s){
    this->save=s;
}

void Niveaux::remplirSave(char ** s){
    this->save = new char *[40];
    for(int i=0;i<40;i++){
        this->save[i] = new char[120];
        for(int j=0;j<120;j++){
            this->save[i][j]=s[i][j];
        }
    }
}

void Niveaux::setZeeMatrice(char** z){
    this->zeeMatrice=z;
}

void Niveaux::setNumSalle(int a){
    this->numSalle=a;
}

void Niveaux::setNumMonstre(int a){
    this->numMonstre=a;
}

Position * Niveaux::setJoueur(){
    return new Position(this->getRooms()[0]->getPosition()->getX()+1,this->getRooms()[0]->getPosition()->getY()+1);
}

Room ** Niveaux::dessineCarteAutomatique(){

    int h;
    int w;
    int x;
    int y;
    Room ** Nrooms = new Room*[this->numSalle];

    int valX = 0;
    int valY = -37;
    for (int i=0;i<this->numSalle;i++){
        if ((i%2)==0){
            valX=3;
            valY += 40; 
        }else {
            valX = 15;
        }
        h = rand() % 5 + 6;
        w = rand() % 21 + 10;
        y = rand() % (38-w)+valY;
        x = rand() % (12-h)+valX;
        Nrooms[i] = new Room(new Position(x,y),h,w);
    }

    Room * room = new Room (Nrooms,this->numSalle);
    this->setRoomTest(room);

return Nrooms;

}

void Niveaux::ajoutCouloireAutomatique(){
  
    Couloire * cl = new Couloire(this->getZeeMatrice(),this->rooms[0]->getFirstDoor(),this->rooms[1]->getFirstDoor());
    cl->ajoutNouveauCouloire(this->rooms[0]->getSecondDoor(),this->rooms[2]->getFirstDoor());
    cl->ajoutNouveauCouloire(this->rooms[2]->getSecondDoor(),this->rooms[3]->getSecondDoor());
    cl->ajoutNouveauCouloire(this->rooms[1]->getSecondDoor(),this->rooms[3]->getFirstDoor());
    cl->ajoutNouveauCouloire(this->rooms[2]->getThirdDoor(),this->rooms[4]->getFirstDoor());
    if (this->numSalle == 6){
    cl->ajoutNouveauCouloire(this->rooms[3]->getThirdDoor(),this->rooms[5]->getFirstDoor());
    cl->ajoutNouveauCouloire(this->rooms[4]->getSecondDoor(),this->rooms[5]->getSecondDoor());
    }else {
      cl->ajoutNouveauCouloire(this->rooms[3]->getThirdDoor(),this->rooms[4]->getSecondDoor());  
    }
    this->setZeeMatrice(cl->getGrid());
}

void Niveaux::setNivSuivExp(int se){
    this->nivSuivExp=se;
}

void Niveaux::setNombreMonstre(int se){
    this->nombreMonstre=se;
}

void Niveaux::editCaseSave(int x,int y,char c){
    this->save[x][y]=c;
}

void Niveaux::editCaseZeeMatrice(int x,int y,char c){
    this->zeeMatrice[x][y]=c;
}


void Niveaux::enregistreNiveau(){//save level positions
    char ** positions;
    positions = new char*[40];
    for(int i=0;i<40;i++){
        positions[i] = new char[120];
        for(int j=0;j<120;j++){
            positions[i][j]=mvinch(i,j);
        }
    }
    setSave(positions);
}

void Niveaux::ajoutMonstre(){
    int zee;
    for(int i=0;i<this->getNumSalle();i++){//i num room
        zee = rand() % 2 + 2;//2 ou 3
        for (int j=0;j<zee;j++){
            this->monstres.push_back(this->selectioneMonstre(i));
            this->monstres[this->getNumMonstre()]->setMySalle(i+1);
            this->setNumMonstre(this->getNumMonstre()+1);
      }
    }
    this->setNombreMonstre(this->getNumMonstre());
    this->putNivSuivExp(); 
}

Monstre * Niveaux::selectioneMonstre(int numRo){
    int choix = rand() % 3 ;// 1 chance sur 3
    int x,y;
    Monstre * mon;
    int e,f;
    e=this->getRooms()[numRo]->getWidth() - 2;
    f=this->getRooms()[numRo]->getHeight() - 2;
    x=(rand() % f) + this->getRooms()[numRo]->getPosition()->getX() + 1;
    y=(rand() % e) + this->getRooms()[numRo]->getPosition()->getY() + 1;
    if (choix == 0){//K
    
    mon=new Monstre(new Position(x,y),2+(this->getNumNiveaux()*4),'K',1+(this->getNumNiveaux()*2),1,1,1);//create monster
    Jeu::expTotal += 2;

    }else if (choix == 1){//A

    mon=new Monstre(new Position(x,y),3+(this->getNumNiveaux()*3),'A',2+(this->getNumNiveaux()*2),2,2,2);
   Jeu::expTotal += 5;
    }else if (choix == 2){//B
   
    mon=new Monstre(new Position(x,y),10+(this->getNumNiveaux()*10),'B',3+(this->getNumNiveaux()*2),3,4,1);
    Jeu::expTotal += 10;
    }
    return mon;
}


void Niveaux::setPlayer(Position * pp){
    this->player=pp;
}


int Niveaux::getNumeroSalle(Position * p){
    int num=0;
    int x,y,h,w;
    for(int k=0; k < this->getNumSalle(); k++){
            x = this->getRooms()[k]->getPosition()->getX();
            y = this->getRooms()[k]->getPosition()->getY();
            h = this->getRooms()[k]->getHeight();
            w = this->getRooms()[k]->getWidth();

        if((x<p->getX()) && (p->getX()<x+h-1) && (y<p->getY()) &&(p->getY()<y+w-1)){
          num=k+1;
        }

    }
    return num;
}



ostream &operator<<(ostream &o,Niveaux *niv) {
      for (int i=0;i<35;i++){//35
        for (int j=0;j<120;j++){//80
            o<<niv->getZeeMatrice()[i][j];
        }
        cout<<endl;
    }
return o;
}



void Niveaux::setMonstres(vector<Monstre*>vv){
    this->monstres=vv;
}


void Niveaux::supprimeDuVector(int non){
    vector<Monstre*>::iterator in = this->monstres.begin()+non;
    this->setNombreMonstre(this->getNombreMonstre()-1);
    this->monstres.erase(in);
}

void Niveaux::startMoveMonstre(Player * play){

   int salleJoueur = getNumeroSalle(play->getPosition());

    for (int j=this->getMonstres().size()-1;j>=0;j--){
       
        if (this->monstres[j]->getMySalle()==salleJoueur){
            this->monstres[j]->setAfficher(1);
        }          
            this->monstres[j]->moveMonstre(play->getPosition(),this);
            if(this->monstres[j]->isClose(play->getPosition())==1){
                play->setSanter(play->getSanter()-this->monstres[j]->getAtack());
            }
    }     
}



Room * Niveaux::dessineCarteManuelle(int x,int y,int h,int w){//room setup
    return new Room(new Position(x,y),h,w);
}



void Niveaux::ajoutCouloireManuelle(int x,int y){
    this->editCaseZeeMatrice(x,y,'#');
}

vector<string> Niveaux::splitter(const string &s,char delim){
    vector <string> tests;
    string test;
    stringstream ss(s);
    while(getline(ss,test,delim)){
        tests.push_back(test);
    }
    return tests;
}


void Niveaux::obtienLesValeurs(){
    int jindex=0;
    vector <string> ras;
    Room ** Nrooms = new Room*[this->numSalle];
    stringstream stream;
    int i = rand() % 2 + 2*(this->numSalle-5) + 1;
    stream<<i;
    string s;
    stream >> s;
    ifstream fichier(s+".txt");
    if ( fichier ) // ce test échoue si le fichier n'est pas ouvert
    {
        string ligne; 
        // cette boucle s'arrête dès qu'une erreur de lecture survient
        while (getline(fichier,ligne))
        {
            ras = splitter(ligne,' ');
                    if (ras[0] == "DIM"){
                     
                          Nrooms[jindex]= dessineCarteManuelle(stoi(ras[1]),stoi(ras[2]),stoi(ras[3]),stoi(ras[4]));
                          Nrooms[jindex]->setFirstDoor(new Position(stoi(ras[5]),stoi(ras[6])));
                          Nrooms[jindex]->setSecondeDoor(new Position(stoi(ras[7]),stoi(ras[8])));
                         
                         if(this->numSalle == 6 && (jindex==2 || jindex == 3)){
                            Nrooms[jindex]->setThirdDoor(new Position(stoi(ras[9]),stoi(ras[10])));
                            }
                         jindex++;
                          
                    }else if(ras[0] == "INI"){
                          
                          this->setRooms(Nrooms);                        
                          Room * room = new Room (Nrooms,this->numSalle,1);                   
                          this->setRoomTest(room);                         
                          this->setZeeMatrice(this->getRoomTest()->getSauve());
                    }else if(ras[0] == "PAS"){
                        for (int i = 1; i<=ras.size()-2;i=i+2){
                            this->ajoutCouloireManuelle(stoi(ras[i]),stoi(ras[i+1]));
                            }
                }
            }
          
    }else{
        cout<<"probleme de fichier"<<std::flush;
    }
    
}