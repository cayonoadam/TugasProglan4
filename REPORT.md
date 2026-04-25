# Laporan Praktikum Pemrograman: Simple STL & OOP

**Nama:** Adam Naufal Putra Cayono  
**NRP:** 5024251099  
**Departemen:** Teknik Komputer 

---

## 1. Pendahuluan
Program ini dirancang untuk mengklasifikasikan jenis segitiga berdasarkan tiga koordinat titik dalam ruang 2D/3D. Implementasi menggunakan paradigma **Object-Oriented Programming (OOP)** dengan memanfaatkan **Standard Template Library (STL)** `std::vector` untuk manajemen data dan **Namespace** untuk pengorganisasian kode yang lebih modular.

## 2. Struktur Kelas
Program terdiri dari dua kelas utama yang dibungkus dalam namespace `Geometry`:

### A. Kelas `Point2D`
Digunakan untuk merepresentasikan titik dalam koordinat $(x, y, z)$.
* **Atribut:** `_x`, `_y`, `_z` (float).
* **Fitur:** Getter/Setter dan *Operator Overloading* untuk operasi vektor dasar ($+$, $-$, $*$).

### B. Kelas `Triangle`
Digunakan untuk merepresentasikan objek segitiga yang terdiri dari tiga objek `Point2D`.
* **Metode Utama:** * `calculateDistance()`: Menghitung jarak Euclidean antar dua titik.
    * `getTriangleType()`: Menentukan klasifikasi segitiga.

## 3. Logika Perhitungan
Penentuan jenis segitiga dilakukan dengan menghitung panjang tiga sisi ($s1, s2, s3$) menggunakan rumus:

$$d = \sqrt{(x_2-x_1)^2 + (y_2-y_1)^2 + (z_2-z_1)^2}$$

Klasifikasi dilakukan dengan urutan prioritas sebagai berikut:
1.  **Sama Sisi:** Jika $s1 \approx s2 \approx s3$.
2.  **Siku-Siku:** Menggunakan Hukum Pythagoras $a^2 + b^2 \approx c^2$. Implementasi menggunakan `std::sort` pada kuadrat sisi untuk akurasi.
3.  **Sama Kaki:** Jika minimal ada dua sisi yang panjangnya sama.
4.  **Sembarang:** Jika tidak memenuhi kriteria di atas.

> **Catatan Teknis:** Program menggunakan nilai toleransi (Epsilon) sebesar $1e-4$ untuk mengantisipasi ketidaktelitian variabel `float` pada operasi akar kuadrat.

## 4. Implementasi Namespace
Sesuai instruksi untuk mendapatkan nilai tambahan, seluruh kelas dan fungsi didefinisikan di dalam `namespace Geometry`. Hal ini mencegah terjadinya *naming collision* dengan library standar atau library pihak ketiga lainnya.

Contoh penggunaan:
```cpp
using namespace Geometry;
Triangle t(p1, p2, p3);
```

## 5. Contoh Input dan Output
Berikut adalah hasil pengujian program menggunakan beberapa skenario koordinat:

| Input (3 Titik Koordinat) | Output Program | Keterangan |
| :--- | :--- | :--- |
| `0 0 0`, `3 0 0`, `0 4 0` | `siku-siku` | Sisi 3, 4, dan 5 |
| `0 0 0`, `2 0 0`, `1 1.732 0` | `sama sisi` | Sisi $\approx 2$ |
| `0 0 0`, `4 0 0`, `2 3 0` | `sama kaki` | Dua sisi sama panjang |
| `1 0 1`, `3 3 5`, `5 6 7` | `sembarang` | Tidak ada sisi sama/siku |

## 6. Kesimpulan
Program berhasil mengimplementasikan konsep OOP, STL `vector`, dan Namespace secara efektif. Penggunaan tipe data `float` memerlukan penanganan khusus berupa *epsilon comparison* agar logika perbandingan sisi tetap akurat.