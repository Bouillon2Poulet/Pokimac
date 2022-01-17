#include <iostream>
#include <stdio.h>

#include "main.h"
#include "combat.h"
#include "map.h"
#include "pokemon.h"
#include "intro.h"
#include "menu.h"

 
#include <fstream>

using namespace std;


int main()
{

    // remplissage des maps
    Map* map = remplissageMap("./map.txt");
    Map* map2 = remplissageMap("./map2.txt");
    Map* map3 = remplissageMap("./map3.txt");


    Map* listeMap[3] = {map,map2,map3};
    int mapwidth = 3;
    int mapx = 0;
    int mapy = 0;

    // initialisation de la map sur laquelle on joue
    /*Map* mapJeu = new Map;
    remplaceMap(mapJeu,1,listeMap);*/

    //Declarations
    //Joueur et Pokémon Sauvage
    Player player;
    PkmSauvage pokemonSauvage1;
    Pokemon listePokemon[40];
    Attaque listeAttaque[40];

    //Initialisations
    initListeAttaque (listeAttaque);
    initPlayer (&player, 20, 20);
    initListePokemon(listePokemon,listeAttaque); //Initialise les pokémons
    initInventaire(player.inv);
    initEkip(&player);
    initPokemonSauvage (listePokemon, &pokemonSauvage1, *map);


    //Intro 
    intro(&player,listePokemon);
    wclear();
    cout << "Liste attaque[0] " << listeAttaque[0].name << endl;
    cout << "Starter attaque[0] " << player.ekip[0].attaque[0].name << endl;
    cout << "Starter attaque[1] " << player.ekip[0].attaque[1].name << endl;
    onMap (player, pokemonSauvage1, &mapx, &mapy, mapwidth, listeMap);
    return 0;

}

 Map* remplissageMap(string adresseMap){
    ifstream monFlux(adresseMap); // récup du fichier dans monFlux
    Map* interMap = new Map;
    vector<char> inverse;
    if(monFlux) // vérification que le fichier soit bien lu
    {
        int width = 0;
        bool ligne = false;
        
        int height = 1;
        char c;
        
        while(monFlux.get(c)) // tant qu'il y a des caractères on les met dans la map 
        { // une première fois pour def la taille de la map
            
            if (c!='\n') inverse.push_back(c);

            if (c!= '\n' && ligne == false) { // saut le saut de ligne
                width++;
            }
            else  
            {
                ligne = true;
            }

            if (c== '\n') height++;
        }

        // remise de la map dans le bon sens
        for (int i =0; i<inverse.size(); i++){
            interMap->Lmap.push_back(inverse.at(i));
        }
        
        interMap->width = width;
        interMap->height = height;
        interMap->adresse= adresseMap;
        cout << endl;
        }
    else cout << "erreur avec le fichier" <<  endl;
    return interMap;
}

