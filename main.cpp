#include <iostream>
#include <stdio.h>
#include "main.h"
#include "map.h"
#include "pokemon.h"
#include "intro.h"
#include "menu.h"

 
#include <fstream>

using namespace std;


int main()
{

    remplissageMap(map);
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
    //initMap(map);
    

    //Intro 
    intro(&player);
    wclear();
    onMap (player, pokemonSauvage1);
    return 0;

}

void remplissageMap(char map[width*height]){
    ifstream monFlux("./map.txt"); // récup du fichier dans monFlux
    if(monFlux) // vérification que le fichier soit bien lu
    {
        int i = 0;
        char c;
        
        while(monFlux.get(c)) // tant qu'il y a des caractères on les met dans la map
        {
            if (c!= '\n') { // saut le saut de ligne
                map[i] = c;
                i++;
            }   
        }
        cout << endl;
    }
    else cout << "erreur avec le fichier" <<  endl;
}


