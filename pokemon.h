#pragma once
#include <iostream>
#include "main.h"

void initListePokemon(Pokemon listePkm[], Attaque listeAttaque[]);
void initPokemonSauvage (Pokemon listePkm[], PkmSauvage *pokemonSauvage);
void copyPokemon(Pokemon source, Pokemon *destination); //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
void initListeAttaque(Attaque listeAttaque[]);
void copyAttaque(Attaque source, Attaque *destination);