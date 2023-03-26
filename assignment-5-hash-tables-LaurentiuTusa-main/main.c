#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//am folosit un input mai ciudat ca sa fac recordurile sa aiba acelasi hash code si sa pun in folosinta linked lists

int main(int argc, char **argv)
{
    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");
    NodeT *BucketTable[B];
    int i;

    for (i=0; i < B; i++)
    {
        BucketTable[i] = NULL;
    }

    int index;
    char cod[32];
    while( fscanf(fi, "%31s", cod) != EOF)
    {
         if (strcmp(cod, "i") == 0)
         {
            fscanf(fi, "%c", cod);//citeste spatiu i_Alex
            fgets(cod, 31, fi);
            index = HashFct(cod);
            InsertRecord(index, cod, BucketTable);
         }

         else if (strcmp(cod, "d") == 0)
         {
            fscanf(fi, "%c", cod);//citeste spatiu i_Belex
            fgets(cod, 31, fi);
            index = HashFct(cod);
            DeleteRecord(index, cod, BucketTable);
         }

         else if (strcmp(cod, "f") == 0)
         {
            fscanf(fi, "%c", cod);//citeste spatiu i_Alex
            fgets(cod, 31, fi);// cod holds the name
            index = HashFct(cod);
            if (findRecord(index, cod, BucketTable))
            {
                fprintf(fo, "yes - The hash is %d for the record %s", index, cod);
            }
            else fprintf(fo, "no - no record for %s", cod);
         }

         else if (strcmp(cod, "l") == 0)
         {
            for ( i=0; i<B; i++ )
            {
                if (BucketTable[i] != NULL)
                {
                    NodeT *p;
                    fprintf(fo, "Records for hash value %d\n", i);
                    p = BucketTable[i];
                    while (p != NULL)
                    {
                        fprintf(fo, "%s", p->key);
                        p = p->next;
                    }
                }
            }
         }

    }
    fclose(fi);
    return 0;
}
