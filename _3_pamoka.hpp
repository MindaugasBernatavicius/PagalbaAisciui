


void treciaPamokaRikiavimas(){

    int arr [] = {192, 164, 165, 190, 170, 159}; // 6

    cout << "Before sorting: ";
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int iteraciju_kiekis = 0;
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0]) - 1); i++){
        for(int j = 0; j < (sizeof(arr)/sizeof(arr[0]) - 1 - i); j++){
            iteraciju_kiekis++;
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "After sorting: ";
        for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Iteraciju kiekis: " << iteraciju_kiekis;
}

int arYra(int arr[], int size, int ieskomasis){
    int arYraAukstesniu = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == ieskomasis)
            arYraAukstesniu = 1;
    }
    return arYraAukstesniu;
}

void treciaPamokaPaieska(){
    int arr [] = {192, 164, 165, 190, 170, 196, 159}; // 6

    if(arYra(arr, sizeof(arr)/sizeof(arr[0]), 189))
        cout << "Yra" << endl;
    else
        cout << "Nera" << endl;
}
