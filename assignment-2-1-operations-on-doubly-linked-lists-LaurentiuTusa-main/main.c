#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char **argv)
{

    DLListT *listPtr = createEmptyDLL();
    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");

    char cod[30];
    int val;
    while(fscanf(fi, "%s", cod) != EOF)
    {
       if(strcmp(cod, "AL") == 0)
      {
         fscanf(fi, "%d", &val);
         InsertAtBack(listPtr, val);
      }

       else if (strcmp(cod, "AF") == 0)
      {
        fscanf(fi, "%d", &val);
        InsertAtFront(listPtr, val);
      }

      else if(strcmp(cod, "DF") == 0)
      {
        DeleteFirst(listPtr);
      }

      else if(strcmp(cod, "DL") == 0)
      {
        DeleteLast(listPtr);
      }

      else if(strcmp(cod, "DE") == 0)
      {
        fscanf(fi, "%d", &val);
        DeleteByKey(listPtr, val);
      }

      else if(strcmp(cod, "PRINT_ALL") == 0)
      {
        PrintAll(listPtr, fo);
      }

      else if(strcmp(cod, "PRINT_F") == 0)
      {
        fscanf(fi, "%d", &val);
        PrintFirst(listPtr, fo, val);
      }

      else if(strcmp(cod, "PRINT_L") == 0)
      {
        fscanf(fi, "%d", &val);
        PrintLast(listPtr, fo, val);
      }

      else if(strcmp(cod, "DOOM_THE_LIST") == 0)
      {
        Doom(listPtr);
      }
   // PrintAll(listPtr, fo);
  //  control++;
    }

    fclose(fi);
    fclose(fo);

    return 0;
}
