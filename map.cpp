#include <iostream>
#include "map.h"
#include "menu.h"
using namespace std;

char map [width*height];


void updateMap(char map[width*height], Player player, PkmSauvage pokemonSauvage)
{
    int nb_aff_ligne = 0;
    bool aff_car = true;


    for (int j=0; j<height; j++)
        {
            for (int h=0; h<width; h++)
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
                    cout << pokemonSauvage.cara;;
                    nb_aff_ligne ++;
                    h++;
                }
                
                if (nb_aff_ligne<=width-1 && aff_car){
                    afficheCouleur(map[h+width*j]);
                    nb_aff_ligne ++;
                }
                aff_car = true;
            }
        cout << "           nb_aff -> " << nb_aff_ligne << endl;
        nb_aff_ligne =0;
        }
        cout << white << endl; // reset de la couleur
}


void deplacement_perso(Player *player, string input, char map[]){
    // demander le déplacement
    //if (input == 'p') return input; // on arrête de joueur à la map en appuyant sur P


    // déplacement selon l'input et selon la position

    if (input=="z")
    {
        if ((player->posy >0) && (map[(player->posx)+((player->posy)-1)*width]==' ')) 
        {
            //MAJ de l'ancienne position
            player->posxAv = player->posx;
            player->posyAv = player->posy;                
            // MAj de la nouvelle position
            player->posy --;
        }
    }

    if (input=="q")
    {
        if ((player->posx >0) && (map[(player->posy)*width+(player->posx)-1]==' ')) 
        {
            //MAJ de l'ancienne position
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx --;
        }
    }

    if (input=="s")
    {
        if ((player->posy <height-1) && (map[(player->posx)+((player->posy)+1)*width]==' ')) 
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posy ++;
        }
    }
    if (input=="d")
    {
        if ((player->posx <width-1) && (map[(player->posy)*width+(player->posx)+1]==' '))
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx ++;
        }
    }
    
}

void onMap ( Player player, PkmSauvage pokemonSauvage1)
{
    updateMap(map, player, pokemonSauvage1);
            while(true)
            {
            string input;
                input = getch(); //getch prend direct l'input sans attendre de enter
                wclear();
                if (input == "1")
                {
                    wclear();
                    afficheInventaire(player.inv);
                    cout << "Appuyez sur X pour revenir sur la map" << endl;
                    input = getch();
                    while (input=="x"&& input=="X")
                    {
                        wclear();
                        updateMap(map, player, pokemonSauvage1);
                    }
                }
                if (input == "2")
                {   
                    wclear();
                    afficheEkip(player);
                    cout << "Appuyez sur X pour revenir sur la map" << endl;
                    input = getch();
                    while (input=="x"&& input=="X")
                        {
                            wclear();
                            updateMap(map, player, pokemonSauvage1);
                        }
                }
                if (input == "3")
                {   
                    wclear();
                    affichePlayer(player);
                    cout << "\n\n\nAppuyez sur X pour revenir sur la map" << endl;
                    input = getch();
                    while (input=="x"&& input=="X")
                        {
                            wclear();
                            updateMap(map, player, pokemonSauvage1);
                        }
                }
                deplacement_perso(&player, input, map);
                updateMap(map, player, pokemonSauvage1);
                afficheMenu(player);
            }
} 


void afficheCouleur( char c){
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