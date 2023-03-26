#include "Mascota.h"

// constructor
Mascota::Mascota(string nom, string tipus, char genere, int edat)
{
    this->nom = nom;
    this->tipus = tipus;
    this->genere = genere;
    this->edat = edat;
}

// getters
string Mascota::getNom() { return this->nom; }
string Mascota::getTipus() { return this->tipus; }
char Mascota::getGenere() { return this->genere; }
int Mascota::getEdat() { return this->edat; }

// print
void Mascota::print()
{
    cout << "Mascota (Nom ==> " << this->nom << ", Tipus ==> " << this->tipus
         << ", Genere ==> " << this->genere << ", Edat ==> " << this->edat << ")\n";
}