 /*****************************************************************
 *  Datei:          VL1-03-schloss_knacken.c
 *  erstellt:       07.06.2022
 *  von wem:
 *  hhttps://wiki.freitagsrunde.org/C-Kurs/%C3%9Cbungsaufgaben
 *  Beschreibung:
 *    tbd
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int* abb;
unsigned int versuche = 0;

void generate(void);
int test(unsigned int);
char * toBin(unsigned int);
unsigned int switchBit(int key, int whichBit);

int main (void)
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
		unsigned int x = 1 << i;
		if(! ~((toTest & x) ^ (*abb| ~x))){
			rightBits++;
		}
	}
	if(rightBits == 32){
		printf ("\nGratulation !\n\n");
		printf ("Die Tuer ist offen.\n");
		printf ("So sahen Schluessel und Schloss aus \n");
		printf ("Schloss    : %42s \n", toBin(*abb));
		printf ("Schluessel : %42s \n", toBin(~*abb));
		exit(0);
	}else{
		printf ("%d . Versuch, %d richtige Bits \n", ++versuche, rightBits);
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
char * toBin(unsigned int num)
{
	static char retbuf[43];
	int i =0;
	for(; i<43 ; i++){ // 4 bytes = 32 bits + 7 Halfbyte Zwischenräume + 3 Byte Zwischenräume = 42
		retbuf[i]='0'; //init mit 0

	}
	char *p; i=0;
	p = &retbuf[sizeof(retbuf)-1]; // ans ENDE VOM String zeigen
	*p = '\0'; // Stringabschluss
	do {
		*--p = "0123456789abcdef"[num % 2]; // nur die ersten 2 Zeichen werden benötigt..
		num /= 2;
        if ((++i)%4==0) *--p=' '; // Half-Byte Zwischenraum
        if (i%8==0) *--p=' '; // Byte Zwischenraum
	} while(num != 0);
	return retbuf;
}
