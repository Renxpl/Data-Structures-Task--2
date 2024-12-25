
#include "Agac.hpp"

Agac::Agac(char karakter)
{
    this->basDugum = new Dugum(karakter);   
    this->sonrakiAgac = nullptr;
    
}

Agac::~Agac()
{

    

}

void Agac::Ekle(Dugum* dugum, char karakter)
{
    /*
    gezici->Sifirla(basDugum);
    bool sol = true;
    bool sag = false;
    bool arananDugumBulundu=false;
    while(!arananDugumBulundu){

        if(karakter < gezici->DugumDon()->karakter){
            if(gezici->DugumDon()->solDugum != nullptr)
            gezici->Git(sol);
            else{
                arananDugumBulundu=true;
                gezici->DugumDon()->yaprakMI =false;
                gezici->DugumDon()->solDugum = new Dugum(karakter);
            } 

        }

        else if(karakter >= gezici->DugumDon()->karakter){
            if(gezici->DugumDon()->sagDugum != nullptr)
            gezici->Git(sag);
            else{
                arananDugumBulundu=true;
                gezici->DugumDon()->yaprakMI =false;
                gezici->DugumDon()->sagDugum = new Dugum(karakter);
            } 
            

        }
       
    }*/

   if(dugum== nullptr) return;

   if(karakter < dugum->karakter){
        if(dugum->solDugum != nullptr) Ekle(dugum->solDugum, karakter);
        else dugum->solDugum = new Dugum(karakter);
   }
    else{
        if(dugum->sagDugum != nullptr) Ekle(dugum->sagDugum, karakter);
        else dugum->sagDugum = new Dugum(karakter);
    }

    

}


void Agac::Yazdir(Dugum* dugum, int katsayi, int derece)
{
    if(dugum ==nullptr) return;
    /*
    //Inorder yazım
    Yazdir(dugum->solDugum);
    cout << dugum->karakter;
    Yazdir(dugum->sagDugum);
    
    //Postorder yazım
    Yazdir(dugum->solDugum);
    Yazdir(dugum->sagDugum);
    cout << dugum->karakter;
    */
  
    /*
    
    int tutamac = derece;
    for(int i = 0; i < derece ; i++){
        for(int j = 0 ; j<tutamac; j++){
            cout << setw(katsayi/tutamac+1) << right<< dugum->karakter;
        }
    

    tutamac*=2;
    cout <<endl;


    }*/

    int derecee = DereceDondur(dugum,0);
    int levelBuyukluk =1;

    int total = 1;
    for(int i = 0 ; i < derecee+1;i++){
        total*=2;
    }


    Kuyruk* yeni = new Kuyruk(basDugum);
    int satir ;
    for(int j = 0 ; j < derecee;j++){
        int artisMiktari=4;
        int satir=4;
        for(int k = 1 ; k <derecee-j;k++){

            satir = (satir *2 + (artisMiktari))/2;
            artisMiktari*=2;


        }   
        int y = 0;

        bool nullMu= false;
        bool gSayacBaslat=false;
        int sayac = 0;
        int gSayac=0;
        yeni->TakibiSifirla();
        for(int k = 0; k< total;k++){
            if(j!=0){
                if(k== satir-1+(y*artisMiktari)){
                    if(yeni->takip->suankiDugum != nullptr){
                        nullMu=false;
                        cout<<"."; 
                        if(yeni->takip->sonraki!= nullptr && yeni->takip->sonraki->suankiDugum == nullptr ){
                            gSayacBaslat=true;
                        }
                    }
                    else{
                        if(yeni->takip->sonraki!= nullptr && yeni->takip->sonraki->suankiDugum == nullptr ){
                            sayac = artisMiktari-1;
                        }
                        else if(yeni->takip->sonraki!= nullptr && yeni->takip->sonraki->suankiDugum != nullptr){
                            sayac = (artisMiktari/2)-1;
                        }
                        nullMu = true;
                        cout<< " ";
                        
                    }
                    y++;
                    
                        yeni->takip =yeni->takip->sonraki;
                    
                    
                   
                    
                }
                else if(y % 2 == 1 ){
                    if (gSayac==(artisMiktari/2))
                    {
                        sayac=(artisMiktari/2)-1;
                        gSayacBaslat=false;
                    }
                    
                    if(sayac==0){
                        
                        cout<<".";
                        if(gSayacBaslat)
                        gSayac++;
                    }
                    else{
                        cout<< " ";
                        sayac--;
                    }
                }
                    
                else if(y%2==0) {
                    cout <<" ";
                    sayac = 0;
                    if(gSayac>0) 
                    gSayac= 0;
                }

            }
            


        }
        //total *=2;
        cout << endl;
        y = 0;
        yeni->TakibiSifirla();
        for(int k = 0; k< total;k++){
            
            if(j!=0){
                if(k== satir-1+(y*artisMiktari)){
                    if(yeni->takip->suankiDugum != nullptr){
                        cout<<"."; 
                    }
                    else{
                        cout<< " ";
                    }
                    y++;
                    yeni->takip =yeni->takip->sonraki;
                }
                    
                else 
                    cout <<" ";

            }
            
        

        }
        yeni->TakibiSifirla();
        cout << endl;
       

        for(int i = 0; i < levelBuyukluk; i++){
            
            
            if(i==0)
            yeni->Yazdir(satir);
            else
            yeni->Yazdir((artisMiktari));
            if(yeni->BasDugumDon()->suankiDugum== nullptr){
                yeni->Ekle(nullptr);
                yeni->Ekle(nullptr);
            }
            else{
            if(yeni->BasDugumDon()->suankiDugum->solDugum!= nullptr){
                yeni->Ekle(yeni->BasDugumDon()->suankiDugum->solDugum);

            }
            else{
                yeni->Ekle(nullptr);
            }
            
            if(yeni->BasDugumDon()->suankiDugum->sagDugum!= nullptr){
                yeni->Ekle(yeni->BasDugumDon()->suankiDugum->sagDugum);

            }
            else{
                yeni->Ekle(nullptr);
            }

            
            }
            yeni->Cikar();

        }
        cout <<endl;

        levelBuyukluk*=2;
        


    }
    




    
    
    delete yeni;



    
}

int Agac::Toplam(Dugum* dugum, int katsayi)
{
    if(dugum == nullptr) return 0;

    return Toplam(dugum->solDugum, 2) + Toplam(dugum->sagDugum, 1) + (katsayi * dugum->karakter);


}

void Agac::Aynala(Dugum* dugum)
{
    if(dugum == nullptr) return;

    Aynala(dugum->solDugum);
    Aynala(dugum->sagDugum);
    Dugum* tutamac;
    tutamac = dugum ->solDugum;
    dugum->solDugum = dugum->sagDugum;
    dugum->sagDugum = tutamac;

}



Dugum* Agac::BasDugumGetir()
{
    return basDugum;
}

int Agac::DereceDondur(Dugum* dugum , int derece)
{
    if(dugum == nullptr) return derece;

    
    if(DereceDondur(dugum->sagDugum, derece+1)>DereceDondur(dugum->solDugum, derece+1)){
        return DereceDondur(dugum->sagDugum, derece+1);
    }    
    else{
        return DereceDondur(dugum->solDugum, derece+1);
    }


}

void Agac::AgacSil(Dugum* dugum)
{
    if(dugum==nullptr) return;


    AgacSil(dugum->solDugum);
    AgacSil(dugum->sagDugum);

    delete dugum;


}



