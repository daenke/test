 /*****************************************************************
 *  Datei:          VL1-01-pythagoras.c
 *  erstellt:       04.06.2022
 *  von wem:
 *  hhttps://wiki.freitagsrunde.org/C-Kurs/%C3%9Cbungsaufgaben
 *  Beschreibung:
 *    Ein Pythagoras-Triplet ist eine Menge von drei natürlichen Zahlen,
 *    für die gilt:
 *      a < b < c
 *      a² + b² = c²
 *    Zum Beispiel: 3² + 4² = 9 + 16 = 25 = 5².
 ******************************************************************/

#include <stdio.h>

int main(int argc, char **argv) {
    int a, b, c;
    for(a=0; a<998; a++) {
        for(b=a+1; b<999; b++) {
            for(c=b+1; c<1000; c++) {
                if(a*a+b*b==c*c && a+b+c<=1000) { // viele Lösungen
//                if(a*a+b*b==c*c && a+b+c==1000) { // eine Lösung
                    printf("Found: %d %d %d\n", a, b, c);
//                    return 0; // wegen viele Lösungen ausgegraut
                }
            }
        }
    }
    return 1;
}
