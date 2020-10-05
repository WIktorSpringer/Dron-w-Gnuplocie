#ifndef WEKTOR_HH
#define WEKTOR_HH
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

/*!
 * \file  Wektor.hh
 *  
 *  Plik zawiera definicje klasy szablonowej Wektor
 *  
 */
template <int rozmiar>
class Wektor {
  double wektor[rozmiar];
  
  
  
  public:
 static int ilosc_wek_ogolnie;
 static int ilosc_aktualnie;
 static int ilosc_usunietych;
 

double &operator [] (const int i)
{
  return wektor[i];
}

double operator [] (const int i)const
{
   return wektor[i];

}

Wektor<rozmiar> operator + (const Wektor<rozmiar> wek)
{
    Wektor<rozmiar> wynik;
  for(int i=0; i <rozmiar; i++)
   {
    wynik[i]=wektor[i]+wek[i];
   }
  return wynik;

}

Wektor<rozmiar> operator - (const Wektor<rozmiar> wek)
{
  Wektor<rozmiar> wynik;
  for(int i=0; i <rozmiar; i++)
   {
    wynik[i]=wektor[i]-wek[i];
   }
  return wynik;

}

double licz_dlug(const Wektor<rozmiar> Wek)
{
    double suma=0;

    for(int i=0; i<rozmiar; i++)
    {
      suma+=pow((wektor[i]-Wek[i]),2);

    }

    return sqrt(suma);
}

Wektor<rozmiar>()
{
for(int i=0; i<rozmiar; i++)
 {
  wektor[i]=0;
  
 }
 ++ilosc_wek_ogolnie;
 ++ilosc_aktualnie;
}

~Wektor<rozmiar> ()
{
  --ilosc_aktualnie;
  ++ilosc_usunietych;
}




static int Zwroc_ilosc_wek_ogolnie()
{
  return ilosc_wek_ogolnie;
}
static int Zwroc_ilosc_aktualnie()
{
  return ilosc_aktualnie;
}
static int Zwroc_ilosc_usunietych()
{
  return ilosc_usunietych;
}



};



/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <int rozmiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<rozmiar> &Wek)
{

    for(int i=0; i<rozmiar; i++)
    {
        Strm << Wek[i] << " ";
    }

    return Strm;

}

template <int rozmiar>
std::istream& operator >> (std::istream &Strm, Wektor<rozmiar> &Wek)
{
   for(int i=0; i<rozmiar; i++)
   {
       Strm >> Wek[i];
   }

   return Strm;
}



#endif
