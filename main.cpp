#include <iostream>
#include "main.h"
#include "map.h"

using namespace std;



int main()
{
    init_pokemons(listePkm); //Initialise les pokémons
    
    remplissageMap(map);
    
    string suivant;
    Player player; // Initialise les coordonnées du joueur et son inventaire
    player.posx = 5;
    player.posy = 5;
    player.posxAv =5;
    player.posyAv = 5;
    init_inv(player.inv);

    

    /////////////////////////LE DEBUT DU JEU ////////////////////////////////

    intro(&player, &suivant);
    choix_starter(&player, &suivant, listePkm);
    intro2(&player, &suivant);
    


    //////////////// LA MAP + DEPLACEMENT PERSO //////////////////////////

    //déf de la map
    


    // affichage de la map
    afficheMap (map);


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
    cout << "INTRO 2\n";
}




void choix_starter (Player *player, string *suivant, Pokemon listePkm[])
{
    clear();
    cout << "Choix du Pokemon :" << endl;
    cout << red << "1 - Salamèche" << white << endl;
    cout << green << "2 - Bulbizarre" << white << endl;
    cout << blue << " 3 - Carapuce" << white << endl;
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




void deplacement_perso(Player *player, char input){
    // demander le déplacement
    //if (input == 'p') return input; // on arrête de joueur à la map en appuyant sur P


    // déplacement selon l'input et selon la position

    switch (input){
        case 'z':
            if (player->posy >0) 
            {
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                player->posy --;
            }
        break;

        case 'q':
            if (player->posx >0) 
            {
                
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                player->posx --;
            }
        break;

        case 's':
            if (player->posy <height-1) 
            {
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                player->posy ++;
            }
        break;

        case 'd':
            if (player->posx <width-1) 
            {
                player->posxAv = player->posx;
                player->posyAv = player->posy;
                player->posx ++;
            }
        break;
    }
    //return ' '; // renvoie espace si le joueur joue
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

