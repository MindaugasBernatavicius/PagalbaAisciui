#include <fstream>
#include <iostream>

using namespace std;


void function_pass_by_copy(int i){
    cout << "Viduje funkcijos: " << ++i << endl;
}

void function_pass_by_ref(int &i){
    cout << "Viduje funkcijos: " << ++i << endl;
}

void function_pass_by_ref_w_pointers(int * i){
    cout << "Viduje funkcijos: " << ++(*i) << endl;
}

void sestaPamoka(){
    int test = 1;

//    cout << "Pries kvieciant: " << test << endl;
//    function_pass_by_copy(test);
//    cout << "Po kvietimo: " << test << endl;
//
//    cout << endl;
//    cout << "Pries kvieciant: " << test << endl; // 1
//    function_pass_by_ref(test); // 2
//    cout << "Po kvietimo: " << test << endl; // 2
//
//    cout << endl;
//    cout << "Pries kvieciant: " << test << endl; // 1
//    function_pass_by_ref_w_pointers(&test); // 2
//    cout << "Po kvietimo: " << test << endl; // 2
}
