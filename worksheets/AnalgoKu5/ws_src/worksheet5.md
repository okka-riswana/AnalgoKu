# Worksheet 5

```
Nama  : Okka Riswana
NPM   : 140810180032
```

## Case 1

### Soal

Tentukan rekurensi dari algoritma tersebut, dan selesaikan rekurensinya menggunakan metode
recursion tree untuk membuktikan bahwa algoritma tersebut memiliki Big-O (n lg n)

### Jawaban
Recurrence relations-nya didapat $T(n) = 2T(\frac{n}{2}) + O(n)$. Menggunakan metode master karena $a = b^k$ didapat $O(n \log(n))$.


## Case 2

### Soal

Relasi rekurensi untuk algoritma rekursif di atas dapat ditulis seperti di bawah ini. C adalah konstanta.

$T(n) = 3T(\frac{n}{2}) + n$.

Selesaikan rekurensi tersebut dengan Metode Master

### Jawaban
Dari persamaan diatas dengan teorema master didapat $O(n^{\log(3)}) \approx O(n^{1.59})$

## Case 3

### Soal

Relasi rekurensi untuk algoritma rekursif di atas dapat ditulis seperti di bawah ini. C adalah konstanta.

$T(n) = 4T(\frac{n}{2}) + C$.

Selesaikan rekurensi tersebut dengan Metode Master

### Jawaban
Dari persamaan diatas didapat $a = 4, b = 2,$ dan $k = 1$, jadi sesuai teorema master:

$T(n) \in \Theta(n^{\log_{b}{a}})$ jika $a > b^k$, maka $T(n) \in \Theta(n^2)$.
