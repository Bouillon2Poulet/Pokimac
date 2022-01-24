
#pragma once // Remplace ifdef

#include <iostream>
#include "main.h"

//Prototypes de fonctions
void combat(Player *player, Pokemon *pokemonAdverse, int canAttack, bool sauvage);
int attaque (Player *player, Pokemon *pokemonAdverse);
void afficheCombat (Player *player, Pokemon *pokemonAdverse);
void calcDamage (Attaque attaque, Pokemon *destination);
bool calcCapture(Pokemon *pokemon);

// boss fight
bool unPerdant (Player *player, Player* boss);
void introCombatBoss ();

void combatBoss (Player* player, Player* boss);
