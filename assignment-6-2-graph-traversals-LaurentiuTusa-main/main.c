#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


int main(int argc, char **argv)
{

    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");
    char cod[50];
    int c, r;
    int i = 0;
    fgets(cod, 50, fi);//first line of input
    fgets(cod, 50, fi);

    while (cod[i] != '\0')
    {
        if (cod[i] == '(')
        {
            sscanf(cod + i, "(%d%d)", &r, &c);
            //printf("%d %d", r, c);
            ADJmatrix[r][c] = 1;
            //ADJmatrix[c][r] = 1;  pentru neorientat
        }
        i++;
    }

    for (int k=1; k<8; k++)
    {
        for (int p=1; p<8; p++)
        {
            printf("%d ", ADJmatrix[k][p]);
        }
        printf("\n");
    }

 /*   QueueT *QueuePtr = createEmptyQueue();
    enQueue(QueuePtr, 10);
    enQueue(QueuePtr, 20);
    deQueue(QueuePtr);
    deQueue(QueuePtr);
    enQueue(QueuePtr, 30);
    enQueue(QueuePtr, 40);
    enQueue(QueuePtr, 50);
    printf("\n%d", QueuePtr->last->key);
*/
    bfs(5, 1, ADJmatrix, fo);
    fprintf(fo, "\n");
    dfs(5, 1, ADJmatrix, fo);


    fclose(fo);
    fclose(fi);
    return 0;
}
