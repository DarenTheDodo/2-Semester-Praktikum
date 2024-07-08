// Kzande3s
// 2_Aufgabe4 (PQ Rechner-Called By Reference)
// p = 4, q = -5
// X1 = 1, X2= -5
//
// p = 2, q = 2
// Es gibt keine Nullstellen
//
// p = -6, q = 9
// X1= 3 X2= 3

#include <stdio.h>
#include <math.h>


int pqformel(double p, double q, double *x1, double *x2) {
    int anz;
    double root;

    //Teil der PQ formel unter der Wurzel
    root = ((p * p) / (2 * 2) - q);

    //Nullstellen prüfen
    if (root == 0) {
        //Ersetze p durch die Nullstelle um Speicher zu sparen
        *x1 = -p / 2;
        anz = 1;
    } else if (root < 0) {
        anz = 0;
    } else {
        root = sqrt(root);
//        //Ersetze p und q durch die Nullstelle um Speicher zu sparen
//        //Wichtig zuerst q damit man bei der Zweiten Rechnung nicht mit X1 weiter rechnet
//        q = (-p / 2) + root;
//        p = (-p / 2) - root;
        *x1 = (-p / 2) + root;
        *x2 = (-p / 2) - root;
        anz = 2;
    }
    return anz;
}

int main() {
    double p, q,x1,x2;
    int anz;
    // Scan PQ Input
    printf("p: ");
    scanf("%lf", &p);

    printf("q: ");
    scanf("%lf", &q);

    anz = pqformel(p, q, &x1, &x2);

    printf("Anzahl Nullstellen: %i\n", anz);

    if (anz == 0) {
        printf("Keine Nullstellen Gefunden\n");
    } else if (anz == 1) {
        printf("X =  %lf\n", x1);
    } else {
        printf("X1 = %lf\n", x1);
        printf("X2 = %lf\n", x2);
    }

//    switch (anz) {
//        case 0:
//        break;
//        case 1:
//            printf("X = %lf\n", p);
//
//        break;
//        case 2:
//            printf("X1 = %lf\n", q);
//            printf("X2 = %lf\n", p);
//
//        break;
//    }
    return 0;
}
