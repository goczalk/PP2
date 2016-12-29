# include <iostream>
# include <stdexcept>
# include <string.h>

using namespace std;

#ifndef book_base_hpp
#define book_base_hpp

class Book{
	public:
		string author;
		string category;
		unsigned int pages;
		int availability;
		
		Book(string a, string c, int p, int av): author(a), category(c), pages(p), availability(av){}
		Book(): author("Not known"), category("Not known"), pages(0), availability(1){}
		friend std::ostream & operator <<( std::ostream & s, const Book& m){
				s << "Author: " << setw(20) << m.author << setw(15) << "category: " << setw(15) << m.category
					<< setw(12) << "pages: " << setw(5) << m.pages
					<< setw(20) << "availability: ";
				if (m.availability)
					s << "available";
				else
					s << "not available";
				return s;
			}
};

# endif