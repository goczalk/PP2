# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <math.h>
# include "wymierne.hpp"


Irrational::Irrational(double r /*= 0*/ , double i /*= 0*/){
	Real = r;
	Imag = i;
}

Irrational::~Irrational(){
	//printf("Obiekt Irrational niszczony.\n");
}

Irrational Irrational::operator - () const{
	return Irrational(-Real,-Imag);
}

Irrational & Irrational::operator += (Irrational c){ 
	Real += c.Real;
	Imag += c.Imag;
	return *this;
}

Irrational operator + (const Irrational & s1, const Irrational & s2){
  Irrational c (s1);
  return c += s2;
}

Irrational & Irrational::operator -= (Irrational c){
	Real -= c.Real;
	Imag -= c.Imag;
	return *this;
}

Irrational operator - (const Irrational & s1, const Irrational & s2){
  Irrational c (s1);
  return c -= s2;
}

Irrational & Irrational::operator *= (Irrational c){
	Irrational temp = *this * c;
	*this = temp;
	return *this;
}

Irrational operator * (const Irrational & s1, const Irrational & s2){
  Irrational c (s1);
  c.Real = s1.Real * s2.Real + 2 * s1.Imag * s2.Imag;
  c.Imag = s1.Imag * s2.Real + s1.Real * s2.Imag;
  return c;
}

Irrational & Irrational::operator /= (Irrational c){
	if ((c.Real == 0 && c.Imag == 0) || (c.Real * c.Real == 2 * c.Imag * c.Imag)){
		printf("Dividing by 0. Exiting.\n");
		exit(1);
	}
	Irrational temp = *this / c;
	*this = temp;
	return *this;
}

Irrational operator / (const Irrational & s1, const Irrational & s2){
	if ((s2.Real == 0 && s2.Imag == 0) || (s2.Real * s2.Real == 2 * s2.Imag * s2.Imag)){
		printf("Dividing by 0. Exiting.\n");
		exit(1);
	}
	Irrational c (s1);
	
	double div = s2.Real * s2.Real - 2 * s2.Imag * s2.Imag;
	Irrational sprzez(s2.Real, -s2.Imag);
	
	c.Real = (s1 * sprzez).Real / div;
	c.Imag = (s1 * sprzez).Imag / div;
	return c;
}

std::ostream & operator <<( std::ostream & s, const Irrational & c){
	char a;
	if (c.Imag >= 0){
		a = '+';
	}
	else{
		a = '\0';
	}
	std::cout.precision(2);
    return s << std::fixed << c.Real << a << std::fixed << c.Imag << "sqrt(2)" << std::endl;
}

void Irrational::print() const{
	if (Imag >= 0){
		printf("%0.2f+%0.2fsqrt(2) \n", Real, Imag);
	}
	else{
		printf("%0.2f%0.2fsqrt(2) \n", Real, Imag);
	}
}
