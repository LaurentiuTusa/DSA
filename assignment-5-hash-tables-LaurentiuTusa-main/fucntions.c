#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int B;
    typedef struct cell
    {
        char key[60];
        struct cell *next;
    } NodeT;

int HashFct(char code[31])
{
     int k = 1;
     int sum =0;
     int len = strlen(code);
     for ( int i = 0; i < len; i++ )
     {
        sum += k*code[i];
        k++;
     }
    return (sum % B);
}

void InsertRecord(int index, char cod[32], NodeT *BucketTable[B])
{
    NodeT *p;
    p = (NodeT *) malloc(sizeof(NodeT));
    if (p)
    {
        strcpy(p->key, cod);
        if (BucketTable[index] == NULL)
        {
            BucketTable[index] = p;
            p->next = NULL;
        }
        else if (BucketTable[index]->next == NULL )
        {
            BucketTable[index]->next = p;
            p->next = NULL;
        }
        else
        {
            NodeT *v;
            v = BucketTable[index]->next;
            BucketTable[index]->next = p;
            p->next = v;

        }
    }
}

NodeT *findRecord(int index, char cod[32], NodeT *BucketTable[B])
{
    NodeT *p;
    p = BucketTable[index];
    while (p != NULL)
    {
        if (strcmp(cod, p->key) == 0)
            return p;
        p = p->next;
    }
    return NULL;//not found
}

void DeleteRecord(int index, char cod[32], NodeT *BucketTable[B])
{
    NodeT *p;
    p = BucketTable[index];
    if (p == NULL)
        return;//no record

    if ( p->next == NULL) //in primul nod
    {
        free(p);
        BucketTable[index] = NULL;
        return;
    }

    NodeT *q;
    q = NULL;
    int control = 0;
    while ( p != NULL )
    {
        if (strcmp(cod, p->key) == 0)
         {
            if ( control == 0)
            {
                BucketTable[index] = BucketTable[index]->next;
                return;
            }
            q->next = p->next;
            free(p);
            return;
        }
        q = p;
        p = p->next;
        control++;
    }
}
