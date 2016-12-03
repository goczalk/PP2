# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <math.h>
# include "complex.hpp"

/*
Complex::Complex(){
	Real = 0;
	Imag = 0;
	//Imag ( 0 );
}

Complex::Complex(double r){
	Real = r;
	Imag = 0;
}
*/

Complex::Complex(double r /*= 0*/ , double i /*= 0*/){
	Real = r;
	Imag = i;
}

Complex::~Complex(){
	//printf("Obiekt Complex niszczony.\n");
}

//konstruktor przypisania -> kopiowanie glebokie; TYLKO GDY DYNAMICZNA ALOKACJA PAMIECI
/*
Complex::Complex& operator = (const Complex& c){
	//nie trzeba rozpatrywac jesli do samego siebie bo tylko pola double, bez alokacji, nadpisze
	Real = c.Real;
	Imag = c.Imag;
	return *this; //zwraca obiekt
}
*/

//konstruktor kopiujacy
//referencja zeby uniknac narzutu kopiowania
/*
Complex::Complex(const Complex& s){
	Real = s.Real;
	Imag = s.Imag;
}
*/

/*
Complex & Complex::operator = (double c){
	Real = c;
	Imag = 0;
	return *this;
}
*/

Complex Complex::operator - () const{
	return Complex(-Real,-Imag);
}

Complex & Complex::operator += (Complex c){ 
	Real += c.Real;
	Imag += c.Imag;
	return *this;
}

Complex operator + (const Complex & s1, const Complex & s2){
  Complex c (s1);
  return c += s2;
}

Complex & Complex::operator -= (Complex c){
	Real -= c.Real;
	Imag -= c.Imag;
	return *this;
}

Complex operator - (const Complex & s1, const Complex & s2){
  Complex c (s1);
  return c -= s2;
}

//nie uzywamy operatora * zeby nie bylo narzutu kopiowania?
Complex & Complex::operator *= (Complex c){
	double temp = Real;
	Real = temp * c.Real - Imag * c.Imag;
	Imag = temp * c.Imag + Imag * c.Real;
	return *this;
}

Complex operator * (const Complex & s1, const Complex & s2){
  Complex c (s1);
  c.Real = s1.Real * s2.Real - s1.Imag * s2.Imag;
  c.Imag = s1.Real * s2.Imag + s2.Real * s1.Imag;
  return c;
}

Complex & Complex::operator /= (Complex c){
	if (c.Real == 0 && c.Imag == 0){
		printf("Dividing by 0. Exiting.\n");
		exit(1);
	}
	double temp = Real;
	double div = c.Real * c.Real + c.Imag * c.Imag;
	Real = (temp * c.Real + Imag * c.Imag) / div;
	Imag = (Imag * c.Real - temp * c.Imag) / div;
	return *this;
}

Complex operator / (const Complex & s1, const Complex & s2){
	if (s2.Real == 0 && s2.Imag == 0){
		printf("Dividing by 0. Exiting.\n");
		exit(1);
	}
	Complex c (s1);
	double div = s2.Real * s2.Real + s2.Imag * s2.Imag;
	c.Real = (s1.Real * s2.Real + s1.Imag * s2.Imag) / div;
	c.Imag = (s1.Imag * s2.Real - s1.Real * s2.Imag) / div;
	return c;
}

bool operator == (const Complex & s1, const Complex & s2){
	if (s1.Real == s2.Real && s1.Imag == s2.Imag){
		return true;
	}
	else {
		return false;
	}
}

std::ostream & operator <<( std::ostream & s, const Complex & c){
	char a;
	if (c.Imag >= 0){
		a = '+';
	}
	else{
		a = '\0';
	}
	std::cout.precision(2);
    return s << std::fixed << c.Real << a << std::fixed << c.Imag << 'i' << std::endl;
}

double Complex::getReal() const{
	return Real;
}

double Complex::getImag() const{
	return Imag;
}

double Complex::getAmp() const{
	return sqrt(Real * Real + Imag * Imag);
}

double Complex::getPhase() const{
	return ((atan(Imag/Real) * 180) / M_PI);
}

void Complex::print() const{
	if (Imag >= 0){
		printf("%0.2f+%0.2fi \n", Real, Imag);
	}
	else{
		printf("%0.2f%0.2fi \n", Real, Imag);
	}
}
