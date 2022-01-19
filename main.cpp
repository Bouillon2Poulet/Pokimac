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
    Map* mapForet = remplissageMap("./map/foret.txt");
    Map* mapVolcan = remplissageMap("./map/volcan.txt");
    mapVolcan->bgMap = bgBrown;
    Map* mapRiviere = remplissageMap("./map/riviere.txt");
    Map* mapChamps = remplissageMap("./map/champs.txt");
    mapRiviere->bgMap = bgGreen;


    Map* listeMap[4] = {mapVolcan,mapRiviere,mapChamps,mapForet};
    int mapwidth = 2;
    
    // permet de donner la map de départ !
    int mapx = 0;
    int mapy = 1;

    //Declarations
    //Joueur et Pokémon Sauvage
    Player player;
    PkmSauvage pokemonSauvage1;
    Pokemon listePokemon[40];
    Attaque listeAttaque[40];

    //Initialisations
    
    // init de la position du player de manière aléatoire
    int posx = 5;
    int posy = 5;
    
    initListeAttaque (listeAttaque);
    initPlayer (&player, 5, 5);
    initListePokemon(listePokemon,listeAttaque); //Initialise les pokémons
    initInventaire(player.inv);
    initEkip(&player);
    initPokemonSauvage (listePokemon, &pokemonSauvage1, *mapChamps);


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