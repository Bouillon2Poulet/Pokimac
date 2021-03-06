#include <iostream>
#include "menu.h"
using namespace std;
void afficheMenu(const Player *player){ 
    cout << endl << "----------" << endl << endl;
    cout << "1 : Inventaire" << endl;
    cout << "2 : Pokemons" << endl;
    cout << "3 : "<< player->pseudo << endl;
}

void afficheInventaire(Inventaire inv){
    cout<< endl;
    cout << "- INVENTAIRE -" << endl ;
    cout<< endl;
    cout << "1 Potion : " << inv.nbPotion << endl;
    cout << "2 Pokeball :1 " << inv.nbPokeball << endl;
    cout << "3 Antidote : " << inv.nbAntidote << endl;
    cout << endl << endl << endl;
    cout << "Argent : " << inv.argent << endl << endl << endl;
}

int compteEkip(Player *player){ //retourne le nombre de Pokemon dans l'équipe du joueur
    int compteur=0;
    while (player->ekip[compteur].name!="XOX")
    {
        compteur++;
    }
    return compteur;
}

void afficheEkip(Player *player){
    cout << "- EKIP -" << endl << endl;
    for (int i=0;i<compteEkip(player);i++)
    {
        cout<<i+1<<" - " <<  player->ekip[i].name << " " << player->ekip[i].type.cara << endl;
        cout << "Niveau :" << player->ekip[i].niveau << endl;
        cout << "XP : " << player->ekip[i].xp << "/" << player->ekip[i].xpmax << endl<<endl;
        cout << "PV :" << player->ekip[i].pv << "/" << player->ekip[i].pvmax << endl<<endl;

    }

}
void affichePlayer(Player *player){
    wclear();
    cout << "Dresseur.e :" << endl;
    cout << "\nPseudo :" << player->pseudo << endl;
    cout << "-----"<<endl;
    cout << "Nombre de Pokemon : "<< compteEkip(player) << endl;
    for (int i = 0;i<compteEkip(player);i++)
    {
        cout << player->ekip[i].type.cara << " ";
    }
}