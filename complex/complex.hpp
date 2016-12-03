# include <iostream>

#ifndef complex_hpp
#define complex_hpp	

class Complex
{
	private:
		double Real, Imag;
		
	public:    
		//Complex();
		//Complex(double);
		Complex(double = 0 , double = 0); //w definicji juz bez domyslnych
		~Complex();
		//konstruktor kopiujący i przypisania niepotrzebny bo nie ma alokowania pamięci
		
		//Complex & operator = (double); //rzutowanie samo, ale tylko gdy friend
		Complex operator - () const;
		Complex & operator += (Complex);
		Complex & operator -= (Complex);
		Complex & operator *= (Complex);
		Complex & operator /= (Complex); //Complex& c sie nie da bo nie zmieni z double na Complexa, musi dzialac na kopii
		
		double getReal() const; //const i & unikasz kopii
		double getImag() const;
		double getAmp() const;
		double getPhase() const;
		void print() const;
		
		friend Complex operator + (const Complex &, const Complex &);
		friend Complex operator - (const Complex &, const Complex &);
		friend Complex operator * (const Complex &, const Complex &);
		friend Complex operator / (const Complex &, const Complex &);
		friend bool operator == (const Complex & s1, const Complex & s2);
		friend std::ostream & operator << ( std::ostream &, const Complex &);
};

#endif
