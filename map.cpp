#include <iostream>
#include "map.h"
#include "menu.h"
using namespace std;


void updateMap(Map map, Player player, PkmSauvage pokemonSauvage)
{
    int nb_aff_ligne = 0;
    bool aff_car = true;

    for (int j=0; j<map.height; j++)
        {
            for (int h=0; h<map.width; h++)
            {

                if (h==player.posx && j==player.posy) // Affichage joueur
                {
                    cout << white << 1;
                    nb_aff_ligne ++;
                    h++;
                }

                if ((h==player.posxAv && j==player.posyAv)) // Affichage Pokémon qui suit 
                {
                    cout << player.ekip[0].cara;
                    nb_aff_ligne ++;
                    aff_car = false;
                }

                if (h==pokemonSauvage.posx && j==pokemonSauvage.posy) // Affichage Pokémon sauvage
                {
                    cout << pokemonSauvage.cara;
                    nb_aff_ligne ++;
                    h++;
                }
                
                if (nb_aff_ligne<=map.width-1 && aff_car){
                    afficheCouleur(map.Lmap.at(h+map.width*j));
                    nb_aff_ligne ++;
                }
                aff_car = true;
            }
        cout << "           nb_aff -> " << nb_aff_ligne << endl;
        nb_aff_ligne =0;
        }
        cout << white << endl; // reset de la couleur
}


void deplacement_perso(Player *player, char input, Map map){
    if (input=='z')
    {
        if ((player->posy >0) && (map.Lmap.at((player->posx)+((player->posy)-1)*map.width)==' ')) 
        {
            //MAJ de l'ancienne position
            player->posxAv = player->posx;
            player->posyAv = player->posy;                
            
            // MAj de la nouvelle position
            player->posy --;
        }
    }
    if (input=='q')
    {
        if ((player->posx >0) && (map.Lmap.at((player->posy)*map.width+(player->posx)-1)==' ')) 
        {
            //MAJ de l'ancienne position
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx --;
        }
    }

    if (input=='s')
    {
        if ((player->posy <map.height-1) && (map.Lmap.at((player->posx)+((player->posy)+1)*map.width)==' ')) 
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posy ++;
        }
    }
    if (input=='d')
    {
        if ((player->posx <map.width-1) && (map.Lmap.at((player->posy)*map.width+(player->posx)+1)==' '))
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx ++;
        }
    }
    
}

void onMap (Player player, PkmSauvage pokemonSauvage1, Map map)
{
    updateMap(map, player, pokemonSauvage1);
    afficheMenu(player);
    char input='s';
    char reponse='x';
    input =getch();

    if (input=='z'||input=='q'||input=='s'||input=='d')
    {
        wclear();
        deplacement_perso(&player, input, map);
        checkIfTooClose(&player,pokemonSauvage1);
        if (player.tooClose==1)
        {
            combat(&player,&pokemonSauvage1);
            onMap(player,pokemonSauvage1,map);
        }
        else
        {
           onMap(player,pokemonSauvage1,map); 
        }
    }
    switch (input)
    {
        case '1':
        wclear();
        afficheInventaire(player.inv);
        cout << "Appuyez sur X pour revenir sur la map" << endl;
        if  (checkInput(reponse)==1)
        {
            wclear();
            onMap(player,pokemonSauvage1,map);
        }
        break;

        case '2':
        wclear();
        afficheEkip(player);
        cout << "Appuyez sur X pour revenir sur la map" << endl;
        if  (checkInput(reponse)==1)
        {
            wclear();
            onMap(player,pokemonSauvage1,map);
        }
        break;
        
        case '3':
        wclear();
        affichePlayer(player);
        cout << "\n\n\nAppuyez sur X pour revenir sur la map" << endl;
        if  (checkInput(reponse)==1)
        {
            wclear();
            onMap(player,pokemonSauvage1,map);
        }
        break;
    }
}


void afficheCouleur(char c){
    switch (c){

        case '#':
            cout << blue << "#";
        break;        
        
        case '-':
        case '|':
        case '~':
            cout << grey << c;
        break;

        case '@':
            cout << yellow << "@";
        break;

        default:
            cout << white << c;
    }
}

void checkIfTooClose(Player *player,PkmSauvage pokemonSauvage1){
    bool tooCloseX=false;
    bool tooCloseY=false;
    if (player->posx>=pokemonSauvage1.posx-1 && player->posx<=pokemonSauvage1.posx+1)
    {
        tooCloseX=true;
    }

    if (player->posy>=pokemonSauvage1.posy-1 && player->posy<=pokemonSauvage1.posy+1)
    {
        tooCloseY=true;
    }
    if (tooCloseX==true && tooCloseY==true)
    {
        player->tooClose=1;
    }
    else
    {
        player->tooClose=0;
    }
}

void combat(Player *player, PkmSauvage *pokemonSauvage){
    wclear();
    bool combatContinue = 1;
    while (combatContinue == 1)
    {
        cout << "COMBAT" << endl << "---" << endl;
        cout << "Ton Pokemon :\n" << player->ekip[0].cara<<" "<< player->ekip[0].name << endl << "PV:" << player->ekip[0].pv;
        cout << "Pokemon Sauvage :\n" << pokemonSauvage->cara<<" "<< pokemonSauvage->name << endl << "PV:" << pokemonSauvage->pv<<endl;
        cout << "Pour sortir appuyer sur a"<<endl;
        char reponse ='a';
        if (checkInput(reponse)==1)
        {
            combatContinue=0;
        }
        if (player->ekip[0].pv==0)
        {
            combatContinue=0;
        }
        if (pokemonSauvage->pv==0)
        {
            combatContinue=0;
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

        
    
    char reponse ='a';
    if (checkInput(reponse)==1)
    {
        combatContinue=0;
    }
    if (player->ekip[0].pv==0)
    {
        combatContinue=0;
    }
    if (pokemonSauvage->pv==0)
    {
        combatContinue=0;
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