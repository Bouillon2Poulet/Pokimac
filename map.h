#pragma once // Remplace ifdef

#include <iostream>
#include "main.h"
using namespace std;


//Prototypes de fonctions
void updateMap(Map* listeMap[], int* mapx, int* mapy, int mapwidth, Player player, Pokemon pokemonSauvage);
void deplacement_perso(Player *player, char input, int* mapx, int* mapy , int mapwidth, Map* listeMap[]);
void onMap (Player player, Pokemon pokemonSauvage1, int* mapx, int* mapy, int mapwidth, Map* listeMap[]);
void remplaceMap(Map* mapAv, int nbNext, int mapwidth, Map* listeMap[]);
void afficheCouleur(char c);
void checkIfTooClose(Player *player, Pokemon pokemonSauvage1);
