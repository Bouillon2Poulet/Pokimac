#pragma once
#include <iostream>
#include "main.h"

//Prototypes de fonctions
void initPokemonSauvage (Pokemon listePkm[], Pokemon *pokemonSauvage, Map *map);
void copyPokemon(Pokemon source, Pokemon *destination); //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
void copyAttaque(Attaque source, Attaque *destination);
void copyType (Type source, Type *destination);