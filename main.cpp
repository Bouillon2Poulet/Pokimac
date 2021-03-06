#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    // initialisation de la graine pour rand
    time_t t;
    srand((unsigned) time(&t));

    // remplissage des maps
    Map* mapForet = remplissageMap("./map/foret.txt");
    Map* mapVolcan = remplissageMap("./map/volcan.txt");
    Map* mapRiviere = remplissageMap("./map/riviere.txt");
    Map* mapChamps = remplissageMap("./map/champs.txt");
    Map* dansVolcan = remplissageMap("./map/dansVolcan.txt");
    Map* salleBoss = remplissageMap("./map/salleBoss.txt");
    Map* centrePokemon = remplissageMap("./map/centrePokemon.txt");


    Map* listeMap[7] = {mapVolcan,mapRiviere,mapChamps,mapForet,dansVolcan, salleBoss, centrePokemon};
    int mapwidth = 2;
    int mapheight = 4;
    
    //Map de départ
    int mapx = 0;
    int mapy = 1;

    //Declarations
    //Joueur, le Boss et Pokémon Sauvage
    Player player;
    Player boss;
    Pokemon pokemonSauvage1;
    Pokemon pokemonSauvage2;
    Pokemon pokemonSauvage3;
    Pokemon pokemonSauvage4;
    Pokemon pokemonSauvage5;
    Pokemon pokemonSauvage6;
    Pokemon pokemonSauvage7;
    Pokemon pokemonSauvage8;

    Pokemon listePokemon[40];
    Attaque listeAttaque[40];
    Type listeType[15];

    //Initialisation
    initPlayer (&player);
    initPlayer (&boss);
    initPositionPlayer(&boss, 9, 3); // la position du boss dans la salle du boss
    boss.cara = 'X';
    initPokemon(listePokemon,listeAttaque,listeType);

    //Initialisation de l'ékip du boss
    copyPokemon(&listePokemon[0], &boss.ekip[0]);
    copyPokemon(&listePokemon[1], &boss.ekip[1]);
    copyPokemon(&listePokemon[2], &boss.ekip[2]);
    copyPokemon(&listePokemon[1], &boss.ekip[3]);
    copyPokemon(&listePokemon[2], &boss.ekip[4]);
    copyPokemon(&listePokemon[0], &boss.ekip[5]);


    boss.ekip[0].pv = 36;
    boss.ekip[1].pv = 38;
    boss.ekip[2].pv = 41;
    boss.ekip[3].pv = 40;
    boss.ekip[4].pv = 39;
    boss.ekip[5].pv = 80;
    
    boss.ekip[0].niveau = 7;
    boss.ekip[1].niveau = 6;
    boss.ekip[2].niveau = 8;
    boss.ekip[3].niveau = 8;
    boss.ekip[4].niveau = 10;
    boss.ekip[5].niveau = 25;


    //Initialisation des Pokemons sauvages sur les cartes
    initPokemonSauvage (listePokemon, &pokemonSauvage1,mapForet);
    initPokemonSauvage (listePokemon, &pokemonSauvage2,mapRiviere);
    initPokemonSauvage (listePokemon, &pokemonSauvage3,mapChamps);
    initPokemonSauvage (listePokemon, &pokemonSauvage4,mapVolcan);
    initPokemonSauvage (listePokemon, &pokemonSauvage5,mapForet);
    initPokemonSauvage (listePokemon, &pokemonSauvage6,mapRiviere);
    initPokemonSauvage (listePokemon, &pokemonSauvage7,mapChamps);
    initPokemonSauvage (listePokemon, &pokemonSauvage8,mapVolcan);
    
    int nbPokemonSauvage = 8;

    Pokemon listePokemonSauvage [8] = {pokemonSauvage1, pokemonSauvage2, pokemonSauvage3, pokemonSauvage4, pokemonSauvage5, pokemonSauvage6, pokemonSauvage7, pokemonSauvage8};

    //JEU
    intro(&player,listePokemon,listeType);

    onMap (&player,&boss, listePokemonSauvage, nbPokemonSauvage, &mapx, &mapy, mapwidth, listeMap);

    return 0;

}


//Définition de fonction
 Map* remplissageMap(string adresseMap){ //Remplie les maps à partir des .txt de ./map
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
        }
    else cout << adresseMap << " : erreur avec le fichier" <<  endl;
    return interMap;
}


void debug(){
    int debug;
    cin >> debug;
}

void delay(int secondes){ //Fais une pause dans l'execution du programme
    time_t timer;
    time(&timer);

    time_t timer2;
    time(&timer2);

    while (timer2-timer < secondes){
        time(&timer2);
    }
    return;

}