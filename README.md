# Sistem Leaderboard Game

Sistem Leaderboard Game adalah program berbasis CLI yang mensimulasikan pengelolaan data pemain dan peringkat pada sebuah game kompetitif menggunakan bahasa C. Program ini dirancang untuk menyelesaikan masalah nyata dalam pengelolaan data pemain yang tidak terstruktur, seperti lambatnya proses pencarian dan pengurutan skor ketika jumlah pemain terus bertambah. Pendekatan teknis yang digunakan menggabungkan tiga struktur data sekaligus — Array, Linked List, dan Binary Search Tree (BST) — sehingga setiap operasi dapat memanfaatkan keunggulan masing-masing struktur secara optimal.

Proyek ini dikembangkan sebagai bagian dari Ujian Akhir Semester Praktikum Struktur Data dan Algoritma, Program Studi Informatika, Fakultas MIPA, Universitas Syiah Kuala, 2025/2026.

---

## Struktur Data dan Algoritma yang Diimplementasikan

### Struktur Data

| Array | Penyimpanan utama data pemain secara statis untuk akses cepat berbasis indeks |

| Linked List (Singly) | Pengelolaan data pemain secara dinamis, mendukung penambahan dan penghapusan data tanpa pergeseran elemen |

| Binary Search Tree (BST) | Penyimpanan data pemain terurut berdasarkan skor secara otomatis, mendukung traversal inorder untuk menampilkan ranking |

### Algoritma

| Bubble Sort | O(n²) | Mengurutkan data pemain berdasarkan skor secara descending |

| Insertion Sort | O(n²) / O(n) best case | Mengurutkan data pemain, optimal untuk data yang hampir terurut |

| Selection Sort | O(n²) | Mengurutkan data pemain dengan jumlah swap minimum |

| Inorder Traversal BST | O(n) | Menampilkan seluruh data pemain berdasarkan urutan skor dari BST |

| Linear Search | O(n) | Mencari data pemain berdasarkan nama |

---

## Cara Menjalankan Program

### Prasyarat

- GCC versi 9.0 atau lebih baru
- Sistem operasi: Windows (dengan MinGW / Command Prompt), Linux, atau macOS

### Kompilasi

```bash
gcc -o leaderboard leaderboard.c
```

### Jalankan

```bash
./leaderboard
```

> Pada Windows menggunakan Command Prompt:
> ```
> leaderboard.exe
> ```

### Catatan

Seluruh kode program terdapat dalam satu file `leaderboard.c`. Tidak diperlukan Makefile atau file tambahan untuk kompilasi.

---

## Tampilan Program

```
====================================================
            SISTEM LEADERBOARD GAME
====================================================
[1] Tambah Pemain Baru
[2] Tampilkan Leaderboard
[3] Pilih Metode Sorting
[4] Cari Pemain
[5] Hapus Pemain
[6] Tampilkan BST Inorder
[0] Keluar
====================================================
Pilih menu :
```

Menu sorting (pilihan 3):

```
=== PILIH METODE SORTING ===
1. Bubble Sort
2. Insertion Sort
3. Selection Sort
Pilihan :
```

---

## Tim Pengembang

| Nama | Kontribusi Utama |
|---|---|
| Nawal Azqia | Penyusunan BAB I (latar belakang, rumusan masalah, tujuan, batasan masalah), koordinasi tim, dan revisi laporan |
| Naila Syakira Bahri | Analisis masalah (BAB III), perancangan flowchart sistem, penggabungan laporan, dan finalisasi dokumen |
| M. Hafidh Farras | Implementasi program (struktur data Array, Linked List, BST, algoritma sorting), debugging, dan integrasi antar modul |
| Alief Aqsha | Penyusunan rancangan jangka panjang (BAB V), roadmap pengembangan, identifikasi risiko, dan revisi laporan |

---

## Lisensi

Proyek ini dibuat untuk keperluan akademik dalam rangka Ujian Akhir Semester Praktikum Struktur Data dan Algoritma, Program Studi Informatika, Universitas Syiah Kuala. Bebas digunakan sebagai referensi pembelajaran dengan menyebutkan sumber.
