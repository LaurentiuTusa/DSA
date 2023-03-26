#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char **argv)
{

    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");

    char cod[32];
    int val;
    BSTNodeT *root;
    int ok = 0;
 //   int control = 1;

    while( fscanf(fi, "%31s", cod) != EOF /*&& control < 24*/) // control = 23 is the preorder after the 3 rotations
    {

       if (strcmp(cod, "insert") == 0)
      {
          if (ok == 0)
          {
              fscanf(fi, "%d", &val);
              root = CreateNode(val);
              ok++;
          }
          else
          {
            fscanf(fi, "%d", &val);
            InsertNode(root, val);
          }

      }

      else if (strcmp(cod, "delete") == 0)
      {
          fscanf(fi, "%d", &val);
          delNode(root, val);
      }

      else if (strcmp(cod, "preorder") == 0)
      {
          Preorder(root, fo);
          fprintf(fo, "\n");
      }

      else if (strcmp(cod, "inorder") == 0)
      {
          Inorder(root, fo);
          fprintf(fo, "\n");
      }

      else if (strcmp(cod, "postorder") == 0)
      {
          Postorder(root, fo);
          fprintf(fo, "\n");
      }

      else if (strcmp(cod, "rotate_right") == 0)
      {
          fscanf(fi, "%d", &val);
          if (root->key == val)
          {
            root = Rotate_right_root(root);
          }
          else
            PrepareRotationRight(root, val);

      }

      else if (strcmp(cod, "rotate_left") == 0)
      {
          fscanf(fi, "%d", &val);
          if (root->key == val)
            {
                root = Rotate_left_root(root);
            }
            else
             PrepareRotationLeft(root, val);
      }

      else if (strcmp(cod, "insert_avl") == 0)
      {
          fscanf(fi, "%d", &val);
      }

      else if (strcmp(cod, "delete_avl") == 0)
      {
          fscanf(fi, "%d", &val);
      }

      else if (strcmp(cod, "purge") == 0)
      {
          Purge(root);
          root = NULL;
          ok = 0;
      }
     //   control++;
    }


    fclose(fo);
    fclose(fi);
    return 0;
}
