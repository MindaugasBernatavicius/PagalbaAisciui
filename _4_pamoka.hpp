#include <stdlib.h>


int rasosMasyvas [] = {37, 49, 58, 125, 200, 545, 685, 721};
int rimoMasyvas [] = {49, 52, 66, 133, 200};

void ketvirtaPamoka(){

    // ... suskaiciuojame kiek rasos masyve yra dvizenkliu
    int kiekDvizenkliu = 0;
    for(int i = 0; i < sizeof(rasosMasyvas)/sizeof(rasosMasyvas[0]); i++){
        if(rasosMasyvas[i] > 99){
            kiekDvizenkliu = i;
            break;
        }
    }

    // ... kuriame nauja, didesni masyva rimui, kuris talpins senus rimo indeksus ir naujus dvizenklius
    int naujoRimoMasyvoDydis = (sizeof(rimoMasyvas)/sizeof(rimoMasyvas[0])) + kiekDvizenkliu;
    int naujasRimoMasyvas[naujoRimoMasyvoDydis];

    // ... konstruojame nauja rimo masyva
    // TODO :: nebedeti 3-zenkliu skaiciu !!!!
    int kiekRasosPanaudota = 0;
    int kiekRimoPanaudota = 0;
    for(int i = 0; i < naujoRimoMasyvoDydis; i++){
        if(kiekRasosPanaudota < kiekDvizenkliu){
            if(rimoMasyvas[kiekRimoPanaudota] < rasosMasyvas[kiekRasosPanaudota]){
                naujasRimoMasyvas[i] = rimoMasyvas[kiekRimoPanaudota];
                kiekRimoPanaudota++;
            } else {
                naujasRimoMasyvas[i] = rasosMasyvas[kiekRasosPanaudota];
                kiekRasosPanaudota++;
            }
        } else {
            naujasRimoMasyvas[i] = rimoMasyvas[kiekRimoPanaudota];
            kiekRimoPanaudota++;
        }
    }

    for(int i = 0; i < naujoRimoMasyvoDydis; i++){
        cout << naujasRimoMasyvas[i];
        if(i != naujoRimoMasyvoDydis - 1)
            cout << ", ";
    }
    cout << endl;


    // ... suzinome, kiek trizenkliu skaiciu yra rimo masyve ir nuo kurios vietos ji prasideda
    int kiekTrizenkliu = 0;
    int trizenkliuPradzia = 0;
    int senoRimoMasyvoDydis = sizeof(rimoMasyvas)/sizeof(rimoMasyvas[0]);
    for(int i = 0; i < senoRimoMasyvoDydis; i++){
        if(rimoMasyvas[i] > 99){
            kiekTrizenkliu = senoRimoMasyvoDydis - i;
            trizenkliuPradzia = i;
            break;
        }
    }


    // ... konstruojame naujaji rasos masyva - iskart nebedesime dvizeznkliu skaiciu
    for(int i = trizenkliuPradzia; i < kiekTrizenkliu + trizenkliuPradzia; i++){
        cout << rimoMasyvas[i] << endl;
    }

    cout << endl << "kiekTrizenkliu : " << kiekTrizenkliu << endl;
    cout << endl << "trizenkliuPradzia : " << trizenkliuPradzia << endl;
    exit (EXIT_SUCCESS);
}
