#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

//wyczysc wartosci ze stosu, nie niszczac go
void clear(stack_t * pstack){
    pstack->index = 0;
}

void stack_init(stack_t * pstack){
    pstack->size = 0;
    pstack->index = 0;
	pstack->buffer = NULL;
}

//sprawdz czy indeks == 0 --> wtedy stos "pusty"
bool stack_empty(const stack_t * pstack){
    if( pstack->index == 0)
        return true;
    return false;
}

void stack_free(stack_t * pstack){
    free(pstack->buffer);
   // free(pstack);
}

//sprawdz czy indeks == size - 1 --> wtedy stos "pelny"
bool stack_full(const stack_t * pstack){
    if ( pstack->index == (pstack->size))
        return true;
    return false;
}

//wyœwietla wszystkie elementy stosu, bez jego modyfikowania.
void stack_print(const stack_t* pstack){
    int i;
    for(i=0; i < pstack->index; i++){
        printf("%d ", pstack->buffer[i]);
    }
    printf("\n");
}

//abort gdy nie udalo sie bo stos jest pusty
int stack_try_pop(stack_t * pstack){
    if( stack_empty(pstack) == true ){
        printf("Stos jest pusty, nie mozna zwrocic zadnej wartosci.\n");
        abort();
    }
    else {
		pstack->index --;
        int value = pstack->buffer[pstack->index];
		return value;
    }
}

//zwraca 1 gdy sie udalo bo niepelny stos
bool stack_try_push(stack_t * pstack, int value){
    int * tmp;
    if ( stack_full(pstack) == true){
		if( pstack->size == 0) {
			pstack->buffer = (int *)malloc(sizeof(int));
			pstack->size = 1;
		}
		else{
		    tmp = (int *)realloc(pstack->buffer, (pstack->size * 2)*sizeof(int));
		    if(!tmp){ //gdy realloc mial problem
		        printf("Nie udalo sie zaalokowac pamieci.\n");
		        return false;
		    }
		    pstack->buffer = tmp;
		    pstack->size *= 2;
		}
    }
    pstack->buffer[pstack->index] = value;
    pstack->index ++;
    return true;
}

