#include <iostream>
#include "intro.h"
using namespace std;

void intro (Player *player, string *suivant)
{
    cout << "Bienvenue dans le monde des Pokemons..." << endl << endl;
    cout << "...Appuyez sur entrer pour commencer l'aventure"<< endl;
    *suivant = getchar();
    wclear();

    cout << "Comment t'appelles-tu ?" << endl;
    cin >> player->pseudo; // Pseudo
    wclear();

    getchar(); // Vider le tampon du premier getchar()

    cout << "OK " << player->pseudo << " tu te crois capable de pouvoir être le meilleur dresseur" << endl;
    cout << " d'animaux de combats que l'on nomme POKEMON ?" << endl;
    cout << "si oui appuie sur entrer avec vigueur !!!!"<< endl;
    *suivant = getchar();
    wclear();
}



void choix_starter (Player *player, string *suivant, Pokemon listePkm[])
{
    wclear();
    cout << "Choix du Pokemon :" << endl;
    cout << "\033[31m 1 - Salamèche\033[0m\n";
    cout << "\033[32m 2 - Bulbizarre\033[0m\n";
    cout << "\033[34m 3 - Carapuce\033[0m\n";
    int choix;
    cin >> choix;
    switch (choix)
    {
        case 1: copyPokemon(listePkm[0],&player->ekip[0]);
        break;

        case 2: copyPokemon(listePkm[1],&player->ekip[0]);
        break;

        case 3: copyPokemon(listePkm[2],&player->ekip[0]);
        break;

        default: cout << "Veuillez entrer un chiffre entre 1 et 3" << endl;
        *suivant = getchar();
        choix_starter(player,suivant,listePkm);
    }
}


void intro2(Player *player, string *suivant)
{
    cout << "Bonne chance avec ton " << player->ekip[0].nom << "dans le monde des Pokémon !";
}