// Kzande3s
// 2_Aufgabe3 (Vorlesung FelderStringsZeiger)


#include <stdio.h>


int main() {
    int *weltmeisterschaft[4];
    int spielzeit;
    int tore[] = {1, 7, 1};
    int weltmeister[] = {1954, 1974, 1990, 2014};
    char gewinner[] = {'D', 'E', 'U', 'T', 'S', 'C', 'H', 'L', 'A', 'N', 'D'};
    int neuer[] = {27, 3, 1986, 52};

    spielzeit = 120;
    weltmeisterschaft[2] = &spielzeit;
    *weltmeisterschaft = tore;
    weltmeisterschaft[3] = weltmeister;
    *(weltmeisterschaft + 1) = &neuer[0];

    printf("%c\n", *(gewinner + 2));
    printf("%i\n", *(weltmeisterschaft + 1));
    printf("%i\n", **(weltmeisterschaft));
    printf("%i\n", *(weltmeisterschaft[3] + 1));
    printf("%c\n", gewinner[1]);
    printf("%i\n", weltmeisterschaft[2][1]);
    printf("%i\n", *(*(weltmeisterschaft + 1) + 1));

    return 0;
}