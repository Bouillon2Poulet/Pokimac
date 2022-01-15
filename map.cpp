#include <iostream>
#include "map.h"
using namespace std;

char map [width*height];
    // remplissage de la map ---> elle ne sert plus à rien vu qu'il y a init m
void initMap(char map[width*height])
{   
    for (int i=0; i<width*height;i++)
    {
        if (i <2*width || i%width <2 || i%width >=width-2 || i >width*(height-2))
        {
            map[i] = '#';
        }
        else
        { 
            map[i] = ' ';
        }
        if (i == 90) map[i] = '#';
    }
}


void updateMap(char map[width*height], Player player, PkmSauvage pokemonSauvage)
{
    int nb_aff_ligne = 0;
    bool aff_car = true;

    int diff = player.posx-player.posxAv;
    diff = diff*diff;
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
                    cout << white<< map[h+width*j];
                    nb_aff_ligne ++;
                }
                aff_car = true;
            }
        cout << "           nb_aff -> " << nb_aff_ligne <<  " // diff -> " << diff << endl;
        nb_aff_ligne =0;
        }
}


void deplacement_perso(Player *player, char input, char map[]){
    // demander le déplacement
    //if (input == 'p') return input; // on arrête de joueur à la map en appuyant sur P


    // déplacement selon l'input et selon la position

    switch (input){
        case 'z':
            if ((player->posy >0) && (map[(player->posx)+((player->posy)-1)*width]!='#')) 
            {
                //MAJ de l'ancienne position
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                
                // MAj de la nouvelle position
                player->posy --;
            }
        break;

        case 'q':
            if ((player->posx >0) && (map[(player->posy)*width+(player->posx)-1]!='#')) 
            {
                
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                player->posx --;
            }
        break;

        case 's':
            if ((player->posy <height-1) && (map[(player->posx)+((player->posy)+1)*width]!='#')) 
            {
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                player->posy ++;
            }
        break;

        case 'd':
            if ((player->posx <width-1) && (map[(player->posy)*width+(player->posx)+1]!='#'))
            {
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                player->posx ++;
            }
        break;
    }
    //return ' '; // renvoie espace si le joueur joue
}


