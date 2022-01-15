#include <iostream>
#include <conio.h>
#include "intro.h"
using namespace std;

void intro (Player *player)
{
    char input;
    cout << "Bienvenue dans le monde des Pokemons..." << endl << endl;
    cout << "...Appuyez sur A pour commencer l'aventure"<< endl;
    input = getch();
    if (input == 'a')
    {
        clear();
        cout << "Comment t'appelles-tu ?" << endl;
        cin >> player->pseudo; // Pseudo
        clear();
        cout << "OK " << player->pseudo << " tu te crois capable de pouvoir être le meilleur dresseur" << endl;
        cout << " d'animaux de combats que l'on nomme POKEMON ?" << endl;
        cout << "si oui appuie sur A avec vigueur !!!!"<< endl;
        input = getch();
        if (input == 'a')
        {
            clear();
            choixStarter(player, listePkm);
        }
    }   
}



void choixStarter (Player *player, Pokemon listePkm[])
{
    int input;
    {
        clear();
        cout << "Choix du Pokemon :" << endl;
        cout << "\033[31m 1 - Salamèche\033[0m\n";
        cout << "\033[32m 2 - Bulbizarre\033[0m\n";
        cout << "\033[34m 3 - Carapuce\033[0m\n";
        cin>>input;
        if (input==1||input==2||input==3)
        {
            copyPokemon(listePkm[input-1],&player->ekip[0]);
            clear();
            cout << "Bonne chance avec ton " << player->ekip[0].nom << " dans le monde des Pokémon !\n\n\n\n Appuyez sur A pour continuer";
            string input;
            while (input!="a")
            {
                input = getch();
            }
  
        }
        else 
        {
            choixStarter (player,listePkm);
        }
    }
}
