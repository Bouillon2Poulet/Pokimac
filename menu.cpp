#include <iostream>
#include "menu.h"
using namespace std;
void afficheMenu(const Player player){
    cout << endl << "----------" << endl << endl;
    cout << "1 : Inventaire" << endl;
    cout << "2 : Pokémons" << endl;
    cout << "3 : "<< player.pseudo << endl;
}

void afficheInventaire(Inventaire inv){
    cout << "- INVENTAIRE -" << endl<<endl;
    cout<<"-----"<<endl;
    cout << "1 Potion : " << inv.nbPotion << endl;
    cout << "2 Pokeball " << inv.nbPokeball << endl;
    cout << "3 Antidote : " << inv.nbAntidote << endl;
    cout << "4 Truc" << inv.nbTruc << endl << endl << endl;
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
        cout<<i+1<<" - " <<  player.ekip[1].name << " " << player.ekip[1].type.cara << endl; 
    }

}
void affichePlayer(Player player){
    wclear();
    cout << "Dresseur.e > " << player.pseudo << endl;
    cout << "-----"<<endl;
    cout << "Nombre de Pokemon > "<< compteEkip(player) << endl;
    for (int i = 0;i<compteEkip(player);i++)
    {
        cout << player.ekip[i].type.cara << " ";
    }
}

