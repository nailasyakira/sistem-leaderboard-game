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
