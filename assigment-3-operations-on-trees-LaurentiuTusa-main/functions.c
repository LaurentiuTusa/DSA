#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a =0;
int hmax = 0;
typedef struct node_type
{
    char id;
    struct node_type *left;
    struct node_type *right;
}NodeT;

NodeT *CreateBinTree(FILE *fi, FILE *fo)
{
    NodeT *p;
    char c;
    fscanf(fi, "%c", &c);
    if ( c == '*' )
        return NULL;
    else
    {
        p = (NodeT *)malloc(sizeof (NodeT));
        if (p == NULL)
            fprintf(fo, "Out of space in createBinTree");

        p->id = c;
        p->left = CreateBinTree(fi, fo);
        p->right = CreateBinTree(fi, fo);
    }
    return p;
}

void Preorder( NodeT *p, FILE *fo)
{
    if (p != NULL)
    {

            fprintf(fo, "%c", p->id);
            Preorder(p->left, fo);
            Preorder(p->right, fo);
    }
}

void Inorder(NodeT *p, FILE *fo)
{
    if (p != NULL)
    {
        Inorder(p->left, fo);

        fprintf(fo, "%c", p->id);
        Inorder(p->right, fo);
    }
}

void Postorder(NodeT *p, FILE *fo)
{
    if (p != NULL)
    {
        Postorder(p->left, fo);
        Postorder(p->right, fo);

        fprintf(fo, "%c", p->id);
    }
}

void Leaves(NodeT *p)
{
    if (p != NULL)
    {
        if ( (p->left == NULL) && (p->right == NULL) )
        {
            a++;
        }
        Leaves(p->left);
        Leaves(p->right);
    }
}

int ReturnA()
{
    return a;
}

void Height(NodeT *p, int h)
{
    if (p != NULL)
    {
        if ( (p->left == NULL) && (p->right == NULL) )
        {
            if (h > hmax)
                hmax = h;
        }
        Height(p->left, h+1);
        Height(p->right, h+1);
    }
}

int ReturnH()
{
    return hmax;
}

void Swap(NodeT *p, char key, FILE *fo)
{
    if (p != NULL)
    {   char node_id;
        node_id = (p->id);
       if (node_id == key)
       {
        NodeT *aux;
        aux = (NodeT *)malloc(sizeof (NodeT));
        if (aux == NULL)
            fprintf(fo, "Out of space in SwapAUX");

        aux = p->left;
        p->left = p->right;
        p->right = aux;
       }

    Swap(p->left, key, fo);
    Swap(p->right, key, fo);
    }
}

void FreeMemory(NodeT *p)
{
    if (p != NULL)
    {
        FreeMemory(p->left);
        FreeMemory(p->right);

        free(p);
    }
}

/*DLListT *createEmptyDLL()
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
}*/
