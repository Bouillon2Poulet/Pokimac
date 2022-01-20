#pragma once // Remplace ifdef
#include <iostream>
#include "main.h"

//Prototypes de fonctions
void afficheMenu(const Player *player);
void afficheInventaire(Inventaire inv);
void afficheEkip(Player *player);
void affichePlayer(Player *player);

int compteEkip(Player *player);