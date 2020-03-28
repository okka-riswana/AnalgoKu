# Analisis Algoritma Gale-Shapley

> Apakah jawaban Anda di Worksheet 01 dan Program sama persis? Jika Tidak? Kenapa?

Output program sama persis dengan yang menggunakan iterasi secara manual.
```
Amy     -       Yancey
Bertha  -       Victor
Clare   -       Zeus
Diane   -       Wyatt
Erika   -       Xavier
```

## Teorema

**Teorema 1.3**. Algoritma G-S berakhir setelah paling banyak $n^2$ iterasi menggunakan _While Loop_.

**Bukti**.
> $P(t) := \#\{\ (m, w)\ |$ `hasproposed`$(m, w)\ \}$

Pada setiap iterasi dalam loop. Kita punya $P(t) < P(t+1)$ karena
* Pada setiap iterasu, kita mengeksekusi `hasproposed`$(m, w) :=$ `true`,
* **kecuali**, ketika kita keluar dari loop saat instruksi pertama.

---

**Teorema 1.4**. Jika seorang pria bebas di beberapa titik dalam eksekusi algoritma, maka ada seorang wanita yang belum dia ajak bertunangan.

**Bukti**. (_dengan kontradiksi_)
Asumsikan bahwa seorang pria bebas dan sudah melamar ke setiap wanita.

Lakukan analisis dari persfektif si wanita:
* Kita si wanita sudah dilamar, dia tidak lagi bebas;
* antara dia tetap dalam pertunangannya yang saat ini, atau bertunangan
kepada pria yang mengajaknya jika pria itu lebih tinggi di peringkat preferensinya.

Dengan asumsi ini, diimplikasikan bahwa semua $n$ wanita sudah bertunangan.
Karena satu wanita dipasangkan hanya dengan satu pria, semua $n$ pria bertunangan.

Ini mengarah pada kontradiksi, sehingga anggapan itu **salah**.

---

**Teorema 1.5**. Himpunan $S$ yang dikembalikan saat terminasi adalah _Perfect Matching_.

**Bukti**. Pertama, kita memverifikasi bahwa himpunan pasangan sudah cocok melalui analisis dari sudut pandang seorang wanita.
Seorang wanita bisa bebas atau bertunangan hanya dengan satu pria, jadi setiap wanita hanya muncul sekali di himpunan. Seorang pria yang bertunangan, tidak melamar. Seorang pria bisa bebas atau bertunangan dengan satu wanita, sehingga setiap pria hanya muncul sekali di himpunan. Dengan dua kalimat sebelumnya, himpunan yang dikembalikan adalah yang cocok.

Kedua, kita menunjukkan bahwa himpunan ini _Perfect Matching_ dengan menggunakan **kontradiksi**.

Asumsikan algoritma berakhir dengan manusia bebas. Dengan _Lemma_ sebelumnya, ada seorang wanita yang yang belum dilamar oleh pria bebas itu. Tetapi algoritma hanya berakhir jika tidak ada pria yang belum melamar setiap wanita.

Ini bertentangan dengan asumsi, dengan itu kita memiliki _Perfect Matching_.

---

**Teorema 1.6**. Sebuah eksekusi algoritma G-S mengembalikan satu set pasanagan S. Set S adalah pasangan yang stabil.

**Bukti**. Dari _Lemma_ sebelumnya, kita punya _Perfect Matching_.
Kita akan membuktikan stabilitasnya dengan **kontradiksi**.

Asumsikan $(m, w), (m', w') \in S$ punya ketidakstabilan $(m, w')$: $m$ lebih memilih $w'$ ketimbang $w$ dan $w'$ lebih memilih $m$ ketimbang $m'$.

Lamaran terakhir dari $m$ adalah lamaran ke $w$. Apakah $m$ melamar ke $w'$?

* Jika $m$ **tidak** melamar $w'$, maka $w$ lebih tinggi di daftar preferensi $m$, dengan mengambil asumsi bahwa $m$ lebih memilih $w'$ ketimbang $w$.
* Jika $m$ telah melamar ke $w'$, maka
  * bisa berari bahwa $w'$ sudah bertunangan dengan $m''$ yang berperingkat lebih tinggi dari $m$, yang maka $w'$ menolak lamaran dari $m$;
  * atau $w'$ telah menerima lamaran dari $m''$ yang berperingkat lebih tinggi dari $m$, yang maka $w'$ bercerai dengan $m$.

Ini merupakan kontradiksi jika $m' = m''$. Jika $m' \neq m''$, maka $w'$ lebih memilih $m'$ daripada $m''$, $w'$ lebih memilih $m''$ daripada $m'$, dengan itu $w'$ memilih $m'$ ketimbang $m$.

Ini berkontradiksi dengan asumsi yang kita buat yaitu S adalah pasangan yang stabil.