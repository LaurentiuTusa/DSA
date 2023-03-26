#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define INFTY 999

int ADJmatrix[20][20];
int COSTmatrix[20][20];



void Length(int n, FILE *fo);
void The_Path(int n, FILE *fo, int PathOrder[8], int COSTmatrix[][20]);
void source_to_destination_path(int source, int destination, int k, int PathOrder[8]);
void Dijkstra(int NrOfNodes, int Source, int COSTmatrix[][20], FILE *fo);

#endif // HEADER_H_INCLUDED
