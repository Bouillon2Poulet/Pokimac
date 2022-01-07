#include <iostream>
using namespace std;

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
    