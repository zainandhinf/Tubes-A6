# UNO Game in C

Game UNO versi konsol sederhana yang dikembangkan dalam bahasa C sebagai latihan implementasi berbagai struktur data. Proyek ini menggunakan **Linked List**, **Queue**, **Stack**, **Binary Tree**, dan **Non-Binary Tree** untuk mengatur logika permainan.

## Fitur Utama

- Mode permainan Player vs Player
- Pemrosesan giliran menggunakan **Queue**
- Penyimpanan kartu tangan pemain menggunakan **Binary Tree**
- Pembuatan rekomendasi kombinasi kartu menggunakan **Non-Binary Tree** 
- Daftar kartu pada deck dan discard pile menggunakan **Stack**

## Struktur Data yang Digunakan

| Struktur Data   | Penggunaan                                               |
|-----------------|----------------------------------------------------------|
| Linked List     | Merepresentasi pemain dengan double linked list          |
|                 | Menyimpan rekomendasi dalam bentuk single linked list    |
| Queue           | Mengatur giliran pemain                                  |
| Stack           | Mengatur deck dan discard pile                           |
| Binary Tree     | Mengatur kartu di tangan pemain                          |
| Non-Binary Tree | Mengatur rekomendasi dan kombo yang bisa dimainkan       |

