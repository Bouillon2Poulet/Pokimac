#include <iostream>
#include "main.h"

using namespace std;

void initPlayer (Player *player, int posx, int posy);
void affiche_menu(const Player player);
void init_inv(Inventaire inv);
void initEkip(Player *player);
void affiche_inventaire(Inventaire inv);
void affichePokemon (Player player);