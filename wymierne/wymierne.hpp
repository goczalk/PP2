# include <iostream>

#ifndef wymierne_hpp
#define wymierne_hpp	

class Irrational
{
	private:
		double Real, Imag;
		
	public:    
		Irrational(double = 0 , double = 0);
		~Irrational();

		Irrational operator - () const;
		Irrational & operator += (Irrational);
		Irrational & operator -= (Irrational);
		Irrational & operator *= (Irrational);
		Irrational & operator /= (Irrational);
		void print() const;
		
		friend Irrational operator + (const Irrational &, const Irrational &);
		friend Irrational operator - (const Irrational &, const Irrational &);
		friend Irrational operator * (const Irrational &, const Irrational &);
		friend Irrational operator / (const Irrational &, const Irrational &);

		friend std::ostream & operator << ( std::ostream &, const Irrational &);
};

#endif
