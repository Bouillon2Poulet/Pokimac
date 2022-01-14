#include <iostream>
#include "header.h"
using namespace std;

Pokemon salameche;
Pokemon bulbizarre;
Pokemon carapuce;
Pokemon listePkm [40];

int main()
{
    string suivant;
    Player player; // Initialise les coordonnées du joueur et son inventaire
    player.posx = 5;
    player.posy = 5;
    init_inv(player.inv);

    init_pokemons(listePkm); //Initialise les pokémons

    /////////////////////////LE DEBUT DU JEU ////////////////////////////////

    intro(&player, &suivant);
    choix_starter(&player, &suivant, listePkm);
    intro2(&player, &suivant);


    //////////////// LA MAP + DEPLACEMENT PERSO //////////////////////////

    //déf de la map
    char map [width*height];

    // remplissage de la map
    for (int i=0; i<width*height;i++){
        cout << i << endl;
        if (i == 25) {
            map[i] = '2';
        }
        else{ map[i] = '8';}

    }

    // affichage de la map
    affiche_map (map);


    // test du déplacement
    while(true){
        char input;
        cin >> input;
        clear();
        if (input=='1') { // on entre dans l'inventaire;
            affiche_inventaire(player.inv);
            cout << "Appuyez sur ECHAP pour revenir sur la map" << endl;
            cin >> suivant;
            clear();
        }


        deplacement_perso(&player, input);
        updateMap(map, player);
        affiche_menu(player);
    }
    return 0;
}



    /////////////////////////Définitions fonctions////////////////////////////////

void intro (Player *player, string *suivant)
{
    cout << "Bienvenue dans le monde des Pokemons..." << endl << endl;
    cout << "...Appuyez sur entrer pour commencer l'aventure"<< endl;
    *suivant = getchar();
    clear();

    cout << "Comment t'appelles-tu ?" << endl;
    cin >> player->pseudo; // Pseudo
    clear();

    getchar(); // Vider le tampon du premier getchar()

    cout << "OK " << player->pseudo << " tu te crois capable de pouvoir être le meilleur dresseur" << endl;
    cout << " d'animaux de combats que l'on nomme POKEMON ?" << endl;
    cout << "si oui appuie sur entrer avec vigueur !!!!"<< endl;
    *suivant = getchar();
    clear();
}

void intro2(Player *player, string *suivant)
{
    cout << "INTRO 2";
}

void init_pokemons(Pokemon listePkm[])
{
    salameche.nom = "Salameche";
    salameche.type = "Feu";
    salameche.pv = 39;
    salameche.dmg = 60;
    salameche.def = 60;
    listePkm[0] = salameche;

<<<<<<< Updated upstream
    bulbizarre.nom = "Bulbizarre"; // A Changer
    bulbizarre.type = "Plante";
    bulbizarre.pv = 45;
    bulbizarre.dmg = 49;
    bulbizarre.def = 49;
    listePkm[1] = bulbizarre;

    carapuce.nom = "Carapuce"; // A Changer
    carapuce.type = "Eau";
    carapuce.pv = 44;
    carapuce.dmg = 48;
    carapuce.def = 65;
    listePkm[2] = carapuce;


=======
    /*bulbizarre.nom = "Bulbizarre";
    bulbizarre.type = "Plante";
    bulbizarre.pv = 39;
    bulbizarre.dmg = 60;
    bulbizarre.def = 60;
    listePkm[0] = bulbizarre;*/
>>>>>>> Stashed changes
}

void copyPokemon(Pokemon source, Pokemon *destination) //Copie un pokémon source vers un pokémon cible pour résoudre le problème des strings qui se copient mal
{
    destination->nom=source.nom;
    destination->type=source.type;
    destination->pv=source.pv;
    destination->dmg=source.dmg;
    destination->def=source.def;
}


void choix_starter (Player *player, string *suivant, Pokemon listePkm[])
{
    clear();
    cout << "Choix du Pokemon :" << endl;
    cout << "\033[31m 1 - Salamèche\033[0m\n";
    cout << "\033[32m 2 - Bulbizarre\033[0m\n";
    cout << "\033[34m 3 - Carapuce\033[0m\n";
    int choix;
    cin >> choix;
    switch (choix)
    {
        case 1: copyPokemon(listePkm[0],&player->ekip[0]);
        cout << "pkm = " << player->ekip[0].nom << endl;
        break;

        case 2: copyPokemon(listePkm[1],&player->ekip[0]);
        cout << "pkm = " << player->ekip[0].nom << endl;
        break;

        case 3: copyPokemon(listePkm[2],&player->ekip[0]);
        cout << "pkm = " << player->ekip[0].nom << endl;
        break;

        default: cout << "Veuillez entrer un chiffre entre 1 et 3" << endl;
        *suivant = getchar();
        choix_starter(player,suivant,listePkm);
    }
}



void affiche_map (char map[width*height]){
    for (int k=0; k<height; k++){
        for (int i = 0; i < width; i++){
            cout << map[i+height*k];
        }
        cout << endl;
    }
}

void deplacement_perso(Player *player, char input){
    // demander le déplacement
    //if (input == 'p') return input; // on arrête de joueur à la map en appuyant sur P


    // déplacement selon l'input et selon la position
    switch (input){
        case 'z':
            if (player->posy >0) player->posy --;
        break;

        case 'q':
            if (player->posx >0) player->posx --;
        break;

        case 's':
            if (player->posy <height-1) player->posy ++;
        break;

        case 'd':
            if (player->posx <width-1) player->posx ++;
        break;
    }
    //return ' '; // renvoie espace si le joueur joue
}

void updateMap(char map[], Player player)
{
    int nb_aff_ligne = 0;
    for (int j=0; j<height; j++)
        {
            for (int h=0; h<width; h++)
            {
                if (h==player.posx && j==player.posy)
                {
                    cout << 1;
                    nb_aff_ligne ++;
                    h++;
                }
                nb_aff_ligne ++;
                if (nb_aff_ligne<=width){
                    cout << map[h+width*j];
                }
            }
        cout << endl;
        nb_aff_ligne =0;
        }
}


void affiche_menu(const Player player){
    cout << endl << "----------" << endl << endl;
    cout << "1 : Inventaire" << endl;
    cout << "2 : Pokémons" << endl;
    cout << "3 : "<< player.pseudo << endl;
}

void init_inv(Inventaire inv){
    inv.nb_pokeball = 0;
    inv.nb_popo2 = 0;
    inv.nb_potions = 0;
    inv.nb_trucopif = 0;
}

void affiche_inventaire(Inventaire inv){
    cout << "- INVENTAIRE -" << endl<<endl;
    cout << "mmmmmh yeah !! " << endl;
    cout << "ton nombre de pokeballs est : " << inv.nb_pokeball << endl;
    cout << "ton nombre de popo2 est : " << inv.nb_popo2 << endl;
    cout << "ton nombre de trucopif est : " << inv.nb_trucopif << endl << endl << endl;
}

//void affiche_pokemon ()
