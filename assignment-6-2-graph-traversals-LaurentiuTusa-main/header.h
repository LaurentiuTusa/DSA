#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct node
    {
        int key;
        struct node *next;
    }NodeT;

typedef struct
    {
        int count;
        NodeT *first;
        NodeT *last;
    }QueueT;

typedef struct
    {
        int count;
        NodeT *first;
    }StackT;

int ADJmatrix[50][50];

QueueT *createEmptyQueue();
void enQueue(QueueT *Queueptr, int key);
void *deQueue(QueueT *Queueptr);
void bfs(int NrOfNodes, int SrcNode, int ADJmatrix[][50], FILE *fo);
StackT *createEmptyStack();
void push(StackT *StackPtr, int key);
void pop(StackT *StackPtr);
void dfs(int NrOfNodes, int SrcNode, int ADJmatrix[][50], FILE *fo);

#endif // HEADER_H_INCLUDED
