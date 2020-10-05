#ifndef Przeszkoda_HH
#define Przeszkoda_HH

#include "ObiektSceny.hh"
#include "Figura.hh"
#include "lacze_do_gnuplota.hh"



class Przeszkoda:public ObiektSceny, public Figura
{

    PzG::LaczeDoGNUPlota  *Lacze;
    int id;
public:
    Przeszkoda (const Wektor3D wek1, const Wektor3D wek2,int glebokosc, PzG::LaczeDoGNUPlota  *Lacze, int id)
    {
        this->Lacze=Lacze;
        this->id=id;
        string nazwa="dat/Przeszkoda"+to_string(id)+".dat";
        Lacze->DodajNazwePliku(&nazwa[0]);
        wieszcholki.resize(16);
        wieszcholki[0] = wek1;
        wieszcholki[0][2] = 0;

        wieszcholki[1][0] = wek1[0];
        wieszcholki[1][2] = 0;
        wieszcholki[1][1] = wek2[1];

        wieszcholki[2] = wek2;
        wieszcholki[2][2] = 0;

        wieszcholki[3][0] = wek2[0];
        wieszcholki[3][1] = wek1[1] ;
        wieszcholki[3][2] = 0;

        wieszcholki[4] = wek1;
        wieszcholki[4][2] = 0;

        wieszcholki[5] = wek1;
        wieszcholki[5][2] = glebokosc;

        wieszcholki[6] = wieszcholki[1];
        wieszcholki[6][2] = glebokosc;

        wieszcholki[7] = wieszcholki[1];

        wieszcholki[8] = wieszcholki[6];

        wieszcholki[9] = wieszcholki[2];
        wieszcholki[9][2] = glebokosc;

        wieszcholki[10] = wieszcholki[3];
        wieszcholki[10][2] = glebokosc;

        wieszcholki[11] = wieszcholki[0];
        wieszcholki[11][2] = glebokosc;

        wieszcholki[12] = wieszcholki[10];

        wieszcholki[13] = wieszcholki[3];

        wieszcholki[14] = wieszcholki[2];

        wieszcholki[15] = wieszcholki[2];
        wieszcholki[15][2] = glebokosc;
        ofstream Plik;
        Plik.open("dat/Przeszkoda"+to_string(id)+".dat" );
        for(int i=0; i<wieszcholki.size(); i++)
        {
            Plik << wieszcholki[i] << endl;

        }
        Plik.close();

        Lacze->Rysuj();
    }
    bool czy_kolizja(shared_ptr<Dron> dron_obsl)
    {
        double x=wieszcholki[0][0], x_min=wieszcholki[0][0];
        double y=wieszcholki[0][1], y_min=wieszcholki[0][1];
        double z=wieszcholki[0][2], z_min=wieszcholki[0][2];
        for(int i=0; i<wieszcholki.size(); i++)
        {
            if(x<wieszcholki[i][0])
                x=wieszcholki[i][0];
            if(x_min>wieszcholki[i][0])
                x_min=wieszcholki[i][0];


            if(y<wieszcholki[i][1])
                y=wieszcholki[i][1];
            if(y_min>wieszcholki[i][1])
                y_min=wieszcholki[i][1];


            if(z<wieszcholki[i][2])
                z=wieszcholki[i][2];
            if(z_min>wieszcholki[i][2])
                z_min=wieszcholki[i][2];
        }


        if(dron_obsl->zwroc_srodek()[0]<x+20 && dron_obsl->zwroc_srodek()[0]>x_min-20 &&
                dron_obsl->zwroc_srodek()[1]<y+20 && dron_obsl->zwroc_srodek()[1]>y_min-20 &&
                dron_obsl->zwroc_srodek()[2]<z+8 && dron_obsl->zwroc_srodek()[2]>z_min-8)
        {
            cout << "kolizja z (PRZESZKODA)" << endl;
            return true;
        }


        return false;
    }


};
#endif
