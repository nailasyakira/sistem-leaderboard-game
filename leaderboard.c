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

BSTNode* insertBST(BSTNode *root, Pemain p) {

    if(root == NULL)
        return buatNodeBST(p);

    if(p.skor < root->data.skor)
        root->left = insertBST(root->left, p);
    else
        root->right = insertBST(root->right, p);

    return root;
}

void inorderBST(BSTNode *root) {

    if(root != NULL) {

        inorderBST(root->right);

        printf("%-20s %5d\n",
               root->data.nama,
               root->data.skor);

        inorderBST(root->left);
    }
}

void bangunUlangBST() {

    root = NULL;

    for(int i=0;i<jumlahPemain;i++) {

        root = insertBST(root, pemain[i]);
    }
}

void swap(Pemain *a, Pemain *b) {

    Pemain temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Pemain arr[], int n) {

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j].skor < arr[j+1].skor)
                swap(&arr[j], &arr[j+1]);  
        }
    }
}

void insertionSort(Pemain arr[], int n) {
    for(int i=1;i<n;i++) {

        Pemain key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j].skor < key.skor) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; }
}

void selectionSort(Pemain arr[], int n) {
    for(int i=0;i<n-1;i++) {

        int max = i;
        for(int j=i+1;j<n;j++) {

            if(arr[j].skor > arr[max].skor)
                max = j;
        }
        swap(&arr[i], &arr[max]);
    }
}

void tambahPemain() {
    
    if(jumlahPemain >= MAX) {
        printf("\nData penuh!\n");
        return;  }

    Pemain p;
    
    printf("\nNama pemain : ");
    scanf(" %[^\n]", p.nama);

    printf("Skor        : ");
    scanf("%d", &p.skor);

    pemain[jumlahPemain++] = p;

    tambahLinkedList(p);

    root = insertBST(root, p);

    printf("\n====================================\n");
    printf("Pemain berhasil ditambahkan!\n");
    printf("Nama : %s\n", p.nama);
    printf("Skor : %d\n", p.skor);
    printf("====================================\n");
}

void tampilLeaderboard() {

    if(jumlahPemain == 0) {

        printf("\nBelum ada data pemain!\n");
        return;
    }

    printf("\n");
    printf("====================================\n");
    printf("          LEADERBOARD GAME\n");
    printf("====================================\n");

    printf("%-5s %-20s %-10s\n",
           "No",
           "Nama",
           "Skor");

    printf("------------------------------------\n");

    for(int i=0;i<jumlahPemain;i++) {

        printf("%-5d %-20s %-10d\n",
               i+1,
               pemain[i].nama,
               pemain[i].skor);
    }

    printf("====================================\n");
}
void cariPemain() {

    char nama[50];
    int ditemukan = 0;

    printf("\n====================================\n");
    printf("          CARI PEMAIN\n");
    printf("====================================\n");

    printf("Masukkan nama pemain yang dicari : ");
    scanf(" %[^\n]", nama);

for(int i=0;i<jumlahPemain;i++) {

        if(strcmp(pemain[i].nama, nama) == 0) {

            printf("\nData ditemukan!\n");
            printf("Metode Pencarian : Linear Search\n");
            printf("------------------------------------\n");
            printf("Nama : %s\n", pemain[i].nama);
            printf("Skor : %d\n", pemain[i].skor);

            ditemukan = 1;
            break;
        }
    }

    if(!ditemukan) {

        printf("\nPemain tidak ditemukan!\n");
    }
}

void hapusPemain() {

    char nama[50];

    printf("\nNama pemain yang dihapus : ");
    scanf(" %[^\n]", nama);

    int ditemukan = 0;

    for(int i=0;i<jumlahPemain;i++) {

        if(strcmp(pemain[i].nama, nama) == 0) {
            
            for(int j=i;j<jumlahPemain-1;j++)
            pemain[j] = pemain[j+1];

jumlahPemain--;
            hapusLinkedList(nama);
            bangunUlangBST();

            ditemukan = 1;
            break;
        }
    }

    if(ditemukan) {
    printf("\n====================================\n");
    printf("Pemain berhasil dihapus!\n");
    printf("====================================\n");
} else {
    printf("\n====================================\n");
    printf("Pemain tidak ditemukan!\n");
    printf("====================================\n");
}} 
void pilihSorting() {

    if(jumlahPemain == 0) {

        printf("\nBelum ada data pemain!\n");
        return;
    }

    int pilih;

    printf("\n=== PILIH METODE SORTING ===\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("Pilihan : ");
    scanf("%d", &pilih);

    switch(pilih) {

case 1:
             bubbleSort(pemain, jumlahPemain);

             printf("\n====================================\n");
             printf("      HASIL BUBBLE SORT\n");
             printf("====================================\n");

            tampilLeaderboard();
             break;

        case 2:
             insertionSort(pemain, jumlahPemain);

             printf("\n====================================\n");
             printf("     HASIL INSERTION SORT\n");
             printf("====================================\n");

            tampilLeaderboard();
             break;

        case 3:
             selectionSort(pemain, jumlahPemain);

            printf("\n====================================\n");
            printf("     HASIL SELECTION SORT\n");
            printf("====================================\n");

            tampilLeaderboard();
            break;

        default:
            printf("\nPilihan tidak valid!\n");
    }
}

void menu() {

    printf("\n");
    printf("====================================================\n");
    printf("            SISTEM LEADERBOARD GAME\n");
    printf("====================================================\n");
    printf("[1] Tambah Pemain Baru\n");
    printf("[2] Tampilkan Leaderboard\n");
    printf("[3] Pilih Metode Sorting\n");
    printf("[4] Cari Pemain\n");
    printf("[5] Hapus Pemain\n");
    printf("[6] Tampilkan BST Inorder\n");
    printf("[0] Keluar\n");
    printf("====================================================\n");
    printf("Pilih menu : ");
}
int main() {

    int pilihan;

    do {

        menu();
        scanf("%d", &pilihan);

        switch(pilihan) {

            case 1:
                tambahPemain();
                break;

            case 2:
                tampilLeaderboard();
                break;

            case 3:
                pilihSorting();
                break;

            case 4:
                cariPemain();
                break;

            case 5:
                hapusPemain();
                break;

case 6:
                printf("\n====================================\n");
                printf("      BST INORDER TRAVERSAL\n");
                printf("====================================\n");

                if(root == NULL)
                   printf("Belum ada data pemain!\n");
                else
                   inorderBST(root);
                break;

            case 0:
                printf("\nTerima kasih.\n");
                break;

            default:
                printf("\nMenu tidak tersedia!\n");
        }

    } while(pilihan != 0);

    return 0;
}
