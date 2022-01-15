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
    string cara;
};

struct PkmSauvage{
    string nom;
    string type;
    int pv;
    int dmg;
    int def;
    string cara;
    int posx;
    int posy;
};



extern Pokemon listePkm []; //Déclaration de la liste
extern char map[];

const string red = "\033[31m";
const string green = "\033[32m";
const string blue = "\033[34m";
const string white = "\033[0m";



struct Inventaire{
    int nb_potions;
    int nb_pokeball;
    int nb_popo2;
    int nb_trucopif;
};

struct Player{
    int posx;
    int posy;
    int posxAv;
    int posyAv;
    string pseudo;
    Inventaire inv;
    Pokemon ekip[6];
};





extern Pokemon listePkm []; //Déclaration de la liste
extern char map[];
//Liste des pokémons
extern Pokemon salameche;  // Salamèche
extern Pokemon bulbizarre;   //Bulbizarre
extern Pokemon carapuce;   //Bulbizarre


extern Pokemon listPokemon[]; //Liste des Pokemons




// le prototypage
void copyPokemon(Pokemon source, Pokemon *destination);
void init_pokemons(Pokemon listePkm[]);




