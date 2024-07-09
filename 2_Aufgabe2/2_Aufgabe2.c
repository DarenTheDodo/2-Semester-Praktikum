#include <stdio.h>

void print_arr(char arr[10][10]) {
    //printf("   A  B  C  D  E  F  G  H  I  J  \n");
    int row;
    int col;
    for (col = 0; col < 10; col++) {
        for (row = 0; row < 10; row++) {
            if (row == 0 && col == 0) {
                printf("%c ", arr[row][col]);
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

void fill_array(char arr[10][10]) {
    int row;
    int col;
    for (col = 1; col < 10; col++) {
        for (row = 1; row < 10; row++) {
            arr[col][row] = '.';
        }
    }
}


int place_ship(char arr[10][10], int row, int col) {
    arr[row][col] = 'S';
    return 0;
}

int main() {
    int row;
    int col;
    char arr[10][10];
    printf("\n Schiff positions reihe eingeben: ");
    scanf("%i", &row);

    printf("\n Schiff positions Zeile eingeben: ");
    scanf("%i", &col);

    fill_array(arr);
    build_structure(arr);
    place_ship(arr, row, col);
    print_arr(arr);
    return 0;
}
