#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    }ListT;

void PrintALLlist(ListT *listPtr, FILE *fo)
{
    ListT *temporary = listPtr;

    while (temporary->first != NULL)
    {
        fprintf(fo, "%d - ", temporary->first->key);
        temporary->first = temporary->first->next;
    }
    fprintf(fo, "\n");
}

void PrintFirstList(ListT *listPtr, FILE *fo, int valx)
{
    if ( valx >= listPtr->count)
    {
        PrintALLlist(listPtr, fo);
    }
    else
        {
            ListT *t = listPtr;
            int k = 1;
            while (k<= valx && t->first != NULL)
            {
                fprintf(fo, "%d - ", t->first->key);
                t->first = t->first->next;
                k++;
            }
        }

    fprintf(fo, "\n");
}

void PrintLastList(ListT *listPtr, FILE *fo, int val)
{
    if ( val >= listPtr->count)
    {
        PrintALLlist(listPtr, fo);
    }
    else
    {
        ListT *t = listPtr;
        int i;
        int skip = listPtr->count - val;
        while (i <= skip && t->first != NULL)
        {
            t->first = t->first->next;
            i++;
        }

        while(i <= val && t->first != NULL)
        {
            fprintf(fo, "%d - ", t->first->key);
            t->first = t->first->next;
            i++;
        }
    }
    fprintf(fo, "\n");
}

ListT *createEmptySLL()
{
    ListT *listPtr = (ListT*)malloc(sizeof(ListT));
    if (listPtr)
    {
        listPtr->count = 0;
        listPtr->first = listPtr->last = NULL;
    }
    return listPtr;
}

NodeT *createNode(int key)
{
    NodeT *p = (NodeT *)malloc(sizeof(NodeT));
    if(p)
    {
        p->key = key;
        p->next = NULL;
    }
    return p;
}

int insertAtFront(ListT *listptr, NodeT *p)
{
    if(listptr)
    {
        p->next = listptr->first;
        if (listptr->first == NULL)
        {
            listptr->last = p;
        }
        listptr->first = p;
        listptr->count++;
        return 1;
    }
    return 0;
}

int insertAtBack(ListT *listptr, NodeT *p)
{
    if(listptr)
    {
        if (listptr->first == NULL)
        {
            listptr->first = p;
        }
         else
         {
            listptr->last->next = p;
         }

    listptr->last = p;
    listptr->count++;
    return 1;
    }
    return 0;
}

NodeT *deleteFirst(ListT *listptr)
{
        NodeT *p;
        if (listptr->first != NULL)
        {
            p = listptr->first;
            listptr->first = listptr->first->next;
            listptr->count--;
            if (listptr->first == NULL)
                listptr->last = NULL;
            return p;
        }
        return NULL;
}

NodeT *deleteLast(ListT *listptr)
{
    NodeT *q, *q1;
    q1 = NULL;
    q = listptr->first;
    if (q != NULL)
    {
        while(q != listptr->last)
        {
            q1 = q;
            q = q->next;
        }
        if (q == listptr->first)
        {
            listptr->first = listptr->last = NULL;
            listptr->count--;
        }
        else
        {
            q1->next = NULL;
            listptr->last = q1;
            listptr->count--;
        }
    }
    return q;
}

int deleteByKey(ListT *listptr, int val)
{
    NodeT *q, *q1;
    q1 = NULL;
    q = listptr->first;
    while ( q != NULL)
    {
        if(q->key == val) break;
        q1 = q;
        q = q->next;
    }

    if (q != NULL)
    {
        if (q == listptr->first)
        {
            listptr->first = listptr->first->next;
            free(q);
            listptr->count--;
            if( listptr->first == NULL)
                listptr->last = NULL;
        }
            else
            {
                q1->next = q->next;
                if (q == listptr->last)
                    listptr->last = q1;
                free(q);
                listptr->count--;
            }
         return 1;
    }
    return 0;
}

void doom(ListT *listptr)
{
    NodeT *p;
    while (listptr->first != NULL)
    {
        p = listptr->first;
        listptr->first = listptr->first->next;
        free(p);
    }
    listptr->last = NULL;
    listptr->count = 0;
}
