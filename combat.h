#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include "main.h"
using namespace std;

void combat(Player *player, PkmSauvage *pokemonSauvage);
void attaque (Player *player, PkmSauvage *pokemonSauvage);
void afficheCombat (Player *player, PkmSauvage *pokemonSauvage);