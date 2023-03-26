#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
enum {UNVISITED, VISITED};

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

QueueT *createEmptyQueue()
{
    QueueT *QueuePtr = (QueueT*)malloc(sizeof(QueueT));
    if (QueuePtr)
    {
        QueuePtr->count = 0;
        QueuePtr->first = QueuePtr->last = NULL;
    }
    return QueuePtr;
}

StackT *createEmptyStack()
{
    StackT *StackPtr = (StackT*)malloc(sizeof(StackT));
    if (StackPtr)
    {
        StackPtr->count = 0;
        StackPtr->first = NULL;
    }
    return StackPtr;
}

void push(StackT *StackPtr, int key)
{

    if (StackPtr)
    {
        NodeT *p = (NodeT *)malloc(sizeof(NodeT));
        if(p)
        {
        p->key = key;
        p->next = NULL;
        }

        if (StackPtr->count == 0)
        {
            StackPtr->first = p;
            p->next = NULL;
        }
        else
        {
            p->next = StackPtr->first;
            StackPtr->first = p;
        }
        StackPtr->count++;
    }
}

void enQueue(QueueT *Queueptr, int key)
{

    if(Queueptr)
    {
        NodeT *p = (NodeT *)malloc(sizeof(NodeT));
        if(p)
        {
            p->key = key;
            p->next = NULL;
        }

        if (p == NULL)
        {
            printf("No more memory / Node not allocated");
            return;
        }


        if (Queueptr->first == NULL)
        {
            Queueptr->first = p;
        }
         else
         {
            Queueptr->last->next = p;
         }

    Queueptr->last = p;
    Queueptr->count++;
    }
}

void pop(StackT *StackPtr)
{
    NodeT *p;
    if (StackPtr->first != NULL)
    {
        if (StackPtr->count == 1)
        {
            p = StackPtr->first;
            StackPtr->first = NULL;
            free(p);
        }
        else
        {
            p = StackPtr->first;
            StackPtr->first = StackPtr->first->next;
            free(p);
        }
        StackPtr->count--;
    }
}

void deQueue(QueueT *Queueptr)
{

        if (Queueptr->first == NULL)
            return;

        NodeT *p;
        p = Queueptr->first;
        Queueptr->first = Queueptr->first->next;
        Queueptr->count--;

        if (Queueptr->first == NULL)
            Queueptr->last = NULL;
        free(p);
}

void bfs(int NrOfNodes, int SrcNode, int ADJmatrix[][50], FILE *fo)
{
    int mark[10];

    QueueT *QueuePtr = createEmptyQueue();

    for (int i=0; i< 10; i++)//atentie mark trebuie sa ajunga pana la labelul cel mai mare din graf
    {
        mark[i] = UNVISITED;
    }
    mark[SrcNode] = VISITED;
    enQueue(QueuePtr, SrcNode);

    fprintf(fo, "BFS starting at %d:", SrcNode);
    while (QueuePtr->count != 0)
    {
        int v = QueuePtr->first->key;
        deQueue(QueuePtr);
        fprintf(fo, " %d", v);
        for (int i=1; i<8; i++)
        {
            if ( ADJmatrix[v][i] == 1 )
            {
                if (mark[i] == UNVISITED)
                {
                    mark[i] = VISITED;
                    enQueue(QueuePtr, i);
                }
            }
        }
    }

}

void dfs(int NrOfNodes, int SrcNode, int ADJmatrix[][50], FILE *fo)
{
    int mark[10];
    StackT *StackPtr = createEmptyStack();
    for (int i = 0; i<10; i++)
    {
        mark[i] = UNVISITED;
    }
    mark[SrcNode] = VISITED;
    push(StackPtr, SrcNode);
    fprintf(fo, "DFS starting at %d: %d", SrcNode, SrcNode);
    while (StackPtr->count != 0)
    {
        int v = StackPtr->first->key;
        int w = -2;
        for (int j = 1; j<8; j++ )
        {
            if (ADJmatrix[v][j] == 1 && mark[j] == UNVISITED)
            {
                w = j;
                break;
            }
        }
        if (w != -2)
        {
            mark[w] = VISITED;
            push(StackPtr, w);
            fprintf(fo, " %d", w);
        }
        else pop(StackPtr);

    }
}
