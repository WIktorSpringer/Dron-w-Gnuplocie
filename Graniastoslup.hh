#ifndef  GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
#include <vector>
#include <iostream>
#include "Figura.hh"
/*!
 * \file  Graniastoslup.hh
 *  
 *  Plik zawiera definicje klasy Graniastoslup
 *  ktora to dziedziczy par i met po klasie figura
 */
class Graniastoslup: public Figura {
public:
bool ZapiszGraniastoslup6(double  Kat_st, double  x_trans, double  y_trans, double  z_trans);


};

std::ostream &operator<<(std::ostream &Strm,const Graniastoslup &Pr);

#endif 
