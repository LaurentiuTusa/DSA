#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_type
{
    int key;
    struct node_type *left;
    struct node_type *right;
}BSTNodeT;

BSTNodeT *Rotate_right(BSTNodeT *node);
void PrepareRotationRight(BSTNodeT *root, int val);
void PrepareRotationLeft(BSTNodeT *root, int val);
BSTNodeT *Rotate_left(BSTNodeT *node);
BSTNodeT *Rotate_left_root(BSTNodeT *root);
BSTNodeT *Rotate_right_root(BSTNodeT *root);

BSTNodeT *findMin(BSTNodeT *node)//cu root
{
    if(node == NULL)
    {
        return NULL;
    }
    if (node->left)
        return findMin(node->left);
    else
        return node;
}

BSTNodeT *findMax(BSTNodeT *node)//cu root
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->right)
        return findMax(node->right);
    else
        return node;
}

BSTNodeT *CreateNode(int givenKey)
{
    BSTNodeT *p = (BSTNodeT *) malloc (sizeof(BSTNodeT));
    if (p)
    {
        p->key = givenKey;
        p->left = p->right = NULL;
    }
    return p;
}

BSTNodeT *InsertNode(BSTNodeT *root, int key)
{
    if(root == NULL)
        root = CreateNode(key);
    else
    {
        if (key < root->key)
            root->left = InsertNode(root->left, key);
        else if (key > root->key)
            root->right = InsertNode(root->right, key);
        else
            printf("\nNode with key = %d already exists\n", key);
    }
    return root;
}

void Preorder(BSTNodeT *p, FILE *fo)
{
    if (p != NULL)
    {

            fprintf(fo, "%d ", p->key);
            Preorder(p->left, fo);
            Preorder(p->right, fo);
    }
}

void Inorder(BSTNodeT *p, FILE *fo)
{
    if (p != NULL)
    {
        Inorder(p->left, fo);

        fprintf(fo, "%d ", p->key);
        Inorder(p->right, fo);
    }
}

void Postorder(BSTNodeT *p, FILE *fo)
{
    if (p != NULL)
    {
        Postorder(p->left, fo);
        Postorder(p->right, fo);

        fprintf(fo, "%d ", p->key);
    }
}

void Purge(BSTNodeT *root)
{
    if (root != NULL)
    {
        Purge(root->left);
        Purge(root->right);
        free(root);
    }
}

BSTNodeT *delNode(BSTNodeT *node, int key)
{
    if (node == NULL)
    {
        printf("Element not found");
    }
    else if (key < node->key)
    {
        node->left = delNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = delNode(node->right, key);
    }
    else
    {
        if (node->right && node->left)
        {
            BSTNodeT *temp = findMin(node->right);
            node->key = temp->key;
            node->right = delNode(node->right, temp->key);
        }
        else
        {
            BSTNodeT *temp = node;
            if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
}

void PrepareRotationRight(BSTNodeT *root, int val)
{
    if (root == NULL)
        return;

    if (root->right->key == val)
    {
        root->right = Rotate_right(root->right);
        return;
    }
    if(root->left->key == val)
    {
        root->left = Rotate_right(root->left);
        return;
    }
    if (root->key < val)
        PrepareRotationRight(root->right, val);
    else
        PrepareRotationRight(root->left, val);

}

BSTNodeT *Rotate_right_root(BSTNodeT *root)
{
     if (root == NULL)
    {
        return NULL;
    }
    BSTNodeT *grandchild = root->left->right;
    BSTNodeT *child = root->left;
    BSTNodeT *aux = root;
    aux->left = grandchild;
    child->right = aux;
    return child;
}

BSTNodeT *Rotate_left_root(BSTNodeT *root)
{
     if (root == NULL)
    {
        return NULL;
    }
    BSTNodeT *grandchild = root->right->left;
    BSTNodeT *child = root->right;
    BSTNodeT *aux = root;
    aux->right = grandchild;
    child->left = aux;
    return child;
}

BSTNodeT *Rotate_right(BSTNodeT *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    BSTNodeT *p;
    BSTNodeT *child;
    BSTNodeT *grandchild = NULL;

    p = node;
    child = node->left;
    if (node->left)
        grandchild = node->left->right;
    child->right = p;
    node->left = grandchild;
    return child;
}

void PrepareRotationLeft(BSTNodeT *root, int val)
{
    if (root == NULL)
        return;

    if (root->left->key == val)
    {
        root->left = Rotate_left(root->left);
        return;
    }
    if(root->right->key == val)
    {
        root->right = Rotate_left(root->right);
        return;
    }
    if (root->key < val)
        PrepareRotationLeft(root->right, val);
    else
        PrepareRotationLeft(root->left, val);

}

BSTNodeT *Rotate_left(BSTNodeT *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    BSTNodeT *p;
    BSTNodeT *child;
    BSTNodeT *grandchild = NULL;

    p = node;
    child = node->right;
    if (node->right)
    {
        grandchild = node->right->left;
    }
    child->left = p;
    node->right = grandchild;
    return child;
}


