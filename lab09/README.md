# Ćwiczenia 9

## Drzewa B-tree

| Nr| Polecenie |Zrobione |
|--|--|--|
|1 |Dana jest tablica `bool A[N][N]`. Gracz początkowo znajduje się na zadanej pozycji (x,y), dla której zachodzi `A[y][x] == true`. Z danej pozycji wolno bezpośrednio przejść jedynie na pozycję, której dokładnie jedna współrzędna różni się o 1 oraz której wartość w tablicy A wynosi true. Proszę napisać funkcję obliczającą do ilu różnych pozycji możne dojść gracz startując z zadanej pozycji|[✓](../lab09/01.cpp "zad 1")|
|2 |Dana jest struktura węzła drzewa B-tree przechowującego unikalne klucze: `struct node{ int N; // liczba kluczy zawarta w węźle' 'int key[N]; //tablica kluczy w węźle` `node* child[N+1]; // wskaźniki do synów węzła` `bool leaf // czy węzeł jest liściem }`. Proszę napisać funkcję `bool is_b_tree(node* p)`, sprawdzającą czy wskaźnik p wskazuje na poprawne drzewo b_tree|[✓](../lab09/02.cpp "zad 2")|
|3 |Dany jest graf, a każda krawędź ma wagę. Trzeba usunąć krawędzie, tak aby graf pozostał pełny, a suma wag krawędzi była jak najmniejsza|[✓](../lab09/03.cpp "zad 3")|
|4 |Statek znajduje się na pozycji (x,y) i chce wpłynąć do portu (0,0). Zanurzenie statku wynosi t i statek może przepłynąć przez dane pole, jeśli głębokość wody w danym miejscu nie jest mniejsza niż jego zanurzenie. Czy statek może dopłynąć do portu? |[✓](../lab09/04.cpp "zad 4")|