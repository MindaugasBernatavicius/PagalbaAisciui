#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void nulinePamoka(){
    // 0. Susikurti string / char[], kuris nurodys failo pavadinima
    const char inFailas [] = "data.txt"; // string == char[]

    // 1. Kintamieji, kurie nurodys, kada nustoti skaityti is failo
    int darbininkaiBrigadoje;
    int dienuSkaicius;

    // 2. Sukuriame input file stream - "srautą"
    ifstream fd(inFailas);

    // 3. Įskaitome į kintamąjį aka į atmintį
    fd >> darbininkaiBrigadoje;
    fd >> dienuSkaicius;

    // 4. Pasikrinimui išspausdiname
    //    cout << darbininkaiBrigadoje << endl;
    //    cout << dienuSkaicius << endl;

    string vardas;
    int litai, centai;

    string brigadosVardai[darbininkaiBrigadoje];
    int brigadosNarioLitai[darbininkaiBrigadoje];
    int brigadosNarioCentai[darbininkaiBrigadoje];

    // 5 .Nuskaitome visa info apie brigada
    // ++i; i++; i=i+1; i+=1;
    for(int i = 0; i < darbininkaiBrigadoje; i+=1){
        fd >> vardas;
        brigadosVardai[i] = vardas;
        fd >> litai;
        brigadosNarioLitai[i] = litai;
        fd >> centai;
        brigadosNarioCentai[i] = centai;
    }

//    for(int i = 0; i < darbininkaiBrigadoje; i+=1){
//        cout << brigadosVardai[i] << " "
//            << brigadosNarioLitai[i] << " "
//            << brigadosNarioCentai[i]
//            << endl;
//    }

    // 3 x 4
    // 6. Nuskaitome visa apie dienas
    int tmp;
    int brigadosArai[dienuSkaicius][darbininkaiBrigadoje];
    for(int i = 0; i < dienuSkaicius; i++){
        for(int j = 0; j < darbininkaiBrigadoje; j++){
            fd >> tmp;
            brigadosArai[i][j] = tmp;
        }
    }
    fd.close();

//    for(int i = 0; i < dienuSkaicius; i++){
//        for(int j = 0; j < darbininkaiBrigadoje; j++){
//            cout << brigadosArai[i][j] << " ";
//        }
//        cout << endl;
//    }

    // 7. Atliekame skaiciavimus
    int brigadosNariuAruSumos[darbininkaiBrigadoje];
    for(int i = 0; i < darbininkaiBrigadoje; i++){ // 0 iki 2
        int sum = 0;
        for(int j = 0; j < dienuSkaicius; j++) // 0 iki 3
            sum += brigadosArai[j][i];
        brigadosNariuAruSumos[i] = sum;
    }

    // 8. Spausdiname kiekvieno brigadiniko suma
    int bendraSuma = 0;
    for(int i = 0; i < darbininkaiBrigadoje; i++){
        // 9. Suskaiciuojame ir spausdiname bendraja suma
        int brigadinikoSuma = (brigadosNariuAruSumos[i] * brigadosNarioLitai[i] * 100)
                    + (brigadosNariuAruSumos[i] * brigadosNarioCentai[i]);
        bendraSuma += brigadinikoSuma;
        cout << left << setw(17) << brigadosVardai[i]
            << brigadinikoSuma  / 100 << " Lt "
            << bendraSuma % 100 << " ct" << endl;
    }

    cout << left << setfill('.') << setw(17) << "Is viso"
        << bendraSuma / 100 << " Lt "
        << bendraSuma % 100 << " ct" << endl;
}
