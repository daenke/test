 /*****************************************************************
 *  Datei:          VL1-02-fibonacci.c
 *  erstellt:       04.06.2022
 *  von wem:        ???
 *  https://wiki.freitagsrunde.org/C-Kurs/%C3%9Cbungsaufgaben
 *  Beschreibung:
 *    Das n-te Folgenglied ist dabei die Summe der beiden vorherigen.
 *    fib(0) = 0
 *    fib(1) = 1
 *    fib(n) = fib(n-1) + fib(n-2)
 *    Als Beispiel [1]: fib(24) = 46.368 oder beginnend mit 0:
 *    0>0, 1>1, 2>1, 3>2, 4>3, 5>5, 6>8, 7>13, 8>21, 9>34, 10>55...
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* hier sollten alle verwendeten Funkltionen deklarariert werden ( insbesondere die fib() Funktion ) */
int fib(int);

int main(int argc, char *argv[]) {
  /* hier wird der Kommandozeilenparameter ausgelesen und in der Integer-Variablen 'n' gespeichert */
  if(argc != 2 ){
    printf("usage: './fib n' where n is a number \n");
  }else{
    int n = atoi(argv[1]);

    /* hier wird der Integer-Variablen 'result' das Ergbniss der Funktion fib zugewiesen.*/
    int result = fib(n);

    /* wenn das Ergebnis der Rechung weiterhin in der Integer-Variablen 'result' gespeichert ist wird deren Wert hier auf der Konsole ausgegeben. */
    printf("%d \n",result);
  }
  return 0;
}

/* diese Funktion berechnet das n-te Folgebglied der Fibonacci-Folge */
int fib(int n){
  if( n == 0){ /* das 0-te Folgenglied ist per Definition 0 */
    return 0;
  }
  if( n == 1){ /* das 1-te Folgenglied ist per Definition 1 */
    return 1;
  }
  if( n > 1){ /* alle weiteren Folgenglieder werden aus den jeweiligen Vorgaengern berechnet */
    return fib(n-1)+fib(n-2);
  }
  return 0;
}
