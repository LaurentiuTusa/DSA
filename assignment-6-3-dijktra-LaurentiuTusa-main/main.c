#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int PathOrder[8];

int main(int argc, char **argv)
{

    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");

    int c, r, cost;

    while (fscanf(fi, "%d,%d=%d", &r, &c, &cost) != EOF)
    {
        ADJmatrix[r][c] = 1;
        COSTmatrix[r][c] = cost;
    }

    printf("Informatii despre graf:\nMatrice de adiacenta:\n");

    for (int k=1; k<8; k++)
    {
        for (int p=1; p<8; p++)
        {
            printf("%d ", ADJmatrix[k][p]);
        }
        printf("\n");
    }

printf("\nMatrice de costuri(999 inseamna ca nu exista arc):\n");

    for (int k=1; k<8; k++)
    {
        for (int p=1; p<8; p++)
        {
            if (k == p)
                COSTmatrix[k][p] = 0;
            else
            {
                if (COSTmatrix[k][p] == 0)
                    COSTmatrix[k][p] = INFTY;
            }
            printf("%3d ", COSTmatrix[k][p]);
        }
        printf("\n");
    }

    Dijkstra(7, 1, COSTmatrix, fo);
    fprintf(fo, "Path from 1 to 7:");
    source_to_destination_path(1, 7, 3, PathOrder);
    The_Path(7, fo, PathOrder, COSTmatrix);

    /*
    for (int w=1; w<8; w++)
    {
        printf("\n%d", PathOrder[w]);
    }*/

    for (int g=0; g<8; g++)
        PathOrder[g] = 0;

    fclose(fi);
    fclose(fo);
    return 0;
}
