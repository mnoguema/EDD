#include <iostream>
#include <cstdlib>
using namespace std;

#include "ArbreBinari.h"

int main(){
    try{
        ArbreBinari<int, int> arbre;
        int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
        int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11}; 

        for(int i = 0; i<8; i++){
            arbre.insert(testKeys[i], testValues[i]);
        }
        cout <<"Pre-ordre"<<endl;
        arbre.imprimirPreordre();
        cout << endl;

        cout <<"In-ordre"<<endl;
        arbre.imprimirInordre();
        cout << endl;

        cout <<"Post-ordre"<<endl;
        arbre.imprimirPostordre();
        cout << endl;
    }catch(invalid_argument& ex){
        cout << ex.what()<<endl;
    }
        return 0;

}

