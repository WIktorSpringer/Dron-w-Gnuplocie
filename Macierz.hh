#ifndef MACIERZ_HH
#define MACIERZ_HH


#include <iostream>
#include "Wektor.hh"
#include <math.h>
/*!
 * \file  Figura.hh
 *  
 *  Plik zawiera definicje klasy Figura
 *  
 */
template <int rozmiar>
class Macierz {
 Wektor<rozmiar> ma[rozmiar];
 Wektor<rozmiar> srodek_obrotu;

  public:

  void ustaw_srodek( Wektor<rozmiar> srodek)
  {
   srodek_obrotu=srodek;
  }

  Wektor<rozmiar> &operator[](const int i) 
 {
   return ma[i];


 }


  void tryg(const double kat) 
  {
    for(int i=0; i<rozmiar; i++)
    for(int j=0; j<rozmiar; j++)
    if (i==j) {
      ma[i][j]=cos(kat*M_PI/180);
    }
    else
    {
      ma[i][j]=sin(kat*M_PI/180);
    }


  }

 Wektor<rozmiar> operator *(const Wektor<rozmiar> wek) 
 {
   Wektor<rozmiar> wynik;
   for(int i=0; i<rozmiar; i++)
   wynik[i]=0;

   for(int i=0; i<rozmiar; i++)
    {
           for(int j=0; j<rozmiar; j++)
           wynik[i]+=ma[i][j]*(wek[j]-srodek_obrotu[j]);

           wynik[i]+=srodek_obrotu[i];

   }



   return wynik;

 }

 Macierz<rozmiar> operator^ (Macierz<rozmiar> macierz1) 
 {
   Macierz<rozmiar> wynik;

   for(int i=0; i<rozmiar; i++)
   for(int j=0; j<rozmiar; j++)
   {
     wynik[i][j]=ma[i][j]*macierz1[i][j];

   }

  return wynik;
 }


 Macierz<rozmiar> operator* (Macierz<rozmiar> macierz1) 
 {
   Macierz<rozmiar> wynik;
   double suma;
  for(int i=0; i<rozmiar; i++)
  for(int j=0; j<rozmiar; j++)
  {
    suma=0;

  for(int k=0; k<rozmiar; k++)
  {
    suma+=ma[i][k]*macierz1[k][j];


  }

  wynik[i][j]=suma;
  }
  return wynik;

 }


 void jednostkowa()
 {
  for(int i=0; i<rozmiar; i++)
  for(int j=0; j<rozmiar; j++)
  {
    if(i==j)
    {
      ma[i][j]=1;
    }
    else
    {
      ma[i][j]=0;
    }

 }
 }
 Macierz<rozmiar> ()
 {
  for(int i=0; i<rozmiar; i++)
  for(int j=0; j<rozmiar; j++)
  {
    if(i==j)
    {
      ma[i][j]=1;
    }
    else
    {
      ma[i][j]=0;
    }

  }



 }


};



#endif
