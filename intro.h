#pragma once // Remplace ifdef
#include <iostream>
#include "main.h"

void intro (Player *player, Pokemon listePokemon[]);
void choixStarter (Player *player, Pokemon listePkm[]);
char descriptionStarter(char a, Pokemon listePkm[]);
bool starterText (int input);