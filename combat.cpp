#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "combat.h"
#include "menu.h"
#include "pokemon.h"

using namespace std;

void combat(Player *player, Pokemon *pokemonAdverse, int canAttack){
     
    int k = 0;
    
    if (player->ekip[0].pv<=0) //Si les PV de l'un des pokémons tombe à zéro
    {
        player->ekip[0].pv = 0;
        afficheCombat(player,pokemonAdverse);
        cout << "Ton pokemon " << player->ekip[0].name << " n'a plus de pv" << endl << endl;

        
        // on regarde si on a d'autre pokémon avec de la vie
        while (k<5 && (player->ekip[k].name == "XOX" || player->ekip[k].pv == 0))
        {
            k++;
        }
        if (k==5)
        {
            cout << "Tes Pokemons n'ont plus de vie !" << endl << endl;
            cout << "----   Fin du combat   ----" ;
            cout << "\n\n\n\n\n\n\n";
            cout <<" ---Appuies sur une touche pour continuer"<< endl;
            getChar();
            wclear();
            return;
        }
        
        // si on a au moins un autre pokemon avc de la vie
        // on échange les 2 pokémons
        // il n'y a pas de choix du suivant
        Pokemon * poketemp = new Pokemon;
        copyPokemon(&player->ekip[k], poketemp);
        copyPokemon(&player->ekip[0], &player->ekip[k]);
        copyPokemon(poketemp, &player->ekip[0]);
        
        delete poketemp;

        cout <<  player->ekip[0].name << " entre en jeu !!" << endl;
        
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        getChar();
        delay(1);
        wclear();

        combat(player, pokemonAdverse, canAttack);
    }
    if (pokemonAdverse->pv<=0)
    {
        pokemonAdverse->pv =0;
        afficheCombat(player,pokemonAdverse);
        cout << "Tu as vaincu le pokemon adverse" << endl;
        srand (time(NULL)); // initialisation de la graine
        int aleatoire = rand() % 500 + 200;  // entre 0 et 3 attaques
        cout << "Vous gagnez " << aleatoire << " $ !";
        player->inv.argent+=aleatoire;
        cout << "\n\n\n\n\n\n\n";
        cout <<" ---Appuies sur une touche pour continuer"<< endl;
        getChar();
        wclear();

        if (player->ekip[0].xp >= player->ekip[0].xpmax)
        {
            cout << "Votre "<<player->ekip[0].name << " monte de niveau !" << endl << endl;

            cout << "-> Avant" << endl << "Niveau : " << player->ekip[0].niveau << endl << "PVmax : " << player->ekip[0].pvmax << endl << "PV : " << player->ekip[0].pv << endl;

            for (int i=0;player->ekip[0].attaque[i].puissance!=-1;i++)
            {
                cout << "Degat de  : " << player->ekip[0].attaque[i].name << " : "<<player->ekip[0].attaque[i].puissance << endl;
            }
            int pvActuel=player->ekip[0].pv;
            int pvMaxAvant=player->ekip[0].pvmax;
            calcPvXp(player->ekip[0].niveau+1, &player->ekip[0]);
            player->ekip[0].pv=pvActuel+player->ekip[0].pvmax-pvMaxAvant;

            cout << endl << endl << "-> Après" << endl << "Niveau : " << player->ekip[0].niveau << endl << "PVmax : " << player->ekip[0].pvmax << endl << "PV : " << player->ekip[0].pv << endl;

            for (int i=0;player->ekip[0].attaque[i].puissance!=-1;i++)
            {
                cout << "Degat de  : " << player->ekip[0].attaque[i].name << " : "<<player->ekip[0].attaque[i].puissance << endl;
            }
            cout << "\n\n\n\n\n\n\n";
            cout <<" ---Appuies sur une touche pour continuer"<< endl;
            getChar();
            wclear();   
        }
        return;
    }

    if (canAttack!=-1)
    {
        afficheCombat(player, pokemonAdverse);
            
        cout << "1 - Attaque         2 - Sac" << endl;
        cout << "3 - Pokemon         4 - Fuite" << endl;
    }

    
    if (canAttack==0) //Le Pokemon sauvage attaque si on ne peut pas attaquer
    {
        int aleatoire=3;
        while (pokemonAdverse->attaque[aleatoire].name=="xxx")
        {
            srand (time(NULL)); // initialisation de la graine
            aleatoire = rand() % 3 + 0;  // entre 0 et 3 attaques
        }
        cout <<" Le " << pokemonAdverse->name << " sauvage utilise " << pokemonAdverse->attaque[aleatoire].type.bashCouleur << pokemonAdverse->attaque[aleatoire].name << white << endl;
        calcDamage(pokemonAdverse->attaque[aleatoire], &player->ekip[0]);
        getChar();
        wclear();
        combat(player,pokemonAdverse,1);
    }

    if(canAttack==1)
    {
        switch (getChar())
        {
            case '1' :
                wclear();
                afficheCombat(player,pokemonAdverse);
                if (attaque(player, pokemonAdverse)!=-1)
                {
                    wclear();
                    combat(player,pokemonAdverse,0); 
                }
                else
                {
                    wclear();
                    combat(player,pokemonAdverse,1); 
                }
            break;
            
            case '2' :
                wclear();
                afficheInventaire(player->inv);
                cout << "\n\n\n\n\n\n\n";
                cout <<" ---Appuies sur une autre touche pour sortir"<< endl;
                switch (getChar())
                {
                    case '1' :
                        if (player->inv.nbPotion>0)
                        {
                            player->inv.nbPotion--;
                            wclear();
                            afficheInventaire(player->inv);

                            cout << player->pseudo << " utilise une potion sur "<<player->ekip[0].name << "\nil regagne 10PV"<<endl;
                            cout << "\n\n\n\n\n\n\n";
                            player->inv.nbPotion--;
                            cout <<" ---Appuies sur une touche pour continuer"<< endl;
                            player->ekip[0].pv+=10;
                            getChar();
                            combat(player,pokemonAdverse,0);
                        }
                        else
                        {
                            cout << "vous n'avez pas de potion" << endl;
                            cout << "\n\n\n\n\n\n\n";
                            cout <<" ---Appuies sur une touche pour continuer"<< endl;
                            getChar();
                            wclear();
                            canAttack=0;
                        }
                    break;

                    case '2' : 
                        wclear();
                        if (player->inv.nbPokeball>0)
                        {
                            afficheCombat(player,pokemonAdverse);
                            cout << "Vous lancez une pokeball !" << endl;
                            if(calcCapture(pokemonAdverse)==1)
                            {
                                copyPokemon(pokemonAdverse,&player->ekip[compteEkip(player)]);
                                cout << "La capture a réussi" << endl;
                                cout << pokemonAdverse->name << " a rejoins votre équipe !"<<endl;
                                cout << "\n\n\n\n\n\n\n";
                                player->inv.nbPokeball--;
                                cout <<" ---Appuies sur une touche pour continuer"<< endl;
                                getChar();
                                wclear();
                                pokemonAdverse->pv = 0; // pour faire u en sorte qu'il disparaisse
                                return;
                            }
                            else
                            {
                                cout << "La capture a échoué ";
                                cout << "\n\n\n\n\n\n\n";
                                player->inv.nbPokeball--;
                                cout <<" ---Appuies sur une touche pour continuer"<< endl;
                                getChar();
                                wclear();
                                combat(player,pokemonAdverse,0);      
                            }

                        }
                        else
                        {
                            cout << "Vous n'avez pas de pokeball"<<endl;
                            cout << "\n\n\n\n\n\n\n";
                            cout <<" ---Appuies sur une touche pour continuer"<< endl;
                            getChar();
                            wclear();
                            canAttack=0;
                            wclear();
                            combat(player,pokemonAdverse,1);                            
                        }
                    break;
                }
            break;
                
            case '3' :
                wclear();
                cout << "Quel pokemon voulez-vous envoyer au combat ?" << endl << endl;
                afficheEkip(player);
                char input;
                input = getChar();
                int i;
                
                switch (input)
                {
                    case '1': i = -1; break;
                    case '2': i = 1; break;
                    case '3': i = 2; break;
                    case '4': i = 3; break;
                    case '5': i = 4; break;
                    case '6': i = 5; break;
                    default : i=-1;
                }
                wclear();
                if (i!=-1&&player->ekip[i].name!="xox")
                {
                    Pokemon *poketemp = new Pokemon;
                    copyPokemon(&player->ekip[i], poketemp);
                    copyPokemon(&player->ekip[0], &player->ekip[i]);
                    copyPokemon(poketemp, &player->ekip[0]);
                    delete poketemp;
                    afficheCombat(player,pokemonAdverse);
                    cout << player->ekip[i].name << " reviens !" << endl;
                    cout << player->ekip[0].name << ", a ton tour !!!" << endl;
                    getChar();
                    wclear();
                    combat(player,pokemonAdverse,0);  
                }
                else
                {
                    combat(player,pokemonAdverse,1);  
                }                   
            break;

            case '4' :
                wclear();
                return;
            break;

            default:
                wclear();
                combat(player,pokemonAdverse,1);
        }
    }
}
    


int attaque (Player *player, Pokemon *pokemonAdverse)
{
    for (int i=0;player->ekip[0].attaque[i].puissance!=-1;i++)
    {
        cout << " " << i+1 << " " << player->ekip[0].attaque[i].type.cara << player->ekip[0].attaque[i].name << endl;
        cout << "Puissance " << player->ekip[0].attaque[i].puissance<< endl << endl;  
    }
    cout << "\n\n\n\n\n\n\n";
    cout <<" ---Appuies sur une autre touche pour sortir"<< endl;
    char input;
    input = getChar();
    int i=0;
    switch (input)
    {
        case '1' : i=0; break;
        case '2' : i=1; break;
        case '3' : i=2; break;
        case '4' : i=3; break;
        default: return -1;
    }  
    wclear();
    afficheCombat(player,pokemonAdverse);
    cout << player->ekip[0].name << " utilise " << player->ekip[0].attaque[i].name << endl;
    calcDamage(player->ekip[0].attaque[i], pokemonAdverse);
    getChar();
    return 1;
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

bool calcCapture(Pokemon *pokemon){
    int quotient = (pokemon->pvmax/pokemon->pv)*3; //+pv est petit, +quotient est grand, + de chance
    srand (time(NULL)); //
    int aleatoire = rand() % 10 + 0;
    getChar();
    if (quotient >= aleatoire)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}