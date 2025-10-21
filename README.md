# 🔢 Sorting Linked List in C

Program ini merupakan implementasi dari **tiga algoritma pengurutan (Bubble Sort, Selection Sort, dan Quick Sort)** pada struktur data **Linked List** menggunakan bahasa **C**.
Program ini juga mengukur **waktu eksekusi** setiap algoritma sorting untuk membantu memahami perbedaan efisiensi antar metode.

---

## 🧠 Deskripsi Proyek

Sorting atau pengurutan adalah salah satu operasi fundamental dalam ilmu komputer.
Pada umumnya, pengurutan dilakukan pada **array**, namun dalam proyek ini pengurutan diterapkan pada **linked list**.

Linked list memiliki karakteristik berbeda karena setiap elemen (node) saling terhubung menggunakan pointer.
Dengan demikian, algoritma sorting perlu disesuaikan agar bekerja berdasarkan pointer, bukan indeks seperti pada array.

Program ini memberikan pengguna opsi untuk:

1. Memasukkan data secara manual ke dalam linked list.
2. Memilih metode sorting yang diinginkan.
3. Menampilkan hasil pengurutan beserta waktu eksekusinya.

---

## ⚙️ Fitur Utama

* 📥 **Input Data**
  Pengguna dapat menambahkan sejumlah data integer ke dalam linked list.

* 🔄 **Tiga Jenis Sorting**

  * **Bubble Sort:** Mengulang proses pertukaran elemen bersebelahan hingga seluruh data terurut.
  * **Selection Sort:** Mencari elemen terkecil dari sisa list dan menukarnya ke posisi yang benar.
  * **Quick Sort:** Menggunakan metode rekursif dengan pembagian (partition) berdasarkan pivot.

* ⏱️ **Pengukuran Waktu Eksekusi**
  Program menampilkan waktu yang dibutuhkan setiap algoritma sorting menggunakan `clock()` dari `<time.h>`.

* 🧹 **Pembersihan Memori (Free List)**
  Setelah program selesai, seluruh node akan dihapus dari memori menggunakan `free()` untuk mencegah memory leak.

---

## 🧩 Struktur Data

Program menggunakan **doubly linked list** dengan struktur berikut:

```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```

Setiap node berisi:

* `data` → nilai integer yang disimpan.
* `next` → pointer ke node berikutnya.
* `prev` → pointer ke node sebelumnya (digunakan dalam Quick Sort).

---

## 🗂️ Alur Program

1. Program menampilkan menu:

   ```
   1. Masukkan data
   2. Pilihan Sorting
   3. Exit
   ```
2. Pengguna dapat memasukkan beberapa data integer ke dalam linked list.
3. Setelah data dimasukkan, pengguna memilih algoritma sorting:

   * a. Bubble Sort
   * b. Selection Sort
   * c. Quick Sort
4. Program akan mengurutkan data, menampilkan hasilnya, dan menunjukkan waktu proses dalam detik.
5. Pengguna dapat kembali ke menu utama atau keluar dari program.

---

## 🧪 Contoh Output

```
Menu:
1. Masukkan data
2. Pilihan Sorting
3. Exit
Pilihan Anda: 1
Masukkan jumlah data yang ingin dimasukkan: 5
Masukkan 5 data:
5 3 1 4 2

Menu:
1. Masukkan data
2. Pilihan Sorting
3. Exit
Pilihan Anda: 2
Pilihan Sorting:
a. Bubble Sort
b. Selection Sort
c. Quick Sort
Pilihan Anda: a
Linked list setelah Bubble Sort:
1 2 3 4 5
Waktu yang dibutuhkan: 0.000012 detik
```

---

## 💻 Cara Menjalankan Program

### 1️⃣ Kompilasi Program

Gunakan GCC untuk meng-compile:

```bash
gcc main.c -o sorting
```

### 2️⃣ Jalankan Program

```bash
./sorting
```

### 3️⃣ Ikuti Menu yang Ditampilkan di Terminal

---

## 📊 Perbandingan Kompleksitas Waktu

| Algoritma          | Kompleksitas Rata-rata | Kompleksitas Terburuk | Karakteristik Utama               |
| ------------------ | ---------------------- | --------------------- | --------------------------------- |
| **Bubble Sort**    | O(n²)                  | O(n²)                 | Mudah diimplementasikan           |
| **Selection Sort** | O(n²)                  | O(n²)                 | Stabilitas rendah, tapi sederhana |
| **Quick Sort**     | O(n log n)             | O(n²)                 | Efisien untuk data besar          |

---

## 🧑‍💻 Kontributor

**Nama:** Marcellus Geraldio Florenta
**NIM:** 2702262816
**Bahasa:** C

---

---

Apakah kamu mau saya bantu tambahkan bagian *preview hasil run* (contoh screenshot terminal dengan hasil sorting)? Itu bisa bikin README-mu lebih menarik di GitHub.
