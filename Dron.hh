#ifndef Dron_HH
#define Dron_HH


#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory>
#include <cmath>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Macierz3x3.hh"
#include "ObiektSceny.hh"



/*!
 * \file  Dron.hh
 *
 *  Plik zawiera definicje klasy Dron
 *
 */

/*!
  * \brief Zestaw informacji dotyczący Drona
  *
  * Klasa modeluje zestaw informacji dotyczący dron i
  * zaawier metody, ktore dzialaja na obiekcie dron
  */
class Dron: public ObiektSceny
{
    /*!
     * \brief podstawa drona
     */
    Prostopadloscian Pr;
    /*!
     * \brief 4 wirniki drona
     */
    Graniastoslup Gr[4];
    /*!
     * \brief Macierz odpowiadajaca za obrot wzgledem x
     */
    Macierz3x3 Ma;
    /*!
     * \brief Macierz odpowiadajaca za kat ruchu postepowego drona
     */
    Macierz3x3 Mdrogi;
    /*!
     * \brief Macierz odpowiadajaca za krecenie wirnikow drona
     */
    Macierz3x3 Wirniki;
    /*!
     * \brief zmienna Lacze
     */
    PzG::LaczeDoGNUPlota  *Lacze;
    /*!
     * \brief zmienna okreslajaca szybkosc ruchu postepowego
     */
    double szybkosc_drona;
    /*!
     * \brief zmienna okreslajaca szybkosc ruchu wirnikow
     *
     */
    double szybkosc_wirnikow;
    /*!
     * \brief zmienna okreslajaca szybkosc obrotu
     */
    double szybkosc_obrotu;
    int id;
public:

    /*!
     * \brief konstruktor okreslajcy niektore parametry klasy dron
     * Lacze klasy zostaje zainicjalizowane oryginalnym laczem zadanym jako argumetn
     */
    Dron (  PzG::LaczeDoGNUPlota  *Lacze, int id)
    {
        this->Lacze=Lacze;
        szybkosc_drona=1;
        szybkosc_wirnikow=10;
        szybkosc_obrotu=1;
        this->id=id;
        string nazwa="dat/prostopadloscian"+to_string(id)+".dat";
        Lacze->DodajNazwePliku(&nazwa[0]);
        nazwa="dat/graniastoslup1"+to_string(id)+".dat";
        Lacze->DodajNazwePliku(&nazwa[0]);
        nazwa="dat/graniastoslup2"+to_string(id)+".dat";
        Lacze->DodajNazwePliku(&nazwa[0]);
        nazwa="dat/graniastoslup3"+to_string(id)+".dat";
        Lacze->DodajNazwePliku(&nazwa[0]);
        nazwa="dat/graniastoslup4"+to_string(id)+".dat";
        Lacze->DodajNazwePliku(&nazwa[0]);
    }
    /*!
     * \brief zapis do pliku
     */
    void zapisz_do_pliku();
    /*!
     * \brief ustalenie wspolrzednych drona
     */
    bool ZapiszDrona(double Kat_st, double x_trans, double z_trans);
    /*!
     * \brief zainicjalizowanie parametrow klasy opowiadajacych za szybkosc ruchu
     */
    void Wstaw_pod_szybDrona(const int  i);
    void Wstaw_pod_szybWirnikow(const int  i);
    void Wstaw_pod_szybObrotu(const int  i);
    /*!
     * \brief Metody opowiadajace za animowanie ruchu postepowego i obrotowego
     */
    bool AnimacjaRuchuDrona_wzgledmpksrodka();
    bool AnimacjaRuchuDrona_doPrzodu( vector<shared_ptr<ObiektSceny>> tablica_obiektow,shared_ptr<Dron> D);
    bool czy_kolizja(shared_ptr<Dron> Dorn_obsl);
    Wektor3D zwroc_srodek()
    {
        return Pr.zwroc_srodek();

    }


};

#endif
