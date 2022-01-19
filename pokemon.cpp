#include <iostream>
#include <stdlib.h>
#include "pokemon.h"
#include "map.h"
#include <time.h>
#include "pokemon.h"


using namespace std;

void initListePokemon(Pokemon listePkm[], Attaque listeAttaque[])
{
    Pokemon salameche;
    salameche.name = "Salameche";
    salameche.type = "Feu";
    salameche.pv = 39;
    salameche.dmg = 60;
    salameche.def = 60;
    salameche.cara = caraFeu;
    cout << "1";
    initAttaque(salameche.attaque);
    cout << "2";
    copyAttaque(listeAttaque[0], &salameche.attaque[0]);
    copyAttaque(listeAttaque[1], &salameche.attaque[1]);
    copyAttaque(listeAttaque[2], &salameche.attaque[2]);
    cout << "2";
    listePkm[0] = salameche;

    Pokemon bulbizarre;
    bulbizarre.name = "Bulbizarre"; // A Changer
    bulbizarre.type = "Plante";
    bulbizarre.pv = 45;
    bulbizarre.dmg = 49;
    bulbizarre.def = 49;
    bulbizarre.cara = caraPlante;
    initAttaque(bulbizarre.attaque);
    copyAttaque(listeAttaque[0], &bulbizarre.attaque[0]);
    copyAttaque(listeAttaque[2], &bulbizarre.attaque[1]);
    listePkm[1] = bulbizarre;

    Pokemon carapuce;
    carapuce.name = "Carapuce"; // A Changer
    carapuce.type = "Eau";
    carapuce.pv = 44;
    carapuce.dmg = 48;
    carapuce.def = 65;
    carapuce.cara = caraEau;
    initAttaque(carapuce.attaque);
    copyAttaque(listeAttaque[0], &carapuce.attaque[0]);
    copyAttaque(listeAttaque[3], &carapuce.attaque[1]);
    listePkm[2] = carapuce;
}


void copyPokemon(Pokemon source, Pokemon *destination) //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
{
    destination->name=source.name;
    destination->type=source.type;
    destination->pv=source.pv;
    destination->dmg=source.dmg;
    destination->def=source.def;
    destination->cara=source.cara;
    for (int i=0;i<4;i++)
    {
        destination->attaque[i]=source.attaque[i]; 
    }
}


void initPokemonSauvage (Pokemon listePkm[], PkmSauvage *pokemonSauvage, Map map){
    cout << "OK5.1" << endl;
    int aleatoire;
    srand (time(NULL)); // initialisation de la graine
    aleatoire = rand() % 3; 
    Pokemon pokeTemp;
    cout << "OK5.2" << endl;
    copyPokemon (listePkm[aleatoire],&pokeTemp);
    pokemonSauvage->name=pokeTemp.name;
    pokemonSauvage->type=pokeTemp.type;
    pokemonSauvage->pv=pokeTemp.pv;
    pokemonSauvage->dmg=pokeTemp.dmg;
    pokemonSauvage->def=pokeTemp.def;
    pokemonSauvage->cara=pokeTemp.cara;
    cout << "OK5.3" << endl;
    for (int i=0;i<4;i++)
    {
        copyAttaque(pokeTemp.attaque[i],&pokemonSauvage->attaque[i]);
    }
    
    int posx = 0;
    int posy = 0;

    cout << "OK5.4" << endl;
    while (peutBouger(map.Lmap.at(posx+map.width*posy))==false){
        srand (time(NULL)); // initialisation de la graine
        posx = rand() %map.width;
        //srand (time(NULL)); // initialisation de la graine
        posy = rand() %map.height;
    }
    
    cout << "OK5.5" << endl;
    pokemonSauvage->posx = posx;
    pokemonSauvage->posy = posy;
}

void initAttaque(Attaque attaque[]){
    for (int i=0;i<4;i++)
    {
        attaque[i].name = "xxx";
        attaque[i].type = "xxx";
        attaque[i].cara = "xxx";
        attaque[i].puissance = -1;
        attaque[i].bash = "XXX";
    }

}
void initListeAttaque(Attaque listeAttaque[]){
    Attaque griffe;
    griffe.name= "griffe"+white;
    griffe.type="normal";
    griffe.cara=caraNormal;
    griffe.puissance=10;
    griffe.bash=white;
    listeAttaque[0]=griffe;

    Attaque flameche;
    flameche.name="flameche"+white;
    flameche.type="plante";
    flameche.cara=caraPlante;
    flameche.puissance=20;
    flameche.bash=red;
    listeAttaque[1]=flameche;

    Attaque fouet_liane;
    fouet_liane.name="fouet_liane"+white;
    fouet_liane.type="plante";
    fouet_liane.cara=caraPlante;
    fouet_liane.puissance=13;
    fouet_liane.bash=green;
    listeAttaque[2]=fouet_liane;

    Attaque pistolet_a_o;
    pistolet_a_o.name="pistolet_a_o"+white;
    pistolet_a_o.type="eau";
    pistolet_a_o.cara=caraEau;
    pistolet_a_o.puissance=18;
    pistolet_a_o.bash=blue;
    listeAttaque[3]=pistolet_a_o;

}
void copyAttaque(Attaque source, Attaque *destination){
    destination->name=source.name;
    destination->type=source.type;
    destination->cara=source.cara;
    destination->puissance=source.puissance;
    destination->bash=source.bash;
}
