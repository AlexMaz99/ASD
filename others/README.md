# Inne zadania

## Zadania przygotowujące do 1 kartkówki
| Nr| Polecenie |
|--|--|
|[1](../others/01.cpp "zad 1") |Dana jest struktura opisująca listę jednokierunkową dla liczb rzeczywistych: `struct Node{ Node* next; double value;}` Proszę zaimplementować funkcję `void Sort( Node* list )`, która otrzymuje na wejściu listę liczb rzeczywistych (z wartownikiem), wygenerowaną zgodnie z rozkładem jednostajnym na przedziale [0,10) i sortuje jej zawartość w kolejności niemalejącej|
|[2](02'.cpp "zad 2") |Proszę zaimplementować funkcję: `int SumBetween(int T[], int from, int to, int n);` Zadaniem tej funkcji jest obliczyć sumę liczb z n elementowej tablicy T, które w posortowanej tablicy znajdywałyby się na pozycjach o indeksach od from do to (włącznie). Można przyjąć, że liczby w tablicy T są parami różne (ale nie można przyjmować żadnego innego rozkładu danych)|
|[3](../others/03.cpp "zad 3") |Proszę napisać jak najszybszy algorytm, który otrzymuje na wejściu pewien ciąg n liter oraz liczbę k i wypisuje najczęściej powtarzający się podciag długości k (jeśli ciągów mogących stanowić rozwiązanie jest kilka, algorytm zwraca dowolny z nich). Można założyć, że ciąg składa się wyłacznie z liter a i b. Na przykład dla ciągu ababaaaabb oraz k = 3 rozwiązaniem jest ciąg aba, który powtarza się dwa razy (to, że te wystąpienia na siebie nachodzą nie jest istotne)|
|[4](../others/04.cpp "zad 4") |Dana jest n elementowa tablica A zawierająca liczby naturalne (potencjalnie bardzo duże). Wiadomo, że tablica A powstała w dwóch krokach. Najpierw wygenerowano losowo (z nieznanym rozkładem) n różnych liczb nieparzystych i posortowano je rosnąco. Następnie wybrano losowo logn elementów powstałej tablicy i zamieniono je na losowo wybrane liczby parzyste. Proszę zaproponować algorytm sortowania tak powstałych danych|
|[5](../others/05.cpp "zad 5") |Dana jest struktura `Node` opisująca listę jednokierunkową: `struct Node { Node * next; int value;}` Proszę zaimplementować funkcję `Node* fixSortedList( Node* L )`, która otrzymuje na wejściu listę jednokierunkową bez wartownika. Lista ta jest prawie posortowana w tym sensie, że powstała z listy posortowanej przez zmianę jednego losowo wybranego elementu na losową wartość. Funkcja powinna przepiąć elementy listy tak, by lista stała się posortowana i zwrócić wskaźnik do głowy tej listy. Można założyć, że wszystkie liczby na liście są różne i że lista ma co najmniej dwa elementy. Funkcja powinna działać w czasie liniowym względem długości listy wejściowej|
|[6](../others/06.cpp "zad 6") |Napisać funkcję: `void sortString(string A[]);` Funkcja sortuje tablicę n stringów różnej długości. Można założyć, że stringi składają się wyłącznie z małych liter alfabetu łacińskiego.|
|[7](../others/07.cpp "zad 7") |Dane są następujące struktury: `struct Node { Node* next; int val;}` `struct TwoLists { Node* even; Node* odd; }` Napisać funkcję: `TwoLists split(Node* list);` Funkcja rozdziela listę na dwie: jedną zawierającą liczby parzyste i drugą zawierającą liczby nieparzyste. Listy nie zawierają wartowników.|
|[8](../others/08.cpp "zad 8") |Jak posortować n-elementową tablicę liczb rzeczywistych, które przyjmują tylko logn różnych wartości?|
|[9](../others/09.cpp "zad 9") |Proszę napisać funkcję `bool possible( char* u, char* v, char* w )`, która zwraca prawdę jeśli z liter słów u i v da się ułożyć słowo w (nie jest konieczne wykorzystanie wszystkich liter) oraz fałsz w przeciwnym wypadku. Można założyć, że w i v składają się wyłącznie z małych liter alfabetu łacińskiego|
|[10](../others/10.cpp "zad 10") |Otrzymujemy tablicę składającą się z n liczb całkowitych i liczby całkowitej k. Proszę wyszukać odpowiedź na pytanie czy w tablicy znajduje się zakres kolejnych liczb całkowitych o długości k|
|[11](../others/11.cpp "zad 11") |Proszę zaimplementować funkcję `double AverageScore (double A[], int n, int lowest, int highest);` Funkcja ta przyjmuje na wejściu tablicę n liczb rzeczywistych (ich rozkład nie jest znany, ale wszystkie są parami różne) i zwraca średnią wartość podanych liczb po odrzuceniu `lowest` najmniejszych oraz `highest` najwiekszych. Zaimplementowana funkcja powinna być możliwie jak najszybsza|
|[12](../others/12.cpp "zad 12") |Proszę zaimplementować funkcję `int findDistrict (int A[], int n);` Funkcja ta przyjmuje na wejściu posortowaną tablicę n liczb całkowitych, w której mogą pojawiać sie duplikaty. Funckja powinna zliczać ilość wystąpień różnych wartości bezwzględnych elementów występujących w tej tablicy|
|[13](../others/13.cpp "zad 13") |Do szkoły chodzi 2n dzieci. Połowa z nich należy do grupy niebieskiej a połowa do grupy zielonej. Na apelu dzieci miały się ustawić podzielone na grupy, najpierw grupa zielona a potem grupa niebieska. Niestety nauczyciel zapomniał im o tym powiedzieć i teraz stoją w szeregu przypadkowo (z odstępami jednego metra między kolejnymi dziećmi). Szereg reprezentowany jest jako lista struktur typu: `struct Pupil { int group; Pupiln *next; };` gdzie `group` to grupa (1 to niebiescy a 0 to zieloni) a `next` to wskaźnik pokazujący kolejną osobę w szeregu. Proszę zaimplementować funkcję `int distanceToIdeal (Pupil *L)`, która oblicza najmniejszą liczbę metrów jaką dzieci muszą sumarycznie przejść, żeby te z grupy zielonej stały przed tymi z grupy niebieskiej (i żeby cały szereg wciąż stał w tym samym miejscu). W zadaniu nie wymaga się sortowania listy|
|[14](../others/14.cpp "zad 14") |Posortowany niemalejąco ciąg n^2 liczb został pocięty na n kawałków, każdy o długości n elementów. Następnie kawałki te zostały umieszczone w tablicy `int A[n*n]` w przypadkowej kolejności. Proszę zaimplementować funkcję: `void sortNNsequence(int A[], int n)` która sortuje tablicę A nierosnąco|

## Zadania przygotowujące do 2 kartkówki
| Nr| Polecenie |
|--|--|
|[15](../others/15.cpp "zad 15") |Student chce wypuścić n różnych pokemonów (numerowanych od 0 do n − 1) z klatek (pokeball’i). Wypuszczony Pokemon natychmiast atakuje swojego wybawiciela, chyba że (a) jest spokojny, lub (b) w okolicy znajdują się co najmniej dwa uwolnione pokemony, na które ten pokemon poluje. Proszę zaimplementować funkcję: `int* releaseThemAll( HuntingList* list, int n )`, gdzie `list` to lista z informacją, które pokemony polują na które (lista nie zawiera powtórzeń): `struct HuntingList { HuntingList* next; //* nastepny element listy*/ int predator; /* numer pokemona, który poluje */ int prey; } /* numer pokemona, na którego poluje */` Funkcja powinna zwrócić n elementową tablicę z numerami pokemonów w kolejności wypuszczania (tak, żeby wypuszczający nie został zaatakowany) lub NULL jesli taka kolejność nie istnieje. Każdy wypuszczony pokemon zostaje ”w okolicy”. Jeśli pokemon nie występuje na liście jako predator to znaczy, że jest spokojny|
|[16](../others/16.cpp "zad 16") |Dana jest struktura `struct HT{ int* table; int size; }`, która opisuje tablicę haszującą rozmiaru `size`, przechowującą liczby nieujemne. Tablica korzysta z funkcji haszującej `int hash(int x)` i liniowego rozwiązywania konfliktów (ujemne wartości w tablicy `table` oznaczają wolne pola). Doskonałością takiej tablicy nazywamy liczbę elementów x takich, że pozycja x w tablicy to hash(x) mod size (a więc x jest na ”swojej” pozycji). Proszę napisać funkcję: `void enlarge( HT* ht);` która powiększa tablicę dwukrotnie i wpisuje elementy w takiej kolejności, by doskonałość powstałej tablicy była jak największa|
|[17](../others/17.cpp "zad 17") |Dane są struktury danych opisujące SkipListe: `struct SLNode { int value; /* wartość przechowywana w węźle */ int level; /* poziom węzła */ SLNode** next; /* level-elementowa tablica wskaźników na następniki */ };` oraz `struct SkipList { SLNode* first; /* wartownik przedni (pole value ma wartość -1) */ SLNode* last; /* wartownik tylni (pole value ma wartość +1) */ };` `const int MAX LEVEL = ... ; // maksymalny poziom węzłów` Proszę zaimplementować funkcję `SkipList merge( SkipList A, SkipList B )`, która scala dwie otrzymane SkipListy (w efekcie powstaje nowa SkipLista składająca się z dokładnie tych samych węzłów co poprzednie; nie nalezy zmieniać poziomów węzłów). Węzły wartowników mają poziom MAX LEVEL|
|[18](../others/18.cpp "zad 18") |W ramach obchodów międzynarodowego święta cyklistów organizatorzy przewidzieli górską wycieczkę rowerową. Będzie się ona odbywać po bardzo wąskiej ścieżce, na której rowery mogą jechać tylko jeden za drugim. W ramach zapewnienia bezpieczeństwa każdy rowerzysta będzie miał numer identyfikacyjny oraz małe urządzenie, przez które będzie mógł przekazać identyfikator rowerzysty przed nim (lub -1 jeśli nie widzi przed sobć nikogo). Należy napisać funkcję, która na wejściu otrzymuje informacje wysłane przez rowerzystów i oblicza rozmiar najmniejszej grupy (organizatorzy obawiają się, że na małe grupy mogłyby napadać dzikie zwierzęta). Dane są następujące struktury danych: `struct Cyclist { int id, n_id; // identyfikator rowerzysty oraz tego, którego widzi };` Funkcja powinna mieć prototyp `int smallestGroup( Cyclist cyclist[], int n )`, gdzie `cyclist` to tablica `n` rowerzystów. Funkcja powinna być możliwie jak najszybsza. Można założyć, że identyfikatory rowerzystów to liczby z zakresu 0 do 108 (osiem cyfr napisanych w dwóch rzędach na koszulce rowerzysty) i że pamięć nie jest ograniczona. Rowerzystów jest jednak dużo mniej niż identyfikatorów (nie bez powodu boją się dzikich zwierząt). Należy zaimplementować wszystkie potrzebne struktury danych|
|[19](../others/19.cpp "zad 19") |Pewna firma przechowuje dużo iczb pierwszych w postaci binarnej jako stringi ”10101...”. Zaimplementuj strukturę danych `Set` do przechowywania tych danych. Napisz funkcje: `Set createSet( string A[], int n )`, która tworzy `Set` z n-elementowej tablicy stringów oraz `bool contains( Set a, string s )`, która sprawdza czy dana liczba jest w Secie|
|[20](../others/20.cpp "zad 20") |Zaproponuj algorytm, który policzy ile jest najkrótszych ścieżek w grafie z danego wierzchołka u do v. Wskazówka: Dla każdej najkrótszej ścieżki przechodzącej przez wierzchołek w, odległość w od startu jest taka sama jak odległość w do mety|
|[21](../others/21.cpp "zad 21") |Proszę zaimplementować funkcję wstawiającą zadaną liczbę do SkipListy przechowującej dane typu int oraz analogiczną funkcję usuwającą|
|[22](23.cpp "zad 22") |Drzewo BST jest opisane przez strukturę `struct BST{ BST *left, *right; int value; };`. Proszę zaimplementować funkcję `int countInterval(BST *T, int a, int b)`, która oblicza ile liczb z zadanego przedziału domkniętego **[a,b]** znajduje się w drzewie **T**.|

## Zadania przygotowujące do 3 kartkówki
| Nr| Polecenie |
|--|--|
|[23](../others/23.cpp "zad 23") |Złodziej widzi na wystawie po kolei n przedmiotów o wartościach A[0], A[1], ..., A[n − 1]. Złodziej chce wybrać przedmioty o jak największej wartości, ale resztki przyzwoitości zabraniają mu ukraść dwa przedmioty leżące obok siebie. Proszę zaimplementować funkcję: `int goodThief( int A[], int n );` która zwraca maksymalną wartość przedmiotów, które złodziej może ukraść zgodnie ze swoim kodeksem moralnym oraz wypisuje numery przemiotów które powinien wybrać. Proszę uzasadnić poprawność algorytmu oraz oszacować jego złożoność czasową|