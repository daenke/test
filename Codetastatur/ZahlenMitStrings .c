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

int _main() {
		int counter = 0; // zaehlt Zahlen ohne Wiederholungen von Ziffern in der Zahl
		bool checker; // nur wenn true gab es keine Wiederholungen
		char zahl[20]="hallo";
		int strLen=0;

		printf("ZahlenMitString\n strlen vor äußerem for:\n");
		for (int i=1000; i<999999999; ++i) {
			checker = true;
			sprintf(zahl, "%d", i);

			strLen=strlen(zahl);
			for (int j=0; j<strLen; j++) {
				if (checker == false) break;
				for (int k=1+j; k<strLen; k++) {
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
