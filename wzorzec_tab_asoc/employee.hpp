# include <iostream>
# include <stdexcept>
# include <iomanip>
# include <string.h>

using namespace std;

#ifndef employee_hpp
#define employee_hpp

class Employee{
	public:
		string name;
		string position;
		unsigned int age;
	
		Employee(string n, string p, int a): name(n), position(p), age(a){}
		Employee(): name("None"), position("None"), age(0){}
		friend std::ostream & operator <<( std::ostream & s, const Employee& m){
				s << "Name: "<< setw(15) << m.name << setw(12) << " position: " << setw(15)  << m.position << setw(7) << " age: " << m.age;
				return s;
			}
};


# endif