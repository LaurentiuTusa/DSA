#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFTY 999
int dist[8];
int parent[8];

int S[8];
enum {UNVISITED, VISITED};


void Dijkstra(int NrOfNodes, int Source, int COSTmatrix[][20], FILE *fo)
{
    int order[8];
    int y = 1;
    int k;
    for (int i = 1; i<=7; i++)
    {
        S[i] = 0;
        dist[i] = COSTmatrix[Source][i];
        if (dist[i] < INFTY)
            parent[i] = Source;
        else
            parent[i] = 0;
    }

    S[Source] = 1;
    order[1] = Source;
    parent[Source] = 0;
    dist[Source] = 0;

    for(int step = 1; step <= 7; step++)
    {
        int minimum = 1000;
        for (int g = 1; g<=7; g++)
        {
            if (S[g] == 0)
            {
                if (dist[g] < minimum)
                {
                    minimum = dist[g];
                    k = g;
                }

            }
        }
        if (minimum == INFTY)
            return;
        S[k] = 1;
        y++;
        order[y] = k;
        for (int j =1; j<= 7; j++)
        {
            if(S[j] == 0 && dist[k] + COSTmatrix[k][j] <dist[j])
            {
                dist[j] = dist[k] + COSTmatrix[k][j];
                parent[j] = k;
            }
        }
    }
    int minimumTotal = 0;
    printf("\nInformatii despre parinti si distanta minima de la nodul sursa la fiecare nod:");
    for (int i = 1; i<=7; i++)
    {
        printf("\n parintele lui %d este %d; dist = %d", i, parent[i], dist[i]);
        minimumTotal += dist[i];
    }

    printf("\nSuma arcelor din MST: %d", minimumTotal);
    printf("\nOrdinea nodurilor in aplicarea algoritmului Dijkstra: %d", Source);

    for (int i =2; i<=7; i++)
    {
        printf("-%d", order[i]);
    }
    //                                            1-5-7-3-4-6-2
    printf("\n");
}

void source_to_destination_path(int source, int destination, int k, int PathOrder[8])
{
    if (parent[destination] == source)
    {
        printf("%d-%d", source, destination);
        PathOrder[1] = source;
        PathOrder[2] = destination;
        return;
    }

    else
    {
        source_to_destination_path(source, parent[destination], k+1, PathOrder);
        printf("-%d", destination);
        PathOrder[k] = destination;
    }
}

void The_Path(int n, FILE *fo, int PathOrder[8], int COSTmatrix[][20])
{
    int v = 2;
    fprintf(fo, " %d ", dist[n]);
    fprintf(fo, "%d", PathOrder[1]);
    while (PathOrder[v] != 0)
    {
        fprintf(fo, "-%d", PathOrder[v]);
        v++;
    }       // v ramane cu 1 peste cele folosite
    fprintf(fo, " (");
    fprintf(fo, "%d", COSTmatrix[1][PathOrder[2]]);
    for (int i = 2; i<v-1; i++)
    {
        fprintf(fo, ",%d", COSTmatrix[PathOrder[i]][PathOrder[i+1]]);

    }
    fprintf(fo, ")");
}
