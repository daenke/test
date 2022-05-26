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
		int counter = 0; // zahlt Zahlen ohne Wiederholungen von Ziffern in der Zahl
		boolean checker; // nur wenn true gab es keine Wiederholungen
			
		System.out.println("Zahlen mit Strings plus führende Nullen:\n");
		
		for (int i=0; i<999999999 ; ++i) {
			checker = true;
			String zahl= Integer.toString(i);
				
			for (int j=0; j<zahl.length(); j++) {
				if (checker == false) break;
				for (int k=1+j; k<zahl.length(); k++) {
					if (zahl.charAt(j) == zahl.charAt(k)) {
						checker=false; break;
					}
				}
			}
			if ( checker == true) counter++;
			
			//ab hier für führende Nullen
			checker=true;
			if (zahl.length() < 9) {
				zahl = "0"+zahl;
				for (int j=0; j<zahl.length(); j++) {
					if (checker == false) break;
					for (int k=1+j; k<zahl.length(); k++) {
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
