#include <iostream>
#include "menu.h"
using namespace std;

void affiche_menu(const Player player){
    cout << endl << "----------" << endl << endl;
    cout << "1 : Inventaire" << endl;
    cout << "2 : Pokémons" << endl;
    cout << "3 : "<< player.pseudo << endl;
}

void init_inv(Inventaire inv){
    inv.nb_pokeball = 0;
    inv.nb_popo2 = 0;
    inv.nb_potions = 0;
    inv.nb_trucopif = 0;
}

void affiche_inventaire(Inventaire inv){
    cout << "- INVENTAIRE -" << endl<<endl;
    cout << "mmmmmh yeah !! " << endl;
    cout << "ton nombre de pokeballs est : " << inv.nb_pokeball << endl;
    cout << "ton nombre de popo2 est : " << inv.nb_popo2 << endl;
    cout << "ton nombre de trucopif est : " << inv.nb_trucopif << endl << endl << endl;
}