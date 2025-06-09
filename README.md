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
-Menjalankan program 
 -Compile file .c ini untuk memulai permainan 
 -Program akan menghasilkan sebuah tampilan layar 
-Tampilan memunculkan tampilan pilihan  
 -Mulai 
 -Info
 -Keluar
-Jika ingin mengetahui info mengenai permainan maka pilih di menu awal adalah 2.info, jika sudah membaca info dalam permainan maka bisa mengetik ‘1’ untuk kembali ke menu sebelumnya 
-Jika ingin memulai permainan maka pilih 1. Mulai, setelah memilih mulai menampilkan pilihan: 
 -Menu pemain 
 -Mulai permainan 
 -Kembali ke menu sebelumnya
-Jika ingin melihat pemain maka memilih menu pemain, dan jika ingin kembali ke menu sebelumnya maka input angka 1 
-Jika ingin memulai permainan maka input 2. mulai permainan 
 -Saat sudah memilih mulai permainan akan menampilkan list giliran pemain 
 -Saat pemain 1 bermain maka, pemain yang lain tidak boleh melihat layar, kecuali pemain 1 
 -Pemain dapat melihat kartu yang ada di tangan dan yang kartu yang rekomendasikan 
 -pemain mennetukan kartu apa yang ingin di keluarkan sesua dengan kartu yang di rekomendasikan, jika ingin mengeluarkan kartu wild atau wild draw 4 , maka setelah memilih pemain harus mentukan warna apa yang ingin di keluarkan. 
 -Jika sudah mengeluarkan kartu maka pemain berganti dengan pemain selanjutnya, dan bergantian dengan pemain lain untuk melihat layar 
 -Jika pemain yang mengeluarkan skip maka, pemain selanjutnya terskip/di lewati. Jika pemain mengeluarkan kartu reverse maka arah giliran pemain berubah 
 -Jika pemain yang mengeluarkan kartu draw 2/4 maka pemain selanjutnya bertambah kartu dan terlewati  
 -Jika pemain yang mengeluarkan wild maka kartu dapat berubah sesuai dengan keinginan pemain. Dan pemain yang mengeluarkan wild draw 4 maka kartu dapat berubah warna dan pemain selanjutnya terkena efek skip dan bertambah kartu sebanyak 4. 
 -Jika pemain tidak mempunyai kartu yang sesuai dengan discard pile maka pemain tersebut mengambil kartu dari deck, dan permainan lanjut ke pemain selanjutnya 
 -Permainan ini terus berlanjut hingga salah satu pemain kartu yang di tangan sudah habis, maka pemain tersebut menang 
-Jika pemain sudah ada yang menang maka dapat pilihan untuk kembali ke menu sebelumnya sehingga jika ingin bermain lagi menginputkan 2 untuk mulai permainan. Jika tidak ingin melakukan bermain lagi maka dapat memilih 3 untuk kembali ke menu awal  
-Jika ingin keluar dari program maka memilih 3 dan akan keluar dari program 

 
