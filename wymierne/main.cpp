#include "wymierne.hpp"
# include <iostream>

int main(){
	Irrational a(1.0, -2.0);
	Irrational b(-3.0, 5.0);
	a.print();
	b.print();

	Irrational c = a + b;
	c.print();
	
	Irrational w(1.0, -2.0);
	w += b;
	w.print();
	
	c = a - b;
	c.print();
	
	a -= b;
	a.print();

	Irrational d(1.0, -2.0);
		
	c = d * b;
	c.print();
	
	d *= b;
	d.print();

	Irrational g(1.0, -2.0);
	
	c = g / b;
	c.print();
	
	g /= b;
	g.print();

	Irrational r(3.0, -10.0);
	r.print();
	r += 2.0;
	r.print();
	
	r -= 2.0;
	r.print();
	
	r *= 2.0;
	r.print();
	
	r /= 2.0;
	r.print();
	
	Irrational e (5.0);
	std::cout << e;
	
	return 0;
}

//g++ -g -Wall -pedantic -Werror Irrational.cpp main.cpp -o Irrational
//valgrind --leak-check=full ./Irrational
