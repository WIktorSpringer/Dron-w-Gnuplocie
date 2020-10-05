#ifndef ObiektSceny_HH
#define ObiektSceny_HH
#include "Dron.hh"


class Dron;

class ObiektSceny
{

public:
    virtual bool czy_kolizja(shared_ptr<Dron> dorn_obsl)=0;


};






#endif // ObiektSceny_HH
