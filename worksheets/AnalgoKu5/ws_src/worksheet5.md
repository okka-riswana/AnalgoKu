# Worksheet 5

```
Nama  : Okka Riswana
NPM   : 140810180032
```

## Soal

Relasi rekurensi untuk algoritma rekursif di atas dapat ditulis seperti di bawah ini. C adalah konstanta.

$T(n) = 4T(\frac{n}{2}) + C$.

Selesaikan rekurensi tersebut dengan Metode Master

## Jawaban
Dari persamaan diatas didapat $a = 4, b = 2,$ dan $k = 1$, jadi sesuai teorema master:

$T(n) \in \Theta(n^{\log_{b}{a}})$ jika $a > b^k$, maka $T(n) \in \Theta(n^2)$.
