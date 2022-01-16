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


void deplacement_perso(Player *player, char input, char map[]){
    switch (input)
    {
        case 'z':
        if ((player->posy >0) && (map[(player->posx)+((player->posy)-1)*width]==' ')) 
        {
            //MAJ de l'ancienne position
            player->posxAv = player->posx;
            player->posyAv = player->posy;                
            // MAj de la nouvelle position
            player->posy --;
        }
        break;

        case 'q':
        if ((player->posx >0) && (map[(player->posy)*width+(player->posx)-1]==' ')) 
        {
            //MAJ de l'ancienne position
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx --;
        }
        break;
    
        case 's':
        if ((player->posy <height-1) && (map[(player->posx)+((player->posy)+1)*width]==' ')) 
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posy ++;
        }
        break;

        case 'd':
        if ((player->posx <width-1) && (map[(player->posy)*width+(player->posx)+1]==' '))
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx ++;
        }
        break;
    }
    
}

void onMap ( Player player, PkmSauvage pokemonSauvage1, char map[]){
    updateMap(map, player, pokemonSauvage1);
    afficheMenu(player);
    char input='s';
    char reponse='x';
    input =getch();

    if (input=='z'||input=='q'||input=='s'||input=='d')
    {
        wclear();
        deplacement_perso(&player, input, map);
        onMap(player,pokemonSauvage1,map);
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