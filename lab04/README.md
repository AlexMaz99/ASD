# Ćwiczenia 4

## Zastosowania sortowań

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 |Dana jest posortowana tablica `int A[N]` oraz liczba x. Napisać program, który stwierdza czy istnieją indeksy i oraz j, takie że A[i] + A[j] = x (Powinno działać w czasie O(N))|[✓](../lab04/01.cpp "zad 1")|
|2 |Zaimplementować algorytm, który dla tablicy `int A[N]` wyznacza rekurencyjną medianę median (magiczne piątki)|[✓](../lab04/02.cpp "zad 2")|
|3 |Mamy daną tablicę A z n liczbami. Proszę zaproponować algorytm o złożoności O(n), który stwierdza, czy w tablicy ponad połowa elementów ma jednakową wartość|[✓](../lab04/03.cpp "zad 3")|
|4 |Wyszukiwanie binarne - znajdowanie elementu o wartosci x w posortowanej tablicy|[✓](../lab04/04.cpp "zad 4")|
|5 |Znalezienie k-tego co do wielkości elementu w tablicy|[✓](../lab04/05.cpp "zad 5")|

## Podsumowanie sortowań

| Sortowanie | Złożoność optymistyczna | Złożoność pesymistyczna | Złożoność pamięciowa | Stabilność | Zalety | Wady |
|--|--|--|--|--|--|--|
|Bubble Sort| $n^2$ | $n^2$ | 1 | TAK | prosty i krótki kod | zawsze wykonuje tyle samo porównań | 