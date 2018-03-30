#ifndef ECRAND_H
#define ECRAND_H
#include<iostream>
#include<string>
#include<ostream>
#include<ncurses.h>
#include"Player.hpp"
#include<stdlib.h>
#include<string>

using namespace std;

class Ecrand {
private:


public:
Ecrand();
static void EcrandMaj(Player *,Niveaux *);
static void detruireEcrand(string);
void afficheMatricePourTest(char **);
static void afficheMatricePourJouer(char **);




};

#endif