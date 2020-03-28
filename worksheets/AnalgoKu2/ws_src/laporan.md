# Worksheet 2

Nama: Okka Riswana

NPM: 140810180032

## Study Case 1: Max Integer

```cpp
uint64_t maks = data[0];    // 2 operasi
size_t i = 1;               // 2 operasi

while (i < data.size()) {   // 2 s.d n - 1 operasi
  if (data[i] > maks) {     // 1 s.d n - 2 operasi
    maks = data[i];         // 0 s.d. n - 2 operasi
  }
  i = i + 1;                // 1 s.d n - 2 operasi
}
```

Time Complexity:

* $\Omega(1)$
* $\Theta(n)$
* $O(n)$

---

## Study Case 2: Sequential Search

```cpp
size_t i = 0, idx;                  // 3 operasi
bool found = false;                 // 2 operasi

while (i < data.size() && !found) { // 2(3) s.d. 3(n + 1) operasi
  if (data[i] == target) {          // 1 s.d. n operasi
    found = true;                   // 0 s.d. 1  operasi
  } else {
    i = i + 1;                      // 0 s.d. 2n operasi
  }
}

if (found) {                        // 1 operasi
  idx = i;                          // 0 s.d 1 operasi
} else {
  idx = -1;                         // 0 s.d. operasi
}
```

Time Complexity:

* $\Omega(1)$
* $\Theta(n)$
* $O(n)$

---

## Study Case 3: Binary Search

```cpp
size_t i = 0, j = data.size(), mid, idx;
bool found = false;

while (i <= j && !found) {
  mid = (i + j) / 2;
  if (data[mid] == target) {
    found = true;
  } else {
    if (data[mid] < target) {
      i = mid + 1;
    } else {
      j = mid - 1;
    }
  }
}
```

Time Complexity:

* **Best Case**. Binary search akan langsung menemukan elemen yang dicari ditengah. Jadi kompleksitas waktunya adalah **konstan**.

* **Average Case**.

  Minimum internal path length: $\displaystyle I(n)=\sum _{k=1}^{n}\left\lfloor \log _{2}(k)\right\rfloor$

  Jumlah iterasi rata-rata: $\displaystyle T(n)=1+{\frac {I(n)}{n}}$

  $I(n)$ dapat diubah menjadi: ${\displaystyle I(n)=\sum _{k=1}^{n}\left\lfloor \log _{2}(k)\right\rfloor =(n+1)\left\lfloor \log _{2}(n+1)\right\rfloor -2^{\left\lfloor \log _{2}(n+1)\right\rfloor +1}+2}$

  Kemudian substitusikan $I(n)$ ke $T(n)$ untuk mendapatkan kompleksitas watu rata-rata:

  ${\displaystyle T(n)=1+{\frac {(n+1)\left\lfloor \log _{2}(n+1)\right\rfloor -2^{\left\lfloor \log _{2}(n+1)\right\rfloor +1}+2}{n}}=\frac{\lfloor \log _{2}(n)\rfloor +1-(2^{\lfloor \log _{2}(n)\rfloor +1}-\lfloor \log _{2}(n)\rfloor -2)}{n}}$

* **Worst Case**. Dimana elemen tidak ada atau gagal dicari.

  Minimum external path length adalah internal path length ditambah 2. Maka,

  ${\displaystyle E(n)=I(n)+2n=\left[(n+1)\left\lfloor \log _{2}(n+1)\right\rfloor -2^{\left\lfloor \log _{2}(n+1)\right\rfloor +1}+2\right]+2n}$
  
  $\displaystyle {E(n) = (n+1)(\lfloor \log _{2}(n)\rfloor +2)-2^{\lfloor \log _{2}(n)\rfloor +1}}$

  Jumlah iterasi rata-rata: ${\displaystyle T'(n)={\frac {E(n)}{n+1}}}$

  Kemudian substitusikan $E(n)$ ke $T'(n)$ untuk mendapatkan kompleksitas watu rata-rata:

  ${\displaystyle T'(n)={\frac {(n+1)(\lfloor \log _{2}(n)\rfloor +2)-2^{\lfloor \log _{2}(n)\rfloor +1}}{(n+1)}}=\lfloor \log _{2}(n)\rfloor +2-2^{\lfloor \log _{2}(n)\rfloor +1}/(n+1)}$

$\therefore$ Kompleksitas waktunya adalah:

* $\Omega(1)$
* $\Theta(log_{2}n)$
* $O(log_{2}n)$

---

## Study Case 4: Insertion Sort

```cpp
size_t i, j, imaks;
uint64_t temp;

for (i = data.size(); i > 1; --i) {
  imaks = 1;
  for (j = 1; j <= i; ++j) {
    if (data[j] > data[imaks]) {
      imaks = j;
    }
  }
  temp = data[i];
  data[i] = data[imaks];
  data[imaks] = temp;
}
```

Time Complexity:

* **Best Case**.

  $\displaystyle \sum_{i = 1}^{n - 1} 1 = n - 1$

  $\displaystyle \Omega(n)$

* **Average Case**.

  $\displaystyle \sum_{i=1}^{n-1} \frac{i+1}{2} = \frac{(n-1) \cdot n}{4} + \frac{n - 1}{2} = \frac{(n - 1)(n + 2)}{4}$

  $\displaystyle \Theta(n^2)$


* **Worst Case**.

  $\displaystyle \sum_{i=1}^{n-1} i = 1 + 2 + 3 + \ldots + (n - 1) = \frac{(n-1) \cdot n}{2}$

  $\displaystyle O(n^2)$

## Study Case 5: Selection Sort

```cpp
size_t i, j, imaks;
uint64_t temp;

for (i = data.size(); i > 1; --i) {
  imaks = 1;
  for (j = 1; j <= i; ++j) {
    if (data[j] > data[imaks]) {
      imaks = j;
    }
  }
  temp = data[i];
  data[i] = data[imaks];
  data[imaks] = temp;
}
```

Time Complexity:

* **Best Case**, **Average Case**, dan **Worst Case**.

  $\displaystyle \sum_{i = 0}^{n - 1} \sum_{j = i + 1}^{n - 1} 1 = n^2 - n$

  $\displaystyle \therefore \Omega(n^2), \Theta(n^2), O(n^2)$
