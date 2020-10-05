#include "Figura.hh"
/*!
 * \file  Figura.cpp
 *
 *  Plik zawiera definicje klasy Figura
 *
 */

/*!
* \brief Przeciazenie []
*
* Pozwala na odwolywanie sie do odpowiedniej komurki tablicy dynamicznej vector
* \param i to numer komorki do ktorej chcemy sie odwolac
*/
Wektor3D &Figura::operator[](const int i)  /*Wyciagniecie danego wieszcholka*/
{
    return wieszcholki[i];
}

Wektor3D Figura::operator[](const int i) const /*Wyciagniecie danego wieszcholka dla <<*/
{
    return wieszcholki[i];
}
/*!
* \brief Zapisz 3 wartosci
*
* Pozwala na uzupelnienie jednej komurki tablicy
* dynamicznej vector zmienna typu Wektor3D dannym wartosciami
*/
void Figura::ZapiszTrzyWartosci( double w1, double w2, double w3)
{
    Wektor3D wek1;

    wek1[0]=w1;
    wek1[1]=w2;
    wek1[2]=w3;
    wieszcholki.push_back(wek1);
}


/*!
* \brief Zapisanie 4 wieszcholkow
*
* Pozwala na wywolanie metody Zapisz trzy wartosci x4
*/
void Figura::ZapiszCzteryWierzcholki(double x_wierz, double y_wierz, double z_wierz, double x_trans, double y_trans, double z_trans)
{
    ZapiszTrzyWartosci(  x_trans, y_trans, z_wierz+z_trans );
    ZapiszTrzyWartosci(  x_wierz+x_trans, y_wierz+y_trans, z_wierz+z_trans );
    ZapiszTrzyWartosci(  x_wierz+x_trans, y_wierz+y_trans, -z_wierz+z_trans );
    ZapiszTrzyWartosci(  x_trans, y_trans, -z_wierz+z_trans );

}
/*!
* \brief Zwroc rozmiar
*
* Metoda zwracajaca rozmair tablicy dynamicznej
*/
int Figura::Zwroc_rozmiar() const
{
    return wieszcholki.size();
}
/*!
* \brief Zmien srodek
*
* Pozwala na zmiennienie wspolrzednych srodka
*/
void Figura::zmien_srodek(Wektor3D wek1)
{
    srodek_fig=wek1;
}
/*!
* \brief zwroc srodek
*
* Pozwala na zwrocenie srodka fig
*/
Wektor3D Figura::zwroc_srodek()
{
    return srodek_fig;
}

