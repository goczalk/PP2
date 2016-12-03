#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
Zaimplementuj w j�zyku C stos liczb ca�kowitych. Zapewnij nast�puj�c� funkcjonalno��:

void init(struct Stack* s)
void destroy(struct Stack* s)
void push(struct Stack* s, int element)
int pop(struct Stack* s)
void clear(struct Stack* s)
bool isEmpty(struct Stack* s) - upewnij si� ze za��czasz plik nag��wkowy stdbool.h - konieczne aby u�ywa� typu bool w j�zyku C
U�yj dynamicznie alokowanej tablicy do przechowywania element�w na stosie.
Gdy tablica si� zape�ni zwi�kszaj jej rozmiar dwukrotnie.
W razie wyst�pienia b��du (np. wywo�anie funkcji pop gdy stos jest pusty) wywo�uj funkcj� assert lub abort aby zako�czy� dzia�anie programu.
Podziel program na nast�puj�ce pliki: Stack.h, Stack.c, main.c. Nie jest wymagane przygotowanie pliku makefile.
Wskaz�wka: mo�esz zdefiniowa� struktur� z u�yciem s�owa kluczowego typedef aby nie trzeba by�o p�niej w programie wsz�dzie stosowa� s�owa kluczowego struct.
Wymaganie: za pomoc� programu valgrind sprawd� czy poprawnie zarz�dzasz pami�ci�.
*/

int main()
{
    int i;

	stack_t wsk_t;// = (stack_t *)malloc(sizeof(stack_t));

    stack_init(&wsk_t);

	stack_try_push(&wsk_t, 11);

	stack_print(&wsk_t);

    printf("%d\n", (&wsk_t)->size); 

	for (i = 0; i <= 10; i++){
		stack_try_push(&wsk_t, i);
    }

    stack_print(&wsk_t);

    printf("%d\n", (&wsk_t)->size);

    stack_try_push(&wsk_t, 22);

    printf("%d\n", (&wsk_t)->size);

    for (i = 0; i <= 11; i++){
		stack_try_push(&wsk_t, i);
    }

    printf("%d\n", (&wsk_t)->size);

    stack_print(&wsk_t);

    //p�tl� to sprawdzenia, czy warto�ci zdejmowane ze stosu s� poprawne (1000 -> 1)
    /*
    int * a;
    for(i = 1000; i >= 0;  i--){
        stack_try_pop(wsk_t, a);
        if(i != *a){
            printf("Cos nie tak!\n");
            break;
        }
    }
    */

    if(stack_empty(&wsk_t)){
        printf("Pusty!");
    }
    else {
        printf("Niepusty!");
    }

	printf("%d\n", stack_try_pop(&wsk_t));

	stack_print(&wsk_t);

    if(stack_empty(&wsk_t)){
        printf("Pusty!");
    }
    else {
        printf("Niepusty!");
    }

    stack_free(&wsk_t);

    return 0;
}

