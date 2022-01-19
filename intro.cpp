#include <iostream>
#include "intro.h"
#include "pokemon.h"
using namespace std;

void intro (Player *player, Pokemon listePkm[])
{
    wclear();
    cout << "Bienvenue dans le monde des Pokemons..." << endl;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "           ---Appuies sur une touche pour continuer" << endl;
    getChar();
    //char input;
    string input="";
    while(input=="")
    {
        wclear();
        cout << "Comment t'appelles-tu ?" << endl;
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "           ---Appuies sur entree pour continuer" << endl;
        cin >> input;
        player->pseudo; // Pseudo
    }
     player->pseudo=input;
    wclear();
    cout << "C PARTI !!!\nAlors " << player->pseudo << ", tu te crois capable de pouvoir etre le meilleur dresseur de Pokemon ?" << endl << endl;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "           ---Appuies sur une touche pour continuer" << endl;
    getChar();
    wclear();
    choixStarter(player, listePkm);
    
}

////

void choixStarter (Player *player, Pokemon listePkm[])
{
    char a='X';
    int b;
    switch (descriptionStarter(a,listePkm))
    {
        case '1': b=1;break;
        case '2': b=2;break;
        case '3': b=3;break;
    }
    copyPokemon(listePkm[b],&player->ekip[0]);
    wclear();
    cout << "Bonne chance avec ton " << player->ekip[0].name << " dans le monde des Pokémon !\n\n";
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "---Appuies sur une touche pour continuer..." << endl;
    getChar();
    return;
}

char descriptionStarter(char choix, Pokemon listePkm[]){
    wclear();
    cout << "Choix du Pokemon :" << endl;
    for (int i =1;i<=3;i++)
    {
        cout << i << " " << listePkm[i].type.bashCouleur << listePkm[i].name << white << endl;
    }
    cout << "\n\n\n\n\n\n\n\n\n";
    switch (choix)
    {
        case '1': cout << "\n Pokémon Salamandre\nType Feu "<<listePkm[1].type.cara<<endl; break;
        case '2': cout << "\n Pokémon plante ?\nType Plante "<<listePkm[2].type.cara<<endl; break;
        case '3': cout << "\n Pokémon Tortue\nType Eau "<<listePkm[3].type.cara<<endl; break;
        case 'X': cout <<"\n"; break;
    }
    cout << endl << endl << endl;
    cout << "Appuyez sur un numero pour voir le Pokemon"<<endl;
    cout << "Appuies sur A pour confirmer"<<endl;
    cout << "Appuies sur autre touche pour retour"<<endl;
    char a = getChar();
    if (choix!='X')
    {
        if (a=='a'||a=='A')
        {
            return choix;   
        }

    }
    if (a=='1'||a=='2'||a=='3')
    {
        descriptionStarter(a,listePkm);
    }

    else
    {
        descriptionStarter('X',listePkm);
    }
    
}

