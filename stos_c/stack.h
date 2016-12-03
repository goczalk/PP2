#ifndef stack_h
#define stack_h

int dodajLiczby( int a, int b );

typedef struct  {
    int size;
    int index; //aktualny
    int * buffer; //zawsze trzyma poczatek listy zeby zwolnic pamiec!
}stack_t;

typedef enum { false, true } bool;

void clear(stack_t * pstack);
void stack_init(stack_t * pstack);
bool stack_empty(const stack_t * pstack);
void stack_free(stack_t * pstack);
bool stack_full(const stack_t * pstack);
void stack_print(const stack_t* pstack);
int stack_try_pop(stack_t * pstack);
bool stack_try_push(stack_t * pstack, int value);

#endif
