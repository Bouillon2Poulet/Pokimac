#include <iostream>
#include "initialisation.h"
#include "pokemon.h"
using namespace std;

void initPlayer (Player *player)
{
    initPositionPlayer (player, 5,10);
    initInventaire(&player->inv);
    initEkip(player);
}

void initPositionPlayer (Player *player, int posx, int posy){
    player->posx = posx;
    player->posy = posy;
    player->tooClose=0;
    player->posxAv =posx;
    player->posyAv = posy;
}

void initInventaire(Inventaire *inv){
    inv->nbPotion = 3;
    inv->nbPokeball = 2;
    inv->nbAntidote = 1;
    inv->nbTruc = 3;
    inv->argent = 1000;
}

void initEkip(Player *player){
    for (int i=0; i<6; i++)
    {
        player->ekip[i].name="XOX";
        player->ekip[i].pv = 0;
    }
}

void initPokemon (Pokemon listePokemon[], Attaque listeAttaque[], Type listeType[])
{
    initListeType (listeType);
    initListeAttaque (listeAttaque, listeType);
    initListePokemon(listePokemon,listeAttaque,listeType); 
}

void initListeType (Type listeType[]){

    Type normal;
    normal.name="normal";
    normal.superEfficaceContre=" ";
    normal.peuEfficaceContre="roche";
    normal.cara= white + '#' + white;
    normal.bashCouleur=white;
    listeType[0]=normal;

    Type feu;
    feu.name="feu";
    feu.superEfficaceContre="plante glace insecte";
    feu.peuEfficaceContre="feu eau roche dragon";
    feu.cara= red + '*' + white;
    feu.bashCouleur=red;
    listeType[1]=feu;

    Type eau;
    eau.name="eau";
    eau.superEfficaceContre="feu sol roche";
    eau.peuEfficaceContre="eau plante dragon";
    eau.cara=blue + '%'+ white;
    eau.bashCouleur=blue;
    listeType[2]=eau;
  
    Type plante;
    plante.name="plante";
    plante.superEfficaceContre="eau sol roche";
    plante.peuEfficaceContre="feu plante poison vol insecte dragon";
    plante.cara= green + '&' + white;
    plante.bashCouleur=green;
    listeType[3]=plante;

    Type electrik;
    electrik.name="electrik";
    electrik.superEfficaceContre="eau vol";
    electrik.peuEfficaceContre="plante electrik sol dragon";
    electrik.cara= yellow + '!' + white;
    electrik.bashCouleur=yellow;
    listeType[4]=electrik;
    
    Type glace;
    glace.name="glace";
    glace.superEfficaceContre="plante sol vol dragon";
    glace.peuEfficaceContre="eau glace";
    glace.cara= cyan + '#' + white;
    glace.bashCouleur=cyan;
    listeType[5]=glace;

    Type combat;
    combat.name="combat";
    combat.superEfficaceContre="normal glace roche";
    combat.peuEfficaceContre="poison vol psy insecte spectre";
    combat.cara= brown + '#' + white;
    combat.bashCouleur=brown;
    listeType[6]=combat;

    Type poison;
    poison.name="combat";
    poison.superEfficaceContre="plante insecte";
    poison.peuEfficaceContre="poison sol roche spectre";
    poison.cara= purple + '#' + white;
    poison.bashCouleur=purple;
    listeType[7]=poison;

    Type sol;
    sol.name="sol";
    sol.superEfficaceContre="feu electrik poison roche";
    sol.peuEfficaceContre="plante insecte";
    sol.cara= grey + '#' + white;
    sol.bashCouleur=grey;
    listeType[8]=sol;

    Type vol;
    vol.name="vol";
    vol.superEfficaceContre="plante combat insecte";
    vol.peuEfficaceContre="electrik roche";
    vol.cara= cyan + '#' + white;
    vol.bashCouleur=cyan;
    listeType[9]=vol;

    Type psy;
    psy.name="psy";
    psy.superEfficaceContre="combat poison";
    psy.peuEfficaceContre="insecte";
    psy.cara= yellow + '#' + white;
    psy.bashCouleur=yellow;
    listeType[10]=psy;

    Type insecte;
    insecte.name="insecte";
    insecte.superEfficaceContre="plante poison psy";
    insecte.peuEfficaceContre="feu combat vol spectre";
    insecte.cara= red + '#' + white;
    insecte.bashCouleur=red;
    listeType[11]=insecte;

    Type roche;
    roche.name="roche";
    roche.superEfficaceContre="feu glace vol insecte";
    roche.peuEfficaceContre="combat sol";
    roche.cara= brown + '#' + white;
    roche.bashCouleur=brown;
    listeType[12]=roche;

    Type spectre;
    spectre.name="spectre";
    spectre.superEfficaceContre="spectre";
    spectre.peuEfficaceContre="normal psy";
    spectre.cara= purple + '#' + white;
    spectre.bashCouleur=purple;
    listeType[13]=spectre;

    Type dragon;
    dragon.name="dragon";
    dragon.superEfficaceContre="dragon";
    dragon.peuEfficaceContre="";
    dragon.cara=blue + '#' + white;
    dragon.bashCouleur=blue;
    listeType[14]=dragon;
}
void initListeAttaque(Attaque listeAttaque[],Type listeType[]){
    Attaque griffe;
    griffe.name= "griffe"+white;
    griffe.type=listeType[0];
    griffe.puissance=10;
    listeAttaque[0]=griffe;

    Attaque flameche;
    flameche.name="flameche"+white;
    flameche.type=listeType[1];
    flameche.puissance=20;
    listeAttaque[1]=flameche;

    Attaque fouet_liane;
    fouet_liane.name="fouet_liane"+white;
    fouet_liane.type=listeType[3];
    fouet_liane.puissance=13;
    listeAttaque[2]=fouet_liane;

    Attaque pistolet_a_o;
    pistolet_a_o.name="pistolet_a_o"+white;
    pistolet_a_o.type=listeType[2];;
    pistolet_a_o.puissance=18;
    listeAttaque[3]=pistolet_a_o;

}

void initListePokemon(Pokemon listePkm[], Attaque listeAttaque[],Type listeType[])
{
    Pokemon pikachu;
    pikachu.name = "Pikachu";
    copyType(listeType[4], &pikachu.type);
    pikachu.constpv = 5;
    pikachu.constatak = 3; //plus constatak est faible, plus les attaques du pokémon gagneront de puissance quand il lvl up
    initAttaque(pikachu.attaque);
    copyAttaque(listeAttaque[0], &pikachu.attaque[0]);
    copyAttaque(listeAttaque[1], &pikachu.attaque[1]);
    copyAttaque(listeAttaque[2], &pikachu.attaque[2]);
    listePkm[0] = pikachu;

    Pokemon salameche;
    salameche.name = "Salameche";
    copyType(listeType[1], &salameche.type);
    salameche.constpv = 4;
    salameche.constatak = 2;
    initAttaque(salameche.attaque);
    copyAttaque(listeAttaque[0], &salameche.attaque[0]);
    copyAttaque(listeAttaque[1], &salameche.attaque[1]);
    copyAttaque(listeAttaque[2], &salameche.attaque[2]);
    listePkm[1] = salameche;

    Pokemon bulbizarre;
    bulbizarre.name = "Bulbizarre"; // A Changer
    copyType(listeType[3], &bulbizarre.type);
    bulbizarre.constpv = 6;
    bulbizarre.constatak = 4;
    initAttaque(bulbizarre.attaque);
    copyAttaque(listeAttaque[0], &bulbizarre.attaque[0]);
    copyAttaque(listeAttaque[2], &bulbizarre.attaque[1]);
    listePkm[2] = bulbizarre;

    Pokemon carapuce;
    carapuce.name = "Carapuce"; // A Changer
    copyType(listeType[2], &carapuce.type);
    carapuce.constpv = 5;
    carapuce.constatak = 2;
    initAttaque(carapuce.attaque);
    copyAttaque(listeAttaque[0], &carapuce.attaque[0]);
    copyAttaque(listeAttaque[3], &carapuce.attaque[1]);
    listePkm[3] = carapuce;
}

void initAttaque(Attaque attaque[]){
    for (int i=0;i<4;i++)
    {
        attaque[i].name = "xxx";
        attaque[i].puissance = -1;  
    }
}
