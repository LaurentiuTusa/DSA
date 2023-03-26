#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.functions.h"

int main()
{
    ListT *listPtr = createEmptySLL();

    FILE *fi = fopen("input.dat", "r");
    FILE *fo = fopen("output.dat", "w");
    char cod[20];
    int val;

    while(fscanf(fi, "%s", cod) != EOF)
    {
       if(strcmp(cod, "AL") == 0)
      {
         fscanf(fi, "%d", &val);
         insertAtBack(listPtr, createNode(val));
      }

       else if (strcmp(cod, "AF") == 0)
      {
        fscanf(fi, "%d", &val);
        insertAtFront(listPtr, createNode(val));
      }

      else if(strcmp(cod, "DF") == 0)
      {
        deleteFirst(listPtr);
      }

      else if(strcmp(cod, "DL") == 0)
      {
        deleteLast(listPtr);
      }

      else if(strcmp(cod, "DE") == 0)
      {
        fscanf(fi, "%d", &val);
        deleteByKey(listPtr, val);
      }

      else if(strcmp(cod, "PRINT_ALL") == 0)
      {
        PrintALLlist(listPtr, fo);
      }

      else if(strcmp(cod, "PRINT_F") == 0)
      {
        fscanf(fi, "%d", &val);
        PrintFirstList(listPtr, fo, val);
      }

      else if(strcmp(cod, "PRINT_L") == 0)
      {
        fscanf(fi, "%d", &val);
        PrintLastList(listPtr, fo, val);
      }

      else if(strcmp(cod, "DOOM_THE_LIST") == 0)
      {
        doom(listPtr);
      }

    }

    fclose(fi);
    fclose(fo);

    return 0;
}
