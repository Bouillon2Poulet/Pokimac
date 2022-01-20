#include <iostream>
#include <stdio.h>

//Headers
#include "main.h"
#include "initialisation.h"
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
    Map* mapForet = remplissageMap("./map/foret.txt");
    Map* mapVolcan = remplissageMap("./map/volcan.txt");
    //mapVolcan->bgMap = bgBrown;
    Map* mapRiviere = remplissageMap("./map/riviere.txt");
    Map* mapChamps = remplissageMap("./map/champs.txt");
    //mapRiviere->bgMap = bgGreen;
    Map* dansVolcan = remplissageMap("./map/dansVolcan.txt");
    Map* salleBoss = remplissageMap("./map/salleBoss.txt");


    Map* listeMap[6] = {mapVolcan,mapRiviere,mapChamps,mapForet,dansVolcan, salleBoss};
    int mapwidth = 2;
    int mapheight = 3;
    
    // permet de donner la map de départ !
    int mapx = 0;
    int mapy = 1;

    //Declarations
    //Joueur et Pokémon Sauvage
    Player player;
    Pokemon pokemonSauvage1;
    Pokemon listePokemon[40];
    Attaque listeAttaque[40];
    Type listeType[14];

    //Initialisation
    initPlayer (&player);
    initPokemon(listePokemon,listeAttaque,listeType);

    initPokemonSauvage (listePokemon, &pokemonSauvage1, mapForet);

    //Initialisations
    

    initListeAttaque (listeAttaque);
    initPlayer (&player, 10, 10);
    initListePokemon(listePokemon,listeAttaque); //Initialise les pokémons
    initInventaire(player.inv);
    initEkip(&player);
    initPokemonSauvage (listePokemon, &pokemonSauvage1, *mapChamps);


    //Intro 
    for (int i=0;i<15;i++)
    {
        cout << listeType[i].name << endl;
        cout << listeType[i].cara << endl;
        cout << "superEfficaceContre :" << listeType[i].superEfficaceContre << endl; 
        cout << "peuEfficaceContre :" << listeType[i].peuEfficaceContre << endl;
        cout << "-----\n";
    }
    getChar();
    intro(&player,listePokemon);
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
                //cout << c << endl;
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
        cout << adresseMap << " // " << width << endl;
        }
    else cout << adresseMap << " : erreur avec le fichier" <<  endl;
    return interMap;
}