#include "Macierz3x3.hh"


/*!
 * \file  Macierz3x3.cpp
 *  
 *  Plik zawiera instrukcje dzialania funkcji dla typ. Macierz3x3
 * Dokladnie plik zawiera maski nakladne na macierz 3x3
 *  
 */


Macierz3x3 maskaX(const double kat)  
{
    Macierz3x3 macierz;
    macierz[0][0]=1/cos(kat*M_PI/180);
    macierz[0][1]=0;
    macierz[0][2]=0;

    macierz[1][0]=0;
    macierz[1][1]=1;
    macierz[1][2]=-1;

    macierz[2][0]=0;
    macierz[2][1]=1;
    macierz[2][2]=1;
    return macierz;
}

Macierz3x3 maskaY(const double kat) 
{
    Macierz3x3 macierz;
    macierz[0][0]=1;
    macierz[0][1]=0;
    macierz[0][2]=1;

    macierz[1][0]=0;
    macierz[1][1]=1/cos(kat*M_PI/180);
    macierz[1][2]=0;

    macierz[2][0]=-1;
    macierz[2][1]=0;
    macierz[2][2]=1;
     return macierz;
}

Macierz3x3 maskaZ(const double kat) 
{
    Macierz3x3 macierz;
    macierz[0][0]=1;
    macierz[0][1]=-1;
    macierz[0][2]=0;

    macierz[1][0]=1;
    macierz[1][1]=1;
    macierz[1][2]=0;

    macierz[2][0]=0;
    macierz[2][1]=0;
    macierz[2][2]=1/cos(kat*M_PI/180);

     return macierz;
}


