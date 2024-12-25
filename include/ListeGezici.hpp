
#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP
#include "Agac.hpp"

class ListeGezici{

    private:
        Agac *suankiAgac;
        int kacinciAgac;


    public:
        ListeGezici(Agac*);
        void Sifirla(Agac*);
        Agac* Git(int);





};



#endif