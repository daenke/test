/*
 * Zahlen mit Radix-Suche plus führende Nullen.cpp
 *
 * Das Programm sucht nach Zahlen, in denen sich die Ziffern nicht wiederholen
 * und zählt lediglich diese, als zB: 12345, aber nicht 12342
 *
 *  Created on: 28.05.2022
 *      Author: ?? :)
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static int repeats(size_t i, bool pfn)
{
    unsigned char ziffernZaehler[10U] = {0};
    if (pfn) ziffernZaehler[0]++;
    do {
            if (ziffernZaehler[(i % 10U)]++ >= 1) {
                    return 0; // wenn nicht 0 in Zelle gab es schon vorher Treffer
            }				// damit ist Ziifer nicht mehr unique
    } while (i /= 10U);     // eine Stelle nach links rücken
    return 1;
}

int main() {
    int counter = 0; // zaehlt Zahlen ohne Wiederholungen von Ziffern in der Zahl
	size_t maxInt = 1000000000;

	printf("ZahlenMitRadix und führender Nullen:\n");
    for (size_t i=0; i<maxInt/10; ++i) { // für führende Nullen
            counter += repeats(i, true);
    }
    for (size_t i=0; i<maxInt; ++i) {
            counter += repeats(i, false);
    }

    printf("%d\n\r", counter);
    return 0;
}
