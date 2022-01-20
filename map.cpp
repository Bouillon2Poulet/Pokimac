#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "menu.h"
#include "combat.h"
using namespace std;


void updateMap(Map* listeMap[], int* mapx, int* mapy, int mapwidth, Player player, Pokemon listePokemonSauvage[], int nbPokemonSauvage)
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

                for (int i=0; i<nbPokemonSauvage; i++)
                {
                    Pokemon* pokemonSauvage = &listePokemonSauvage[i];
                    if (h==pokemonSauvage->posx && j==pokemonSauvage->posy && pokemonSauvage->mapNom == map->adresse) // Affichage Pokémon sauvage
                    {
                        cout << pokemonSauvage->type.cara;
                        nb_aff_ligne ++;
                        h++;
                    }
                }
                
                if (nb_aff_ligne<=map->width-1 && aff_car){
                    srand (time(NULL));
                    if (h+map->width*j < map->Lmap.size()) afficheCouleur(map->Lmap.at(h+map->width*j),map->bgMap);
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
    
    // passage dans le volcan
        if (map->Lmap.at(player->posx +(player->posy)*(map->width)+1) == '#')
        {
            *mapx = 0;
            *mapy = 2;
            player->posy = listeMap[4]->height-1;
            player->posx = listeMap[4]->width/2;
            player->posyAv = player->posy; 
            player->posxAv = player->posyAv;
            return ;

        }

    // passage dans la salle du boss
    if (map->Lmap.at(player->posx +(player->posy)*(map->width)+1) == '!')
        {
            *mapx = 1;
            *mapy = 2;
            player->posy = listeMap[5]->height-1;
            player->posx = listeMap[5]->width/2;
            player->posyAv = player->posy; 
            player->posxAv = player->posyAv;
            return ;

        }

    
    
    if (input=='z')
    {
        
        // changement de tableau
        if (player->posy == 1 && *mapy >=1){
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
        if (player->posx == 1 && *mapx>=1){
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
        if (player->posy == map->height-1 && *mapy < mapwidth-1){
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
        if (player->posx == map->width-1 && *mapx < mapwidth-1){
            *mapx= *mapx+1;
            player->posx = 1;
            player->posxAv = 1;
        }
        
        // déplacement si la place est libre
        if ((player->posx < map->width-1) && peutBouger(map->Lmap.at((player->posy)*map->width+(player->posx)+1)))
        {
            player->posxAv = player->posx;
            player->posyAv = player->posy;
            player->posx ++;
        }
    } 
    
}

void onMap (Player player, Pokemon listePokemonSauvage[], int nbPokemonSauvage, int* mapx, int* mapy,int mapwidth, Map* listeMap[])
{    
    Map* map = listeMap[(*mapx)+mapwidth*(*mapy)];
    updateMap(listeMap, mapx, mapy, mapwidth, player, listePokemonSauvage, nbPokemonSauvage);
    afficheMenu(&player);
    char input;
    input = getChar();

    if (input=='z'||input=='q'||input=='s'||input=='d')
    {
        wclear();
        deplacement_perso(&player, input, mapx, mapy,mapwidth, listeMap);
        
        Pokemon* pokemonSauvage = &listePokemonSauvage[0];
        for(int i=0; i<nbPokemonSauvage && player.tooClose!=1; i++)
        {
            pokemonSauvage = &listePokemonSauvage[i];
            checkIfTooClose(&player,*pokemonSauvage, map);
        }
        if (player.tooClose==1)
        {
            srand (time(NULL)); // initialisation de la graine
            int canAttack = rand() % 1;  // pile ou face pour commencer
            combat(&player,pokemonSauvage,canAttack);
            wclear();
            onMap(player,listePokemonSauvage,nbPokemonSauvage,mapx, mapy,mapwidth, listeMap);
            player.tooClose==-1;
        }
        else
        {
           onMap(player,listePokemonSauvage,nbPokemonSauvage,mapx, mapy,mapwidth, listeMap);
        }
    }
    switch (input)
    {
        case '1':
        wclear();
        afficheInventaire(player.inv);
        
        cout << "Appuies sur le numéro pour utiliser" << endl;
        cout << "Appuyez sur X pour revenir sur la map" << endl;
        switch (getChar())
        {
            case 'x':
                wclear();
            onMap(player,listePokemonSauvage,nbPokemonSauvage, mapx, mapy,mapwidth, listeMap);
                break;
            
            case '1':
            if (player.inv.nbPotion>0)
            {
                wclear();
                cout << "Quel pokemon voulez-vous soigner ?"<<endl;
                afficheEkip(&player);
                int i;
                switch (getChar())
                {
                    case '1' : i=0; break;
                    case '2' : i=1;break;
                    case '3' : i=2; break;
                    case '4' : i=3;break;
                    case '5' : i=4; break;
                    case '6' : i=5;break;
                }
                player.inv.nbPotion--;
                player.ekip[i].pv+=10;
                wclear();
                cout << endl;
                afficheEkip(&player);
                cout << player.pseudo << " utilise une potion sur "<<player.ekip[i].name << "\nil regagne 10PV"<<endl;
                cout << "\n\n\n\n\n\n\n";
                cout <<" ---Appuies sur une touche pour continuer"<< endl;
                getChar();
                wclear();
                onMap(player,listePokemonSauvage,nbPokemonSauvage, mapx, mapy,mapwidth, listeMap);
            }
            
            else
            {
                cout << "vous n'avez pas de potion" << endl;
                cout << "\n\n\n\n\n\n\n";
                cout <<" ---Appuies sur une touche pour continuer"<< endl;
                getChar();
                wclear();
                onMap(player,listePokemonSauvage,nbPokemonSauvage, mapx, mapy,mapwidth, listeMap);
            }
                
        }
        break;

        case '2':
        wclear();
        afficheEkip(&player);
        cout << "Appuyez sur X pour revenir sur la map" << endl;
        if  (getChar()=='x')
        {
            wclear();
            onMap(player,listePokemonSauvage,nbPokemonSauvage, mapx, mapy,mapwidth, listeMap);
        }
        break;
        
        case '3':
        wclear();
        affichePlayer(&player);
        cout << "\n\n\nAppuyez sur X pour revenir sur la map" << endl;
        if  (getChar()=='x')
        {
            wclear();
            onMap(player,listePokemonSauvage,nbPokemonSauvage,mapx, mapy,mapwidth,listeMap);
        }
        break;
    }
}


void afficheCouleur(char c, string bgMap){
    
    // on met la couleur du bg de la map
    //cout << bgMap;
    switch (c){

        // bleu
        case '(':
        case ')':
            cout << blue << c<< white;
        break;
        
        // marron
        case '/':
            cout << yellow << c<< white; // marron c jaune pour le moment
        break;

        // rouge
        case '.':
            cout << red << c; // marron c jaune pour le moment
        break;

        // gris
        case '|':
        case '~':
        case '*':
            cout << grey << c;
        break;

        // aléatoire
        case '@':
        case '+':
            
            // couleur random de @ et + car sont des fleurs
            int i;
            // initialisation de la graine --> marche mal pour le moment
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
    // on réinitialise la couleur du bg
    cout << reset;
}

void checkIfTooClose(Player *player,Pokemon pokemonSauvage1, Map* map){
    if (map->adresse != pokemonSauvage1.mapNom)
    {
        player->tooClose = 0;
        return;
    }
    
    
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
        case 'v':
        case '>':
        case '^':
        case '#':
        case '.':
        case '!':
            return true;
        break;

        // les autres qui sont bloquants
        default : 
            return false;
        break;

    }
}

