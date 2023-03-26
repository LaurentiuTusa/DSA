#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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

DLListT *createEmptyDLL();
int InsertAtFront(DLListT *listPtr, int key);
int InsertAtBack(DLListT *listPtr, int key);
void DeleteFirst(DLListT *listPtr);
void DeleteLast(DLListT *listPtr);
//void DeleteByKey(DLListT *listPtr, int val);
void DeleteByKey(DLListT *listPtr, int val);
void Doom(DLListT *listPtr);
void PrintAll(DLListT *listPtr, FILE *fo);
void PrintFirst(DLListT *listPtr, FILE *fo, int val);
void PrintLast(DLListT *listPtr, FILE *fo, int val);

#endif // HEADER_H_INCLUDED
