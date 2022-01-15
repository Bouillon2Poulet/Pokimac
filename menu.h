#include <iostream>
#include "main.h"

using namespace std;
//Initialisation
void initPlayer (Player *player, int posx, int posy);
void initInventaire(Inventaire inv);
void initEkip(Player *player);

//Affichage
void afficheMenu(const Player player);
void afficheInventaire(Inventaire inv);
void afficheEkip(Player player);
void affichePlayer(Player player);

int compteEkip(Player player);