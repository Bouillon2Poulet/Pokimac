#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "combat.h"
#include "menu.h"
using namespace std;

bool canAttack = 1;

void combat(Player *player, PkmSauvage *pokemonSauvage){
    wclear();
    bool combatContinue = 1;

    if (player->ekip[0].pv<=0) //Si les PV de l'un des pokémons tombe à zéro le combat s'arrête
    {
        combatContinue=0;
    }
    if (pokemonSauvage->pv<=0)
    {
        combatContinue=0;
    }

    if (combatContinue == 1)
    {
        afficheCombat(player, pokemonSauvage);
     
        cout << "1 - Attaque         2 - Sac" << endl;
        cout << "3 - Pokemon         4 - Fuite" << endl;

        if (canAttack==0)
        {
            int aleatoire = 3;
            while (pokemonSauvage->attaque[aleatoire].name=="xxx")
            {
                srand (time(NULL)); // initialisation de la graine
                aleatoire = rand() % 4;  // entre 0 et 3 attaques
            }
            srand (time(NULL)); // initialisation de la graine
            aleatoire = rand() % 4; 
            cout << pokemonSauvage->name << " utilise " << pokemonSauvage->attaque[aleatoire].bash << pokemonSauvage->attaque[aleatoire].name << endl;
            player->ekip[0].pv=player->ekip[0].pv - pokemonSauvage->attaque[aleatoire].puissance;
            canAttack=1;           
            getChar();
            combat(player,pokemonSauvage);
        }
        
        switch (getChar())
        {
            case '1' :
                wclear();
                afficheCombat(player,pokemonSauvage);
                attaque(player, pokemonSauvage);
                canAttack=0;
                break;
            
            case '2' :
                afficheInventaire(player->inv);
                break;
            case '4' :
                combatContinue=0;
                break;
        }

    }

    if (combatContinue==0)
        {
            wclear();
            return;
        }
    else
    {
        wclear();
        combat(player,pokemonSauvage);    
    }
    
}

void attaque (Player *player, PkmSauvage *pokemonSauvage)
{
    for (int i=0;player->ekip[0].attaque[i].puissance!=-1;i++)
    {
        cout << i+1 << player->ekip[0].attaque[i].bash << player->ekip[0].attaque[i].name << endl;
        cout << "Puissance " << player->ekip[0].attaque[i].puissance<< endl;
        cout << endl;
    }
    char input;
    input = getChar();
    int i=0;
    switch (input)
    {
        case '1' : i=0; break;
        case '2' : i=1; break;
        case '3' : i=2; break;
        case '4' : i=3; break;
    }   
    cout << player->ekip[0].name << " utilise " << player->ekip[0].attaque[i].name;
    pokemonSauvage->pv = pokemonSauvage->pv-player->ekip[0].attaque[i].puissance;
    getChar();
}

void afficheCombat (Player *player, PkmSauvage *pokemonSauvage)
{
        cout << "------"<<endl;
        cout << "COMBAT" << endl;
        cout << "------"<<endl;
        cout << endl << endl;

        cout << "                         " << pokemonSauvage->name << endl;
        cout << "                         PV:" << pokemonSauvage->pv << endl;
        cout << endl << endl;
        cout << "                             " << pokemonSauvage->cara << endl;
        cout << endl << endl<<endl;
        
        cout << player->ekip[0].name << endl;
        cout << "PV: " << player->ekip[0].pv << endl;
        cout << endl << endl;
        cout << "    " << player->ekip[0].cara<<endl;
        cout << endl << endl;
}