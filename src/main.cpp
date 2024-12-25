
#include "BagliListe.hpp"
#include "Agac.hpp"
#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;


int main(){
    Agac* agac;
    BagliListe* bagliListe;
    
    ifstream agaclarDosya("./agaclar.txt");
    //cout << "dosya acildi"<<endl;
    if (!agaclarDosya) {
        cout<<"agaclar.txt dosyasi acilamadi";
        return 1;
    }

    char harf;

    int sayi = 0;

    int hangiAgac = 0;

    int hangiIslem = 0;

    while(agaclarDosya.get(harf)){

        if(harf == '\n'){
            hangiAgac++;
            //cout<<" satir degisti "<<endl;
            sayi = 0;
        }
        else if(harf == ' '){

        }

        else{
            if(sayi == 0){
            if(hangiAgac == 0){
             //   cout<< "okunma basladi"<<endl;
                agac = new Agac(harf);
                bagliListe = new BagliListe(agac);
            }
            else{
                //cout<< "okunma basladi"<<endl;
                agac = new Agac(harf);
                //cout<< "agac olusturuldu"<<endl;
                bagliListe->Ekle(agac);
              //  cout<< "bagliListeye eklendi"<<endl;
            }   


            //bagliListe->Yazdir();
            }
            else{
             // cout<< "okunma basladi"<<endl;
            agac->Ekle(agac->BasDugumGetir(),harf);
            }


            //cout<<harf;
            sayi++;
        }


    }
    /*
    cout <<"Yazdirilmaya geciliyor"<< endl;
    bagliListe->Yazdir();
    
    bagliListe->Cikar(0);
    bagliListe->Cikar(3);
    bagliListe->Cikar(7);
    bagliListe->Yazdir();
    
    cout <<"onceki toplam:" << bagliListe->ToplamaYaptirt(8)<<endl;
    bagliListe->AynalamaYaptir(8);
    bagliListe->Yazdir();
    cout <<"sonraki toplam:"<< bagliListe->ToplamaYaptirt(8)<<endl;
    */

   //Secim



    int secim = 0;
    int index= 0; 
    int yazilacakSayi = 0;
    int sayfa = 0;
    int ustLimit= 0;
    char secme;

   while (secim!=-1){
    

    int j = 0;
    if(sayfa*10<= secim && (sayfa+1)*10>secim){
        

    }
    
    else if(secim < sayfa *10){
        sayfa-=1;
    }

    else if(secim>= (sayfa+1)*10){
        sayfa+=1;
    }
    j = sayfa *10;

    if((sayfa+1)*10<= bagliListe->BuyuklukDon()){
        ustLimit = (sayfa+1)*10;
    }
    else{
        ustLimit = bagliListe->BuyuklukDon();
    }

    for(int i = 0; i <3; i++){
        



        for(int y = j ; y < ustLimit; y++){

            for(int k = 0; k <17; k++){

                if(k < 14){
                    cout << ".";
                }
                else{
                    cout << " ";
                    
                }

            
            

            }
            if (y==(ustLimit-1)) {cout <<endl;}
            

            
/*
            if(i == 2){ 
                
                 for(int k = 0; k <17; k++){
                    
                    if(k < 14){
                    cout << ".";
                    }
                    else{
                    cout << " ";
                    }

            


                }
            }

*/

        }

        for(int y = j ; y < ustLimit; y++){


            for(int k = 0; k <17; k++){

                if(k ==0|| k == 13){
                    cout <<".";
                }
                else if(k>13){
                    cout <<" ";
                }
                if(i==0 && k == 1){
                    cout << right << setw(12)<< bagliListe->AgacDondur(y);
                }
                if(i ==1 && k == 1){
                    cout << right << setw(12)<< bagliListe->ToplamaYaptirt(y);
                }
                
                if(i==2  && k == 1){
                    if(y+1<bagliListe->BuyuklukDon())
                    cout << right << setw(12)<< bagliListe->AgacDondur(y+1);
                    else
                    cout << right << setw(12)<<"none";
                }



            }
            if (y==(ustLimit-1) ) {cout <<endl;}
        }
        

         
            for(int y = j ; y < ustLimit; y++){

            for(int k = 0; k <17; k++){
               if(i ==2){
                if(k < 14){
                    cout << ".";
                }
                else{
                    cout << " ";
                    
                }
               }
            
            

            }
            if (y==(ustLimit-1) && i==2) {cout <<endl;}



            }
       

        }

         for(int y = j ; y < ustLimit; y++){

            for(int k = 0; k <17; k++){
               
                if(k < 14 && secim == y){
                    cout << "^";
                }
                else{
                    cout << " ";
                    
                }
                
            
            

            }
            if (y==(ustLimit-1) ) {cout <<endl;}



        }
        for(int y = j ; y < ustLimit; y++){

            for(int k = 0; k <17; k++){
                
                if(k < 14 && secim == y){
                    cout << "|";
                }
                else{
                    cout << " ";
                    
                }
                
            
            

            }
            if (y==(ustLimit-1) ) {cout <<endl;}



        }

 
    


    
/*
    for(int i = 0; i < 10;i++){

        for(int j = 0 ; j<12; j++){
            if (j<8){
                cout<<".";
            }
            else{
                cout <<" ";
            }


        }

    
    }
    cout << endl;
    for(int i = 0; i < 10;i++){

        for(int j = 0 ; j<12; j++){
            if (j==0 || j==7){
                cout<<".";
            }


            else{
                cout <<" ";
            }


        }

     
    }
    cout << endl;

    for(int i = 0; i < 10;i++){

        for(int j = 0 ; j<12; j++){
            if (j<8){
                cout<<".";
            }
            else{
                cout <<" ";
            }


        }

    
    }


    cout << endl;
*/
    bagliListe->AgacYazdir(secim);
    
    cout<< "Secim: ";
    cin >> secme;


    switch(secme){
        case 'a':
            if(0<secim)secim--;
            break;
        case 'd':
            if(bagliListe->BuyuklukDon()-1>secim)secim++;
            break;
        case 's':
            if(bagliListe->BuyuklukDon()>0) bagliListe->Cikar(secim);
            if(0<secim)secim--;
            break;
        case 'w':
            if(bagliListe->BuyuklukDon()>0) bagliListe->AynalamaYaptir(secim);
            break;
        case 'o':
            secim=-1;
            break;
        case 'A':
            if(0<secim)secim--;
            break;
        case 'D':
            if(bagliListe->BuyuklukDon()-1>secim)secim++;
            break;
        case 'S':
            if(bagliListe->BuyuklukDon()>0) bagliListe->Cikar(secim);
            if(0<secim)secim--;
            break;
        case 'W':
            if(bagliListe->BuyuklukDon()>0) bagliListe->AynalamaYaptir(secim);
            break;
        case 'O':
            secim=-1;
            break;    
        default:

            break;

    }


   }





    agaclarDosya.close();
    delete bagliListe;


}