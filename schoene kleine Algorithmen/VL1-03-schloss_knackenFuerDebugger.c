 /*****************************************************************
 *  Datei:          VL1-schloss_knacken.c
 *  erstellt:       07.06.2022
 *  aktuell:        14.06.2022
 *  von wem:        einige Dinge korrigiert -> dani
 *  hhttps://wiki.freitagsrunde.org/C-Kurs/%C3%9Cbungsaufgaben
 *  param: void
 *  return: int 0 bei ordnungsgemäßem Ende
 *  Beschreibung:
 *    Bitweise Operatoren in C anwenden
 *  veränderbare Parameter:
 *  i DEBUG: true, false
 *      ergibt kürzere oder längere Ausgabe in Konsole
 *      bei DEBUG== true -> max. 32x ENTER tippen, für jede Bitprüfung
 *  e 220614: + / - um beim Scrollen die Geschwindigkeit zu verändern
 *      mit Zahlen besser geloest
 *  i in Zeile Z102 auskommentieren,
 *      wenn das zeitliche Verhalten (Durchlaufen) stört
 *      oder Wartezeit verändern wenn es schneller laufen soll
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

bool DEBUG = true;
unsigned int* abb;
unsigned int bit2Test;
int scrollVelocity = 50000;
int userInput, c; // Zeichen lesen von der Console, letzter Wert in c mit Anpassung

unsigned int switchBit(int key, int whichBit);
int test(unsigned int, bool silent);
void generate(void);
char * bin2String(unsigned int);
char * markPosition(int position);
char * key2String(unsigned int, int);

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

	for(bit2Test=0; bit2Test < 32 ; bit2Test++){/* für jedes Bit wird geprüft ob es richtig ist oder ob es getaucht werden muss*/
		int rightBits  = test(key, false);/* Anzahl der richtigen Bits bevor das i-te Bit getauscht wurde*/
		int newRightBits = test(switchBit(key, bit2Test), true);/* Anzahl der richtigen Bits nachdem das i-te Bit getauscht wurde*/

		//hier drunter den Breakpoint setzen zum Betrachten von key, DEBUG auf false
		if(newRightBits > rightBits)
		/* Wenn die Anzahl der richtigen Bits nach dem Tausch größer ist als vorher,
		 ist der Schluessel mit dem getauschten Bit der neue Schlüssel*/
			key=switchBit(key,bit2Test);
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
int test(unsigned int toTest,  bool silent)
{
	int rightBits = 0;

	for(int i = 0; i < 32 ; i++){
		unsigned int x = 1 << i; // jedes Bit einzeln = Maske: 1, 2, 4, 8, 16, 32, 64...

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
         if (DEBUG && !silent) {
            printf("Schlüssel fertig bis Bit: %d, Bits in Prüfung: %d, Key = %u, richtige Bits = %d\n", bit2Test, i, toTest, rightBits);
            printf("            key: %42s  0x%x\n", key2String(toTest, bit2Test), toTest);
            printf("           goal: %42s  0x%x\n", bin2String(*abb), *abb);
            unsigned int a=toTest & x; printf("   masked key a: %42s  0x%x\n", bin2String(a), a);
            unsigned int b=*abb| ~x; printf("  masked goal b: %42s  0x%x\n", bin2String(b), b);
            unsigned int c= (toTest & x) ^ (*abb| ~x); printf("XOR from both c: %42s  0x%x\n", bin2String(c), c);
            unsigned int d= ~((toTest & x) ^ (*abb| ~x)); printf("  flipped XOR d: %42s  0x%x\n", bin2String(d), d);
            unsigned int e= ! ~((toTest & x) ^ (*abb| ~x)); printf(" NOT from all e: %42s  0x%x\n", bin2String(e), e);
            printf("     Position -> %42s \n\n", markPosition(i));
            usleep(scrollVelocity);
        }
        // bis hier nur fuer Debug
	}

     if(rightBits == 32){
        printf ("\nGratulation !\n\n");
        printf ("Die Tuer ist offen.\n");
        printf ("So sahen Schluessel und Schloss aus \n");
        printf ("Schluessel : %42s  0x%x\n", bin2String(~*abb),~*abb); //auch unschön dass ist NICHT der key
        printf ("Schloss    : %42s  0x%x\n", bin2String(*abb), *abb);
        exit(0); // unschön aber wird gebraucht, dass Console stehen bleibt
    }else{
        if (!silent) {
            printf ("Bit %2d getestet, %d richtige Bits \n", bit2Test, rightBits);
            if (DEBUG) {
                printf("Mit [ENTER] weiter - Geschwindigkeit von [1-9] einstellbar: ");
                //while (getchar()<0); // stdin leeren; kriege ich grad noch nicht hin
                while((userInput = getchar()) != '\n') {
                        c=userInput-'0'+1; // 1=49, Zahlen unten optimiert für große Bandbreite der Geschwindigkeit
                        // und 5 soll gleich wie Vorgabe sein=50000
                }
                printf("%d = Wert für userInput", c-1);
                if ((c>1) && (c<11)) scrollVelocity = 10800000/(c*c*c);
            }
        }
   }
   return rightBits;
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
	for(; i<43 ; i++) retbuf[i]='0'; //init mit 0
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

char * markPosition(int position)
{
	static char retbuf[43];
	int i =0;
	unsigned int marker = (1<<position); // in Bitfolge steht dann bei Position eine 1 >> zB bei Pos 3 eine 8

	for(; i<43 ; i++) retbuf[i]='0'; //init mit 0
	char *p; i=0;
	p = &retbuf[sizeof(retbuf)-1]; // ans ENDE VOM String zeigen
	*p = '\0'; // Stringabschluss
	do {
		*--p = " I∧▲↑↥⇈"[marker % 2]; // nur die ersten 2 Zeichen werden benötigt..
		// marker /= 2; gleich wie:
		marker >>=1;
        if ((++i)%4==0) *--p=' ';
        if (i%8==0) *--p=' ';
	} while(i < 43);
	return retbuf;
}

char * key2String(unsigned int num, int pos2Test)
{
	static char retbuf[43];
	int i =0, bit=0;
	for(; i<43 ; i++) retbuf[i]='0'; //init mit 0
	char *p; i=0;
	p = &retbuf[sizeof(retbuf)-1]; // ans ENDE VOM String zeigen
	*p = '\0'; // Stringabschluss
	do {
		*--p = "0123456789abcdef"[num % 2]; // nur die ersten 2 Zeichen werden benötigt..
		if (bit == pos2Test) *p = '?';
        bit++;
		num /= 2;
        if ((++i)%4==0) *--p=' ';
        if (i%8==0) *--p=' ';
	} while(i < 43);
	return retbuf;
}

