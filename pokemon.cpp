#include <iostream>
#include <stdlib.h>
#include "pokemon.h"
#include "map.h"
#include <time.h>
#include "pokemon.h"


using namespace std;

void initPokemonSauvage (Pokemon listePkm[], Pokemon *pokemonSauvage, Map map){
    
    int aleatoire;
    srand (time(NULL)); // initialisation de la graine
    aleatoire = rand() % 3;
    copyPokemon (listePkm[aleatoire],pokemonSauvage); //Prend un pokémon aléatoire dans la liste de pokémons.

    
    //Position aléatoire
    int posx = 23;
    int posy = 23;
/*
    while (map.Lmap.at(posx+map.width*posy) != ' '){ 
        srand (time(NULL)); // initialisation de la graine
        posx = rand() %map.width;
        //srand (time(NULL)); // initialisation de la graine
        posy = rand() %map.height;
    }
*/
    pokemonSauvage->posx = posx;
    pokemonSauvage->posy = posy;
}

void copyPokemon(Pokemon source, Pokemon *destination) //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
{
    destination->name=source.name;
    destination->pv=source.pv;
    destination->dmg=source.dmg;
    destination->def=source.def;
    for (int i=0;i<4;i++)
    {
        copyAttaque(source.attaque[i],&destination->attaque[i]); 
    }
    copyType(source.type,&destination->type);
}
void copyAttaque(Attaque source, Attaque *destination){
    destination->name=source.name;
    destination->puissance=source.puissance;
    copyType(source.type,&destination->type);
}

void copyType (Type source, Type *destination){
    destination->name=source.name;
    destination->superEfficaceContre=source.superEfficaceContre;
    destination->peuEfficaceContre=source.peuEfficaceContre;
    destination->cara=source.cara;
    destination->bashCouleur=source.bashCouleur;
}