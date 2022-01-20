#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "combat.h"
#include "menu.h"

using namespace std;


//srand (time(NULL)); // initialisation de la graine
int canAttack = rand() % 1;  // pile ou face pour commencer

void combat(Player *player, Pokemon *pokemonAdverse){


    if (player->ekip[0].pv<=0) //Si les PV de l'un des pokémons tombe à zéro le combat s'arrête
    {
        afficheCombat(player,pokemonAdverse);
        cout << "Votre pokemon n'a plus de pv" << endl;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        getChar();
        wclear();
        return;
    }
    if (pokemonAdverse->pv<=0)
    {
        afficheCombat(player,pokemonAdverse);
        cout << "Vous avez vaincu le pokemon adverse" << endl;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        getChar();
        wclear();
        return;
    }


    afficheCombat(player, pokemonAdverse);
    
    cout << "1 - Attaque         2 - Sac" << endl;
    cout << "3 - Pokemon         4 - Fuite" << endl;

    if (canAttack==0) //Le Pokemon sauvage attaque si on ne peut pas attaquer
    {
        int aleatoire;
        while (pokemonAdverse->attaque[aleatoire].name=="xxx")
        {
            srand (time(NULL)); // initialisation de la graine
            aleatoire = rand() % 4;  // entre 0 et 3 attaques
        }
        cout <<" Le " << pokemonAdverse->name << " sauvage utilise " << pokemonAdverse->attaque[aleatoire].type.bashCouleur << pokemonAdverse->attaque[aleatoire].name << white << endl;
        calcDamage(pokemonAdverse->attaque[aleatoire], &player->ekip[0]);
        canAttack=1;
        getch();
        wclear();
        combat(player,pokemonAdverse);
    }

    if(canAttack==1)
    {
        switch (getChar())
        {
            case '1' :
                wclear();
                afficheCombat(player,pokemonAdverse);
                attaque(player, pokemonAdverse);
                wclear();
                canAttack=0;
                combat(player,pokemonAdverse); 
                break;
            
            case '2' :
                wclear();
                afficheInventaire(player->inv);
                switch (getChar())
                {
                    case '1' :
                    if (player->inv.nbPotion>0)
                    {
                        cout << player->pseudo << " utilise une potion sur "<<player->ekip[0].name << "\nil regagne 10PV"<<endl;
                        player->inv.nbPotion--;
                        cout << "\n\n\n\n\n\n\n";
                        cout <<" ---Appuies sur une touche pour continuer"<< endl;
                        getch();
                        canAttack=0;
                        combat(player,pokemonAdverse);
                    }
                    else
                    {
                        cout << "vous n'avez pas de potion" << endl;
                        cout << "\n\n\n\n\n\n\n";
                        cout <<" ---Appuies sur une touche pour continuer"<< endl;
                        getch();
                        canAttack=1;
                        combat(player,pokemonAdverse);
                    }
                    
                }
                break;
            case '4' :
                wclear();
                return;
                break;
            default:
                wclear();
                combat(player,pokemonAdverse);
        }
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
    wclear();
    afficheCombat(player,pokemonAdverse);
    cout << player->ekip[0].name << " utilise " << player->ekip[0].attaque[i].name << endl;
    calcDamage(player->ekip[0].attaque[i], pokemonAdverse);
    getChar();
}

void afficheCombat (Player *player, Pokemon *pokemonAdverse)
{
        cout << "------"<<endl;
        cout << "COMBAT" << endl;
        cout << "------"<<endl;
        cout << endl << endl;

        cout << "                         " << pokemonAdverse->name << endl;
        cout << "                         PV:" << pokemonAdverse->pv << endl;
        cout << "                         LV:" << pokemonAdverse->niveau << endl;
        cout << endl << endl;
        cout << "                             " << pokemonAdverse->type.cara << endl;
        cout << endl << endl<<endl;
        
        cout << player->ekip[0].name << endl;
        cout << "PV: " << player->ekip[0].pv << endl;
        cout << "LV:" << player->ekip[0].niveau << endl;
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
        return;
    }
    if (attaque.type.peuEfficaceContre.find(destination->type.name
    )!= std::string::npos)
    {
        cout << "C'est peu efficace" << endl;
        destination->pv-=attaque.puissance/2;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        return;
    }
    else
    {
        destination->pv-=attaque.puissance;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        return;
    }
}