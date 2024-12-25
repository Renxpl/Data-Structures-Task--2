
#ifndef KUYRUK_HPP
#define KUYRUK_HPP
#include "KuyrukDugum.hpp"
#include <iomanip>


class Kuyruk{
    private:
    KuyrukDugum* basDugum;
    

    public:
    ~Kuyruk();
    KuyrukDugum* takip;
    Kuyruk(Dugum*);

    void TakibiSifirla();

    void Ekle(Dugum*);
    
    void Cikar();
    void Yazdir(int);
    KuyrukDugum* BasDugumDon();






};










#endif