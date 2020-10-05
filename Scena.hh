#ifndef SCENA_HH
#define SCENA_HH


#include "Dron.hh"
#include "Wektor3D.hh"
#include "Przeszkoda.hh"

#include <vector>
#include <memory>


template<int rozmiar> int Wektor<rozmiar>::ilosc_aktualnie=0;
template<int rozmiar> int Wektor<rozmiar>::ilosc_wek_ogolnie=0;
template<int rozmiar> int Wektor<rozmiar>::ilosc_usunietych=0;


void menu_wypisz()
{


    cout<<"##########     MENU      ################" << endl;
    cout << "1. Obrot wzgledem srodka" <<endl;
    cout << "2. przesuniecie o dany kont i dana odleglosc" <<endl;
    cout << "3. Ustawienie szybkosci przesuwania drona !(domyslnie 1)" <<endl;
    cout << "4. Ustawienie szybkosci obracania drona !(domyslnie 1)" <<endl;
    cout << "5. Ustawienie szybkosci obracania wirnikow !(domyslnie 100)" <<endl;
    cout << "6. Wybor drona" <<endl;
    cout << "7. Koniec" <<endl;
    cout << "############################################" <<endl;

    cout << "INF o wektorach:"<< endl;
    cout << "ilosc aktualna:  " << Wektor3D::Zwroc_ilosc_aktualnie() << endl;
    cout << "ilosc ogolna:  " << Wektor3D::Zwroc_ilosc_wek_ogolnie() << endl;
    cout << "ilosc usunietych:  " << Wektor3D::Zwroc_ilosc_usunietych() << endl;


}


class Scena
{
    int opcja;
    bool ciaglasc=true;
    PzG::LaczeDoGNUPlota  Lacze;

    vector<shared_ptr<Dron>> tablica_dronow;
    vector<shared_ptr<ObiektSceny>> tablica_obiektow;
public:
    Scena ()
    {
        Wektor3D wek1, wek2;

        wek1[0]=80;
        wek1[1]=80;
        wek1[2]=80;


        wek2[0]=90;
        wek2[1]=90;
        wek2[2]=90;


        Lacze.ZmienTrybRys(PzG::TR_3D);
        Lacze.Inicjalizuj();

        Lacze.UstawZakresX(-150, 150);
        Lacze.UstawZakresY(-150, 150);
        Lacze.UstawZakresZ(-150, 150);


        Lacze.UstawRotacjeXZ(64,65);
        shared_ptr<Dron> D(new Dron(&Lacze,1));
        D->ZapiszDrona(0,0,0);
        tablica_dronow.push_back(D);
        tablica_obiektow.push_back(D);
        shared_ptr<Dron> D2(new Dron(&Lacze,2));
        D2->ZapiszDrona(0,90,90);
        tablica_dronow.push_back(D2);
        tablica_obiektow.push_back(D2);
        shared_ptr<Przeszkoda> przeszkoda1(new Przeszkoda(wek1, wek2,40, &Lacze, 1));
        tablica_obiektow.push_back(przeszkoda1);
        Lacze.Rysuj();

        wek1[0]=80;
        wek1[1]=-80;
        wek1[2]=80;

        wek2[0]=-90;
        wek2[1]=-90;
        wek2[2]=90;

        shared_ptr<Przeszkoda> przeszkoda2(new Przeszkoda(wek1, wek2,40, &Lacze, 2));
        tablica_obiektow.push_back(przeszkoda2);
        Lacze.Rysuj();
    }




    void Obsluga_Drona ()
    {
        shared_ptr<Dron> D=tablica_dronow[0];
        while(ciaglasc)
        {
            menu_wypisz();
            cout << "wybierz opcje: ";
            cin >> opcja;
            cout <<endl;
            switch (opcja)
            {
            case 1:

                if (!D->AnimacjaRuchuDrona_wzgledmpksrodka())
                {
                    cout << endl
                         << " Problem z zapisem plikow. Prawdopodobnie brak dostepu." << endl
                         << endl;

                    return;
                }

                break;

            case 2:

                if (!D->AnimacjaRuchuDrona_doPrzodu(tablica_obiektow,D))
                {
                    cout << endl
                         << " Problem z zapisem plikow. Prawdopodobnie brak dostepu." << endl
                         << endl;
                    return ;
                }

                break;

            case 3:
                double szybkosc;
                cout<< "Ustaw szybkosc przesuwania sie dronu: ";
                cin >> szybkosc;
                cout <<endl;
                D->Wstaw_pod_szybDrona(szybkosc);
                break;

            case 4:
                double szybkosc1;
                cout<< "Ustaw szybkosc obracania sie dronu: ";
                cin >> szybkosc1;
                cout <<endl;
                D->Wstaw_pod_szybObrotu(szybkosc1);
                break;

            case 5:
                double szybkosc2;
                cout<< "Ustaw szybkosc wirnikow: ";
                cin >> szybkosc2;
                cout <<endl;
                D->Wstaw_pod_szybWirnikow(szybkosc2);
                break;



            case 6:
                int nr_drona;
                cout << "Wybierz drona" <<endl;
                cin >> nr_drona;
                D=tablica_dronow[nr_drona-1];
                break;

             case 7:
                ciaglasc=false;
                break;


            default:
                cout<< "bledny wybor opcji!!"<<endl;

                break;
            }
        }

    }
};

#endif
