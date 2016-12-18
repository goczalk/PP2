/*
Tablica asocjacyjna
Zaimplementuj tablicę asocjacyjną liczb całkowitych indeksowaną łańcuchem tekstowym.
Unikając duplikacji kodu zaimplementuj dwie wersje tej tablicy:

    z rozróżnianiem małych i wielkich liter
    bez rozróżniania małych i wielkich liter

Wymaganie: nie wolno używać gotowych kontenerów z biblioteki standardowej.
Wymaganie: nie wolno duplikować kodu. Rozwiązania z duplikacją kodu nie będą akceptowane.
Wskazówka: zamiast duplikować kod należy zaproponować odpowiednią hierarchię
klas z wykorzystaniem polimorfizmu.  
*/

# include "tab_asoc.hpp"
# include <iostream>

using namespace std;

int main(){
	
	AssocTab *wsk_a = new AssocTab;
	//jak chcesz sprawdzic polimorfizm to musisz public:find
	AssocTab_CaseIns *wsk_b= new AssocTab_CaseIns;
	
	wsk_a->insert("ala", 1);
	wsk_a->insert("ola", 2);
	wsk_a->insert("ania", 20);
	wsk_a->print();
	
	wsk_b->insert("maciej", 1);
	wsk_b->insert("olek", 2);
	wsk_b->insert("marek", 20);
	wsk_b->print();
	
	AssocTab a = *wsk_a;
	AssocTab_CaseIns b = *wsk_b;
	
	//szukanie po zwyklym AssocTab
	cout << (a["ania"]) << endl;
	//cout << (a["OLa"]) << endl;
	
	cout << "************" << endl;;
	//szukanie po zwyklym AssocTab_CaseIns
	cout << (b["marek"]) << endl;
	cout << (b["MaREk"]) << endl;
	
	//(*wsk_b)["marek"];
	
	delete wsk_a;
	delete wsk_b;
	
	return 0;
}


//g++ -g -Wall -pedantic -Werror tab_asoc.cpp main.cpp -o tab_asoc
//valgrind --leak-check=full ./tab_asoc