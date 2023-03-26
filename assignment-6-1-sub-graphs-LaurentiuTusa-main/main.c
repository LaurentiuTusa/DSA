#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ADJmatrix[50][50];


int main(int argc, char **argv)
{

    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");
    char cod[60];
    int c, r;
    int i = 0;
    int k = 0;
    int j;
    int Subgraph[4];//subgraph vertices
    fgets(cod, 50, fi);//first line of input
    fgets(cod, 50, fi);

    while (cod[i] != '\0')
    {
        if (cod[i] == '(')
        {
            sscanf(cod + i, "(%d%d)", &r, &c);
            //printf("%d %d", r, c);
            ADJmatrix[r][c] = 1;
        }
        i++;
    }

    fgets(cod, 50, fi);//subgraph vertices
    i = 0;

    while (cod[i] != '\0')
    {
        if (isdigit(cod[i]) == 1)
        {
            Subgraph[k] = atoi(cod + i);
            //printf("%d ", Subgraph[k]);
            k++;
        }
        i++;
    }

    fprintf(fo, "V' arcs");

    for (i=0; i<3; i++)
    {
        r = Subgraph[i];
        for (j=0; j<3; j++)
        {
            c = Subgraph[j];
            if ( ADJmatrix[r][c] == 1 )
            {
                fprintf(fo, " (%d %d)", r, c);
            }
        }
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
