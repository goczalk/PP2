#include <stdio.h>
#include <stdlib.h>
#include "stack.hpp"

/*
Napisz w języku C++ klasę Stack o funkcjonalności analogicznej jak w poprzednim zadaniu.
Tak jak w poprzednim zadaniu możesz używać funkcji malloc i free do alokacji i zwalniania pamięci (nie musisz używać operatorów new i delete). 

Zastąp funkcje init oraz destroy odpowiednio konstruktorem i destruktorem.

Podziel program na następujące pliki: Stack.h, Stack.cpp, main.cpp. Nie jest wymagane przygotowanie pliku makefile.
Wymaganie: za pomocą programu valgrind sprawdź czy poprawnie zarządzasz pamięcią.
*/

int main()
{
    Stack s = Stack();

    int i;
    for(i = 0; i < 10; i++){
        s.push(i);
    }

    s.print();

    printf("%d\n", s.pop());
    s.print();

    printf(s.empty() ? "true\n" : "false\n");
    printf(s.full() ? "true\n" : "false\n");

    s.clear();

    printf(s.empty() ? "true\n" : "false\n");

    for(i = 0; i < 16; i++){
        s.push(i);
    }

    printf(s.full() ? "true\n" : "false\n");

    return 0;
}

