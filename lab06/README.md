# Ćwiczenia 6

## Tablice z hashowaniem

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 |Proszę zaimplementować następujące operacje na tablicy z haszowaniem: wstawianie, usuwanie, wyszukiwanie, reorganizacja (usunięcie kluczy zaznaczonych do skasowania)|[✓](../lab06/01.cpp "zad 1")|
|2 |Dana jest nieposortowana tablica `A[N]` oraz liczba x. Proszę napisać funkcję, która sprawdza na ile sposobów można przedstawić x jako sumę A[i] + A[j] takiego, że i < j|[✓](../lab06/02.cpp "zad 2")|
|3 |Fukcja hashująca dane osoby|[✓](../lab06/03.cpp "zad 3")|
|4 |Dana jest tablica hashująca wypełniona liczbami. Trzeba przebudować tablice, tak aby jak najwięcej elementów znajdowało się na pozycji, na której się hashuje|[✓](../lab06/04.cpp "zad 4")|

## Podsumowanie adresowań

| Adresowanie | Zalety | Wady |
| -- | -- | -- |
| Liniowe | mało pamięci, proste w implementacji, dobra kiedy hasze mają różne wartości | przy dużym wypełnieniu czas może wzrosnąć do O(n), tablica może się zapełnić |
| Listowe | tablica się nie zapełni, najszybsze przy dużym wypełnieniu tablicy, dobra gdy chcemy często usuwać klucze | dodatkowa pamięć, wolne przy długich listach | 
| Kwadratowe | dobre dla danych, które haszują się blisko siebie, mało pamięci, proste w implementacji | przy dużym wypełnieniu czas może wzrosnąć do O(n), może zapełnić tablice, przy dużym wypełnieniu może nie dodać elementu mimo, że będą wolne miejsca |