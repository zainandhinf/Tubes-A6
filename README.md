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


## How To Play

1. Menjalankan program

* Compile file `.c` ini untuk memulai permainan
* Program akan menghasilkan sebuah tampilan layar

2. Tampilan memunculkan tampilan pilihan

* Mulai
* Info
* Keluar

3. Jika ingin mengetahui info mengenai permainan maka pilih di menu awal adalah `2. Info`, jika sudah membaca info dalam permainan maka bisa mengetik `1` untuk kembali ke menu sebelumnya

4. Jika ingin memulai permainan maka pilih `1. Mulai`, setelah memilih mulai akan menampilkan pilihan:

* Menu pemain
* Mulai permainan
* Kembali ke menu sebelumnya

5. Jika ingin melihat pemain maka memilih menu pemain, dan jika ingin kembali ke menu sebelumnya maka input angka `1`

6. Jika ingin memulai permainan maka input `2. Mulai Permainan`

* Saat sudah memilih mulai permainan akan menampilkan list giliran pemain
* Saat pemain 1 bermain maka pemain yang lain tidak boleh melihat layar, kecuali pemain 1
* Pemain dapat melihat kartu yang ada di tangan dan kartu yang direkomendasikan
* Pemain menentukan kartu apa yang ingin dikeluarkan sesuai dengan kartu yang direkomendasikan. Jika ingin mengeluarkan kartu Wild atau Wild Draw 4, maka setelah memilih pemain harus menentukan warna apa yang ingin dikeluarkan
* Jika sudah mengeluarkan kartu maka pemain berganti dengan pemain selanjutnya, dan bergantian dengan pemain lain untuk melihat layar
* Jika pemain mengeluarkan kartu Skip maka pemain selanjutnya terskip/dilewati. Jika pemain mengeluarkan kartu Reverse maka arah giliran pemain berubah
* Jika pemain mengeluarkan kartu Draw 2/4 maka pemain selanjutnya mendapat tambahan kartu dan dilewati
* Jika pemain mengeluarkan kartu Wild maka kartu dapat berubah sesuai dengan keinginan pemain. Dan jika pemain mengeluarkan Wild Draw 4 maka kartu dapat berubah warna dan pemain selanjutnya terkena efek Skip dan mendapat tambahan 4 kartu
* Jika pemain tidak mempunyai kartu yang sesuai dengan discard pile maka pemain tersebut mengambil kartu dari deck, dan permainan lanjut ke pemain selanjutnya
* Permainan ini terus berlanjut hingga salah satu pemain kehabisan kartu di tangan, maka pemain tersebut menang

7. Jika pemain sudah ada yang menang maka akan muncul pilihan untuk kembali ke menu sebelumnya, sehingga jika ingin bermain lagi dapat menginput `2` untuk mulai permainan. Jika tidak ingin bermain lagi maka dapat memilih `3` untuk kembali ke menu awal

8. Jika ingin keluar dari program maka pilih `3` dan program akan keluar

 
