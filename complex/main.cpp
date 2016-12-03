/*Zaimplementuj klasę Complex reprezentującą liczby zespolone.
 Zapewnij następującą funkcjonalność:

OK	podstawowe operatory arytmetyczne +, -, *, /, +=, -=, *=, /=
OK  operator porównujący ==
OK  operator <<
OK  funkcje zwracające część rzeczywistą i urojoną
OK  funkcje zwracające amplitudę i fazę

Starannie przetestuj całą zaimplementowaną funkcjonalność. Przetestuj przypadki szczególne jak:

    a += b += c
    a * 10
    10 * a

Podziel program na następujące pliki: Complex.h, Complex.cpp, main.cpp.
Wskazówka: implementuj większość funkcjonalności jako funkcje składowe klasy.
Pisz funkcje nieskładowe tylko gdy jest to uzasadnione. */

//kopiowanie
//Complex kopia(b);
//Complex d = Complex(4);
//dziala bo int musi sam byc awansowany do double, tak samo char

//czemu tak duzo razy niszczone??

#include "complex.hpp"

# include <iostream>

int main(){
		
	Complex a/* = Complex*/(1.0, -2.0);
	Complex b/* = Complex -wtedy kopia*/(1.0, 2.0);
	a.print();
	b.print();

	Complex c = a + b;
	c.print();
	
	c = a - b;
	c.print();

	c = a * b;
	c.print();

	c = a / b;
	c.print();

	Complex d (5.0);

	if (  5.0 == d){std::cout <<"hahaha!";} 

	std::cout << a;
	
	return 0;
}

//g++ -g -Wall -pedantic -Werror complex.cpp main.cpp -o complex
//valgrind --leak-check=full ./complex
