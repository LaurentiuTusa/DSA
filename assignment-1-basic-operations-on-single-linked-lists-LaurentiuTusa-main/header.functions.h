#ifndef HEADER_FUNCTIONS_H_INCLUDED
#define HEADER_FUNCTIONS_H_INCLUDED

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

void PrintALLlist(ListT *listPtr, FILE *fo);
void PrintFirstList(ListT *listPtr, FILE *fo, int valx);
void PrintLastList(ListT *listPtr, FILE *fo, int val);
ListT *createEmptySLL();
NodeT *createNode(int key);
int insertAtFront(ListT *listptr, NodeT *p);
int insertAtBack(ListT *listptr, NodeT *p);
NodeT *deleteFirst(ListT *listptr);
NodeT *deleteLast(ListT *listptr);
int deleteByKey(ListT *listptr, int val);
void doom(ListT *listptr);


#endif // HEADER_FUNCTIONS_H_INCLUDED
