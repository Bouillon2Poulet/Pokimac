#include <iostream>
#include <conio.h>
#include "intro.h"
using namespace std;

void intro (Player *player)
{
    clear();
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
        cout << "OK " << player->pseudo << " tu te crois capable de pouvoir être le meilleur dresseur de Pokemon ?" << endl << endl;

        cout << "...Appuyez sur A si vous vous sentez prêt"<< endl;
        input = getch();
        if (input == 'a')
        {
            choixStarter(player, listePkm);
        }
    }   
}

////

void choixStarter (Player *player, Pokemon listePkm[])
{
    char a='&';
    int b;
    switch (descriptionStarter(a,listePkm))
    {
        case '1': b=1;break;
        case '2': b=2;break;
        case '3': b=3;break;
    }
    copyPokemon(listePkm[b-1],&player->ekip[0]);
    clear();
    cout << "Bonne chance avec ton " << player->ekip[0].name << " dans le monde des Pokémon !\n\n\n\n Appuyez sur A pour continuer";
    string inputStr;
    while (inputStr!="a")
    {
        inputStr = getch();
    }
}

char descriptionStarter(char a, Pokemon listePkm[]){
    clear();
    cout << "Choix du Pokemon :" << endl;
    cout << "\033[31m 1 - Salameche\033[0m\n";
    cout << "\033[32m 2 - Bulbizarre\033[0m\n";
    cout << "\033[34m 3 - Carapuce\033[0m\n";


    cout << "a = " << a << endl;
        switch (a){
            case '1': cout << "\n Pokémon Salamandre\nType Feu "<<listePkm[0].cara<<endl; break;
            case '2': cout << "\n Pokémon de merde\nType Plante "<<listePkm[1].cara<<endl; break;
            case '3': cout << "\n Pokémon tortue\nType Eau "<<listePkm[2].cara<<endl; break;
            default : cout <<"XXX"; break;
        }
        cout << endl << endl << endl;
        cout << "Appuyez sur A pour confirmer"<<endl;
        cout << "Appuyez sur B pour retour"<<endl;
        char b;
        b=getch();   
        if (b=='a')
        {
            return a;
        }
        else
        {
            descriptionStarter(b,listePkm);
        }
}

