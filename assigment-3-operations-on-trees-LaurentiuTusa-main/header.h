#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct node_type
{
    char id;
    struct node_type *left;
    struct node_type *right;
}NodeT;

NodeT *CreateBinTree(FILE *fi, FILE *fo);
void Preorder( NodeT *p, FILE *fo);
void Inorder(NodeT *p, FILE *fo);
void Postorder(NodeT *p, FILE *fo);
void Leaves(NodeT *p);
int ReturnA();
void Height(NodeT *p, int h);
int ReturnH();
void Swap(NodeT *p, char key, FILE *fo);
void FreeMemory(NodeT *p);

#endif // HEADER_H_INCLUDED
