/*
 * ZahlenMitStrings.cpp
 *
 * Das Programm sucht nach Zahlen, in denen sich die Ziffern nicht wiederholen
 * und zählt lediglich diese, als zB: 12345, aber nicht 12342
 *
 *  Created on: 23.05.2022
 *      Author: dani
 */

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
		int counter = 0; // zaehlt Zahlen ohne Wiederholungen von Ziffern in der Zahl
		bool checker; // nur wenn true gab es keine Wiederholungen
		char zahl[20]="hallo";

		for (int i=1000; i<999999999; ++i) {
			checker = true;
			sprintf(zahl, "%d", i);

			for (int j=0; j<(int)strlen(zahl); j++) {
				if (checker == false) break;
				for (int k=1+j; k<(int) strlen(zahl); k++) {
					if (zahl[j] == zahl[k]) {
						checker=false; break;
					}
				}
			}
			if ( checker == true) counter++;
	}
	printf("%d\n\r", counter);
	return 0;
}
