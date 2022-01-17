#include <iostream>
#include "pokemon.h"
using namespace std;


void initListePokemon(Pokemon listePkm[], Attaque listeAttaque[])
{
    Pokemon salameche;
    salameche.name = "Salameche";
    salameche.type = "Feu";
    salameche.pv = 39;
    salameche.dmg = 60;
    salameche.def = 60;
    salameche.cara = caraFeu;
    copyAttaque(listeAttaque[0], &salameche.attaque[0]);
    copyAttaque(listeAttaque[1], &salameche.attaque[1]);
    listePkm[0] = salameche;

    Pokemon bulbizarre;
    bulbizarre.name = "Bulbizarre"; // A Changer
    bulbizarre.type = "Plante";
    bulbizarre.pv = 45;
    bulbizarre.dmg = 49;
    bulbizarre.def = 49;
    bulbizarre.cara = caraPlante;
    listePkm[1] = bulbizarre;

    Pokemon carapuce;
    carapuce.name = "Carapuce"; // A Changer
    carapuce.type = "Eau";
    carapuce.pv = 44;
    carapuce.dmg = 48;
    carapuce.def = 65;
    carapuce.cara = caraEau;
    listePkm[2] = carapuce;
}


void copyPokemon(Pokemon source, Pokemon *destination) //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
{
    destination->name=source.name;
    destination->type=source.type;
    destination->pv=source.pv;
    destination->dmg=source.dmg;
    destination->def=source.def;
    destination->cara=source.cara;
    for (int i=0;i<2;i++)
    {
        destination->attaque[i]=source.attaque[i]; 
    }
}


void initPokemonSauvage (Pokemon listePkm[], PkmSauvage *pokemonSauvage){
    int aleatoire = rand() % 2; //insérer nombre de pokemon au total)
    Pokemon pokeTemp;
    copyPokemon (listePkm[aleatoire],&pokeTemp);
    pokemonSauvage->name=pokeTemp.name;
    pokemonSauvage->type=pokeTemp.type;
    pokemonSauvage->pv=pokeTemp.pv;
    pokemonSauvage->dmg=pokeTemp.dmg;
    pokemonSauvage->def=pokeTemp.def;
    pokemonSauvage->cara=pokeTemp.cara;
    pokemonSauvage->posx=rand() % 20 + 10;
    pokemonSauvage->posy=rand() % 20 + 10;
}

void initListeAttaque(Attaque listeAttaque[]){
    Attaque griffe;
    griffe.name= "griffe"+white;
    griffe.type="normal";
    griffe.cara=caraNormal;
    griffe.puissance=10;
    griffe.bash=white;
    listeAttaque[0]=griffe;

    Attaque flameche;
    flameche.name="flameche"+white;
    flameche.type="feu";
    flameche.cara=caraFeu;
    flameche.puissance=20;
    flameche.bash=red;
    listeAttaque[1]=flameche;
}

void copyAttaque(Attaque source, Attaque *destination){
    destination->name=source.name;
    destination->type=source.type;
    destination->cara=source.cara;
    destination->puissance=source.puissance;
}
