
#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP
#include <iostream>
#include "Dugum.hpp"
#include "ListeGezici.hpp"
#include "Agac.hpp"

class BagliListe{

    private:
        Agac *basAgac;
        int buyukluk;
        ListeGezici *gezici;
        

    public:
        
        

        BagliListe(Agac*);
        ~BagliListe();

        void Ekle(Agac*);

        void Cikar(int);

        void Yazdir();

        void AynalamaYaptir(int sira);

        int ToplamaYaptirt(int sira);
        
        Agac* AgacDondur(int sira);

        int BuyuklukDon();

        void AgacYazdir(int sira);

};







#endif