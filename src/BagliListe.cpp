
#include "BagliListe.hpp"

BagliListe::BagliListe(Agac* basAgac)
{
    this->basAgac = basAgac;
    this->buyukluk = 1;
    basAgac->sira = 0;
    gezici = new ListeGezici(basAgac);

}

BagliListe::~BagliListe()
{
    gezici->Sifirla(basAgac);
    
    for (int i = 0;i < buyukluk; i++)
    {
        
        Agac* silinecekAgac = gezici->Git(i);
        if(gezici->Git(i)->sonrakiAgac!=nullptr)
        gezici->Git(i)->sonrakiAgac;
        
        delete silinecekAgac;
     

    }





}

void BagliListe::Ekle(Agac* eklenecekAgac)
{
    
    gezici->Git(buyukluk-1)->sonrakiAgac = eklenecekAgac;
    eklenecekAgac->sira = buyukluk;
    buyukluk++;
    //cout<<"eklendi";
    
}

void BagliListe::Cikar(int sira)
{
    if(sira>= buyukluk || sira<0) 
    throw runtime_error("cikarmada hata, dizi siniri asildi");
    gezici->Sifirla(basAgac);
    Agac* oncekiAgac;
    Agac* silinecekAgac;
    if(sira != 0){
        
        oncekiAgac = gezici->Git(sira-1);
        silinecekAgac = gezici->Git(sira);
        oncekiAgac->sonrakiAgac = oncekiAgac->sonrakiAgac->sonrakiAgac;

    }
    else {
        silinecekAgac = basAgac;
        oncekiAgac= basAgac->sonrakiAgac;
        basAgac = oncekiAgac;
    }
    
    buyukluk--;
    gezici->Sifirla(basAgac);
    oncekiAgac = basAgac;
    for (int i = 0;i<buyukluk;i++)
    {
       
      
       oncekiAgac->sira = i;
       oncekiAgac=oncekiAgac->sonrakiAgac; 

    }
    silinecekAgac->AgacSil(silinecekAgac->BasDugumGetir());
    delete silinecekAgac;



}

void BagliListe::Yazdir()
{
    /*
    gezici->Sifirla(basAgac);
    
    for (int i = 0;i < buyukluk; i++)
    {
        
        cout <<i;
        
        gezici->Git(i)->Yazdir(gezici->Git(i)->BasDugumGetir());
        cout << endl;

    }*/

}

void BagliListe::AynalamaYaptir(int sira)
{
    gezici->Sifirla(basAgac);
    gezici->Git(sira)->Aynala(gezici->Git(sira)->BasDugumGetir());

}

int BagliListe::ToplamaYaptirt(int sira)
{
    gezici->Sifirla(basAgac);
    gezici->Git(sira)->Toplam(gezici->Git(sira)->BasDugumGetir(), 1);

}

Agac* BagliListe::AgacDondur(int sira)
{
    gezici->Sifirla(basAgac);

    return gezici->Git(sira);







}

int BagliListe::BuyuklukDon()
{
    return buyukluk;
}

void BagliListe::AgacYazdir(int sira)
{
    if(basAgac==nullptr) return;
    gezici->Sifirla(basAgac);
    
    int derece = gezici->Git(sira)->DereceDondur(gezici->Git(sira)->BasDugumGetir(), 0);
    int boslukSayisi = 3;
   
    int katsayi = 1;

    for(int i = 0; i< derece;i++){
        katsayi*=2;
    } 

    katsayi *= boslukSayisi;    
    gezici->Git(sira)->Yazdir(gezici->Git(sira)->BasDugumGetir(),katsayi,1);
    cout << endl;

    


}





