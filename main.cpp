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
    // remplissage des maps
    Map* map = remplissageMap("./map.txt");
    map->mapRight = "map2.txt";

    Map* map2 = remplissageMap("./map.txt");
    map->mapLeft = "map.txt";
    
    Map* mapJeu = map;

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
    onMap (player, pokemonSauvage1, *mapJeu);
    return 0;

}

 Map* remplissageMap(string adresseMap){
    ifstream monFlux("./map.txt"); // récup du fichier dans monFlux
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
        cout << endl;
        }
    else cout << "erreur avec le fichier" <<  endl;
    return interMap;
}



/*bool checkInput(char reponse){
    char input;
    input = getChar();
    if (reponse ==input)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/