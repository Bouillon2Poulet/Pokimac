#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;

// dimensions de la map
const int width = 40;
const int height = 30;


void afficheMap (char map[width*height]);
void updateMap(char map[width*height], Player player, PkmSauvage pokemonSauvage);
void remplissageMap(char map[width*height]);
void deplacement_perso(Player *player, char input, char map[]);

