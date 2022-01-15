#include <iostream>
#include <conio.h>
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
    init_pokemons(listePkm); //Initialise les pokémons
    init_inv(player.inv);
    initEkip(&player);
    initPokemonSauvage (listePkm, &pokemonSauvage1);
    initMap(map);
    
    
    string suivant;

    

    //Intro

    intro(&player, &suivant);
    choix_starter(&player, &suivant, listePkm);
    intro2(&player, &suivant);


    // test du déplacement
    while(true){
        char input;
        input = _getch(); //getch prend direct l'input sans attendre de enter
        clear();
        switch (input) {
            case '1':
                affiche_inventaire(player.inv);
                cout << "Appuyez sur ECHAP pour revenir sur la map" << endl;
                cin >> suivant;
                clear();
                break;

            case '2':
                affichePokemon(player);
                    cout << "Appuyez sur ECHAP pour revenir sur la map" << endl;
                    cin >> suivant;
                    clear();
                    break;
           
        }


        deplacement_perso(&player, input, map);
        updateMap(map, player, pokemonSauvage1);
        affiche_menu(player);
    }
    return 0;
}



