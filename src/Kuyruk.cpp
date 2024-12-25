
#include "Kuyruk.hpp"
Kuyruk::Kuyruk(Dugum* dugum)
{
    basDugum = new KuyrukDugum(dugum);
    takip = basDugum;
    
}

void Kuyruk::TakibiSifirla()
{
    takip= basDugum;
}

void Kuyruk::Ekle(Dugum* dugum)
{
    TakibiSifirla();
    while(takip->sonraki != nullptr){

        takip = takip->sonraki;
    } 

    takip->sonraki= new KuyrukDugum(dugum);


}

void Kuyruk::Cikar()
{
    KuyrukDugum* tutamac = basDugum;

    basDugum= basDugum->sonraki;
    TakibiSifirla();
    tutamac->suankiDugum=nullptr;
    delete tutamac;

}

void Kuyruk::Yazdir(int satir)
{   
    if(basDugum->suankiDugum== nullptr) {
        cout <<setw(satir) <<right << " "; 
        return;
    }
    cout <<setw(satir) <<right << basDugum->suankiDugum->karakter;
}

KuyrukDugum* Kuyruk::BasDugumDon()
{
    return basDugum;
}

Kuyruk::~Kuyruk()
{
    /*
    if(basDugum== nullptr) return;
    while(basDugum!=nullptr){
    KuyrukDugum* tutamac = basDugum;
    if(basDugum->sonraki!= nullptr)
    basDugum= basDugum->sonraki;
    tutamac->suankiDugum=nullptr;
    //delete tutamac;   

    }


*/
}
