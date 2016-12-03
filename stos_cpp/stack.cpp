#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.hpp"

//kontruktor
Stack::Stack(){
	printf("konstuktor\n");
    this->size = 0;
    this->index = 0;
    this->buffer = 0;
}

//destruktor
Stack::~Stack(){
	printf("destruktor\n");
    free(this->buffer);
}

//wyczysc wartosci ze stosu, nie niszczac go
void Stack::clear(){
    this->index = 0;
}

//sprawdz czy indeks == 0 --> wtedy stos "pusty"
bool Stack::empty(){
    if( this->index == 0)
        return true;
    return false;
}

//sprawdz czy indeks == size - 1 --> wtedy stos "pelny"
bool Stack::full(){
    if ( this->index == (this->size))
        return true;
    return false;
}

//wyœwietla wszystkie elementy stosu, bez jego modyfikowania.
void Stack::print(){
    int i;
    for(i=0; i < this->index; i++){
        printf("%d ", this->buffer[i]);
    }
    printf("\n");
}

//abort gdy nie udalo sie bo stos jest pusty
int Stack::pop(){
    if( this->empty() == true ){
        printf("Stos jest pusty, nie mozna zwrocic zadnej wartosci.\n");
        abort();
    }
    else {
		this->index --;
        int value = this->buffer[this->index];
		return value;
    }
}

//zwraca 1 gdy sie udalo bo niepelny stos
bool Stack::push(int value){
    int * tmp;
    if ( this->full() == true){
		if( this->size == 0) {
			this->buffer = (int *)malloc(sizeof(int));
			this->size = 1;
		}
		else{
		    tmp = (int *)realloc(this->buffer, (this->size * 2)*sizeof(int));
		    if(!tmp){ //gdy realloc mial problem
		        printf("Nie udalo sie zaalokowac pamieci.\n");
		        return false;
		    }
		    this->buffer = tmp;
		    this->size *= 2;
		}
    }
    this->buffer[this->index] = value;
    this->index ++;
    return true;
}
