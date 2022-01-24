#include <iostream>
#include "intro.h"
#include "pokemon.h"
using namespace std;

void intro (Player *player, Pokemon listePkm[], Type listeType[]) //Intro partie 1
{
    wclear();
    cout << "Bienvenue dans le monde des Pokemons..." << endl;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "           ---Appuies sur une touche pour continuer" << endl;
    getChar();
    wclear();
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
    
    choixCaraPlayer(player, 'x'); //Choix du caractère représentant le joueur

    cout << "C PARTI !!!\nAlors " << player->pseudo << ", tu te crois capable de pouvoir etre le meilleur dresseur de Pokemon ?" << endl << endl;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "           ---Appuies sur une touche pour continuer" << endl;
    getChar();
    wclear();
    choixStarter(player, listePkm); //Choix du starter

    cout << "Les Pokemons sont des creatures merveilleuses," << endl;
    cout << "qui peuplent le monde que tu t'appretes a parcourir..." << endl;
    cout << endl;
    cout << "Chaque Pokemon a un type :\n" << endl;
    for (int i=0;i<15;i++)
    {
        if (i==5)
        {
            cout << "\n(\n";
        }
        cout <<"    - " << listeType[i].name << " " << listeType[i].cara;
        cout << endl;
        if (i==14)
        {
            cout << "                  ) -> a implementer";
        }
    }
    cout << "\n\nC'est par le symbole associe a leurs types qu'ils sont representes sur la carte" << endl;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "           ---Appuies sur une touche pour continuer" << endl;
    getChar();
    wclear();
    cout << "Attention :\nsi les pv de tes pokemons tombent a zero,\ntu dois te rendre au PokeCentre indique par un C sur la carte" << endl;
    cout << "Tu pourras aussi y acheter des potions et des Pokeball pour continuer l'aventure" << endl;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "           ---Appuies sur une touche pour continuer" << endl;
    getChar();
    wclear();
    cout << "Appuies sur ZQSD pour te deplacer dans le monde des Pokemons !\n\n";
    cout << "Sois prudent, tu risques de croiser des Pokemons sauvages sur ta route...";
    cout << "... et peut etre d'autres dresseurs...\n\n";
    cout << "Bonne chance !!!";
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "           ---Appuies sur une touche pour continuer" << endl;
    getChar();
    wclear();
}


void choixStarter (Player *player, Pokemon listePkm[]) //Choix du starter
{
    char a='X';
    int b;
    switch (descriptionStarter(a,listePkm))
    {
        case '1': b=1;break;
        case '2': b=2;break;
        case '3': b=3;break;
    }
    copyPokemon(&listePkm[b],&player->ekip[0]);
    calcPvXp(6, &player->ekip[0]);
    player->ekip[0].pv=player->ekip[0].pvmax;
    wclear();
    cout << "Bonne chance avec ton " << player->ekip[0].name << " dans le monde des Pokemons !\n\n";
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "---Appuies sur une touche pour continuer..." << endl;
    getChar();
    wclear();
    return;
}

void choixCaraPlayer(Player* player, char entree){ //Choix du caractère représentant le joueur
    wclear(); 

    char cara;
    switch (entree)
    {
        case 'x' : cara = '0'; break;
        case '1': cara = 'Q'; break;
        case '2': cara = 'P'; break;
        case '3': cara = 'B'; break;
    }

    if (cara =='0')
    {
        cout << "A quoi ressembles-tu ?:" << endl << endl << endl;
        cout << "1: Q" << endl << "2: P" << endl << "3: B" << endl << endl;
        entree = getChar();
        if (entree!='1' && entree!='2' && entree!='3')
        {
            choixCaraPlayer(player,'x');
        }
        else
        {
            choixCaraPlayer(player,entree);  
        }
    }

    if (cara!='0')
    {
        cout << "A quoi ressembles-tu ?:" << endl << endl << endl;
        cout << "1: Q" << endl << "2: P" << endl << "3: B" << endl << endl;
        cout << "Ton avatar est : " << cara << endl << endl;
        cout << "Appuies sur A pour confirmer " <<endl;
        cout << "Appuies sur un autre numero pour changer d'avatar" << endl;
        char confirmation = getChar();
        switch (confirmation)
        {
            case 'a' :
                player->cara = cara;
                wclear();
                return;
            break;

            default : choixCaraPlayer(player,confirmation);
        }
    }
}

char descriptionStarter(char choix, Pokemon listePkm[]){ //Affiche la description des Starters
    wclear();
    cout << "Choix du Pokemon :" << endl;
    for (int i =1;i<=3;i++)
    {
        cout << i << " " << listePkm[i].type.bashCouleur << listePkm[i].name << white << endl;
    }
    cout << "\n\n\n\n\n\n\n\n\n";
    switch (choix)
    {
        case '1': cout << "\n Pokemon Salamèche\nType Feu "<<listePkm[1].type.cara<<endl; break;
        case '2': cout << "\n Pokemon Bulbizarre\nType Plante "<<listePkm[2].type.cara<<endl; break;
        case '3': cout << "\n Pokemon Carapuce\nType Eau "<<listePkm[3].type.cara<<endl; break;
        case 'X': cout <<"\n"; break;
    }
    cout << endl << endl << endl;
    cout << "Appuyes sur un numero pour voir le Pokemon"<<endl;
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

