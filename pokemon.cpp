#include <iostream>
#include "pokemon.h"
using namespace std;

Pokemon salameche;
Pokemon bulbizarre;
Pokemon carapuce;
Pokemon listePkm [40];
PkmSauvage pokemonSauvage1;



void init_pokemons(Pokemon listePkm[])
{
    salameche.nom = "Salameche";
    salameche.type = "Feu";
    salameche.pv = 39;
    salameche.dmg = 60;
    salameche.def = 60;
    salameche.cara = red + '*' + white;
    listePkm[0] = salameche;

    bulbizarre.nom = "Bulbizarre"; // A Changer
    bulbizarre.type = "Plante";
    bulbizarre.pv = 45;
    bulbizarre.dmg = 49;
    bulbizarre.def = 49;
    bulbizarre.cara = green + '&' + white;
    listePkm[1] = bulbizarre;

    carapuce.nom = "Carapuce"; // A Changer
    carapuce.type = "Eau";
    carapuce.pv = 44;
    carapuce.dmg = 48;
    carapuce.def = 65;
    carapuce.cara = blue + '%'+ white;
    listePkm[2] = carapuce;
}


void copyPokemon(Pokemon source, Pokemon *destination) //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
{
    destination->nom=source.nom;
    destination->type=source.type;
    destination->pv=source.pv;
    destination->dmg=source.dmg;
    destination->def=source.def;
    destination->cara=source.cara;
}


void initPokemonSauvage (Pokemon listePkm[], PkmSauvage *pokemonSauvage){
    int aleatoire = rand() % 2; //insérer nombre de pokemon au total)
    Pokemon pokeTemp;
    copyPokemon (listePkm[aleatoire],&pokeTemp);
    pokemonSauvage->nom=pokeTemp.nom;
    pokemonSauvage->type=pokeTemp.type;
    pokemonSauvage->pv=pokeTemp.pv;
    pokemonSauvage->dmg=pokeTemp.dmg;
    pokemonSauvage->def=pokeTemp.def;
    pokemonSauvage->cara=pokeTemp.cara;
    pokemonSauvage->posx=rand() % 20 + 10;
    pokemonSauvage->posy=rand() % 20 + 10;
    cout << pokemonSauvage->nom << endl << pokemonSauvage->pv << endl << pokemonSauvage->cara << endl << "posx : x" << pokemonSauvage->posx << "posx : y" << pokemonSauvage->posy << endl << endl;
}