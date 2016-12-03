/*
Zaimplementuj klasę Matrix reprezentującą macierz liczb rzeczywistych typu double. Zapewnij następującą funkcjonalność:

OK	podstawowe operacje arytmetyczne +, -, *, +=, -=, *=
OK	konstruktor kopiujący oraz operator przypisania =
OK	operator porównania ==
OK	operator wyświetlania <<
OK	możliwość wczytywania macierzy z plikowego strumienia wejściowego
OK	dostęp do pojedynczego elementu - możesz przeciążyć operator(),
		tak aby m(2, 3) oznaczało element umieszczony w rzędzie 2, kolumnie 3 obiektu macierzy m.
		Należy rozróżniać pomiędzy operacją zapisu a odczytu.
		Jeżeli zaprezentujesz program który traktuje każdy dostęp do elementu jako operację zapisu możesz uzyskać maksymalnie 60%.

OK 	Zastosuj w implementacji zliczanie odwołań (ang. reference counting).

OK Obsługa błędów:
	W razie wystąpienia błędu wyrzucaj wyjątek
	Rozróżniaj różne rodzaje błędów poprzez wyrzucanie wyjątków różnego typu
	Zapewnij własne klasy do reprezentacji błędów (jedna klasa na każdy jeden typ błędu)

	Starannie przetestuj całą zaimplementowaną funkcjonalność. 
*/
# include "matrix.hpp"
# include <iostream>

using namespace std;

int main(){
	
	
	//TESTY
	
	//	1.
	//test konstruktora czytania z pliku
	/*
	Matrix A("dane2.txt");
	cout << A;
	*/
	
	//	2.
	//test porownania
	/*
	Matrix A("dane2.txt");
	cout << A ;
	
	Matrix B(2,3);
	cout << "B" << endl << B;
	
	Matrix C(2,3);
	cout << "C" << endl << C;
	
	if ( A == B ) cout << "A = B" << endl; //nie powienien
	if ( B == C ) cout << "B = C" << endl; //powinien
	
	C.array->wsk[0][0] = 5.0;
	
	if ( B == C) cout << "B == C 2"; //nie powienien
	*/
	
	//	3.
	//testy na dzialania arytmetyczne
	/*
	Matrix A("dane2.txt");
	std::cout << "A" << std::endl << A;
	
	Matrix B("dane2_2.txt");
	std::cout << "B" << std::endl << B;

	Matrix C = A + B;
	std::cout << "C" << std::endl << C;
	
	
	Matrix D = C - B;
	std::cout << "D" << std::endl << D;
	
	
	std::cout << "A" << std::endl << A;
	Matrix E("dane3.txt");
	std::cout << "E" << std::endl << E;
	
	
	Matrix F = A * E;
	std::cout << "F" << std::endl << F;
	
	Matrix G = 10 * F;
	std::cout << "G" << std::endl << G;
	
	Matrix H = G * 10;
	std::cout << "H" << std::endl << H;
	
	//error rozmiarow
	//std::cout << "A" << std::endl << A;
	//std::cout << "B" << std::endl << B;
	//A *= B;
	//std::cout << "A" << std::endl << A;
	
	
	Matrix W("dane3na3.txt");
	std::cout << "W" << std::endl << W;
	
	Matrix V("dane3na3_2.txt");
	std::cout << "V" << std::endl << V;
	
	W *= V;
	std::cout << "W" << std::endl << W;
	
	W*=10;
	std::cout << "W" << std::endl << W;
	*/
	
	
	
	//	4.
	//testy przypisania i kopiowania
	/*
	Matrix A("dane2.txt");
	std::cout << "A" << std::endl << A;
	
	Matrix V("dane3na3_2.txt");
	std::cout << "V" << std::endl << V;

	Matrix B(A);	
	A = V;
	
	std::cout << "A" << std::endl << A;
	cout << "B" << endl << B;
	std::cout << "V" << std::endl << V;
	*/
	
	
	//	5.
	//test operatorow dostepu i dziwnych przypisan ze zmiana wielkosci matrixa
	/*
	Matrix A("dane2.txt");
	std::cout << "A" << std::endl << A;
	
	A(0,0) = 4.0;
	std::cout << "A" << std::endl << A;
	double d = A(2, 3);
	cout << d << endl;
	
	Matrix B ("dane3na3.txt");
	std::cout << "B" << std::endl << B;
	std::cout << "A" << std::endl << A;

	Matrix C = B;
	std::cout << "C" << std::endl << C;
	
	A = C;
	std::cout << "A" << std::endl << A;
	*/
	
	
	
	
		// TESTY WYJATKOW
	
	/*
	Matrix A("dane2.txt");
	cout << A;
	Matrix B("dane3na3.txt");
	cout << B;
	
	try{
	//matrix_is_not_quadratic:
	//A *= B;
	
	//bad_size_of_matrixes
	//Matrix C = A * B;
	//Matrix C = A + B;
	//Matrix C = A - B;
	
	//index_out_of_range
	//A(3,4) = 5.0;
	//double d = A(5,6);
	//cout << d;

	//file_open_failed
	//Matrix C("dane666.txt");
	
	//matrix_size_cannot_be_negative
	//Matrix C(-1,-2);
	
	}
	catch (MatrixException::Exception& err){
		cout << err.error_message << endl;
	}
	*/
	
	return 0;
}

//g++ -g -Wall -pedantic -Werror matrix.cpp main.cpp -o matrix
//valgrind --leak-check=full ./matrix