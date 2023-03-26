#include "Client.h"

// constructor
Client::Client(string nom, string poblacio, string telefon)
{
    this->nom = nom;
    this->poblacio = poblacio;
    this->telefon = telefon;
    this->mascotes = Llista<Mascota>();
}

// getters
string Client::getNom() { return nom; }
string Client::getPoblacio() { return poblacio; }
string Client::getTelefon() { return telefon; }

// print
void Client::print()
{
    cout << "Client (Nom ==> " << this->nom << ", Poblacio ==> " << this->poblacio
         << ", Telefon ==> " << this->telefon << ")\n";
}

// metode que afegeix una mascota al vector de mascotes del client
void Client::afegeixMascota(string nom, string tipus, char genere, int edat)
{
    Mascota mascota(nom, tipus, genere, edat);
    mascotes.inserirFinal(mascota);
}

// recorrem la llista de mascotes del client en concret fins que trobem una que tingui el mateix nom
// si l'hem trobat aleshores l'eliminem. si no enviem una excepcio
void Client::eliminaMascota(string nom)
{
    bool trobat = false;
    Posicio<Mascota> position = mascotes.principi();
    while (!trobat && position != mascotes.final())
    {
        trobat = position.element().getNom() == nom;
        position = position.next();
    }
    if (trobat)
    {
        Posicio<Mascota> mascota_eliminar = position.anterior();
        mascotes.elimina(mascota_eliminar);
    }
    else
        throw invalid_argument("Aquesta mascota no existeix");
}

// recorrem la llista de mascotes i anem imprimint amb el metode print implementat a la classe Mascota
void Client::mostraMascotes()
{
    for (Posicio<Mascota> it = this->mascotes.principi(); it != this->mascotes.final(); ++it)
    {
        it.element().print();
    }
}
