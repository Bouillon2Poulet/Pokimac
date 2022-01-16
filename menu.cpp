#include <iostream>
#include "menu.h"
using namespace std;

void initPlayer (Player *player, int posx, int posy){
    player->posx = posx;
    player->posy = posy;
    player->posxAv =posx;
    player->posyAv = posy;
}

void initInventaire(Inventaire inv){
    inv.nb_pokeball = 0;
    inv.nb_popo2 = 0;
    inv.nb_potions = 0;
    inv.nb_trucopif = 0;
}

void initEkip(Player *player){
    for (int i=0; i<6; i++)
    {
        player->ekip[i].name="XOX";
    }
}

void afficheMenu(const Player player){
    cout << endl << "----------" << endl << endl;
    cout << "1 : Inventaire" << endl;
    cout << "2 : Pokémons" << endl;
    cout << "3 : "<< player.pseudo << endl;
}

void afficheInventaire(Inventaire inv){
    cout << "- INVENTAIRE -" << endl<<endl;
    cout << "mmmmmh yeah !! " << endl;
    cout << "ton nombre de pokeballs est : " << inv.nb_pokeball << endl;
    cout << "ton nombre de popo2 est : " << inv.nb_popo2 << endl;
    cout << "ton nombre de trucopif est : " << inv.nb_trucopif << endl << endl << endl;
}

int compteEkip(Player player){
    int compteur=0;
    while (player.ekip[compteur].name!="XOX")
    {
        compteur++;
    }
    return compteur;
}

void afficheEkip(Player player){
    cout << "- EKIP -" << endl << endl;
    for (int i=0;i<compteEkip(player);i++)
    {
        cout<<i+1<<" - " <<  player.ekip[1].name << " " << player.ekip[1].cara << endl; 
    }

}
void affichePlayer(Player player){
    wclear();
    cout << "Dresseur.e > " << player.pseudo << endl;
    cout << "-----"<<endl;
    cout << "Nombre de Pokemon > "<< compteEkip(player) << endl;
    for (int i = 0;i<compteEkip(player);i++)
    {
        cout << player.ekip[i].cara << " ";
    }
}

