#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kartu.h"

KartuNBTree *createNBTreeNode(Kartu card)
{
    KartuNBTree *newNode = (KartuNBTree *)malloc(sizeof(KartuNBTree));
    newNode->card = card;
    newNode->firstson = NULL;
    newNode->nextbrother = NULL;
    newNode->parent = NULL;
    return newNode;
}

void InitKartu(List *kartu)
{
    CreateList(kartu);

    WarnaKartu warna;
    int angka;
    int i, j;

    for (warna = MERAH; warna <= KUNING; warna++)
    {
        Kartu k0;
        k0.warna = warna;
        k0.jenis = ANGKA;
        k0.angka = 0;
        k0.efek = '\0';
        InsVLast(kartu, k0);

        for (angka = 1; angka <= 9; angka++)
        {
            for (i = 0; i < 2; i++)
            {
                Kartu k;
                k.warna = warna;
                k.jenis = ANGKA;
                k.angka = angka;
                k.efek = '\0';
                InsVLast(kartu, k);
            }
        }
    }

    JenisKartu aksi[] = {SKIP, REVERSE, DRAW2};
    for (warna = MERAH; warna <= KUNING; warna++)
    {
        for (i = 0; i < 3; i++)
        {
            JenisKartu jenis = aksi[i];
            for (j = 0; j < 2; j++)
            {
                Kartu k;
                k.warna = warna;
                k.jenis = jenis;
                k.angka = -1;
                k.efek = '\0';
                InsVLast(kartu, k);
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        Kartu wild;
        wild.warna = HITAM;
        wild.jenis = WILD;
        wild.angka = -1;
        wild.efek = '\0';
        InsVLast(kartu, wild);

        Kartu draw4;
        draw4.warna = HITAM;
        draw4.jenis = WILD_DRAW4;
        draw4.angka = -1;
        draw4.efek = '\0';
        InsVLast(kartu, draw4);
    }
}

boolean compareCards(Kartu a, Kartu b, CompareMode mode)
{
    if (mode == COMPARE_PLAYABLE && b.warna == HITAM)
    {
        return true;
    }

    switch (mode)
    {
    case COMPARE_EQUAL:
        if (a.warna != b.warna)
            return false;
        if (a.jenis != b.jenis)
            return false;
        if (a.jenis == ANGKA)
            return a.angka == b.angka;
        return true;

    case COMPARE_SAMETYPE:
        if (a.jenis != b.jenis)
            return false;
        if (a.jenis == ANGKA)
            return a.angka == b.angka;
        return true;

    case COMPARE_PLAYABLE:
        if (a.warna == b.warna)
            return true;
        if (a.jenis == b.jenis && a.jenis != ANGKA)
            return true;
        if (a.jenis == ANGKA && b.jenis == ANGKA)
            return a.angka == b.angka;
        return false;

    case COMPARE_GROUP:
        if (a.jenis != b.jenis)
            return false;
        if (a.jenis == ANGKA)
            return a.angka == b.angka;
        return true;

    default:
        return false;
    }
}

void BagiKartu(Stack *deck, PemainList pemain[])
{
    Kartu kartu;
    int i, j;

    for (i = 0; i < 4; i++)
    {
        pemain[i].root = NULL;
        pemain[i].info.jumlahKartu = 0;
    }

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (!IsEmpty(*deck))
            {
                Pop(deck, &kartu);
                TambahKartuKePemain(&pemain[j], kartu);
            }
        }
    }
}

void TambahKartuKePemain(PemainList *pemain, Kartu kartu)
{
    pemain->root = insert(pemain->root, kartu);
    pemain->info.jumlahKartu++;
}

void TampilkanKartuPemain(PemainList pemain)
{
    printf("Jumlah kartu: %d\n", pemain.info.jumlahKartu);
    printf("Daftar kartu:\n");
    inOrder(pemain.root);
}

void addChild(KartuNBTree *parent, KartuNBTree *child)
{
    if (parent == NULL || child == NULL)
        return;

    child->parent = parent;

    if (parent->firstson == NULL)
    {
        parent->firstson = child;
    }
    else
    {
        KartuNBTree *sibling = parent->firstson;
        while (sibling->nextbrother != NULL)
        {
            sibling = sibling->nextbrother;
        }
        sibling->nextbrother = child;
    }
}

void printCard(Kartu k)
{
    switch (k.warna)
    {
    case MERAH:
        printf("MERAH ");
        break;
    case HIJAU:
        printf("HIJAU ");
        break;
    case BIRU:
        printf("BIRU ");
        break;
    case KUNING:
        printf("KUNING ");
        break;
    case HITAM:
        printf("HITAM ");
        break;
    }

    switch (k.jenis)
    {
    case ANGKA:
        printf("%d", k.angka);
        break;
    case SKIP:
        printf("SKIP");
        break;
    case REVERSE:
        printf("REVERSE");
        break;
    case DRAW2:
        printf("DRAW2");
        break;
    case WILD:
        printf("WILD");
        break;
    case WILD_DRAW4:
        printf("WILD_DRAW4");
        break;
    }
    printf("\n");
}

KartuNBTree *buildRecommendations(Kartu topDiscard, KartuBTree *playerCards)
{
    KartuNBTree *root = createNBTreeNode(topDiscard);

    findMatchingCards(root, playerCards);

    return root;
}

void findMatchingCards(KartuNBTree *parent, KartuBTree *playerCards)
{
    if (playerCards == NULL)
        return;

    if (compareCards(parent->card, playerCards->info, COMPARE_PLAYABLE))
    {
        KartuNBTree *child = createNBTreeNode(playerCards->info);
        addChild(parent, child);

        findGroupMatches(child, playerCards->info, playerCards);
    }

    findMatchingCards(parent, playerCards->left);
    findMatchingCards(parent, playerCards->right);
}

void findGroupMatches(KartuNBTree *node, Kartu matchPattern, KartuBTree *playerCards)
{
    if (playerCards == NULL)
        return;

    if (compareCards(matchPattern, playerCards->info, COMPARE_SAMETYPE) &&
        !compareCards(matchPattern, playerCards->info, COMPARE_EQUAL))
    {
        KartuNBTree *sibling = createNBTreeNode(playerCards->info);

        sibling->nextbrother = node->firstson;
        node->firstson = sibling;
        sibling->parent = node;
    }

    findGroupMatches(node, matchPattern, playerCards->left);
    findGroupMatches(node, matchPattern, playerCards->right);
}

void printRecommendations(KartuNBTree *node, int depth)
{
    if (node == NULL)
        return;

    int i;

    for (i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printCard(node->card);

    printRecommendations(node->firstson, depth + 1);

    printRecommendations(node->nextbrother, depth);
}

void deleteNBTree(KartuNBTree *node)
{
    if (node == NULL)
        return;

    deleteNBTree(node->firstson);
    deleteNBTree(node->nextbrother);
    free(node);
}

void buildPaths(KartuNBTree *node, RecommendationPath **paths)
{
    if (node == NULL)
        return;

    if (node->firstson == NULL)
    {
        addPathFromLeaf(node, paths);
    }

    buildPaths(node->firstson, paths);
    buildPaths(node->nextbrother, paths);
}

void printAllPaths(RecommendationPath *paths)
{
    int count = 1;
    while (paths != NULL)
    {
        printf("Linked list %d: ", count++);
        KartuListNode *current = paths->head;
        while (current != NULL)
        {
            printCardNoNewline(current->card);
            if (current->next != NULL)
            {
                printf(" -> ");
            }
            current = current->next;
        }
        printf("\n");
        paths = paths->next;
    }
}

void printRecommendationLists(KartuNBTree *root)
{
    if (root == NULL || root->firstson == NULL)
    {
        printf("Tidak ada rekomendasi.\n");
        return;
    }

    RecommendationPath *paths = NULL;
    buildPaths(root->firstson, &paths);
    printAllPaths(paths);

    RecommendationPath *currentPath = paths;
    while (currentPath != NULL)
    {
        RecommendationPath *nextPath = currentPath->next;
        KartuListNode *currentCard = currentPath->head;
        while (currentCard != NULL)
        {
            KartuListNode *nextCard = currentCard->next;
            free(currentCard);
            currentCard = nextCard;
        }
        free(currentPath);
        currentPath = nextPath;
    }
}

void addPathFromLeaf(KartuNBTree *leaf, RecommendationPath **paths)
{
    KartuListNode *head = NULL;

    KartuNBTree *current = leaf;
    while (current->parent != NULL)
    {
        KartuListNode *newNode = (KartuListNode *)malloc(sizeof(KartuListNode));
        newNode->card = current->card;
        newNode->next = head;
        head = newNode;
        current = current->parent;
    }

    RecommendationPath *newPath = (RecommendationPath *)malloc(sizeof(RecommendationPath));
    newPath->head = head;

    KartuListNode *temp = head;
    while (temp && temp->next != NULL)
        temp = temp->next;
    newPath->tail = temp;

    newPath->next = *paths;
    *paths = newPath;
}

void printCardNoNewline(Kartu k)
{
    switch (k.warna)
    {
    case MERAH:
        printf("MERAH ");
        break;
    case HIJAU:
        printf("HIJAU ");
        break;
    case BIRU:
        printf("BIRU ");
        break;
    case KUNING:
        printf("KUNING ");
        break;
    case HITAM:
        printf("HITAM ");
        break;
    }

    switch (k.jenis)
    {
    case ANGKA:
        printf("%d", k.angka);
        break;
    case SKIP:
        printf("SKIP");
        break;
    case REVERSE:
        printf("REVERSE");
        break;
    case DRAW2:
        printf("DRAW2");
        break;
    case WILD:
        printf("WILD");
        break;
    case WILD_DRAW4:
        printf("WILD_DRAW4");
        break;
    }
    
}

int chooseRecommendation(RecommendationPath *paths)
{
    int count = 1;
    int choice;
    RecommendationPath *current = paths;

    printf("\nPilih rekomendasi:\n");
    while (current != NULL)
    {
        printf("%d. ", count++);
        KartuListNode *node = current->head;
        while (node != NULL)
        {
            printCardNoNewline(node->card);
            if (node->next != NULL)
            {
                printf(" -> ");
            }
            node = node->next;
        }
        printf("\n");
        current = current->next;
    }

    printf("Pilihan Anda (1-%d): ", count - 1);
    scanf("%d", &choice);
    return choice;
}

RecommendationPath *getSelectedPath(RecommendationPath *paths, int choice)
{
    int count = 1;
    RecommendationPath *current = paths;

    while (current != NULL && count < choice)
    {
        current = current->next;
        count++;
    }

    return current;
}

void playSelectedRecommendation(Stack *discardDeck, PemainList *player, KartuNBTree *recommendations)
{
    RecommendationPath *paths = NULL;
    buildPaths(recommendations->firstson, &paths);

    if (paths == NULL)
    {
        printf("Tidak ada rekomendasi yang tersedia.\n");
        return;
    }

    int choice = chooseRecommendation(paths);
    RecommendationPath *selectedPath = getSelectedPath(paths, choice);

    if (selectedPath == NULL || selectedPath->head == NULL)
    {
        printf("Pilihan tidak valid!\n");
        return;
    }

    KartuListNode *current = selectedPath->head;
    while (current != NULL)
    {
        PushDiscard(discardDeck, current->card);
        player->root = deleteNode(player->root, current->card);
        player->info.jumlahKartu--;
        current = current->next;
    }

    RecommendationPath *currentPath = paths;
    while (currentPath != NULL)
    {
        RecommendationPath *nextPath = currentPath->next;
        KartuListNode *currentCard = currentPath->head;
        while (currentCard != NULL)
        {
            KartuListNode *nextCard = currentCard->next;
            free(currentCard);
            currentCard = nextCard;
        }
        free(currentPath);
        currentPath = nextPath;
    }
}