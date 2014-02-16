#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FF 0.00
#define DD 1.00
#define DC 1.50
#define CC 2.00
#define CB 2.50
#define BB 3.00
#define BA 3.50
#define AA 4.00

int derssayisi;
float YANO, GANO;

struct dersyapisi{

    char adi[10];
    float YIBP;
    float GSBP;
    float but;
    float ort;
    float AP;   //Agirlikli Puani = Kredi x Basari Notu Katsayisi
    char ortharf[3]; //ortalamanin harf karsiligi
    int kredi;
    char sonuc[10];
    float harf; // define ile tanimlanan degerler
} ders[15];

void verial(struct dersyapisi sptr[],int n);

void harf(struct dersyapisi sptr[], int n); // ders notlarinin harf karsiliklari

void veriyaz(struct dersyapisi sptr[],int n);

float DonemOrt(struct dersyapisi sptr[], float harf, int n);  //Basarili sayilan derslerin ortalamasi

void DonemGenelOrt(struct dersyapisi sptr[], int n);    //Tum derslerin ortalaması


int main()
{

    printf("Kac tane dersin var? : ");
    scanf("%d",&derssayisi);


    verial(ders,derssayisi);
    harf(ders,derssayisi);
    if ((DonemOrt(ders, DD, derssayisi)) >= CC)
        {veriyaz(ders,derssayisi);}
    else if ((DonemOrt(ders, DC, derssayisi)) >= CC)
        {veriyaz(ders,derssayisi);}
    else if ((DonemOrt(ders, CC, derssayisi)) >= CC)
        {veriyaz(ders,derssayisi);}
    else printf("\nDurum kotu");

    DonemGenelOrt(ders, derssayisi);

    printf("\nBasarili olan derslerin ortalaması (YANO) : %.2f",YANO);
    printf("\nDonemde alinan tum derslerin ortalaması (GANO) : %.2f",GANO);


    printf("\nbitti\n");
    return 0;
}


void verial(struct dersyapisi sptr[],int n)
{
  int i;

  for(i=0;i<n;i++)
  {
  printf("\nDers adi :");
  scanf(" %[^\n]s",sptr[i].adi);  // bosluk karakterine ragmen stdin okumaya devam eder. exclude fgets...

  printf("\nDersinin yil içi başarı puanı (YIBP) : ");
  scanf("%f",&sptr[i].YIBP);

  printf("\nDersinin final notu : ");
  scanf("%f",&sptr[i].GSBP);

  printf("\nDersinin kredisi : ");
  scanf("%d",&sptr[i].kredi);

  sptr[i].ort = (sptr[i].YIBP*0.3) + (sptr[i].GSBP*0.7);

  }
}

void harf(struct dersyapisi sptr[], int n){

    int i;

    for(i=0;i<n;i++){
    if ((sptr[i].ort >= 55) && (sptr[i].ort < 60))
        {sptr[i].harf = DD;
         strcpy(sptr[i].ortharf, "DD");}
    else if ((sptr[i].ort >= 60) && (sptr[i].ort < 65))
        {sptr[i].harf = DC;
         strcpy(sptr[i].ortharf, "DC");}
    else if ((sptr[i].ort >= 65) && (sptr[i].ort < 70))
        {sptr[i].harf = CC;
         strcpy(sptr[i].ortharf, "CC");}
    else if ((sptr[i].ort >= 70) && (sptr[i].ort < 75))
        {sptr[i].harf = CB;
         strcpy(sptr[i].ortharf, "CB");}
   else if ((sptr[i].ort >= 75) && (sptr[i].ort < 80))
        {sptr[i].harf = BB;
         strcpy(sptr[i].ortharf, "BB");}
    else if ((sptr[i].ort >= 80) && (sptr[i].ort < 90))
        {sptr[i].harf = BA;
         strcpy(sptr[i].ortharf, "BA");}
    else if ((sptr[i].ort >=90) && (sptr[i].ort <=100))
        {sptr[i].harf = AA;
         strcpy(sptr[i].ortharf, "AA");}
    else {sptr[i].harf = FF;
          strcpy(sptr[i].ortharf, "FF");}

    sptr[i].AP = sptr[i].harf *  sptr[i].kredi;

    }

}

void veriyaz(struct dersyapisi sptr[],int n)
{


    int i;
    printf("\nDers Adi\t   Kredisi\tOrtalama\tAgırlıklı Puan\tOrt Harf Notu\tSonuc");

    for (i=0;i<n;i++){
    printf("\n%-10s\t    %d\t\t    %.2f\t\t%.2f\t   %s\t\t %s",sptr[i].adi, sptr[i].kredi,sptr[i].ort,sptr[i].AP,sptr[i].ortharf,sptr[i].sonuc);
    }

}


float DonemOrt(struct dersyapisi sptr[], float harf, int n){

    int i;
    int kredi=0;
    float AP=0;
 //   float ortalama;
    for (i=0;i<n;i++){
        if (sptr[i].harf >= harf){
            AP += sptr[i].AP;
            kredi += sptr[i].kredi;
        }
        else continue;
    }
    YANO = AP/kredi;
    if (YANO >= CC){
    for (i=0;i<n;i++){
        if (sptr[i].harf >= harf){
            strcpy(sptr[i].sonuc, "BASARILI");
        }
        else strcpy(sptr[i].sonuc, "BASARISIZ");
    }

    }
    return YANO;
}

void DonemGenelOrt(struct dersyapisi sptr[], int n){

    int i;
    int kredi=0;
    float AP=0;

    for (i=0;i<n;i++){
            AP += sptr[i].AP;
            kredi += sptr[i].kredi;
    }
    GANO =  AP/kredi;

}

