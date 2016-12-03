#ifndef stack_hpp
#define stack_hpp

class Stack
{
	private:
		int size;
		int index; //aktualny
		int * buffer; //zawsze trzyma poczatek listy zeby zwolnic pamiec!
		
	public:    

		Stack(); //konstruktor
		~Stack(); //destruktor

		void clear();
		bool empty();
		bool full();
		void print();
		int pop();
		bool push(int value);

};

#endif
