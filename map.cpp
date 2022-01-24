#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "menu.h"
#include "combat.h"
using namespace std;


void updateMap(Map* listeMap[], int* mapx, int* mapy, int mapwidth, Player *player, Pokemon listePokemonSauvage[], int nbPokemonSauvage)
{
    Map* map = listeMap[(*mapx)+mapwidth*(*mapy)];
    int nb_aff_ligne = 0;
    bool aff_car = true;

    for (int j=0; j<map->height; j++)
        {
            for (int h=0; h<map->width; h++)
            {

                if (h==player->posx && j==player->posy) // Affichage joueur
                {
                    cout << white << player->cara;
                    nb_aff_ligne ++;
                    h++;
                }
                if (map->Lmap.at(player->posx +map->width*player->posy) == 'C')
                {
                    centrePokemon(player,'x');
                }
                if ((h==player->posxAv && j==player->posyAv)) // Affichage Pokémon qui suit 
                {
                    cout << player->ekip[0].type.cara;
                    nb_aff_ligne ++;
                    aff_car = false;
                }

                for (int i=0; i<nbPokemonSauvage; i++)
                {
                    Pokemon* pokemonSauvage = &listePokemonSauvage[i];
                    if (h==pokemonSauvage->posx && j==pokemonSauvage->posy && pokemonSauvage->mapNom == map->adresse && pokemonSauvage->pv >0) // Affichage Pokémon sauvage
                    {
                        cout << pokemonSauvage->type.cara;
                        nb_aff_ligne ++;
                        h++;
                    }
                }
                
                if (nb_aff_ligne<=map->width-1 && aff_car){
                    srand (time(NULL));
                    if (h+map->width*j < map->Lmap.size()) afficheCouleur(map->Lmap.at(h+map->width*j),map->bgMap,h, j);
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

void onMap (Player *player, Pokemon listePokemonSauvage[], int nbPokemonSauvage, int* mapx, int* mapy,int mapwidth, Map* listeMap[])
{    
    Map* map = listeMap[(*mapx)+mapwidth*(*mapy)];
    
    
    updateMap(listeMap, mapx, mapy, mapwidth, player, listePokemonSauvage, nbPokemonSauvage);
    afficheMenu(player);
    char input;
    
    do // éviter fin du jeu si mauvaise input
    {
        input = getChar();
    }while (input !='z' && input !='q' && input !='s' && input !='d' && input !='1' && input !='2' && input !='3' && input !='4');

    if (input=='z'||input=='q'||input=='s'||input=='d')
    {
        wclear();
        // déplacement des pokémons sauvages
        Pokemon* pokemonSauvage1 = &listePokemonSauvage[0];
        for (int i=0; i<nbPokemonSauvage; i++){
            pokemonSauvage1 = &listePokemonSauvage[i];
            if (map->adresse == pokemonSauvage1->mapNom && pokemonSauvage1->pv >0) 
            {
                deplacementPokemonSauvage(map,pokemonSauvage1);
            }
        }
        // déplacement du perso
        deplacement_perso(player, input, mapx, mapy,mapwidth, listeMap);
        
        Pokemon* pokemonSauvage = &listePokemonSauvage[0];
        for(int i=0; i<nbPokemonSauvage && player->tooClose!=1; i++)
        {
            pokemonSauvage = &listePokemonSauvage[i];
            checkIfTooClose(player,*pokemonSauvage, map);
        }
        if (player->tooClose==1 && player->ekip[0].pv>0)
        {
            srand (time(NULL)); // initialisation de la graine
            int canAttack = rand() % 1;  // pile ou face pour commencer
            combat(player,pokemonSauvage,canAttack);
            wclear();
            player->tooClose=0;
            onMap(player,listePokemonSauvage,nbPokemonSauvage,mapx, mapy,mapwidth, listeMap);                       
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
        afficheInventaire(player->inv);
        
        cout << "Appuies sur le numero pour utiliser" << endl;
        cout << "Appuyez sur X pour revenir sur la map" << endl;
        switch (getChar())
        {
            case 'x':
                wclear();
            onMap(player,listePokemonSauvage,nbPokemonSauvage, mapx, mapy,mapwidth, listeMap);
                break;
            
            case '1':
            if (player->inv.nbPotion>0)
            {
                wclear();
                cout << "Quel pokemon voulez-vous soigner ?"<<endl;
                afficheEkip(player);
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
                player->inv.nbPotion--;
                player->ekip[i].pv+=10;
                wclear();
                cout << endl;
                afficheEkip(player);
                cout << player->pseudo << " utilise une potion sur "<<player->ekip[i].name << "\nil regagne 10PV"<<endl;
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
        afficheEkip(player);
        cout << "\n\n\nAppuyez sur une touche pour revenir sur la map" << endl;
        getChar();
        wclear();
        onMap(player,listePokemonSauvage,nbPokemonSauvage,mapx, mapy,mapwidth,listeMap);    
        break;
        
        case '3':
        wclear();
        affichePlayer(player);
        cout << "\n\n\nAppuyez sur une touche pour revenir sur la map" << endl;
        getChar();
        wclear();
        onMap(player,listePokemonSauvage,nbPokemonSauvage,mapx, mapy,mapwidth,listeMap);     
        break;
    }
}


void afficheCouleur(char c, string bgMap, int x, int y){
    
    // nb random pour la couleur des fleurs
    int i = x+y;
    
    // on met la couleur du bg de la map
    //cout << bgMap;
    switch (c){

        // bleu
        case '(':
        case ')':
            cout << blue << c<< white;
        break;
        
        // marron
        case '\\':
        case '/':
            cout << yellow << c<< white; // marron c jaune pour le moment
        break;

        // rouge
        case 'C':
        case '.':
            cout << red << c;
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
            

            if (i%4==0) cout << yellow << c << white;
            if (i%4==1) cout << blue << c<< white;
            if (i%4==2) cout << purple << c<< white;
            if (i%4==3) cout << cyan << c<< white;
        break;

        //vert
        case 'T':
        case 'Y':
        case 'w':
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
    if (pokemonSauvage1.pv <=0)
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
        case 'C':
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
        case 'w':
            return true;
        break;

        // les autres qui sont bloquants
        default : 
            return false;
        break;

    }
}

void deplacementPokemonSauvage (Map* map, Pokemon* pokemonSauvage){
    
    // déplacement aléatoire de -1 à 1 en x ou y 
    int dx =  1-rand() % 5; // 5 pour rendre le déplacement moins fréquent
    int dy = 1- rand() % 3;

    if (dx < -1) {
        dx = 0;
        dy = 0;
    }

    // si le déplacement est possible sur la map

   if (pokemonSauvage->posx+dx<map->width-1 && pokemonSauvage->posx+dx>1 && pokemonSauvage->posy+dy<map->height-1 && pokemonSauvage->posy+dy>1)
    {
        if (peutBouger(map->Lmap.at(pokemonSauvage->posx+dx + (pokemonSauvage->posy+dy)*map->width)))
        {
            pokemonSauvage->posx = pokemonSauvage->posx+dx;
            pokemonSauvage->posy = pokemonSauvage->posy+dy;
        }
    
    }
}

void centrePokemon(Player *player, char entree){
    if (entree=='x')
    {
        cout << "Bienvenue au PokeCentre !!!" << endl;
        cout << "Nous faisons PokeBoutique aussi !" << endl;
        cout << "Que puis-je faire pour vous ?" << endl;
        cout << "1 - Soigner mes Pokemons" << endl;
        cout << "2 - PokeBoutique" << endl;
        cout << "\n\n\n\n\n";
        cout << "Appuyez sur une touche pour retour" << endl;
        entree = getChar();
    }
    switch (entree)
    {
        case '1':
            wclear();
            afficheEkip(player);
            cout << "Je vais soigner vos Pokemons" << endl;
            for (int i=0;i<compteEkip(player);i++)
            {
                player->ekip[i].pv=player->ekip[i].pvmax;
            }
            getChar();
            wclear();
            afficheEkip(player);
            cout << "\n\n\n\n\n";
            cout << "Appuyez sur une touche pour retour" << endl;
            getChar();
            wclear();
            centrePokemon(player, 'x');
        break;
        
        case '2' :
            wclear();
            cout << "Que souhaitez-vous acheter ?" << endl;
            cout << "1 - Pokeball                100$" << endl;
            cout << "2 - Potion                  200$" << endl;
            cout << "3 - Antidote                300$" << endl;
            cout << "\n\n\n\n\n";
            cout << "Appuyez sur une touche pour choisir" << endl;
            cout << "Appuyez sur une autre touche pour retour" << endl;
            switch (getChar())
            {
                case '1' :
                    if (player->inv.argent>=100)
                    {
                        player->inv.nbPokeball++;
                        player->inv.argent-=100;
                        cout << "Vous venez d'acheter 1 Pokeball " << endl;
                        cout << "\n\n\n\n\n";
                        cout << "Appuyez sur une touche pour retour" << endl;
                        getChar();
                        wclear();
                        centrePokemon(player, 'x');
                    }
                    else
                    {
                        cout << endl << endl << "Vous n'avez pas assez d'argent monsieur !" << endl;
                        cout << "\n\n\n\n\n";
                        cout << "Appuyez sur une touche pour retour" << endl;
                        getChar();
                        wclear();
                        centrePokemon(player, '2');
                    }
                break;

                case '2' :
                    if (player->inv.argent>=200)
                    {
                        player->inv.nbPotion++;
                        player->inv.argent-=200;
                        cout << "Vous venez d'acheter 1 Potion " << endl;
                        cout << "\n\n\n\n\n";
                        cout << "Appuyez sur une touche pour retour" << endl;
                        getChar();
                        wclear();
                        centrePokemon(player, 'x');
                    }
                    else
                    {
                        cout << endl << endl << "Vous n'avez pas assez d'argent monsieur !" << endl;
                        cout << "\n\n\n\n\n";
                        cout << "Appuyez sur une touche pour retour" << endl;
                        getChar();
                        wclear();
                        centrePokemon(player, '2');
                    }
                break;

                case '3' :
                    if (player->inv.argent>=300)
                    {
                        player->inv.nbAntidote++;
                        player->inv.argent-=300;
                        cout << "Vous venez d'acheter 1 Antidote " << endl;
                        cout << "\n\n\n\n\n";
                        cout << "Appuyez sur une touche pour retour" << endl;
                        getChar();
                        centrePokemon(player, 'x');
                    }
                    else
                    {
                        cout << endl << endl << "Vous n'avez pas assez d'argent monsieur !" << endl;
                        cout << "\n\n\n\n\n";
                        cout << "Appuyez sur une touche pour retour" << endl;
                        getChar();
                        centrePokemon(player, '2');
                    }
                break;
                default : centrePokemon(player,'x');
            }   
        
        
        default :
            player->posx++;
            wclear();
            return;
    }


}