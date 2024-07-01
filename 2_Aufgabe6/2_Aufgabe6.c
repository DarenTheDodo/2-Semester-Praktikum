#include <stdio.h>


struct Spieler {
    char feld[10][10];
    char trefferFeld[10][10];
    int treffer;
};

void print_arr(char arr[10][10]) {
    //printf("   A  B  C  D  E  F  G  H  I  J  \n");
    int row;
    int col;
    for (col = 0; col < 10; col++) {
        for (row = 0; row < 10; row++) {
            if (row == 0 && col == 0) {
                printf(" %c ", arr[row][col]);
            } else {
                printf(" %c ", arr[row][col]);
            }
        }
        printf("\n");
    }
    printf("\n");

}

int build_structure(char arr[10][10]) {
    int i = 0;
    while (i < 10) {
        arr[i][0] = (char) (i + '0');
        i++;
    }
    i = 0;
    while (i < 10) {
        arr[0][i] = (char) (i + '0');
        i++;
    }
    return 0;
}

int fill_array(char arr[10][10]) {
    int row;
    int col;
    for (col = 1; col < 10; col++) {
        for (row = 1; row < 10; row++) {
            arr[col][row] = '.';
        }
    }
    return 0;
}


int place_ship(char arr[10][10], int row, int col) {
    arr[row][col] = 'S';
    return 0;
}

int check_hit(char trefferFeld[10][10], char gegner[10][10], int row, int col) {
    int hit;
    if (gegner[row][col] == 'S') {
        hit = 1;
        printf("TREFFER!\n");
        trefferFeld[row][col] = 'X';
    } else {
        hit = 0;
        printf("Danneben\n");
        trefferFeld[row][col] = 'O';
    };
    return hit;
}

int main() {
    struct Spieler spieler[2];
    int row, col, ships, spielerAnz;
//    char arr[10][10];



    printf("Anzahl der zu platzierenden Schiffe eingeben: \n");
    scanf("%i", &ships);

    printf("0 Solo, 1 Multiplayer? \n");
    scanf("%i", &spielerAnz);


    int i;
    for (i = 0; i <= spielerAnz; i++) {
        fill_array(spieler[i].feld);
        build_structure(spieler[i].feld);
        fill_array(spieler[i].trefferFeld);
        build_structure(spieler[i].trefferFeld);
        spieler[i].treffer=0;
    }
    i = 0;
    while (i < ships) {
        int spielerfolge = 0;
        while (spielerfolge <= spielerAnz) {

            printf("\nSpieler %i:\n", spielerfolge + 1);
            printf("\n Spieler %i:\n Schiff positions reihe eingeben: ", spielerfolge + 1);
            scanf("%i", &row);

            printf("\n Spieler %i:\n Schiff positions Zeile eingeben: ", spielerfolge + 1);
            scanf("%i", &col);


            place_ship(spieler[spielerfolge].feld, row, col);
            print_arr(spieler[spielerfolge].feld);
            spielerfolge++;
        }
        i++;
        printf("%i von %i Shiffen platziert\n\n\n\n\n\n\n\n", i, ships);
    }


    //Starte Spiele
    while (spieler[0].treffer < ships && spieler[1].treffer < ships) {
        int spielerfolge = 0;
        while (spielerfolge <= spielerAnz) {
            printf("Treffer Spieler %i\n", spielerfolge + 1);
            print_arr(spieler[spielerfolge].trefferFeld);

            printf("\nSpieler %i:\n", spielerfolge + 1);
            printf("\n Spieler %i:\n X: ", spielerfolge + 1);
            scanf("%i", &row);

            printf("\n Spieler %i:\n Y: ", spielerfolge + 1);
            scanf("%i", &col);

            if (spielerfolge == 1) {
                spieler[spielerfolge].treffer = spieler[spielerfolge].treffer +
                                                check_hit(spieler[spielerfolge].trefferFeld,
                                                          spieler[spielerfolge - 1].feld, row, col);
                i= spieler[spielerfolge].treffer;
                printf("%i von %i Schiffe getroffen\n", i , ships);
            } else if (spielerfolge == 0) {
                spieler[spielerfolge].treffer = spieler[spielerfolge].treffer +
                                                check_hit(spieler[spielerfolge].trefferFeld,
                                                          spieler[spielerfolge + 1].feld, row, col);
                i = spieler[spielerfolge].treffer;
                printf("%i von %i Schiffe getroffen\n", i , ships);
            }

            print_arr(spieler[spielerfolge].trefferFeld);

            spielerfolge++;
        }
    }
    printf("\nSpiel vorbei es wurden alle schiffe versenkt");

    return 0;
}
