#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;

// dimensions de la map
const int width = 10;
const int height = 10;


void afficheMap (char map[width*height]);
void updateMap(char map[], Player player);
void remplissageMap(char map[]);
