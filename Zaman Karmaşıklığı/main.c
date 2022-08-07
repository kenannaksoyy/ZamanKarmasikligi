#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct satirlar
{
    char kodSatir[100];
    int kodSatirNo;
} strlr[1000];

int donguKontrolcu(char fSatir[50])
{
    int i,j,k;
    for(i=0; i<strlen(fSatir); i++)
    {
        if(fSatir[i]=='f' && fSatir[i+1]=='o' && fSatir[i+2]=='r')
        {
            return 1;
        }
    }
    for(j=0; j<strlen(fSatir); j++)
    {
        if(fSatir[j]=='w' && fSatir[j+1]=='h' && fSatir[j+2]=='i' && fSatir[j+3]=='l' && fSatir[j+4]=='e')
        {
            return 2;
        }
    }
    return 0;
}

int main()
{

    int maxTahminiSatirUzunlugu = 255;
    char satir[maxTahminiSatirUzunlugu];
    char dosyaIsim[30]="KodParcasi.txt";
    int kodSatirSayisi=0;


    FILE *dosya = fopen(dosyaIsim,"r");

    if ((dosya = fopen(dosyaIsim,"r"))==NULL)
    {
        printf("Dosya acilamadi");
        exit(1);
    }
    else
    {
        while(fgets(satir, maxTahminiSatirUzunlugu, dosya))
        {
            printf("%s", satir);
            strcpy(strlr[kodSatirSayisi].kodSatir,satir);
            strlr[kodSatirSayisi].kodSatirNo=kodSatirSayisi;
            kodSatirSayisi=kodSatirSayisi+1;
        }

    }
    int degiskenSayac=0;
    int diziBoyut=0;
    int i,j,z;
    for(i=0; i<kodSatirSayisi; i++)
    {
        for(j=0; j<strlen(strlr[i].kodSatir); j++)
        {
            if(strlr[i].kodSatir[j]=='i' && strlr[i].kodSatir[j+1]=='n' && strlr[i].kodSatir[j+2]=='t' && strlr[i].kodSatir[j+3]==' ')
            {
                if(strlr[i].kodSatir[j+4]!='m' && strlr[i].kodSatir[j+5]!='a')
                {
                    degiskenSayac=degiskenSayac+1;
                    for(z=0; z<strlen(strlr[i].kodSatir); z++)
                    {
                        if(strlr[i].kodSatir[z]=='[')
                        {
                            diziBoyut=diziBoyut+1;
                        }
                    }
                    for(z=0; z<strlen(strlr[i].kodSatir); z++)
                    {
                        if(strlr[i].kodSatir[z]==',')
                        {
                            degiskenSayac=degiskenSayac+1;
                        }
                    }
                }
            }
        }
    }

    int tut1,tut2,i1;
    int donguDerinlik=0;
    int susluSayac=0;
    int tut1Dizi[15],tut2Dizi[15];
    int donguSayac=0;
    int donguBul;
    for(i=0; i<kodSatirSayisi; i++)
    {
        donguBul=donguKontrolcu(strlr[i].kodSatir);
        if(donguBul==1 || donguBul==2)
        {
            susluSayac=0;
            tut1=strlr[i].kodSatirNo;
            tut1Dizi[donguSayac]=tut1;
            for(j=tut1; j<kodSatirSayisi; j++)
            {
                for(z=0; z<strlen(strlr[j].kodSatir); z++)
                {
                    if(strlr[j].kodSatir[z]=='}' && susluSayac==0)
                    {
                        tut2=j;
                        susluSayac=susluSayac+1;
                        tut2Dizi[donguSayac]=tut2;
                        donguSayac=donguSayac+1;
                    }
                }
                if(susluSayac!=0)
                {
                    break;
                }
            }
        }
    }
    int donguDerinlikDizi[10];
    printf("\nDongu Parcalari\n\n");
    for(i=0; i<donguSayac; i++)
    {
        donguDerinlikDizi[i]=0;
        for(j=tut1Dizi[i]; j<=tut2Dizi[i]; j++)
        {
            printf("!!!!!! ");
            printf("%s",strlr[j].kodSatir);
            donguBul=donguKontrolcu(strlr[j].kodSatir);
            if(donguBul==1 || donguBul==2)
            {
                donguDerinlikDizi[i]=donguDerinlikDizi[i]+1;
            }
            printf("\n");
        }
        printf("Dongu Derinligi %d\n",donguDerinlikDizi[i]);
        printf("---------------------\n");
    }
    int maxDerinlik=0;
    for(i=0; i<donguSayac; i++)
    {
        if(maxDerinlik<donguDerinlikDizi[i])
        {
            maxDerinlik=donguDerinlikDizi[i];
        }
    }




    if(diziBoyut!=0)
    {
        printf("Yer Karmasikligi = 4n^%d + %d\n", diziBoyut, 4*(degiskenSayac-1));
        printf("Zaman Karmasikligi = O(n^%d)\n",maxDerinlik);
    }
    if(diziBoyut==0)
    {
        printf("Yer Karmasikligi = %d",4*degiskenSayac);
        printf("Zaman Karmasikligi = O(n^%d)\n",maxDerinlik);
    }



    return 0;
}
