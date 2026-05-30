#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nama[50];
    int skor;
} Pemain;

Pemain pemain[MAX];
int jumlahPemain = 0;

typedef struct Node {
    Pemain data;
    struct Node *next;
} Node;

Node *head = NULL;

void tambahLinkedList(Pemain p) {
    Node *baru = (Node*)malloc(sizeof(Node));
    baru->data = p;
    baru->next = head;
    head = baru;
}

void hapusLinkedList(char nama[]) {

    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {
        if(strcmp(curr->data.nama, nama) == 0) {

            if(prev == NULL)
                head = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next; }
    }

typedef struct BSTNode {
    Pemain data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode *root = NULL;

BSTNode* buatNodeBST(Pemain p) {

    BSTNode *baru = (BSTNode*)malloc(sizeof(BSTNode));

    baru->data = p;
    baru->left = NULL;
    baru->right = NULL;

    return baru;
}
