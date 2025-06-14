#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kartu.h"

/* Inisialisasi & Struktur Data Kartu */
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

/* Komparasi Kartu */
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

/* Manajemen Gameplay */
void BagiKartu(Stack *deck, Queue *head)
{
    PemainList *current;
    Kartu kartu;
    int i;

    while (current != NULL)
    {
        current->root = NULL;
        current->info.jumlahKartu = 0;
        current = current->next;
    }

    for (i = 0; i < 7; i++)
    {
        current = head->Front;
        while (current != NULL)
        {
            if (!IsEmpty(*deck))
            {
                Pop(deck, &kartu);
                TambahKartuKePemain(current, kartu);
            }
            current = current->next;
        }
    }
}
void TambahKartuKePemain(PemainList *pemain, Kartu kartu)
{
    pemain->root = insert(pemain->root, kartu);
    if (pemain->root == NULL)
    {
        printf("Gagal menambahkan kartu ke pemain!\n");
        return;
    }
    pemain->info.jumlahKartu++;
}

void TampilkanKartuPemain(PemainList *pemain)
{
    printf("Jumlah kartu: %d\n", pemain->info.jumlahKartu);

    if (pemain->info.jumlahKartu > 0)
    {
        printf("Daftar kartu:\n");

        if (pemain->root == NULL)
        {
            printf("Root masih NULL — kartu belum dibagikan\n");
        }
        else
        {
            inOrder(pemain->root);
        }
    }
    else
    {
        printf("Pemain tidak memiliki kartu\n");
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

/* Rekomendasi Kartu Non Binary Tree */
KartuNBTree *buildRecommendations(Kartu topDiscard, KartuBTree *playerCards)
{
    KartuNBTree *root = createNBTreeNode(topDiscard);

    findMatchingCards(root, playerCards);

    return root;
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

/* Rekomendasi Kartu Linked List */
void buildList(KartuNBTree *node, RecommendationList **list)
{
    if (node == NULL)
        return;

    if (node->firstson == NULL)
    {
        addListFromLeaf(node, list);
    }

    buildList(node->firstson, list);
    buildList(node->nextbrother, list);
}
void printAllList(RecommendationList *list)
{
    int count = 1;
    while (list != NULL)
    {
        printf("Linked list %d: ", count++);
        KartuList *current = list->head;
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
        list = list->next;
    }
}
void printRecommendationLists(KartuNBTree *root)
{
    if (root == NULL || root->firstson == NULL)
    {
        printf("Tidak ada rekomendasi.\n");
        return;
    }

    RecommendationList *list = NULL;
    buildList(root->firstson, &list);
    printAllList(list);

    RecommendationList *currentList = list;
    while (currentList != NULL)
    {
        RecommendationList *nextList = currentList->next;
        KartuList *currentCard = currentList->head;
        while (currentCard != NULL)
        {
            KartuList *nextCard = currentCard->next;
            free(currentCard);
            currentCard = nextCard;
        }
        free(currentList);
        currentList = nextList;
    }
}
void addListFromLeaf(KartuNBTree *leaf, RecommendationList **list)
{
    KartuList *head = NULL;

    KartuNBTree *current = leaf;
    while (current->parent != NULL)
    {
        KartuList *newNode = (KartuList *)malloc(sizeof(KartuList));
        newNode->card = current->card;
        newNode->next = head;
        head = newNode;
        current = current->parent;
    }

    RecommendationList *newList = (RecommendationList *)malloc(sizeof(RecommendationList));
    newList->head = head;

    KartuList *temp = head;
    while (temp && temp->next != NULL)
        temp = temp->next;
    newList->tail = temp;

    newList->next = *list;
    *list = newList;
}
int chooseRecommendation(RecommendationList *list)
{
    int count = 1;
    int choice;
    RecommendationList *current = list;

    printf("\nPilih rekomendasi:\n");
    while (current != NULL)
    {
        printf("%d. ", count++);
        KartuList *node = current->head;
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
RecommendationList *getSelectedList(RecommendationList *list, int choice)
{
    int count = 1;
    RecommendationList *current = list;

    while (current != NULL && count < choice)
    {
        current = current->next;
        count++;
    }

    return current;
}
void playSelectedRecommendation(Stack *discardDeck, PemainList *player, KartuNBTree *recommendations)
{
    RecommendationList *list = NULL;
    buildList(recommendations->firstson, &list);

    if (list == NULL)
    {
        printf("Tidak ada rekomendasi yang tersedia.\n");
        return;
    }

    int choice = chooseRecommendation(list);
    RecommendationList *selectedList = getSelectedList(list, choice);

    if (selectedList == NULL || selectedList->head == NULL)
    {
        printf("Pilihan tidak valid!\n");
        return;
    }

    KartuList *current = selectedList->head;
    while (current != NULL)
    {
        if (current->card.jenis == WILD || current->card.jenis == WILD_DRAW4)
        {
            handleWildCard(discardDeck, current->card);
        }
        else
        {
            PushDiscard(discardDeck, current->card);
        }
        player->root = deleteNode(player->root, current->card);
        player->info.jumlahKartu--;
        current = current->next;
    }

    RecommendationList *currentList = list;
    while (currentList != NULL)
    {
        RecommendationList *nextList = currentList->next;
        KartuList *currentCard = currentList->head;
        while (currentCard != NULL)
        {
            KartuList *nextCard = currentCard->next;
            free(currentCard);
            currentCard = nextCard;
        }
        free(currentList);
        currentList = nextList;
    }
}

/*  Efek Kartu Spesial */
void kartuSkip(Queue *q, int jumlahPemain, int skipCount)
{
    if (is_Empty(*q))
    {
        printf("Tidak ada pemain dalam antrian.\n");
        return;
    }

    int i;

    if (skipCount < 0 || skipCount >= jumlahPemain)
    {
        printf("Jumlah pemain yang ingin dilewati tidak valid.\n");
        return;
    }

    for (i = 0; i < skipCount; i++)
    {
        PemainList pemainSekarang;
        deQueue(q, &pemainSekarang.info);
        EnQueue(q, pemainSekarang.info);
    }
    printf("Giliran telah dilewati sebanyak %d kali.\n", skipCount);
}
void kartuReverse(Queue *q)
{
    if (is_Empty(*q))
    {
        printf("Tidak ada pemain dalam antrian.\n");
        return;
    }

    addresspemain prev = NULL;
    addresspemain current = q->Front;
    addresspemain next = NULL;

    q->Rear = q->Front;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    q->Front = prev;
    printf("Antrian pemain telah dibalik.\n");
}
void handleWildCard(Stack *discardDeck, Kartu playedCard)
{
    if (playedCard.jenis == WILD || playedCard.jenis == WILD_DRAW4)
    {
        printf("\nAnda memainkan kartu ");
        printCardNoNewline(playedCard);
        printf(". Pilih warna baru:\n");
        printf("1. MERAH\n");
        printf("2. HIJAU\n");
        printf("3. BIRU\n");
        printf("4. KUNING\n");
        printf("Pilihan (1-4): ");

        int choice;
        do
        {
            scanf("%d", &choice);
            if (choice < 1 || choice > 4)
            {
                printf("Pilihan tidak valid. Masukkan angka 1-4: ");
            }
        } while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1:
            playedCard.warna = MERAH;
            break;
        case 2:
            playedCard.warna = HIJAU;
            break;
        case 3:
            playedCard.warna = BIRU;
            break;
        case 4:
            playedCard.warna = KUNING;
            break;
        }

        printf("Warna dipilih: ");
        printCard(playedCard);

        PushDiscard(discardDeck, playedCard);
    }
}

void handleCardEffect(Stack *discardDeck, Queue *turnQueue, PemainList *currentPlayer, Stack *deck)
{
    Kartu topCard = Top(*discardDeck);
    int i;

    switch (topCard.jenis)
    {
    case SKIP:
        printf("Efek SKIP! Giliran pemain berikutnya dilewati.\n");
        NextGiliran(turnQueue);
        break;

    case REVERSE:
        printf("Efek REVERSE! Arah permainan dibalik.\n");
        kartuReverse(turnQueue);
        break;

    case DRAW2:
    case WILD_DRAW4:
        printf("Efek %s! Pemain berikutnya mengambil %d kartu.\n", (topCard.jenis == DRAW2) ? "DRAW2" : "WILD_DRAW4", (topCard.jenis == DRAW2) ? 2 : 4);
        NextGiliran(turnQueue);
        PemainList *nextPlayer = CurrentPlayer(turnQueue);
        for (i = 0; i < ((topCard.jenis == DRAW2) ? 2 : 4); i++)
        {
            DrawCardWild(deck, nextPlayer);
        }
        break;

    default:
        break;
    }
}

void startGame(PemainList *players, Queue *turnQueue)
{
    Stack deck, discard;
    InitDeck(&deck);

    turnQueue->Front = players;
    PemainList *last = players;
    while (last->next != NULL)
    {
        last = last->next;
    }
    turnQueue->Rear = last;

    PemainList *curr = players;
    while (curr != NULL)
    {
        curr->root = NULL;
        curr->info.jumlahKartu = 0;
        curr = curr->next;
    }
    PrintPlayerList(players);
    BagiKartu(&deck, turnQueue);
    printf("Membagi kartu...\n");
    Sleep(2000);
    printf("Masing-masing pemain telah mendapatkan 7 kartu\n");
    Sleep(2000);

    PemainList *currentPlayer = players;

    InitDiscard(&deck, &discard);

    bool gameRunning = true;

    while (gameRunning)
    {
        currentPlayer = CurrentPlayer(turnQueue);

        printf("\n=== Giliran %s ===\n", currentPlayer->info.nama);
        printf("Kartu teratas di discard pile: ");
        printCard(Top(discard));

        printf("\nKartu di tangan:\n");

        printBinaryTree(currentPlayer->root);
        TampilkanKartuPemain(currentPlayer);

        KartuNBTree *recommendations = buildRecommendations(Top(discard), currentPlayer->root);

        if (recommendations->firstson != NULL)
        {
            printf("\nRekomendasi kartu yang bisa dimainkan:\n");
            printRecommendations(recommendations, 0);
            printRecommendationLists(recommendations);

            playSelectedRecommendation(&discard, currentPlayer, recommendations);

            if (Top(discard).jenis == WILD || Top(discard).jenis == WILD_DRAW4)
            {
                printf("Warna aktif sekarang: ");
                printCard(Top(discard));
            }

            checkWinCondition(turnQueue, &gameRunning);
            if (!gameRunning)
            {
                printf("\n==================================\n");
                printf("%s menang!\n", turnQueue->Front->info.nama);
                printf("==================================\n");
                backToMenu();
            }

            handleCardEffect(&discard, turnQueue, currentPlayer, &deck);
        }
        else
        {
            printf("\nTidak ada kartu yang bisa dimainkan. Mengambil kartu dari deck...\n");
            Sleep(1000);
            DrawCard(&deck, currentPlayer);
        }

        deleteNBTree(recommendations);

        if (gameRunning)
        {
            printf("\nTekan Enter untuk lanjut ke pemain berikutnya...");
            while (getchar() != '\n')
                ;
            getchar();
            NextGiliran(turnQueue);
        }
        system("cls");
    }
}

void checkWinCondition(Queue *turnQueue, bool *gameRunning)
{
    PemainList *currentPlayer = turnQueue->Front;
    if (currentPlayer != NULL && currentPlayer->info.jumlahKartu == 0)
    {
        *gameRunning = false;
    }
}

void printSpaces(int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf(" ");
    }
}

void printBTRecursive(KartuBTree *node, int depth, bool isLeft) {
    if (node == NULL) return;
    
    printSpaces(depth * 3);
    if (depth > 0) {
        printf(isLeft ? "|-- " : "`-- ");
    }
    
    printCardNoNewline(node->info);
    printf(" (h:%d)\n", node->height);
    
    if (node->left != NULL || node->right != NULL) {
        printBTRecursive(node->right, depth + 1, true);
        printBTRecursive(node->left, depth + 1, false);
    }
}

void printBinaryTree(KartuBTree *root) {
    printf("\nStruktur Kartu Pemain (Binary Tree):\n");
    printf("==================================\n");
    printBTRecursive(root, 0, false);
    printf("==================================\n");
}