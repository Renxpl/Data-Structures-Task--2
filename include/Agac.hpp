
#ifndef AGAC_HPP
#define AGAC_HPP
#include "Dugum.hpp"
#include <iomanip> 
#include "Kuyruk.hpp"


class Agac{
    private:
        Dugum *basDugum;


    public:
        int sira;
        Agac *sonrakiAgac;
        Agac(char);
        ~Agac();

        void Ekle(Dugum*,char);

        

        void Yazdir(Dugum*,int,int);
        
        int Toplam(Dugum* dugum, int katsayi);

        void Aynala(Dugum*);

        Dugum* BasDugumGetir();
       
        int DereceDondur(Dugum* dugum, int derece);

        void AgacSil(Dugum*);






};










#endif