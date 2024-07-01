#include <stdio.h>
#include <stdlib.h>
//Definition der Liste
struct Listenelement {
    int wert;
    struct Listenelement *nachfolger;
};

//Definition der Funktionen: anlegenListe, einfuegenDavorInListe, loeschenInListe,ausgebenListe
struct Listenelement *anlegenListe() {

    //erstellen des Listenelements *e0 und *e1, die größe abfragen und mit malloc das Listenelement in der größe deklarieren.
    struct Listenelement *e0 = malloc(sizeof(struct Listenelement));
    struct Listenelement *e1 = malloc(sizeof(struct Listenelement));
    e0->wert = 0;//interpretiert als Anfang
    e0->nachfolger = e1;
    e1->wert = 1;
    e1->nachfolger = NULL;
    return e0;
}

void einfuegenDavorInListe(struct Listenelement *liste, int position, int neuerWert) {

    struct Listenelement *neuesElement;
    int i = 1;
    // Testen ob ob der Listen platz belegt ist
    while (liste != NULL) {
        if (i == position) {

            neuesElement = malloc(sizeof(struct Listenelement));
            neuesElement->wert = neuerWert;
            neuesElement->nachfolger = liste->nachfolger;
            liste->nachfolger = neuesElement;
        }
        liste = liste->nachfolger;
        i = i + 1;
    }
}

void loeschenInListe(struct Listenelement *liste, int position) {
    int i = 1;
    //deklarieren eines Neuen hilfslisten konstrukt
    struct Listenelement *hilf;
    while (liste != NULL) {
        if (i == position) {
            hilf = liste->nachfolger;
            liste->nachfolger = liste->nachfolger->nachfolger;
//Freigabe des Speichers des Elementes, dass man
//aus der Liste löschen will
            free(hilf);
        }
        liste = liste->nachfolger;
        i = i + 1;
    }
}


void ausgebenListe(struct Listenelement *liste) {
    // laden des nächsen listen elements
    liste = liste->nachfolger;
    while (liste != NULL) {
//Datenteil des Listenelementes ausgeben
        printf("Element: %i\n", liste->wert);
        liste = liste->nachfolger;
    }
}

//Deklaraion der Funktion und übergabe der benutzten variablen
void ausgebenPosition(struct Listenelement *liste, int position) {
    //Deklaration des Index
    int i = 1;
    while (liste != NULL){
        //Falls i der übergebenen Position entspricht.
        if (i == position){
            //Ausgabe der Liste an der Stelle des Eingegeben und Übergebenen Index i
            printf("Element: %i\n", liste->wert);

        }
        //Gehe zum nächsten listen element.
        liste = liste->nachfolger;
        //Index erhöhen
        i++;
    }

}


int main(void) {
    // Deklaration der Liste
    struct Listenelement *liste;
    liste = anlegenListe();

    //Deklaration des zu suchenden Index
    int i = 0;

    //
    while(i < 50){
        einfuegenDavorInListe(liste, i,i);
        //Hochzählen whileschleife
        i++;
    }
    //Funktions aufruf der ausgebenListe funktion und übergabe der liste
    ausgebenListe(liste);

    //Ausgabe der Frage an wo gesucht werden soll
    printf("Position eingeben: ");

    //Input scan des Index und eingabe in dem int i speichern
    scanf("%i", &i);

    //Funktions aufruf der Funktion zum auslesen eines Bestimmten platzes in der Liste
    ausgebenPosition(liste,i);



    //Return wert der Main Funktion (hier standart mäßig 0 da wir keinen Wert übergeben wollen)
    //(alternativ Daklariere die Main funktion als Void um keinen Wert zu übergeben).
    return 0;
}
