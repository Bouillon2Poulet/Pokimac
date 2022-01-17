#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;





void updateMap(Map* listeMap[], int* mapx, int* mapy, int mapwidth, Player player, PkmSauvage pokemonSauvage);
void deplacement_perso(Player *player, char input, int* mapx, int* mapy , int mapwidth, Map* listeMap[]);
void onMap (Player player, PkmSauvage pokemonSauvage1, int* mapx, int* mapy, int mapwidth, Map* listeMap[]);
void remplaceMap(Map* mapAv, int nbNext, int mapwidth, Map* listeMap[]);
void afficheCouleur(char c);
void checkIfTooClose(Player *player, PkmSauvage pokemonSauvage1);

//Combat
void combat(Player *player, PkmSauvage *pokemonSauvage);
void attaque (Player *player, PkmSauvage *pokemonSauvage);
void afficheCombat (Player *player, PkmSauvage *pokemonSauvage);
