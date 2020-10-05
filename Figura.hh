#ifndef FIGURA_HH
#define FIGURA_HH
#include <vector>
#include <iostream>
#include "Wektor3D.hh"


#define PROSTOKAT_X  10
#define PROSTOKAT_Y  12
#define PROSTOKAT_Z  5


#define ILOSC_WIERZCHOLKOW_GRANIATOSLUPA  6
#define PROMIEN_PODSTAWY                  10
#define GRUPOSC_ROTORA                    5.0


/*!
 * \file  Figura.hh
 *
 *  Plik zawiera definicje klasy Figura
 *
 */

/*!
 * \brief Zestaw informacji dotyczący Drona
 *
 * Klasa modeluje zestaw informacji dotyczący Figury i
 * zaawier metody, ktore dzialaja na obiekcie Figura
 */
class Figura
{
protected:
    /*!
    * \brief dynamiczna tablica szablonowa typu Wektor3D
    *
    * Pozwala na przechowywanie wspolrzednych danej figury
    */
    vector<Wektor3D> wieszcholki;
    /*!
    * \brief zmienna typu Wektor3D
    *
    * Pozwala na przechowywanie wspolrzednych srodka figury
    */
    Wektor3D srodek_fig;

public:
    /*!
    * \brief przeciazenie operatoru nawiasow kwadratowych
    *
    * Pozwala na odwolanie sie do czesci protected klassy Figura
    */
    Wektor3D &operator [] (const int i);
    Wektor3D operator [] (const int i) const;
    /*!
    * \brief Zapisz trzy wartosci
    *
    * Zapisuje do tablicy dynamicznej Vector, zmienna Wektor3D.
    * /param w1 w2 w3 to wartosci jakie zostana wprowadzone do kolejnych argumnetow zmiennej Wektor3D
    */
    void ZapiszTrzyWartosci( double w1, double w2, double w3);
    /*!
    * \brief Zapis 4 wieszcholkow
    *
    * Metoda pozwalajaca na zapisanie 4 wieszolkow tpyu Wektor 3D do tablicy dynamicznej vector
    */
    void ZapiszCzteryWierzcholki(double x_wierz, double y_wierz, double z_wierz, double x_trans, double y_trans, double z_trans);
    /*!
    * \brief Zwroc rozmiar tablicy
    *
    * Pozwala wyswietlenie aktualnego rozmiaru tablicy dynamiczej vector
    */
    int Zwroc_rozmiar() const;
    /*!
    * \brief Zmien srodek
    *
    * Pozwala na zamiane srodka figury
    */
    void zmien_srodek(Wektor3D wek1);
    /*!
    * \brief Zwroc srodek
    *
    * Pozwala na odowlanie sie do zmiennej protected srodek_figury
    */
    Wektor3D zwroc_srodek();



};

#endif
