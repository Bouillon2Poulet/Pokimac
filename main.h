#pragma once // Remplace ifdef

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
static char getChar() {
#if defined(_WIN32) || defined(_WIN64)
		return getch();
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

//Structures
struct Type {
    string name;
    string superEfficaceContre;
    string peuEfficaceContre;
    string cara;
    string bashCouleur;
};

struct Attaque {
    string name;
    Type type;
    int puissance;
};

struct Pokemon{
    string name;
    Type type;
    int pv;
    int pvmax;
    int niveau;
    int constpv;
    int constatak;
    int xp;
    int xpmax;
    int posx;
    int posy;
    Attaque attaque[4];
    string mapNom;
};


struct Inventaire{
    int nbPotion;
    int nbPokeball;
    int nbAntidote;
    int nbTruc;
    int argent;
};

struct Map{
    int width;
    int height;
    vector<char> Lmap;
    string adresse;
    string bgMap;
};


struct orgaMap{
    int center;
    int left;
    int right;
    int up;
    int down;
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
    char cara;
};


extern Pokemon listePkm []; //Déclaration de la liste
//extern char map[];


//Couleurs texte
const string red = "\033[31m";
const string green = "\033[32m";
const string brown = "\033[1;33m";
const string blue = "\033[34m";
const string purple = "\033[35m";
const string white = "\033[0m";
const string grey = "\033[90m";
const string yellow = "\033[33m";
const string cyan = "\033[36m";

//couleurs background
const string bgBlack = "\033[40m";
const string bgRed = "\033[41m";
const string bgGreen = "\033[42m";
const string bgBrown = "\033[43m";
const string bgBlue = "\033[44m";
const string bgPurple = "\033[45m";

const string reset = "\e[0m";


//Prototypes de fonctions
Map* remplissageMap(string adresseMap);
void debug();
void delay(int secondes);