#include <iostream>
#include <stdlib.h>
#include "pokemon.h"
#include "map.h"
#include <time.h>
#include "pokemon.h"


using namespace std;

void initPokemonSauvage (Pokemon listePkm[], Pokemon *pokemonSauvage, Map* map){
    int aleatoire;
    //srand (time(NULL)); // initialisation de la graine
    aleatoire = rand() % 3;
    copyPokemon (listePkm[aleatoire],pokemonSauvage); //Prend un pokémon aléatoire dans la liste de pokémons.
    //srand (time(NULL));
    int niveau=rand()%2+5; //niveau entre 5 et 7

    calcPvXp (niveau,pokemonSauvage);
    pokemonSauvage->pv=pokemonSauvage->pvmax;

    //Position aléatoire
    
    
    int posx = 5;
    int posy = 5;

    pokemonSauvage->mapNom = map->adresse;

    do { 
        //srand (time(NULL)); // initialisation de la graine
        posx = rand() %map->width;
        //srand (time(NULL)); // initialisation de la graine
        posy = rand() %map->height;
    } while (map->Lmap.at(posx+map->width*posy) != ' ');
    
    cout << posx << " // " << posy << endl;
    cout << pokemonSauvage->name << endl<<endl;
    
    pokemonSauvage->posx = posx;
    pokemonSauvage->posy = posy;
}

void copyPokemon(Pokemon source, Pokemon *destination) //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
{
    destination->name=source.name;
    destination->pv=source.pv;
    destination->pvmax=source.pvmax;
    destination->niveau=source.niveau;
    destination->xp=source.xp;
    destination->xpmax=source.xpmax;
    destination->constpv=source.constpv;
    destination->constatak=source.constatak;
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

void calcPvXp(int niveau, Pokemon *pokemon){//Quand on initialise un pokémon
    pokemon->niveau=niveau; //La recette pour construire un pokémon
    pokemon->xp=0;
    pokemon->xpmax=4*niveau;
    pokemon->pvmax=6*niveau + pokemon->constpv;
    for(int i=0;pokemon->attaque[i].puissance!=-1;i++)
    {
        pokemon->attaque[i].puissance=pokemon->attaque[i].puissance+(pokemon->niveau/pokemon->constatak);
    }
}
