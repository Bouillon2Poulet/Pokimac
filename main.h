#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
using namespace std;

//Vérification de l'OS pour le clear
#ifdef WIN32
        #define clear() system("cls")
#else
    #define clear() system("clear")

        #ifndef NBLIGCLS
            #define NBLIGCLS 30
        #endif

        /*id clear()
        {
            int i;
            for(i = 0; i < NBLIGCLS; i++)
            {
                printf("\n");
            }
        }*/
#endif

///////
struct Pokemon{
    string nom;
    string type;
    int pv;
    int dmg;
    int def;
};

extern Pokemon listePkm []; //Déclaration de la liste
extern char map[];



struct Inventaire{
    int nb_potions;
    int nb_pokeball;
    int nb_popo2;
    int nb_trucopif;
};



struct Player{
    int posx;
    int posy;
    string pseudo;
    Inventaire inv;
    Pokemon ekip[6];
};

//Liste des pokémons
extern Pokemon salameche;  // Salamèche
extern Pokemon bulbizarre;   //Bulbizarre
extern Pokemon carapuce;   //Bulbizarre




// le prototypage
void copyPokemon(Pokemon source, Pokemon *destination);
void init_pokemons(Pokemon listePkm[]);
void intro (Player *player,string *suivant);
void choix_starter(Player *player, string *suivant, Pokemon listePkm[]);
void intro2(Player *player, string *suivant);

void deplacement_perso(Player *player, char input);
void initPlayer (Player *player, int posx, int posy);

void affiche_menu(const Player player);
void init_inv(Inventaire inv);
void affiche_inventaire(Inventaire inv);

