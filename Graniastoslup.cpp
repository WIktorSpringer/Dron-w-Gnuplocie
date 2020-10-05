#include "Graniastoslup.hh"
/*!
 * \file  Graniastoslup.hh
 *  
 *  Plik zawiera instrukcje dzialania metod z klasy Graniastoslup.cpp
 *  
 */

std::ostream &operator<<(std::ostream &Strm,const Graniastoslup &Pr)
{
    for(int i=0; i<Pr.Zwroc_rozmiar(); i++)
    {
        Strm << Pr[i] << endl;
        if((i+1)%4==0)
        Strm <<endl;
    }
    return Strm;
}


bool Graniastoslup::ZapiszGraniastoslup6(double Kat_st, double x_trans, double y_trans, double z_trans)
{




  double  KatSkoku_st = 2*M_PI/ILOSC_WIERZCHOLKOW_GRANIATOSLUPA;
  double  x_wierz, y_wierz;

  for (unsigned int Idx = 0; Idx <= ILOSC_WIERZCHOLKOW_GRANIATOSLUPA; ++Idx) {
    x_wierz = PROMIEN_PODSTAWY*cos(Kat_st);
    y_wierz = PROMIEN_PODSTAWY*sin(Kat_st);
    Kat_st += KatSkoku_st;
    ZapiszCzteryWierzcholki(-x_wierz,y_wierz,GRUPOSC_ROTORA/2,x_trans,y_trans,PROSTOKAT_Z+GRUPOSC_ROTORA/2+z_trans);
  }
  return true;
}


