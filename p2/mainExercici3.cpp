#include "Clinica.h"

int main()
{
    Clinica clinica = Clinica("4gats");
    string nom, poblacio, telefon, nom_mascota, tipus;
    char genere;
    int opcio, edat;
    try
    {
        clinica.afegirClientsArxiu("Clinica_4gats.txt");
        do
        {
            opcio = clinica.seleccionaOpcioMenu();
            switch (opcio)
            {
            case 1:
                cout << "Nom del client: ";
                cin >> nom;
                cout << "On viu: ";
                cin >> poblacio;
                cout << "Telefon de contacte: ";
                cin >> telefon;
                clinica.afegeixClient(Client(nom, poblacio, telefon));
                break;
            case 2:
                cout << "Dona el telefon del client que vols eliminar: ";
                cin >> telefon;
                clinica.eliminaClient(telefon);
                break;
            case 3:
                cout << "Telefon del client en qüestió: ";
                cin >> telefon;
                cout << "Nom de la mascota: ";
                cin >> nom_mascota;
                cout << "Quin tipus d'animal es?: ";
                cin >> tipus;
                cout << "Es mascle o famella (M/F): ";
                cin >> genere;
                cout << "Quina edat te: ";
                cin >> edat;
                clinica.afegeixMascotaClient(telefon, Mascota(nom_mascota, tipus, genere, edat));
                break;
            case 4:
                cout << "Dona el telefon del client: ";
                cin >> telefon;
                cout << "Nom del animal a eliminar: ";
                cin >> nom_mascota;
                clinica.eliminaMascotaClient(telefon, nom_mascota);
                break;
            case 5:
                clinica.mostraClients();
                break;
            case 6:
                cout << "Dona el telefon del client: ";
                cin >> telefon;
                clinica.mostraMascotesClient(telefon);
                break;
            default:
                cout << "Aquesta opcio no es valida";
                break;
            }
        } while (opcio != 0);
    }
    catch (invalid_argument &ex)
    {
        cout << "EXCEPTION: " << ex.what() << "\n";
    }
    return 0;
}