#pragma once // Remplace ifdef

#include <iostream>
#include "main.h"

//Prototypes de fonctions
//Joueur
void initPlayer (Player *player);
void initPositionPlayer (Player *player, int posx, int posy);
void initInventaire(Inventaire *inv);
void initEkip(Player *player);

//Pokemon
void initPokemon (Pokemon listePokemon[], Attaque listeAttaque[], Type listeType[]);
void initListeType (Type listeType[]);
void initListeAttaque(Attaque listeAttaque[],Type listeType[]);
void initAttaque(Attaque attaque[]);
void initListePokemon(Pokemon listePkm[], Attaque listeAttaque[],Type listeType[]);