/*
 * ZahlenMitStringsPlusFuehrendeNullen
 *
 * Das Programm sucht nach Zahlen, in denen sich die Ziffern nicht wiederholen
 * und zählt lediglich diese, als zB: 12345, aber nicht 12342
 *
 *  Created on: 26.05.2022
 *      Author: dani
 */

public class ZahlenMitStringsPFN {
	public static void main(String[] args) {
		long counter = 0; // zahlt Zahlen ohne Wiederholungen von Ziffern in der Zahl
		boolean checker; // nur wenn true gab es keine Wiederholungen
		int stringLength,stringMaxLength;
		long intMax;
		
		intMax = 999999999; intMax*=10; intMax+=9;intMax*=10; intMax+=9;
		  // bis zu 11-stellig wurde betrachtet aber Literale gehen nur bis 9-stellig
		String zahl = Long.toString(intMax);
		stringMaxLength = zahl.length();
			
		System.out.println("Zahlen mit Strings plus führende Nullen:\n");
		
		for (long i=0; i < intMax ; ++i) {
			checker = true;
			zahl = Long.toString(i);
			stringLength = zahl.length();
				
			for (int j=0; j < stringLength; j++) {
				if (checker == false) break;
				for (int k=1+j; k < stringLength; k++) {
					if (zahl.charAt(j) == zahl.charAt(k)) {
						checker=false; break;
					}
				}
			}
			if ( checker == true) counter++;
			
			//ab hier für führende Nullen
			checker=true;
			if (zahl.length() < stringMaxLength) {
				zahl = "0"+zahl;
				stringLength = zahl.length();

				for (int j=0; j < stringLength; j++) {
					if (checker == false) break;
					for (int k=1+j; k < stringLength; k++) {
						if (zahl.charAt(j) == zahl.charAt(k)) {
							checker=false; break;
						}
					}
				}
				if ( checker == true) counter++;			
			}
		}
		System.out.println(counter);
	}

}
