// Kzande3s
// 2_Aufgabe5
//X1:3
//Y1:5
//X2:1
//Y2:7
//Real Teil: 4.000000
//Imaginär Teil: i12.000000
//X1:-3
//Y1:-4
//X2:1
//Y2:7
//Real Teil: -2.000000
//Imaginär Teil: i3.000000
//X1:-3
//Y1:-6
//X2:-1
//Y2:-3
//Real Teil: -4.000000
//Imaginär Teil: i-9.000000

#include <stdio.h>

struct Komplex {
    double x;
    double y;
};


struct Komplex addiereKomlex(struct Komplex zahl1, struct Komplex zahl2) {
    struct Komplex zahl3;
    zahl3.x = zahl1.x+zahl2.x;
    zahl3.y = zahl1.y+zahl2.y;
    return zahl3;
}

int main(void) {
    struct Komplex zahl1,zahl2,zahl3;
    //Scan Numbers
    printf("X1:");
    scanf("%lf", &zahl1.x);
    printf("Y1:");
    scanf("%lf", &zahl1.y);

    printf("X2:");
    scanf("%lf", &zahl2.x);
    printf("Y2:");
    scanf("%lf", &zahl2.y);


    zahl3 = addiereKomlex(zahl1,zahl2);
    printf("Real Teil: %lf\n", zahl3.x);
    printf("Imagin\x84r Teil: i%lf\n", zahl3.y);
    return 0;
}
