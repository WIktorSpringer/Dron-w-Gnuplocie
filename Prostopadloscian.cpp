#include "Prostopadloscian.hh"

using namespace std;
/*!
 * \file  Prostopadloscian.cpp
 *
 *  Plik zawiera instrukcje działania metod
 *
 */


/*!
 * \brief Przeciazenie operatoru przesuniecia bitowego
 *
 * Dzieki tej funkcji zdefiniowane zostalo wyswietlanie  Prostopadloscianu
 *
 * \param  Strm - zmienna rekurencyjna typu ostream
 * \param  Pr - zmienna rekurencyjna typu Prostopadloscian ktorego argumenty nie zmienia sie
 */

std::ostream &operator<<(std::ostream &Strm,const Prostopadloscian &Pr)
{
    for(int i=0; i<Pr.Zwroc_rozmiar(); i++)
    {
        Strm << Pr[i] << endl;
        if((i+1)%4==0)
            Strm <<endl;
    }
    return Strm;
}

/*!
 * \briefZapiszProstopadloscian
 *  Metoda wysyłajaca odpowiednie dane do metody Klasy Figura
 *
 * \param  x_trans argument przekazany do metody ZapiszCzteryWieszcholki
 * \param  z_trans argument przekazany do metody ZapiszCzteryWieszcholki
 */

bool Prostopadloscian::ZapiszProstopadloscian(double x_trans = 0, double z_trans = 0)
{

    ZapiszCzteryWierzcholki(-PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,0,z_trans);
    ZapiszCzteryWierzcholki(PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,0,z_trans);
    ZapiszCzteryWierzcholki(PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,0,z_trans);
    ZapiszCzteryWierzcholki(-PROSTOKAT_X,-PROSTOKAT_Y,PROSTOKAT_Z,x_trans,0,z_trans);
    ZapiszCzteryWierzcholki(-PROSTOKAT_X,PROSTOKAT_Y,PROSTOKAT_Z,x_trans,0,z_trans);
    return true;
}
