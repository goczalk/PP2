/*
Zaimplementuj:
OK 1)wzorzec tablicy asocjacyjnej "Map"
OK 2) oraz klasę "Employee" reprezentującą dane personalne pracownika.
OK 3) Przykładowe użycie wzorca "Map" i klasy "Employee" ilustruje ten plik.

Dodatkowo zademonstruj użycie wzorca "Map" do przechowywania
4) bazy danych książek w bibliotece, gdzie klucz jest tytułem książki
	a obiekt wartość przechowuje informacje o autorze, kategorii,
	ilości stron oraz statusie (na półce / wypożyczony).
*/

# include "wzorzec_tab_asoc.hpp"
# include "employee.hpp"
# include "book_base.hpp"
# include <iostream>
# include <string.h>

using namespace std;

//find is private, use [] instead !
/*
E* pE;
pE = &newDatabase[10];
pE->value = 1111;
newDatabase[1].value = 800;
*/

int main(){
	typedef unsigned int ID; 											//Identification number of Employee
	Map<ID,Employee> database;											//Database of employees

	database.insert(761028073,Employee("Jan Kowalski","salesman",28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.insert(510212881,Employee("Adam Nowak","storekeeper",54)); //Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	database.insert(730505129,Employee("Anna Zaradna","secretary",32)); //Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << database << endl;											//Print database

	Map<ID,Employee> newDatabase = database;							//Make a copy of database
	
	Employee* pE;
	pE = &newDatabase[510212881];										//Find employee using its ID
	pE->position = "salesman";											//Modify the position of employee
	pE = &newDatabase[761028073];										//Find employee using its ID
	pE->age = 29;														//Modify the age of employee

	database = newDatabase;												//Update original database
	
	cout << database << endl;
	
	
	// LIBRARY EXAMPLE
	// czy da sie z enum availability oraz czy sensownie do Book dodac title??
	typedef string TITLE; 											
	Map<TITLE,Book> bookDatabase;											

	bookDatabase.insert("Nad Niemnem",Book("Eliza Orzeszkowa", "lektura szkolna", 555, 0));
	bookDatabase.insert("TO",Book("Stephen King", "horror", 1110, 1));
	bookDatabase.insert("Mistrz i Malgorzata",Book("Michaił Bułh", "epika", 666, 1));

	cout << bookDatabase << endl;											

	Map<TITLE,Book> newBookDatabase = bookDatabase;							
	
	Book* pB;
	pB = &newBookDatabase["TO"];										
	pB->author = "Stephani Meyer";											
	pB = &newBookDatabase["Mistrz i Malgorzata"];										
	pB->pages = 333;								

	bookDatabase = newBookDatabase;												
	
	cout << bookDatabase << endl;
	
    return 0;
}


//g++ -g -Wall -pedantic -Werror main.cpp -o wzorzec_tab_asoc
//valgrind --leak-check=full ./wzorzec_tab_asoc
