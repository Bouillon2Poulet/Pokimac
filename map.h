#pragma once // Remplace ifdef

#include <iostream>
#include "main.h"
using namespace std;


//Prototypes de fonctions
void updateMap(Map* listeMap[], int* mapx, int* mapy, int mapwidth, Player *player, Player *boss, Pokemon ListePokemonSauvage[], int nbPokemonSauvage);
void deplacement_perso(Player *player, char input, int* mapx, int* mapy , int mapwidth, Map* listeMap[]);
void onMap (Player *player, Player* boss, Pokemon ListePokemonSauvage[], int nbPokemonSauvage, int* mapx, int* mapy, int mapwidth, Map* listeMap[]);
void remplaceMap(Map* mapAv, int nbNext, int mapwidth, Map* listeMap[]);

//Pokemon sauvage
void deplacementPokemonSauvage (Map* map, Pokemon* pokemonSauvage);

//Centre Pokemon
void centrePokemon(Player *player, char entree);

//Autre
void checkIfTooClose(Player *player, Pokemon pokemonSauvage1, Map* map);
bool peutBouger(char charMap);
void afficheCouleur(char c, string bgMap, int x, int y);