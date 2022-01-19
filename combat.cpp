#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "combat.h"
#include "menu.h"

using namespace std;

bool canAttack = 1;

void combat(Player *player, Pokemon *pokemonAdverse){
    wclear();
    bool combatContinue = 1;

    if (player->ekip[0].pv<=0) //Si les PV de l'un des pokémons tombe à zéro le combat s'arrête
    {
        combatContinue=0;
    }
    if (pokemonAdverse->pv<=0)
    {
        combatContinue=0;
    }

    if (combatContinue == 1)
    {
        afficheCombat(player, pokemonAdverse);
     
        cout << "1 - Attaque         2 - Sac" << endl;
        cout << "3 - Pokemon         4 - Fuite" << endl;

        if (canAttack==0) //Le Pokemon sauvage attaque si on ne peut pas attaquer
        {
            int aleatoire = 3;
            while (pokemonAdverse->attaque[aleatoire].name=="xxx")
            {
                srand (time(NULL)); // initialisation de la graine
                aleatoire = rand() % 4;  // entre 0 et 3 attaques
            }
            srand (time(NULL)); // initialisation de la graine
            aleatoire = rand() % 4; 
            cout <<" Le " << pokemonAdverse->name << " sauvage utilise " << pokemonAdverse->attaque[aleatoire].type.bashCouleur << pokemonAdverse->attaque[aleatoire].name << white << endl;
            calcDamage(pokemonAdverse->attaque[aleatoire], &player->ekip[0]);
            canAttack=1;
            combat(player,pokemonAdverse);
        }
        
        switch (getChar())
        {
            case '1' :
                wclear();
                afficheCombat(player,pokemonAdverse);
                attaque(player, pokemonAdverse);
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
        combat(player,pokemonAdverse);    
    }
    
}

void attaque (Player *player, Pokemon *pokemonAdverse)
{
    for (int i=0;player->ekip[0].attaque[i].puissance!=-1;i++)
    {
        cout << i+1 << player->ekip[0].attaque[i].type.cara << player->ekip[0].attaque[i].name << endl;
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
    cout << player->ekip[0].name << " utilise " << player->ekip[0].attaque[i].name << endl;
    calcDamage(player->ekip[0].attaque[i], pokemonAdverse);
}

void afficheCombat (Player *player, Pokemon *pokemonAdverse)
{
        cout << "------"<<endl;
        cout << "COMBAT" << endl;
        cout << "------"<<endl;
        cout << endl << endl;

        cout << "                         " << pokemonAdverse->name << endl;
        cout << "                         PV:" << pokemonAdverse->pv << endl;
        cout << endl << endl;
        cout << "                             " << pokemonAdverse->type.cara << endl;
        cout << endl << endl<<endl;
        
        cout << player->ekip[0].name << endl;
        cout << "PV: " << player->ekip[0].pv << endl;
        cout << endl << endl;
        cout << "    " << player->ekip[0].type.cara<<endl;
        cout << endl << endl;
}

void calcDamage (Attaque attaque, Pokemon *destination){

    if (attaque.type.superEfficaceContre.find(destination->type.name
    )!= std::string::npos)
    {
        cout << "C'est très efficace" << endl;
        destination->pv-=attaque.puissance*2;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        getChar();
        return;
    }
    if (attaque.type.peuEfficaceContre.find(destination->type.name
    )!= std::string::npos)
    {
        cout << "C'est peu efficace" << endl;
        destination->pv-=attaque.puissance/2;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        getChar();
        return;
    }
    else
    {
        destination->pv-=attaque.puissance;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        getChar();
        return;
    }
}