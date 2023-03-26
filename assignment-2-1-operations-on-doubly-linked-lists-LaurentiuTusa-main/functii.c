#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
    {
        int key;
        struct node *next;
        struct node *prev;
    }NodeT;

typedef struct
    {
        int count;
        NodeT *first;
        NodeT *last;
    }DLListT;

DLListT *createEmptyDLL()
{
    DLListT *listPtr = (DLListT*)malloc(sizeof(DLListT));
    if (listPtr)
    {
        listPtr->count = 0;
        listPtr->first = NULL;
        listPtr->last = NULL;
    }
    return listPtr;
}

int InsertAtFront(DLListT *listPtr, int key)
{
    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    if(p)
    {
        p->key = key;
        p->next = NULL;
        p->prev = NULL;
    }
    if (listPtr)
    {
        if ( listPtr->count == 0)
        {
            listPtr->first = listPtr->last = p;
            p->prev = p->next = NULL;
        }
        else
        {
            p->next = listPtr->first;
            listPtr->first->prev = p;
            p->prev = NULL;
        }
        listPtr->count++;
        listPtr->first = p;
        return 1;
    }
   // free(p);
    return 0;
}

int InsertAtBack(DLListT *listPtr, int key)
{
    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    if(p)
    {
        p->key = key;
        p->next = NULL;
        p->prev = NULL;
    }
    if(listPtr)
    {
        if( listPtr->count == 0)
        {
            listPtr->first = listPtr->last = p;
            p->prev = p->next = NULL;
        }
        else
        {
            p->prev = listPtr->last;
            listPtr->last->next = p;
            p->next = NULL;
        }
        listPtr->count++;
        listPtr->last = p;
        return 1;
    }
 //   free(p);
    return 0;
}

void DeleteFirst(DLListT *listPtr)// atentie se iese din if si se executa urmatorul
{
    NodeT *p;
    if (listPtr->first != NULL)
    {
        if (listPtr->count == 1)
        {
            p = listPtr->first;
            listPtr->first = listPtr->last = NULL;
            free(p);
        }
        else
        {
            p = listPtr->first;
            listPtr->first = listPtr->first->next;
            listPtr->first->prev = NULL;
            free(p);
        }
        listPtr->count--;
    }
  /*  if (listPtr->first == NULL)// nu mai e nevoie
    {
        //listPtr->last == NULL;
        free(p);
    }*/
}

void DeleteLast(DLListT *listPtr)
{
    NodeT *p;
    if (listPtr->first != NULL)
    {
        if (listPtr->count == 1)
        {
            p = listPtr->last;
            listPtr->last = listPtr->first = NULL;//se va intra in ultimul if
            free(p);
        }
        else
        {
            p = listPtr->last;
            listPtr->last = listPtr->last->prev;
            listPtr->last->next = NULL;
            free(p);
        }
        listPtr->count--;
    }
  /*  if (listPtr->first == NULL)//atentie aici
    {
      //  listPtr->last == NULL;
        free(p);
    }*/
}

/*void DeleteByKey(DLListT *listPtr, int val)
{
    NodeT *p;
    p = listPtr->first;
    int ok = 1;
    while (p != NULL && ok == 1)
    {
        if (p->key == val)
        {
            if(listPtr->count == 1)
            {//delete first
                p = listPtr->first;
                if (p->key == val)
                {
                    listPtr->last = NULL;
                    listPtr->first = NULL;
                    free(p);
                    listPtr->count = 0;
                    ok = 3;
                //}

            }
        else if(listPtr->count != 1)
            {
                NodeT *t;
                NodeT *z;
                t = p->prev;
                z = p->next;
                t->next = z;
                z->prev = t;
                free(p);
                listPtr->count--;
                ok = 3;
            }
         //   else free(p);
        }
        p = p->next;
    }
}*/

void DeleteByKey(DLListT *listPtr, int val)
{
    NodeT *p;
    p = listPtr->first;
    if( p->key == val )
    {
        DeleteFirst(listPtr);
        return;
    }

    while (p != NULL && p->key != val)
        p = p->next;

    if (p == NULL)
        return;

    NodeT *t;
    NodeT *z;
    t = p->prev;
    z = p->next;
    t->next = z;
    z->prev = t;
    free(p);
    listPtr->count--;
}

void Doom(DLListT *listPtr)
{
    NodeT *p;
    while (listPtr->first != NULL)
    {
        p = listPtr->first;
        listPtr->first = listPtr->first->next;
        free(p);
    }
    listPtr->last = NULL;
    listPtr->count = 0;
}

void PrintAll(DLListT *listPtr, FILE *fo)
{
    NodeT *p;
    p = listPtr->first;
    if (p != NULL)
    {
        while ( p != NULL )
        {
            if (p->next == NULL)
            {
                fprintf(fo, "%d", p->key);
                p = p->next;
            }
            else
            {
                fprintf(fo, "%d ", p->key);
                p = p->next;
            }

        }
    fprintf(fo, "\n");
    }
}

void PrintFirst(DLListT *listPtr, FILE *fo, int val)
{
    NodeT *p;
    p = listPtr->first;
    int nr = 0;
    if (p != NULL)
    {
        while ( nr < val )//daca nr e cu 1 mai mic decat val atunci e ultime iteratie
        {

            if (p != NULL)
            {
                if ( val-nr == 1 )
                    {
                        fprintf(fo, "%d", p->key);
                        p = p->next;
                    }
                else
                {
                    fprintf(fo, "%d ", p->key);
                    p = p->next;
                }

            }
            nr++;
        }
    fprintf(fo, "\n");
    }
}

void PrintLast(DLListT *listPtr, FILE *fo, int val)
{
    if (val >= listPtr->count)
    {
        PrintAll(listPtr, fo);
    }
    else
    {
        int i;
        NodeT *p;
        p = listPtr->last;
        for (i=1; i<val; i++)
        {
            p = p->prev;
        }

        while ( p != NULL )
        {
            if (p->next == NULL)
            {
                fprintf(fo, "%d", p->key);
                p = p->next;
            }
            else
            {
                fprintf(fo, "%d ", p->key);
                p = p->next;
            }

        }
        fprintf(fo, "\n");
    }
}
