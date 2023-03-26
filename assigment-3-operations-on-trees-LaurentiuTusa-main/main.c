#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char **argv)
{

    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");
    NodeT *root = CreateBinTree(fi, fo);
    char SwapNode = 0;

    if ( strcmp(argv[3], "preorder") == 0)
    {
        Preorder(root, fo);
    }
    else if ( strcmp(argv[3], "inorder") == 0)
    {
        Inorder(root, fo);
    }
    else if ( strcmp(argv[3], "postorder") == 0)
    {
        Postorder(root, fo);
    }
    else if ( strcmp(argv[3], "height") == 0)
    {
        Height(root, 1);
        fprintf(fo, "%d", ReturnH());
    }
    else if ( strcmp(argv[3], "leaves") == 0)
    {
        Leaves(root);
        fprintf(fo, "%d", ReturnA());
    }
    else if ( strcmp(argv[3], "swap") == 0)
    {
        while (!( SwapNode >='A' && SwapNode <='Z' ))
        {
            fscanf(fi, "%c", &SwapNode);
        }
        Swap(root, SwapNode, fo);
        Inorder(root, fo);
    }
    else if ( strcmp(argv[3], "list") == 0)
    {

    }

    FreeMemory(root);

    fclose(fo);
    fclose(fi);
    return 0;
}
