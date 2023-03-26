#include <iostream>
#include <vector>
#include <stdexcept>
#include "PilaEstatica.h"
#include <string>
using namespace std;

int main()
{
    // declarem les varibles
    int tamany = -1, option, element;
    vector<string> arr_options = {"Inserir element a la pila", "Treure element de la pila", "Consultar el top de la pila", "Imprimir tot el contingut de la PilaEstatica", "Imprimir la posició del top de la pila", "Sortir"};

    // si el tamany que ens passen es negatiu llencem expecio
    while (tamany < 0)
    {
        cout << "Crear una PilaEstatica de mida ";
        cin >> tamany;
        if (tamany < 0)
            throw out_of_range("Tamany negatiu introduit\n");
    }

    PilaEstatica pila(tamany);
    do
    {
        try
        {

            for (int i = 1; i <= arr_options.size(); i++)
            {
                cout << i << ". " << arr_options[i - 1] << "\n";
            }
            cin >> option;
            switch (option)
            {
            case 1:
                cout << "Inserir element ";
                cin >> element;
                pila.afegirElement(element);
                break;
            case 2:
                pila.treureElement();
                cout << "Element " << pila.elementFront() << " eliminat\n";
                break;
            case 3:
                element = pila.elementFront();
                cout << "Front: " << element << "\n";
                break;
            case 4:
                pila.imprimeix();
                break;
            case 5:
                cout << "El top de la pila es troba a la posicio " << pila.tamany() << "\n";
                break;
            default:
                cout << "Aquesta opcio no es valida.\n";
                break;
            }
        }
        catch (invalid_argument &ex)
        {
            cout << "EXCEPTION: " << ex.what() << "\n";
        }
    } while (option != 6);

    return 0;
}