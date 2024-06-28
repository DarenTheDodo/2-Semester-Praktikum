#include <stdio.h>


struct Spieler {
    char arr[10][10];
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

int main() {
    struct Spieler spieler[2];
    int row, col, ships, spielerAnz;
//    char arr[10][10];



    printf("Anzahl der zu platzierenden Schiffe eingeben: \n");
    scanf("%i", &ships);

    printf("0 Solo, 1 Multiplayer? \n");
    scanf("%i", &spielerAnz);





    int i;
    for (i = 0; i <= spielerAnz; i++){
        fill_array(spieler[i].arr);
        build_structure(spieler[i].arr);
    }
    i = 0;
    while (i < ships) {
        int spielerfolge = 0;
        while (spielerfolge <= spielerAnz) {
            printf("\nSpieler %i:\n", spielerfolge+1);
            printf("\n Spieler %i:\n Schiff positions reihe eingeben: ", spielerfolge+1);
            scanf("%i", &row);

            printf("\n Spieler %i:\n Schiff positions Zeile eingeben: ", spielerfolge+1);
            scanf("%i", &col);


            place_ship(spieler[spielerfolge].arr, row, col);
            print_arr(spieler[spielerfolge].arr);
            spielerfolge++;
        }
    i++;
        printf("%i von %i Shiffen platziert", i,ships);
    }
    return 0;
}
