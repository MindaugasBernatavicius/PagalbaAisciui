#include <fstream>
#include <iostream>

using namespace std;

struct PratimoIrasas {
    string pratimoPavadinimas;
    int kartai;
};

void rikiuoti_bubble(PratimoIrasas arr[], int dydis){
    for(int i = 0; i < dydis; i++){
        for(int j = 0; j < dydis - 1; j++){
            if(arr[j].kartai < arr[j+1].kartai){
                PratimoIrasas tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void swap(PratimoIrasas *xp, PratimoIrasas *yp)  {
    PratimoIrasas temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void rikiuoti_selection(PratimoIrasas arr[], int dydis){
    int min_idx;
    for (int i = 0; i < dydis - 1; i++){
        min_idx = i;
        for (int j = i + 1; j < dydis; j++)  // perziurime likusius narius
            if (arr[j].kartai > arr[min_idx].kartai)
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
//        PratimoIrasas tmp = arr[min_idx];
//        arr[min_idx] = arr[i];
//        arr[i] = tmp;
    }
}

// TODO :: solve with chars also
void penktaPamoka(){
    const char inFailas [] = "U2.txt";
    const char outFailas [] = "U2rez.txt";

    int pratimuIrasuKiekis;
    ifstream fd(inFailas);
    fd >> pratimuIrasuKiekis;

    PratimoIrasas pratimoIrasai[pratimuIrasuKiekis];

    string laikinasPratPav;
    int laikinasPratKiekis;
    int radomeEgizstuojant = 0;
    int kiekPozicijuPanaudota = 0;
    for(int i = 0; i < pratimuIrasuKiekis; i++){
         fd >> laikinasPratPav;
         for(int j = 0; j < i; j++){
            if(pratimoIrasai[j].pratimoPavadinimas == laikinasPratPav){
                fd >> laikinasPratKiekis;
                pratimoIrasai[j].kartai += laikinasPratKiekis;
                radomeEgizstuojant = 1;
            }
         }
         if(radomeEgizstuojant == 0){
            pratimoIrasai[i].pratimoPavadinimas = laikinasPratPav;
            fd >> pratimoIrasai[i].kartai;
            kiekPozicijuPanaudota++;
         }
    }

    // ... kviečiame rikiavimo funciją
    // rikiuoti_bubble(pratimoIrasai, kiekPozicijuPanaudota);
    rikiuoti_selection(pratimoIrasai, kiekPozicijuPanaudota);

    for(int i = 0; i < kiekPozicijuPanaudota; i++){
        cout << pratimoIrasai[i].pratimoPavadinimas << " "
            << pratimoIrasai[i].kartai << endl;
    }
}
