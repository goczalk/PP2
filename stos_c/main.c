#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
Zaimplementuj w jêzyku C stos liczb ca³kowitych. Zapewnij nastêpuj¹c¹ funkcjonalnoœæ:

void init(struct Stack* s)
void destroy(struct Stack* s)
void push(struct Stack* s, int element)
int pop(struct Stack* s)
void clear(struct Stack* s)
bool isEmpty(struct Stack* s) - upewnij siê ze za³¹czasz plik nag³ówkowy stdbool.h - konieczne aby u¿ywaæ typu bool w jêzyku C
U¿yj dynamicznie alokowanej tablicy do przechowywania elementów na stosie.
Gdy tablica siê zape³ni zwiêkszaj jej rozmiar dwukrotnie.
W razie wyst¹pienia b³êdu (np. wywo³anie funkcji pop gdy stos jest pusty) wywo³uj funkcjê assert lub abort aby zakoñczyæ dzia³anie programu.
Podziel program na nastêpuj¹ce pliki: Stack.h, Stack.c, main.c. Nie jest wymagane przygotowanie pliku makefile.
Wskazówka: mo¿esz zdefiniowaæ strukturê z u¿yciem s³owa kluczowego typedef aby nie trzeba by³o póŸniej w programie wszêdzie stosowaæ s³owa kluczowego struct.
Wymaganie: za pomoc¹ programu valgrind sprawdŸ czy poprawnie zarz¹dzasz pamiêci¹.
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

    //pêtlê to sprawdzenia, czy wartoœci zdejmowane ze stosu s¹ poprawne (1000 -> 1)
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

