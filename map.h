#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;




void updateMap(Map map, Player player, PkmSauvage pokemonSauvage);
void deplacement_perso(Player *player, char input, Map map);
void onMap (Player player, PkmSauvage pokemonSauvage1, Map map);
void afficheCouleur(char c);
void checkIfTooClose(Player *player, PkmSauvage pokemonSauvage1);

//Combat
void combat(Player *player, PkmSauvage *pokemonSauvage);
void attaque (Player *player, PkmSauvage *pokemonSauvage);

