#include <iostream>
using namespace std;

//Vérification de l'OS pour le clear
#ifdef WIN32
    #define clear() system("cls")
#else
    #ifdef UNIX
        #define clear() system("clear")
    #else
 
        #ifndef NBLIGCLS
            #define NBLIGCLS 30
        #endif
 
        void clear()
        {
            int i;
            for(i = 0; i < NBLIGCLS; i++)
            {
                printf("\n");
            }
        }
    #endif
#endif
///////

// dimmensions de la map
const int width = 10;
const int height = 10;

struct Player{
    int posx;
    int posy;
};


// le prototypage
void affiche_map (char map[width*height]);
void deplacement_perso(Player *player);
void initPlayer (Player *player, int posx, int posy);
void updateMap(char map[], Player player);

    