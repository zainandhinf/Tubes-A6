#ifndef AVL_H
#define AVL_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "uno.h"

// An AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};


int max(int a, int b);
KartuBTree *newAvlTree(Kartu info);
KartuBTree *rightRotate(KartuBTree *y);
KartuBTree *leftRotate(KartuBTree *x);
int getBalance(KartuBTree *N);
int compareKartu(Kartu a, Kartu b);
KartuBTree *insert(KartuBTree *node, Kartu kartu);
void preOrder(KartuBTree *root);

#endif