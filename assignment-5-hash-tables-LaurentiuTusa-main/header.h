#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

int B = 31;
    typedef struct cell
    {
        char key[60];
        struct cell *next;
    } NodeT;

int HashFct(char code[31]);
void InsertRecord(int index, char cod[32], NodeT *BucketTable[B]);
NodeT *findRecord(int index, char cod[32], NodeT *BucketTable[B]);
void DeleteRecord(int index, char cod[32], NodeT *BucketTable[B]);


#endif // HEADER_H_INCLUDED
