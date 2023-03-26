#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct node_type
{
    int key;
    struct node_type *left;
    struct node_type *right;
}BSTNodeT;


BSTNodeT *CreateNode(int givenKey);
BSTNodeT *InsertNode(BSTNodeT *root, int key);
void Preorder(BSTNodeT *p, FILE *fo);
void Inorder(BSTNodeT *p, FILE *fo);
void Postorder(BSTNodeT *p, FILE *fo);
void Purge(BSTNodeT *root);
BSTNodeT *findMin(BSTNodeT *node);
BSTNodeT *findMax(BSTNodeT *node);
BSTNodeT *delNode(BSTNodeT *node, int key);
void PrepareRotationRight(BSTNodeT *root, int val);
BSTNodeT *Rotate_right(BSTNodeT *node);
void PrepareRotationLeft(BSTNodeT *root, int val);
BSTNodeT *Rotate_left(BSTNodeT *node);
BSTNodeT *Rotate_left_root(BSTNodeT *root);
BSTNodeT *Rotate_right_root(BSTNodeT *root);

#endif // HEADER_H_INCLUDED
