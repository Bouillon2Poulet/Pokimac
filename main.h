#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
using namespace std;

//Vérification de l'OS pour le clear
#ifdef WIN32
    #define wclear() system("cls")
    #include <conio.h>
    //#define getch() getch()
#else
    #define wclear() system("clear")
    #define getch() getchar()

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


// dimensions de la map
const int width = 40; 
const int height = 30;

///////
struct Pokemon{
    string name;
    string type;
    int pv;
    int dmg;
    int def;
    string cara;
};

struct PkmSauvage{
    string name;
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
const string grey = "\033[90m";
const string mangenta = "\033[35m";
const string yellow = "\033[33m";
const string cyan = "\033[36m";



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
    bool tooClose;
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
void remplissageMap(char map[width*height]);
bool checkInput(char reponse);





