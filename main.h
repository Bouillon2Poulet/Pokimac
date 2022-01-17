#pragma once // magique ça permet de ne pas faire de redef
// remplace ifndef

#include <iostream>
#include <vector>
using namespace std;

//Vérification de l'OS pour le clear
#ifdef WIN32
    #define wclear() system("cls")
    #include <conio.h>

#else
	#include <termios.h>
    #include <unistd.h>
	#include <sys/ioctl.h>
	#include <sys/socket.h>
    #define wclear() system("clear")

        #ifndef NBLIGCLS
            #define NBLIGCLS 30
        #endif
#endif




///////////////////// test du nouveau getch
static char getch(void) {
#if defined(_WIN32) || defined(_WIN64)
		return _getch();
#else
		struct termios oldt, newt;
		int ch;
		tcgetattr(STDIN_FILENO, &oldt); /* grab old terminal i/o settings */
		newt = oldt; /* make new settings same as old settings */
		newt.c_lflag &= ~(ICANON | ECHO); /* disable buffered i/o and set no echo mode */
		tcsetattr(STDIN_FILENO, TCSANOW, &newt); /* use these new terminal i/o settings now */
		ch = getchar();
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		return (char) ch;
#endif
	}


// dimensions de la map
extern int width; 
extern int height;

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
//extern char map[];

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

struct Map{
    int width;
    int height;
    vector<char> Lmap;
    string mapUp;
    string mapLeft;
    string mapRight;
    string mapDown;
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
//extern char map[];
//Liste des pokémons
extern Pokemon salameche;  // Salamèche
extern Pokemon bulbizarre;   //Bulbizarre
extern Pokemon carapuce;   //Bulbizarre


extern Pokemon listPokemon[]; //Liste des Pokemons




// le prototypage
void copyPokemon(Pokemon source, Pokemon *destination);
void init_pokemons(Pokemon listePkm[]);
bool checkInput(char reponse);
Map* remplissageMap(string adresseMap);





