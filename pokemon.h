#pragma once
#include <iostream>
#include "main.h"

//Prototypes de fonctions
//Initialisation
void initPokemonSauvage (Pokemon listePkm[], Pokemon *pokemonSauvage, Map *map);

//Clonage
void copyPokemon(Pokemon *source, Pokemon *destination); 
void copyAttaque(Attaque source, Attaque *destination);
void copyType (Type source, Type *destination);

//Autre
void calcPvXp(int niveau, Pokemon *pokemon);