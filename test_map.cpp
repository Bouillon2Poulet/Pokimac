#include "header.h"

int main(){
    
    Player player;
    player.posx = 5;
    player.posy = 5;

    //déf de la map
    char map [width*height];
    
    // remplissage de la map
    for (int i=0; i<width*height;i++){
        map[i] = '0';
    }
    
    // affichage de la map
    affiche_map (map);
    

    // test du déplacement
    while (true){
        deplacement_perso(&player);
        updateMap(map, player);
        //cout << "en x : " << player.posx << " // en y : " << player.posy << endl;
    }

    return 0;
}


///////////////// LES FONCTIONS !!!!
void affiche_map (char map[width*height]){
    for (int k=0; k<height; k++){
        for (int i = 0; i < width; i++){
            cout << map[i];
        }
        cout << endl; 
    }
}

void deplacement_perso(Player *player){
    // demander le déplacement
    char input;
    cin >> input;
    system("clear");

    
    // déplacement selon l'input et selon la position
    switch (input){
        case 'z':
            if (player->posx  >0) player->posy --;
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
}

void updateMap(char map[], Player player)
{
//player.posx
//player.posy
system("clear");

    for (int j=0; j<height; j++)
        {
            for (int h=0; h<width; h++)
            {
                if (h==player.posx && j==player.posy)
                {
                    cout << 1;
                    h++;
                }
            
            cout << map[h];
            }
        cout << endl;
        }
}


