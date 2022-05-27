/*
 * Zahlen mit Strings plus fuehrende Nullen mit Ausdruck
 *
 * Das Programm sucht nach Zahlen, in denen sich die Ziffern nicht wiederholen
 * und zählt lediglich diese, als zB: 12345, aber nicht 12342
 *
 *  Created on: 27.05.2022
 *      Author: dani
 */

public class ZahlenMitStringsPFNmA {
	public static void main(String[] args) {
		int counter = 0; // zahlt Zahlen ohne Wiederholungen von Ziffern in der Zahl
		boolean checker; // nur wenn true gab es keine Wiederholungen
		int stringLength,stringMaxLength,intMax;
		
		intMax = 999;	// bis zu 9 stellig wurde betrachtet
		String zahl = Integer.toString(intMax);
		stringMaxLength = zahl.length();
			
		System.out.print("    Zahlen mit Strings plus führende Nullen:\n    \n    +\t");
		for (int i=1; i<11; i++) System.out.print(i+"\t");
		System.out.print("\n    \n    0\t");
		
		for (int i=0; i < intMax ; ++i) {
			checker = true;
			zahl = Integer.toString(i);
			stringLength = zahl.length();
				
			for (int j=0; j < stringLength; j++) {
				if (checker == false) break;
				for (int k=1+j; k < stringLength; k++) {
					if (zahl.charAt(j) == zahl.charAt(k)) {
						checker=false; break;
					}
				}
			}
			if ( checker == true) {
				counter++;
				System.out.print(zahl+"\t");
				if (counter%10==0) {
					System.out.print("\n    "+counter+"\t"); // die 4 Leerzeichen braucht es nur für werWeissWas
				}						// zur Formatierung damit es als Code erkannt wird
			}
			
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
				if ( checker == true) {
					counter++;			
					System.out.print(zahl+"\t");
					if (counter%10==0) {
						System.out.print("\n    "+counter+"\t");
					}
				}
			}
		}
		System.out.println("    \n    \n    Anzahl gültiger Codes = "+counter);
	}

}
