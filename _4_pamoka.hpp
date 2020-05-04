#include <stdlib.h>


int rasosMasyvas [] = {37, 49, 58, 125, 200, 545, 685, 721};
int rimoMasyvas [] = {49, 52, 66, 133, 200};

int kiekDvizenkliu(int arr [], int masyvoIlgis){
    int kiekDvizenkliu = 0;
    for(int i = 0; i < masyvoIlgis; i++){
        if(arr[i] > 99){
            kiekDvizenkliu = i;
            break;
        }
    }
    return kiekDvizenkliu;
}

int kiekTrizenkliu(int arr [], int masyvoIlgis){
    int kiekTrizenkliu = 0;
    for(int i = 0; i < masyvoIlgis; i++){
        if(arr[i] > 99){
            kiekTrizenkliu = masyvoIlgis - i;
            break;
        }
    }
    return kiekTrizenkliu;
}

void ketvirtaPamoka(){
    int rasosMasyvoDydis = sizeof(rasosMasyvas) / sizeof(rasosMasyvas[0]);
    int rimoMasyvoDydis = sizeof(rimoMasyvas) / sizeof(rimoMasyvas[0]);

    // ... suskaiciuojame kiek rasos masyve yra dvizenkliu
    int dviezenkliuSkaiciusRasosMasyve = kiekDvizenkliu(rasosMasyvas, rasosMasyvoDydis);
    int dviezenkliuSkaiciusRimoMasyve = kiekDvizenkliu(rimoMasyvas, rimoMasyvoDydis);

    // ... kuriame nauja, didesni masyva rimui, kuris talpins senus rimo indeksus ir naujus dvizenklius
    int naujoRasosMasyvoDydis = dviezenkliuSkaiciusRasosMasyve + dviezenkliuSkaiciusRasosMasyve;
    int naujasRasosMasyvas[naujoRasosMasyvoDydis];

    // ... konstruojame nauja rimo masyva
    int kiekRasosPanaudota = 0;
    int kiekRimoPanaudota = 0;
    for(int i = 0; i < naujoRasosMasyvoDydis; i++){
        if(rimoMasyvas[kiekRimoPanaudota] < rasosMasyvas[kiekRasosPanaudota]){
            naujasRasosMasyvas[i] = rimoMasyvas[kiekRimoPanaudota];
            kiekRimoPanaudota++;
        } else {
            naujasRasosMasyvas[i] = rasosMasyvas[kiekRasosPanaudota];
            kiekRasosPanaudota++;
        }
    }

    cout << "Rasos kolekcija:" << endl;
    for(int i = 0; i < naujoRasosMasyvoDydis; i++){
        cout << naujasRasosMasyvas[i];
        if(i != naujoRasosMasyvoDydis - 1)
            cout << ", ";
    }
    cout << endl;


    // ... suzinome, kiek trizenkliu skaiciu yra masyvuose
    int trizenkliuSkaiciusRasosMasyve = kiekTrizenkliu(rasosMasyvas, rasosMasyvoDydis);
    int trizenkliuSkaiciusRimoMasyve = kiekTrizenkliu(rimoMasyvas, rimoMasyvoDydis);

    int trizenkliuPradziaRasosMasyve = rasosMasyvoDydis - trizenkliuSkaiciusRasosMasyve;
    int trizenkliuPradziaRimoMasyve = rimoMasyvoDydis - trizenkliuSkaiciusRimoMasyve;

    int naujoRimoMasyvoDydis = trizenkliuSkaiciusRasosMasyve + trizenkliuSkaiciusRimoMasyve;
    int naujasRimoMasyvas[naujoRimoMasyvoDydis];


    kiekRasosPanaudota = 0;
    kiekRimoPanaudota = 0;
    for(int i = 0; i < naujoRimoMasyvoDydis; i++){
        if(trizenkliuPradziaRimoMasyve + kiekRimoPanaudota < rimoMasyvoDydis){
            if(rimoMasyvas[trizenkliuPradziaRimoMasyve + kiekRimoPanaudota]
                < rasosMasyvas[trizenkliuPradziaRasosMasyve + kiekRasosPanaudota])
            {
                naujasRimoMasyvas[i] = rimoMasyvas[trizenkliuPradziaRimoMasyve + kiekRimoPanaudota];
                kiekRimoPanaudota++;
            } else {
                naujasRimoMasyvas[i] = rasosMasyvas[trizenkliuPradziaRasosMasyve + kiekRasosPanaudota];
                kiekRasosPanaudota++;
            }
        } else {
            naujasRimoMasyvas[i] = rasosMasyvas[trizenkliuPradziaRasosMasyve + kiekRasosPanaudota];
            kiekRasosPanaudota++;
        }
    }

    cout << "Rimo kolekcija:" << endl;
    for(int i = 0; i < naujoRimoMasyvoDydis; i++){
        cout << naujasRimoMasyvas[i];
        if(i != naujoRimoMasyvoDydis - 1)
            cout << ", ";
    }
    cout << endl;

//    cout << "trizenkliuSkaiciusRasosMasyve: " << trizenkliuSkaiciusRasosMasyve << endl;
//    cout << "trizenkliuSkaiciusRimoMasyve: " << trizenkliuSkaiciusRimoMasyve << endl;
//
//    cout << "trizenkliuPradziaRasosMasyve: " << trizenkliuPradziaRasosMasyve << endl;
//    cout << "trizenkliuPradziaRimoMasyve: " << trizenkliuPradziaRimoMasyve << endl;

    exit (EXIT_SUCCESS);
}
