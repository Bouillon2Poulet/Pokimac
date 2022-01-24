
#pragma once // Remplace ifdef

#include <iostream>
#include "main.h"

//Prototypes de fonctions
//Combat
void combat(Player *player, Pokemon *pokemonAdverse, int canAttack, bool sauvage);
int attaque (Player *player, Pokemon *pokemonAdverse);
void afficheCombat (Player *player, Pokemon *pokemonAdverse);
void calcDamage (Attaque attaque, Pokemon *destination);
bool calcCapture(Pokemon *pokemon);

//BOSS Fight
bool unPerdant (Player *player, Player* boss);
void introCombatBoss ();
bool combatBoss (Player* player, Player* boss);
