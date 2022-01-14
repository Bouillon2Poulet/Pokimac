#include <iostream>
#include "map.h"
using namespace std;

char map [width*height];  
    // remplissage de la map
void remplissageMap(char map[])
{   
    for (int i=0; i<width*height;i++)
    {
        cout << i << endl;
        if (i == 25) 
        {
            map[i] = '2';
        }
        else
        { 
            map[i] = '8';
        }
    }
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

void afficheMap (char map[width*height]){
    for (int k=0; k<height; k++){
        for (int i = 0; i < width; i++){
            cout << map[i+height*k];
        }
        cout << endl;
    }
}
