#include <iostream>
#include <stdio.h>
//#include <curses.h> ---> pb dans la mise en lien
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
    init_pokemons(listePkm); //Initialise les pokémons
    init_inv(player.inv);
    initEkip(&player);
    initPokemonSauvage (listePkm, &pokemonSauvage1);
    //initMap(map);
    
    
    string suivant;

    

    //Intro

    intro(&player, &suivant);
    choix_starter(&player, &suivant, listePkm);
    intro2(&player, &suivant);


    // test du déplacement
    while(true){
        char input;
        input = getch(); //getch prend direct l'input sans attendre de enter
        wclear();
        switch (input) {
            case '1':
                affiche_inventaire(player.inv);
                cout << "Appuyez sur ECHAP pour revenir sur la map" << endl;
                cin >> suivant;
                wclear();
                break;

            case '2':
                affichePokemon(player);
                    cout << "Appuyez sur ECHAP pour revenir sur la map" << endl;
                    cin >> suivant;
                    wclear();
                    break;
           
        }


        deplacement_perso(&player, input, map);
        updateMap(map, player, pokemonSauvage1);
        affiche_menu(player);
    }
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


