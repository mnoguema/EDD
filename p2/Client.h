#include <iostream>
#include <vector>
#include "Llista.h"
#include "Mascota.h"
using namespace std;

class Client
{
private:
    string nom;
    string poblacio;
    string telefon;
    Llista<Mascota> mascotes;

public:
    Client(string nom, string poblacio, string telefon);
    Client();

    string getNom();
    string getPoblacio();
    string getTelefon();

    void print();
    void afegeixMascota(string nom, string tipus, char genere, int edat);
    void eliminaMascota(string nom);
    void mostraMascotes();
};
