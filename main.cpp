#include <iostream>
#include "main.h"
#include "map.h"
#include "pokemon.h"
#include "intro.h"
#include "menu.h"

using namespace std;


int main()
{

    //Declarations
    //Joueur et Pokémon Sauvage
    Player player;
    PkmSauvage pokemonSauvage1;

    //Initialisations
    initPlayer (&player, 20, 20);
    initListePokemon(listePkm); //Initialise les pokémons
    initInventaire(player.inv);
    initEkip(&player);
    initPokemonSauvage (listePkm, &pokemonSauvage1);
    initMap(map);
    

    //Intro 
    intro(&player);


    // test du déplacement
    clear();
    onMap (player, pokemonSauvage1);
    return 0;
}



