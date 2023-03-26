#include "Clinica.h"

// Constructor
Clinica::Clinica(string nom)
{
    this->nom = nom;
    this->clients = Llista<Client>();
}

// getters
string Clinica::getNom()
{
    return nom;
}
// print
void Clinica::imprimir()
{
    cout << "******CLINICA VETERINARIA******" << endl;
    cout << "       " << nom << "            " << endl;
}

/* tenim una variable bool que nomes canvia a true si trobem un client que es digui com el nom que ens passen per parametre
 si acabem de recorrer la llista i no hem trobat el client l'afegim al final. altrament llencem una excepcio */
void Clinica::afegeixClient(Client client)
{
    bool trobat = false;
    Posicio<Client> position = clients.principi();
    while (!trobat && position != clients.final())
    {
        trobat = position.element().getNom() == client.getNom();
        position = position.next();
        throw invalid_argument("El client ja existeix a la llista");
    }
    if (!trobat)
    {
        clients.inserirFinal(client);
    }
}

/* tenim una variable bool que nomes canvia a true si trobem un client que tingui el mateix telefon que passem per parametre
 si acabem de recorrer la llista i no hem trobat el client llencem una excepcio. si l'hem trobat l'eliminem */
void Clinica::eliminaClient(string telefon)
{
    bool trobat = false;
    Posicio<Client> position = clients.principi();
    while (!trobat && position != clients.final())
    {
        trobat = position.element().getTelefon() == telefon;
        position = position.next();
    }
    if (trobat)
    {
        Posicio<Client> client_eliminar = position.anterior();
        clients.elimina(client_eliminar);
    }
    else
        throw invalid_argument("El client no existia");
}

// imprimim els clients cridant el metode print de la classe Client per cada element de la Llista
void Clinica::mostraClients()
{
    for (Posicio<Client> position = clients.principi(); position != clients.final(); position.next())
        position.element().print();
}

/* tenim una variable bool que nomes canvia a true si trobem un client que tingui el mateix telefon que passem per parametre
 si acabem de recorrer la llista i no hem trobat el client llencem una excepcio. si l'hem trobat li afegim una mascota de la classe Mascota
 hi ha error de compatibilitat ja que p.anterior.element es const pero afegeixmascota no */
void Clinica::afegeixMascotaClient(string telefon, Mascota mascota)
{
    bool trobat = false;
    Posicio<Client> position = clients.principi();
    while (!trobat && position != clients.final())
    {
        trobat = position.element().getTelefon() == telefon;
        position = position.next();
    }
    if (trobat)
        position.anterior().element().afegeixMascota(mascota.getNom(), mascota.getTipus(), mascota.getGenere(), mascota.getEdat());
    else
        __throw_invalid_argument("el client no existeix");
}

/* tenim una variable bool que nomes canvia a true si trobem un client que tingui el mateix telefon que passem per parametre
 si acabem de recorrer la llista i no hem trobat el client llencem una excepcio. si l'hem trobat eliminem la mascota
 hi ha error de compatibilitat ja que p.anterior.element es const pero afegeixmascota no */
void Clinica::eliminaMascotaClient(string telefon, string nom_mascota)
{
    bool trobat = false;
    Posicio<Client> position = clients.principi();
    while (!trobat && position != clients.final())
    {
        trobat = position.element().getTelefon() == telefon;
        position = position.next();
    }
    if (trobat)
        position.anterior().element().eliminaMascota(nom_mascota);
    else
        __throw_invalid_argument("el client no existeix");
}

/* recorrem la llista fins trobar el client amb el mateix telefon que passem per parametre i aleshores cridem la funcio de mostra mascotes
si hem trobat el client, si no llencem una excepcio*/
void Clinica::mostraMascotesClient(string telefon)
{
    bool trobat = false;
    Posicio<Client> position = clients.principi();
    while (!trobat && position != clients.final())
    {
        trobat = position.element().getTelefon() == telefon;
        position = position.next();
    }
    if (trobat)
        position.anterior().element().mostraMascotes();
    else
        __throw_invalid_argument("el client no existeix");
}

/* creem un vector d'opcions i la printem i retornem la opcio triada */
int Clinica::seleccionaOpcioMenu()
{
    int option;
    cout << "Què vols fer ?" << endl;
    vector<string> opcions = {"Sortir",
                              "Afegir Client",
                              "Eliminar Client",
                              "Afegir Mascota a un client",
                              "Eliminar Mascota d'un client",
                              "Imprimir clients clínica",
                              "Imprimir les mascotes d'un client"};
    for (int i = 1; i <= opcions.size(); i++)
        cout << i << ". " << opcions[i - 1] << endl;
    cin >> option;
    return option;
}

/* obrim el fitxer que ens passen per parametre i llencem excpecio si aquest no existeix. fins que no estigui buit anem llegint
o be un client o be una mascota */
void Clinica::afegirClientsArxiu(string ruta_arxiu)
{
    string nom, poblacio, telefon, nom_mascota, tipus;
    int edat;
    char option, genere;
    ifstream data_file;
    Client client;
    data_file.open(ruta_arxiu);
    if (!data_file)
    {
        throw invalid_argument("Fitxer no trobat\n");
    }
    /* mentre hi hagi files en el document anem llegint i ens anem guardant la informacio que toca*/
    while (!data_file.eof())
    {
        data_file >> option;
        if (toupper(option) == 'C')
        {
            data_file >> nom;
            data_file >> poblacio;
            data_file >> telefon;
            client = Client(nom, poblacio, telefon);
        }
        data_file >> option;
        if (toupper(option) == 'M')
        {
            data_file >> nom_mascota;
            data_file >> tipus;
            data_file >> genere;
            data_file >> edat;
            client.afegeixMascota(nom_mascota, tipus, genere, edat);
        }
    }
    data_file.close();
}