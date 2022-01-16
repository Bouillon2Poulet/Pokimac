#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;




void updateMap(char map[width*height], Player player, PkmSauvage pokemonSauvage);
void deplacement_perso(Player *player, char map[]);
void onMap ( Player player, PkmSauvage pokemonSauvage1, char map[]);
void afficheCouleur(char c);
void checkIfTooClose(Player *player, PkmSauvage pokemonSauvage1);
void combat(Player *player, PkmSauvage *pokemonSauvage);

