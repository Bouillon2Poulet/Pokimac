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

    init_pokemons(listePkm); //Initialise les pokémons
    
    remplissageMap(map);
    
    string suivant;
    Player player; // Initialise les coordonnées du joueur et son inventaire
    player.posx = 5;
    player.posy = 5;
    player.posxAv =5;
    player.posyAv = 5;
    init_inv(player.inv);
    initEkip(&player);

    

    //Intro

    intro(&player, &suivant);
    choix_starter(&player, &suivant, listePkm);
    intro2(&player, &suivant);
    initPokemonSauvage (listePkm, &pokemonSauvage1);
    


    //////////////// LA MAP + DEPLACEMENT PERSO //////////////////////////

    //déf de la map
    


    // affichage de la map
    afficheMap (map);


    // test du déplacement
    while(true){
        char input;
        cin >> input;
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
            default: cout << "XXXXXX";break; // on entre dans l'inventaire;
           
        }


        deplacement_perso(&player, input, map);
        updateMap(map, player);
        affiche_menu(player);
    }
    return 0;
}



