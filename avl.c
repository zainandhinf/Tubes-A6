// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>
#include "uno.h"
#include "avl.h"

// A utility function to get the height of the tree
int height(KartuBTree *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
KartuBTree *newAvlTree(Kartu info)
{
    KartuBTree *node = (KartuBTree*)malloc(sizeof(KartuBTree));
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
KartuBTree *rightRotate(KartuBTree *y)
{
    KartuBTree *x = y->left;
    KartuBTree *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
KartuBTree *leftRotate(KartuBTree *x)
{
    KartuBTree *y = x->right;
    KartuBTree *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(KartuBTree *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Compare two cards for AVL tree ordering
int compareKartu(Kartu a, Kartu b) {
    // First compare by color
    if (a.warna < b.warna) return -1;
    if (a.warna > b.warna) return 1;
    
    // Then compare by type
    if (a.jenis < b.jenis) return -1;
    if (a.jenis > b.jenis) return 1;
    
    // Then compare by number (if applicable)
    if (a.jenis == ANGKA) {
        if (a.angka < b.angka) return -1;
        if (a.angka > b.angka) return 1;
    }
    
    // If all fields are equal
    return 0;
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
KartuBTree *insert(KartuBTree *node, Kartu kartu)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return (newAvlTree(kartu));

    int comparison = compareKartu(kartu, node->info);

    if (comparison < 0)
        node->left = insert(node->left, kartu);
    else if (comparison > 0)
        node->right = insert(node->right, kartu);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && compareKartu(kartu, node->left->info) < 0)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && compareKartu(kartu, node->right->info) > 0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && compareKartu(kartu, node->left->info) > 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && compareKartu(kartu, node->right->info) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void inOrder(KartuBTree *root)
{
    if (root != NULL) {
        inOrder(root->left);

        printf("Kartu: ");
        switch (root->info.jenis) {
            case ANGKA: printf("%d ", root->info.angka); break;
            case SKIP: printf("SKIP "); break;
            case REVERSE: printf("REVERSE "); break;
            case DRAW2: printf("DRAW2 "); break;
            case WILD: printf("WILD "); break;
            case WILD_DRAW4: printf("WILD_DRAW4 "); break;
        }
        printf("[");
        switch (root->info.warna) {
            case MERAH: printf("MERAH"); break;
            case HIJAU: printf("HIJAU"); break;
            case BIRU: printf("BIRU"); break;
            case KUNING: printf("KUNING"); break;
            case HITAM: printf("HITAM"); break;
        }
        printf("]\n");

        inOrder(root->right);
    }
}


// /* Driver program to test above function*/
// int main()
// {
//     struct Node *root = NULL;

//     /* Constructing tree given in the above figure */
//     //   root = insert(root, 10);
//     //   root = insert(root, 20);
//     //   root = insert(root, 30);
//     //   root = insert(root, 40);
//     //   root = insert(root, 50);
//     //   root = insert(root, 25);

//     root = insert(root, 50);
//     root = insert(root, 20);
//     root = insert(root, 10);
//     root = insert(root, 40);
//     root = insert(root, 30);
//     root = insert(root, 25);

//     /* The constructed AVL Tree would be
//               30
//              /  \
//            20   40
//           /  \     \
//          10  25    50
//     */

//     printf("Preorder traversal : \n");
//     preOrder(root);

//     return 0;
// }