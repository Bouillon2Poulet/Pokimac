#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "menu.h"
#include "combat.h"
using namespace std;


void updateMap(Map* listeMap[], int* mapx, int* mapy, int mapwidth, Player player, Pokemon pokemonSauvage)
{
    Map* map = listeMap[(*mapx)+mapwidth*(*mapy)];
    int nb_aff_ligne = 0;
    bool aff_car = true;

    for (int j=0; j<map->height; j++)
        {
            for (int h=0; h<map->width; h++)
            {

                if (h==player.posx && j==player.posy) // Affichage joueur
                {
                    cout << white << 1;
                    nb_aff_ligne ++;
                    h++;
                }

                if ((h==player.posxAv && j==player.posyAv)) // Affichage Pokémon qui suit 
                {
                    cout << player.ekip[0].type.cara;
                    nb_aff_ligne ++;
                    aff_car = false;
                }

                if (h==pokemonSauvage.posx && j==pokemonSauvage.posy) // Affichage Pokémon sauvage
                {
                    cout << pokemonSauvage.type.cara;
                    nb_aff_ligne ++;
                    h++;
                }
                
                if (nb_aff_ligne<=map->width-1 && aff_car){
                    if (h+map->width*j < map->Lmap.size()) afficheCouleur(map->Lmap.at(h+map->width*j));
                    nb_aff_ligne ++;
                }
                aff_car = true;
            }
        cout << endl;
        nb_aff_ligne =0;
        }
        cout << white << endl; // reset de la couleur
}


void deplacement_perso(Player *player, char input, int* mapx, int* mapy,int mapwidth, Map* listeMap[]){
    Map* map = listeMap[(*mapx)+mapwidth*(*mapy)];
    if (input=='z')
    {
        if (player->posy == 1){
            *mapy= *mapy-1;
            player->posy = map->height-1;
            player->posyAv = map->height-1;
        }
        
        
        if ((player->posy >0) && peutBouger(map->Lmap.at((player->posx)+((player->posy)-1)*map->width))) 
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

        // est on au bout du tableau
        if (player->posx == 1){
            *mapx= *mapx-1;
            player->posx = map->width-1;
            player->posxAv = map->width-1;
        }
        
        if ((player->posx >0) && peutBouger(map->Lmap.at((player->posy)*map->width+(player->posx)-1))) 
        {
            //MAJ de l'ancienne position
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx --;
        }
    }

    if (input=='s')
    {
        if (player->posy == map->height-1){
            *mapy= *mapy+1;
            player->posy = 1;
            player->posyAv = 1;
        }
        
        if ((player->posy <map->height-1) && peutBouger(map->Lmap.at((player->posx)+((player->posy)+1)*map->width))) 
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posy ++;
        }
    }
    if (input=='d')
    {
        // est on au bout du tableau
        if (player->posx == map->width-1){
            *mapx= *mapx+1;
            player->posx = 1;
            player->posxAv = 1;
        }
        
        // déplacement si la place est libre
        if ((player->posx <map->width-1) && peutBouger(map->Lmap.at((player->posy)*map->width+(player->posx)+1)))
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx ++;
        }
    } 
    
}

void onMap (Player player, Pokemon pokemonSauvage1, int* mapx, int* mapy,int mapwidth, Map* listeMap[])
{    
    updateMap(listeMap, mapx, mapy, mapwidth, player, pokemonSauvage1);
    afficheMenu(player);
    char input;
    input = getChar();

    if (input=='z'||input=='q'||input=='s'||input=='d')
    {
        wclear();
        deplacement_perso(&player, input, mapx, mapy,mapwidth, listeMap);
        cout << "mapx apres le deplacement " << *mapx <<endl;
        checkIfTooClose(&player,pokemonSauvage1);
        if (player.tooClose==1)
        {
            combat(&player,&pokemonSauvage1);
            onMap(player,pokemonSauvage1,mapx, mapy,mapwidth, listeMap);
        }
        else
        {
           onMap(player,pokemonSauvage1,mapx, mapy,mapwidth, listeMap);
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
            onMap(player,pokemonSauvage1, mapx, mapy,mapwidth, listeMap);
        }
        break;

        case '2':
        wclear();
        afficheEkip(player);
        cout << "Appuyez sur X pour revenir sur la map" << endl;
        if  (getChar()=='x')
        {
            wclear();
            onMap(player,pokemonSauvage1, mapx, mapy,mapwidth, listeMap);
        }
        break;
        
        case '3':
        wclear();
        affichePlayer(player);
        cout << "\n\n\nAppuyez sur X pour revenir sur la map" << endl;
        if  (getChar()=='x')
        {
            wclear();
            onMap(player,pokemonSauvage1,mapx, mapy,mapwidth,listeMap);
        }
        break;
    }
}


void afficheCouleur(char c){
    switch (c){

        // bleu
        case '(':
        case ')':
            cout << blue << c<< white;
        break;
        
        // marron
        case '/':
            cout << brown << c<< white;
        break;

        // gris
        case '|':
        case '~':
            cout << grey << c<< white;
        break;

        // aléatoire
        case '@':
        case '+':
            
            // couleur random de @ et + car sont des fleurs
            int i;
            srand (time(NULL)); // initialisation de la graine
            i = rand() %4;
            if (i==0) cout << yellow << c << white;
            if (i==1) cout << blue << c<< white;
            if (i==2) cout << purple << c<< white;
            if (i==3) cout << cyan << c<< white;
        break;

        //vert
        case 'T':
        case 'Y':
            cout << green << c<< white;
        break;

        // blanc
        default:
            cout << white << c<< white;
    }
}

void checkIfTooClose(Player *player,Pokemon pokemonSauvage1){
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

bool peutBouger(char charMap){
    
    
    switch (charMap){
        // liste des caractères sur lesquels on peut bouger
        case ' ':
        case '+':
        case '@':
        case '/':
        case '<':
            return true;
        break;

        default : 
            return false;
        break;

    }
}

