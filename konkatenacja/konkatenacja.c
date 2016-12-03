/*Napisac w jezyku C funkcje przyjmujaca dwa lancuchy tekstowe,
alokujaca pamiec i zwracajaca konkatenacje tych lancuchow.
Wykorzystac w przykladowym programie, pamietajac o wlasciwym zarzadzaniu
pamiecia.*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* concatenate(const char* first, const char* second);

int main(){
    const char* a = "Ala ";
    const char* b = "ma kota";
    
    char * c = concatenate(a, b);

    printf("%s", c);

    free(c);
    return 0;
}

char* concatenate(const char* first, const char* second){
    char* result = (char *)malloc(strlen(first)+strlen(second)+1);
    /*result[0] ='\0';
    strcat(result, first);*/
    strcpy(result, first);
    strcat(result, second);
    return result;
}