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
    char input;
    input = getChar();

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
        if  (getChar()=='x')
        {
            wclear();
            onMap(player,pokemonSauvage1,map);
        }
        break;

        case '2':
        wclear();
        afficheEkip(player);
        cout << "Appuyez sur X pour revenir sur la map" << endl;
        if  (getChar()=='x')
        {
            wclear();
            onMap(player,pokemonSauvage1,map);
        }
        break;
        
        case '3':
        wclear();
        affichePlayer(player);
        cout << "\n\n\nAppuyez sur X pour revenir sur la map" << endl;
        if  (getChar()=='x')
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

        switch (getChar())
        {
            case '1' :
                wclear();
                afficheCombat(player,pokemonSauvage);
                attaque(player, pokemonSauvage);
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
    cout << "1 - " <<  player->ekip[0].attaque[0].bash << player->ekip[0].attaque[0].name << endl;
    cout << "Puissance " << player->ekip[0].attaque[0].puissance<< endl;
    cout << endl;

    cout << "2 - " << player->ekip[0].attaque[1].bash <<  player->ekip[0].attaque[1].name << endl;
    cout << "Puissance " << player->ekip[0].attaque[1].puissance<< endl;
    cout << endl;
    char input = getch();
    int i;
    switch (input)
    {
        case '1' : i=0; break;
        case '2' : i=1; break;
        case '3' : i=2; break;
        case '4' : i=3; break;
    }   
    cout << player->ekip[0].name << " utilise " << player->ekip[0].attaque[i].name << " de puissance " << player->ekip[0].attaque[1].puissance;
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
