#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 1. Pirmiausia susikuriame duomenų failą data.txt

// int getNthFromString(string s, int index){
//   int lengthNumber = 0;
//   int lengthToSkip = 0;
//   for(int j = 0; j < index; j++){
//     for(int i = 0; i < s.size(); i++){
//       if(s[i] != ' '){
//         lengthNumber++;
//       } else {
//         break;
//       }
//     }
//   }

//   stoi(s.substr(lengthToSkip, lengthNumber));
//   return 1;
// }

// String splitinimo nesimokė
// string[] stringSplit(string str, string splitter){

// }


int max(int arr[], int size){
  int max = arr[0];
  for(int i = 0; i < size; i++){
    if(max < arr[i]){
      max = arr[i];
    }
  }
  return max;
}

int min(int arr[], int size){
  int min = arr[0];
  for(int i = 0; i < size; i++){
    if(min > arr[i]){
      min = arr[i];
    }
  }
  return min;
}

void pirmaPamoka() {
  // Max algoritmas
  // int peopleHeights[] = {192, 201, 188, 155, 230, 199};
  // cout << max(peopleHeights, sizeof(peopleHeights) / sizeof(int)) << endl;
  // cout << min(peopleHeights, sizeof(peopleHeights) / sizeof(int)) << endl;

  // 2. Įskaitome failą į atmintį

  std::ifstream infile("data.txt");

  // 3. Išsiaiškiname kiek brigadoje žmonių ir kiek dienų jie
  // ... dirbo pagal pirmą eilutę
  std::string line;
  std::getline(infile, line);

  int firstNumberLength = 0;
  for(int i = 0; i < line.size(); i++){
    if(line[i] != ' '){
      firstNumberLength++;
    } else {
      break;
    }
  }

  int secondNumberLength = 0;
  for(int i = 0; i < line.size(); i++){
    if(line[i] != ' '){
      secondNumberLength++;
    } else {
      break;
    }
  }

  int sienpjoviai = stoi(line.substr(0, firstNumberLength));
  int dienos = stoi(line.substr(firstNumberLength + 1, secondNumberLength));

  // 4. Išsiaiškinę kiek žmonių ir kiek dienų, sukuriame string masyvus,
  // ... kuriuose laikysime žmonių ir dienų informacijų
  string brigada [sienpjoviai];
  string isdirbtosDienos [dienos];


  for(int i = 0; i < sienpjoviai; i++){
    std::getline(infile, brigada[i]);
  }

  for(int i = 0; i < dienos; i++){
    std::getline(infile, isdirbtosDienos[i]);
  }

  // 5. Susigaudė visą informaciją į reikalingus masyvus
  // ... galime pradėti skaičiavimus
  int vardoIlgis = 0;
  for(int i = 0; i < brigada[0].size(); i++){
    if(brigada[0][i] != ' '){
      vardoIlgis++;
    } else {
      break;
    }
  }

  cout << vardoIlgis << endl;

  cout <<  brigada[0] << endl;
  // isdirbtosDienos[1][0]
  // isdirbtosDienos[2][0]
}
