#include "Dron.hh"

/*!
 * \file  Dron.hh
 *
 *  Plik zawiera definicje i instukcje metod klasy Dron
 *
 */


/*!
 * \brief zapisz do pliku
 *
 *Otwiera odpowiedni plik oraz zapisuje do niego wspolrzedne danej figur
 */
void Dron::zapisz_do_pliku()
{
    ofstream Plik;
    Plik.open("dat/prostopadloscian"+to_string(id)+".dat" );
    Plik<< Pr;
    Plik.close();

    Plik.open("dat/graniastoslup1"+to_string(id)+".dat");
    Plik<< Gr[0];
    Plik.close();

    Plik.open("dat/graniastoslup2"+to_string(id)+".dat");
    Plik<< Gr[1];
    Plik.close();

    Plik.open("dat/graniastoslup3"+to_string(id)+".dat");
    Plik<< Gr[2];
    Plik.close();

    Plik.open("dat/graniastoslup4"+to_string(id)+".dat");
    Plik<< Gr[3];
    Plik.close();

}
/*!
 * \brief Zapis Drona
 *
 * \param  Kat_st kat nachylenia drona
 * \param  x_tran parametr wplywajacy na okreslenie wspolrzednej x srodka dronu
 * \param  z_tran parametr wplywajacy na okreslenie wspolrzednej z srodka dronu
 */

bool Dron::ZapiszDrona(double Kat_st, double x_trans=0, double z_trans=0)
{
    if (!Pr.ZapiszProstopadloscian(x_trans,z_trans)) return false;
    if (!Gr[0].ZapiszGraniastoslup6(
                Kat_st,
                x_trans+PROSTOKAT_X,
                PROSTOKAT_Y,
                z_trans
            )) return false;
    if (!Gr[1].ZapiszGraniastoslup6(
                -Kat_st,
                x_trans-PROSTOKAT_X,
                PROSTOKAT_Y,
                z_trans
            )) return false;
    if (!Gr[2].ZapiszGraniastoslup6(
                Kat_st,
                x_trans-PROSTOKAT_X,
                -PROSTOKAT_Y,
                z_trans
            )) return false;
    if (!Gr[3].ZapiszGraniastoslup6(
                -Kat_st,
                x_trans+PROSTOKAT_X,
                -PROSTOKAT_Y,
                z_trans
            )) return false;
    Wektor3D wek1;
    wek1[0]=x_trans;
    wek1[1]=0;
    wek1[2]=z_trans;
    Pr.zmien_srodek(wek1);
    zapisz_do_pliku();
    return true;
}
/*!
 * \brief Animacja ruchu obrotoweg wzgledem srodka dronu
 *
 * Dzieki tej metodzie mozliwy jest obrot o zadany kat wzgledem srodka drona
 */
bool Dron::AnimacjaRuchuDrona_wzgledmpksrodka()
{
    double kat_stopnie;
    cout << "podaj kat oborcenia w stopniach C: "<< endl;
    cin>> kat_stopnie;



    for(int w=0; w<kat_stopnie; w=w+szybkosc_obrotu)
    {
        Ma.jednostkowa();

        Ma.tryg(szybkosc_obrotu);
        Ma=Ma^maskaZ(szybkosc_obrotu);
        Ma.ustaw_srodek(Pr.zwroc_srodek());
        Mdrogi=Mdrogi*Ma;

        for(int i=0; i< Pr.Zwroc_rozmiar(); i++)
            Pr[i]=Ma*Pr[i];

        for(int j=0; j<4; j++)
            for(int i=0; i<Gr[j].Zwroc_rozmiar(); i++)
                Gr[j][i]=Ma*Gr[j][i];

        for(int z=0; z<4; z++)
        {
            Wirniki.jednostkowa();


            Wirniki.tryg(szybkosc_wirnikow);
            Wirniki=Wirniki^maskaZ(szybkosc_wirnikow);
            Wirniki.ustaw_srodek(Gr[z][0]);
            for(int i=0; i<Gr[z].Zwroc_rozmiar(); i++)
                Gr[z][i]=Wirniki*Gr[z][i];
        }

        zapisz_do_pliku();
        usleep(50000);
        Lacze->Rysuj();
    }

    return true;
}
/*!
 * \brief Animacja ruchu po wektorze
 *
 * Dzieki tej metodzie mozliwy jest ruch postepowy o zadana odleglosc i kat
 */

bool Dron::AnimacjaRuchuDrona_doPrzodu( vector<shared_ptr<ObiektSceny>> tablica_obiektow,shared_ptr<Dron> D)
{
    double kat_stopnie,droga;
    Wektor3D wek1;
    bool czy_kolizja_zaszla=false;
    cout << "podaj kat nachylenia drogi w stopniach C: "<< endl;
    cin>> kat_stopnie;

    cout << "podaj dlugosc drogi: "<< endl;
    cin>> droga;



    wek1[0]=szybkosc_drona*cos(kat_stopnie*M_PI/180);
    wek1[1]=0;
    wek1[2]=szybkosc_drona*sin(kat_stopnie*M_PI/180);
    wek1=Mdrogi*wek1;
    for(int s=0; s<droga/szybkosc_drona; s++)
    {
        if(czy_kolizja_zaszla)
            break;

        Pr.zmien_srodek(Pr.zwroc_srodek()+wek1);
        for(int i=0; i< Pr.Zwroc_rozmiar(); i++)
            Pr[i]=wek1+Pr[i];

        for(int j=0; j<4; j++)
            for(int i=0; i<Gr[j].Zwroc_rozmiar(); i++)
                Gr[j][i]=wek1+Gr[j][i];
        for(int z=0; z<4; z++)
        {
            Wirniki.jednostkowa();

            Wirniki.tryg(szybkosc_wirnikow);
            Wirniki=Wirniki^maskaZ(szybkosc_wirnikow);
            Wirniki.ustaw_srodek(Gr[z][0]);
            for(int i=0; i<Gr[z].Zwroc_rozmiar(); i++)
                Gr[z][i]=Wirniki*Gr[z][i];
        }
        for(int w=0; w<tablica_obiektow.size(); w++)
        {
            if(tablica_obiektow[w]!=D)
            {

                czy_kolizja_zaszla=tablica_obiektow[w]->czy_kolizja(D);

            }
            if(czy_kolizja_zaszla)
                break;
        }
        zapisz_do_pliku();
        usleep(50000);
        Lacze->Rysuj();
    }

    return true;
}
/*!
 * \brief Wstawie pod szybkosc ruchu postepowego
 * Dzieki tej metodzie mozemy ustawic szybkosc przesuwania sie drona
 *
 * \param  i wartosc jaka przyjmie element klasy Dron : szybkosc_drona paramtr
 * nie zmienia swojej wartosci
 */

void Dron::Wstaw_pod_szybDrona(const int  i)
{
    szybkosc_drona=i;
}


/*!
 * \brief Wstawie pod szybkosc ruchu Wirnikow
 * Dzieki tej metodzie mozemy ustawic szybkosc przesuwania sie wirnikow drona
 *
 * \param  i wartosc jaka przyjmie element klasy Dron : szybkosc_wirnikow paramtr
 * nie zmienia swojej wartosci
 */
void Dron::Wstaw_pod_szybWirnikow(const int  i)
{
    szybkosc_wirnikow=i;
}
/*!
 * \brief Wstawie pod szybkosc ruchu obrotowego
 * Dzieki tej metodzie mozemy ustawic szybkosc obrotu drona
 *
 * \param  i wartosc jaka przyjmie element klasy Dron : szybkosc_obrotu paramtr
 * nie zmienia swojej wartosci
 */
void Dron::Wstaw_pod_szybObrotu(const int  i)
{
    szybkosc_obrotu=i;
}


bool Dron::czy_kolizja(shared_ptr<Dron> dorn_obsl)
{
    Wektor3D wek1;
    double odleglosc_X_Y, odelglosc_Z;

    wek1=dorn_obsl->zwroc_srodek();
    odleglosc_X_Y=sqrt(pow(wek1[0]-Pr.zwroc_srodek()[0],2)+pow(wek1[1]-Pr.zwroc_srodek()[1],2));
    odelglosc_Z=sqrt(pow(wek1[2]-Pr.zwroc_srodek()[2],2));

    if(odleglosc_X_Y<20 && odelglosc_Z<15)
    {
        cout << "KOLIZJA Z DRONEM" << endl;
        return true;
    }

    return false;


}
