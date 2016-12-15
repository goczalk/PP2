#include <iostream>

using namespace std;

class KlaudiaRlz
{
	public:
	    int i,
            to,
            bardzo,
            tak_chce;

		KlaudiaRlz();
		KlaudiaRlz(int, int, int, int=0);
		KlaudiaRlz(const KlaudiaRlz&);
		~KlaudiaRlz();
		KlaudiaRlz operator + (int);
		KlaudiaRlz operator - (int);
		KlaudiaRlz operator * (int);

		friend std::ostream & operator << ( std::ostream &, const KlaudiaRlz &);
};


// MAIN

int main()
{
    cout << "Pacz jaka ta Klaudia swietna!" << endl;

    KlaudiaRlz sam_poczateczek_zabawy;
    KlaudiaRlz a_tak_se_przypisze = sam_poczateczek_zabawy - 8 + 12 + 12;

    cout << sam_poczateczek_zabawy.i << " " << a_tak_se_przypisze.i << " "
            << sam_poczateczek_zabawy.bardzo << " " << a_tak_se_przypisze.bardzo << " "
            << (sam_poczateczek_zabawy * 12).bardzo << " " << sam_poczateczek_zabawy.to << endl;


    cout << sam_poczateczek_zabawy.i << " " << a_tak_se_przypisze.i << " "
            << sam_poczateczek_zabawy.bardzo << " " << a_tak_se_przypisze.bardzo << " ";

    int ja_tu_tylko_pomagam = (a_tak_se_przypisze + 8 + 8).i;
    int a_moze_przeszkadzam = ja_tu_tylko_pomagam + 6;

    cout << ja_tu_tylko_pomagam << " " << (sam_poczateczek_zabawy + 12).bardzo << " " << a_moze_przeszkadzam << " "
            << a_tak_se_przypisze.i << " " << sam_poczateczek_zabawy.to << endl;

    KlaudiaRlz juz_prawie_koniec(32, 50, 79, 1);
    KlaudiaRlz prawie_prawie = juz_prawie_koniec - 12;
    cout << prawie_prawie.bardzo << " " << juz_prawie_koniec << " 122 " << juz_prawie_koniec.bardzo << " 46" ;

    return 0;
}


// FUNCTIONS
KlaudiaRlz::KlaudiaRlz(): i(71), to(44), bardzo(115), tak_chce(1){};

KlaudiaRlz::KlaudiaRlz(int nie, int miej, int watpliwosci, int prawda){
	i = miej;
	to = watpliwosci;
	bardzo = nie;
	tak_chce = prawda;
}

KlaudiaRlz::~KlaudiaRlz(){
    if (tak_chce == 1)
        cout << " 46";
}

KlaudiaRlz::KlaudiaRlz(const KlaudiaRlz& mala_Klaudia){
    i = mala_Klaudia.i;
    to = mala_Klaudia.to;
    bardzo = mala_Klaudia.bardzo;
    tak_chce = 0;
}

KlaudiaRlz KlaudiaRlz::operator - (int nie_jestem_wcale_intem){
    KlaudiaRlz duza_Klaudia(*this);
    if (nie_jestem_wcale_intem == 8)
        duza_Klaudia.i += 40;
	if (nie_jestem_wcale_intem == 4)
        duza_Klaudia.to += 40;
    if (nie_jestem_wcale_intem == 12)
        duza_Klaudia.bardzo += 40;
    return duza_Klaudia;
}

KlaudiaRlz KlaudiaRlz::operator + (int nie_jestem_wcale_intem){
    KlaudiaRlz duza_Klaudia(*this);
    if (nie_jestem_wcale_intem == 8)
        duza_Klaudia.i -= 5;
	if (nie_jestem_wcale_intem == 4)
        duza_Klaudia.to -= 5;
    if (nie_jestem_wcale_intem == 12)
        duza_Klaudia.bardzo -= 5;
    return duza_Klaudia;
}

KlaudiaRlz KlaudiaRlz::operator * (int nie_jestem_wcale_intem){
    KlaudiaRlz duza_Klaudia(*this);
    if (nie_jestem_wcale_intem == 8)
        duza_Klaudia.i += 2;
	if (nie_jestem_wcale_intem == 4)
        duza_Klaudia.to += 2;
    if (nie_jestem_wcale_intem == 12)
        duza_Klaudia.bardzo += 2;
    return duza_Klaudia;
}

ostream & operator <<( std::ostream & s, const KlaudiaRlz & mala_Klaudia){
    return s << mala_Klaudia.i << " " << mala_Klaudia.to << " " << mala_Klaudia.bardzo;
}

