
#include "ListeGezici.hpp"



ListeGezici::ListeGezici(Agac* basAgac)
{
    this->suankiAgac = basAgac;
    this->kacinciAgac = 0;
}

void ListeGezici::Sifirla(Agac* basAgac)
{
    suankiAgac = basAgac;
}

Agac* ListeGezici::Git(int sira)
{
    
    while(suankiAgac->sira != sira){
        suankiAgac = suankiAgac->sonrakiAgac;
        //cout <<"Aranuyor";

    }
    if(suankiAgac->sira==sira){
        return suankiAgac;
        //cout <<"gidildi";
    }
    
    throw runtime_error("Hedef liste bulunamadi.");
    
    
}





