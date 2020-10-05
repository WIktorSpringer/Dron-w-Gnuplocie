#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Figura.hh"



/*!
 * \file  Prostopadloscian.hh
 *
 *  Plik zawiera definicje klasy Prostopadloscian
 *  ktora dziedziczy po klasie Figura
 *
 */
class Prostopadloscian: public Figura
{
public:
    bool ZapiszProstopadloscian(double x_trans, double z_trans);


};


/*
 * \brief Przeciazenie operatoru przesuniecia bitowego
 *
 * W celu zdefiniowania sposobu wyswietlania obiektow typ Prostopadloscian
 *
 */
std::ostream& operator << ( std::ostream       &Strm,
                            const Prostopadloscian    &Pr
                          );


#endif
