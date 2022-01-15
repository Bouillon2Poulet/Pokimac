#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;




void updateMap(char map[width*height], Player player, PkmSauvage pokemonSauvage);
void initMap(char map[width*height]);
void deplacement_perso(Player *player, char input, char map[]);

