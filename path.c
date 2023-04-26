/*
                VERSIOn 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"



#define MAX 5
// stockage du chemin pendant l'exploration recursive
int path[MAX]; //= new int[n];
int pathList[MAX][MAX];

// verrou pour la recherche taboo (tous initialisés à "false" par défaut)
int taboo[MAX] = {0,0,0,0,0}; // new boolean[n];

// sommets de départ/arrivé souhaités
int source = 0; //start
int target = 4; //end

int adj[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
};

void explore(int position, int depth, int pNum)
{
    path[depth] = position;
    pNum +=1;

    // on est sur le sommet d'arrivé -> fini
    if (position == target)
    {
        // affiche la solution
        for (int i = 0; i <= depth; i++)
            pathList[pNum][i] = path[i];
            //printf(" %d ",path[i]);
        printf("\n");
        return;
    }

    // sinon...

    taboo[position] = 1; // on pose un caillou

    // on explore les chemins restants
    for (int i = 0; i < MAX; i++)
    {
        if (adj[position][i] == 0 || taboo[i])
            continue;
        explore(i, depth + 1, pNum);
    }

    taboo[position] = 0; // on retire le caillou
}

int main(int argc, char *argv[])
{
    // test1();
    // test2 ();clear

//   test_parcours();
    for (int i=0; i< MAX; i++)
        for (int j=0; j< MAX; j++)  pathList[i][j] = -1;
        
    explore(0, 0, -1);
    printf ("Chemin : \n");
    for (int i=0; i< MAX; i++)
    {
        for (int j=0; j< MAX; j++)
        {
            if (pathList[i][j] !=-1)    printf ("%d", pathList[i][j]);
        
        }
        printf ("\n");
    }
        

    return 0;
}
