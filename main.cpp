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
    init_inv(player.inv);

    

    //Intro

    intro(&player, &suivant);
    choix_starter(&player, &suivant, listePkm);
    intro2(&player, &suivant);


    //////////////// LA MAP + DEPLACEMENT PERSO //////////////////////////

    //déf de la map
    char map [width*height];


    // affichage de la map
    afficheMap (map);


    // test du déplacement
    while(true){
        char input;
        cin >> input;
        clear();
        if (input=='1') { // on entre dans l'inventaire;
            affiche_inventaire(player.inv);
            cout << "Appuyez sur ECHAP pour revenir sur la map" << endl;
            cin >> suivant;
            clear();
        }


        deplacement_perso(&player, input);
        updateMap(map, player);
        affiche_menu(player);
    }
    return 0;
}

