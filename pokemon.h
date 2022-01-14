
#include <iostream>
#include "main.h"
using namespace std;

void init_pokemons(Pokemon listePkm[]);
void initPokemonSauvage (Pokemon listePkm[], PkmSauvage *pokemonSauvage);
void copyPokemon(Pokemon source, Pokemon *destination); //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
