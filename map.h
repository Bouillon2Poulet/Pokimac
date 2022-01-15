#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;

// dimensions de la map
const int width = 40;
const int height = 30;


void updateMap(char map[width*height], Player player, PkmSauvage pokemonSauvage);
void initMap(char map[width*height]);
void deplacement_perso(Player *player, char input, char map[]);
void onMap (Player player, PkmSauvage pokemonSauvage1);

