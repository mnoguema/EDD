#include <iostream>
#include <fstream>
using namespace std;
#include "Client.h"

class Clinica
{
private:
    string nom;
    Llista<Client> clients;

public:
    Clinica(string nom);
    string getNom();
    void imprimir();
    void afegeixClient(Client);
    void eliminaClient(string telefon);
    void mostraClients();
    void afegeixMascotaClient(string telefon, Mascota mascota);
    void eliminaMascotaClient(string telefon, string nom_mascota);
    void mostraMascotesClient(string telefon);
    int seleccionaOpcioMenu();
    void afegirClientsArxiu(string ruta_arxiu);
};
