 /*****************************************************************
 *  Datei:          VL1-schloss_knacken.c
 *  erstellt:       07.06.2022
 *  von wem:        erweitert von dani
 *  hhttps://wiki.freitagsrunde.org/C-Kurs/%C3%9Cbungsaufgaben
 *  Beschreibung:
 *    tbd
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool DEBUG= true;
unsigned int* abb;
unsigned int versuche = 0;

void generate(void);
int test(unsigned int);
char * bin2String(unsigned int);
unsigned int switchBit(int key, int whichBit);

int main (void) // zum Laufen in main umbenennen
{
	generate();
	unsigned int key = 0;

	/* Ab hier kannst du versuchen die Tür mit deinem Schlüssel zu knacken.
	 Verändere die Variable "Key" mit den dir bekannten bitweisen Operatoren,
	 die du in der Vorlesung kennengelernt hast.
	 Du kannst deinen Schlüssel dann mit der Funktion test() überprüfen,
	 welcher als Parameter übergeben wird.
	 Bitte beachte, dass sowohl Schlüssel als auch Schloss unsigned Integer sind.
	 */

	int i = 0;
	for(; i < 32 ; i++){/* für jedes Bit wird geprüft ob es richtig ist oder ob es getaucht werden muss*/

		int rightBits  = test(key);/* Anzahl der richtigen Bits bevor das i-te Bit getauscht wurde*/
		int newRightBits = test(switchBit(key,i));/* Anzahl der richtigen Bits nachdem das i-te Bit getauscht wurde*/

		//hier drunter den Breakpoint setzen zum Betrachten von key, DEBUG auf false
		if(newRightBits > rightBits)
		/* Wenn die Anzahl der richtigen Bits nach dem Tausch größer ist als vorher,
		 ist der Schluessel mit dem getauschten Bit der neue Schlüssel*/
			key=switchBit(key,i);
	}

	return 0;
}

/*Diese Funktion vertauscht das in whichBit übergebene Bit in dem übergebenen Schlüssel
 und liefert den so veränderten Schlüssel als Rückgabewert*/
unsigned int switchBit(int key , int whichBit)
{
	return key ^ (1<<whichBit);
}

/* Diese Funktion liefert die Anzahl der richtigen Bits des übergebenen Schlüssels zurück.
 Falls 32 zurückgeliefert wird, war der Schlüssel richtig und die Tür öffnet sich.
 */
int test(unsigned int toTest)
{
	int rightBits = 0;
	int i = 0;

	for(; i< 32 ; i++){
		unsigned int x = 1 << i; // 1, 2, 4, 8, 16, 32, 64...

		//hier drunter den Breakpoint setzen zum Betrachten von toTest
		if(! ~((toTest & x) ^ (*abb| ~x))){
                /* zu testen; Schlüsssel UND x betrachtet nur ein Bit (Maske vorrutschend)
                      0 bei Bit  == 0, z.B.: 0100 -> 4 bei Bit =1
                      alle anderen sind 0!!
                   ist das ungleich == XOR mit dem Bit im Schloss (muss ja ungleich sein für KORREKT)
                      diesmal geflippte Maske (== 1011) OR mit dem Bit im Schloss
                      nur wenn Bit im Schloss == 1 kommt es beim OR durch
                      alle anderen Bits werden zu 1!!(unterschiedlich zum Schlüssel), 4 ist nur interressant
                   im Flip danach werden die 0-en betrachtet und damit bleibt nur die 4
                */
			rightBits++;
		}

        //ab hier nur für Debug
        if (DEBUG) {
            printf("Bit-Nummer = %d Key = %u, richtige Bits = %d\n", i+1, toTest, rightBits);
            printf("            key: %42s \n", bin2String(toTest));
            printf("           goal: %42s \n", bin2String(*abb));
            unsigned int a=toTest & x; printf("   masked key a: %42s \n", bin2String(a));
            unsigned int b=*abb| ~x; printf("  masked goal b: %42s \n", bin2String(b));
            unsigned int c= (toTest & x) ^ (*abb| ~x); printf("XOR from both c: %42s \n", bin2String(c));
            unsigned int d= ~((toTest & x) ^ (*abb| ~x)); printf("  flipped XOR d: %42s \n", bin2String(d));
            unsigned int e= ! ~((toTest & x) ^ (*abb| ~x)); printf(" NOT from all e: %42s \n\n", bin2String(e));
        }
        // bis hier nur fuer Debug
	}
	if(rightBits == 32){
		printf ("\nGratulation !\n\n");
		printf ("Die Tuer ist offen.\n");
		printf ("So sahen Schluessel und Schloss aus \n");
		printf ("Schloss    : %42s \n", bin2String(*abb));
		printf ("Schluessel : %42s \n", bin2String(~*abb));
		exit(0);
	}else{
		printf ("%d . Versuch, %d richtige Bits \n\n", ++versuche, rightBits);
		return rightBits;
	}
}

/*Hier wird das zufällige Schloss generiert. Bitte nicht verändern sonst geht der Spaß verloren. */
void generate(void)
{
	printf ("\nSchloss wurde erstellt.\nViel Spass beim probieren.\n\n");
	unsigned int secret;
	abb = (unsigned int*) malloc (sizeof(unsigned int));
	srand ( time(NULL) );
	secret = rand();
	*abb = secret;
}

/*Konvertierungsfunktion zur Ausgabe der Binärrepräsentation einer Zahl*/
char * bin2String(unsigned int num)
{
	static char retbuf[43];
	int i =0;
	for(; i<43 ; i++){
		retbuf[i]='0'; //init mit 0

	}
	char *p; i=0;
	p = &retbuf[sizeof(retbuf)-1]; // ans ENDE VOM String zeigen
	*p = '\0'; // Stringabschluss
	do {
		*--p = "0123456789abcdef"[num % 2]; // nur die ersten 2 Zeichen werden benötigt..
		num /= 2;
        if ((++i)%4==0) *--p=' ';
        if (i%8==0) *--p=' ';
	} while(i < 43);
	return retbuf;
}
