#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mascota
{
private:
    string nom;
    string tipus;
    char genere;
    int edat;

public:
    Mascota();
    Mascota(string nom, string tipus, char genere, int edat);

    string getNom();
    string getTipus();
    char getGenere();
    int getEdat();

    void print();
};


#endif