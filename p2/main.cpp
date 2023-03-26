
/**** he intentat fer el main amb tots els altres mains junts pero com que el tercer exercici no funciona perque
 * hi ha funcions que son const i hi ha un error de compatibilitat ja que els tipus son diferents al ser uns const
 * i els altres no.
 * Estan els 3 mains per separats que si funcionen correctament el 1 i el 2
 ****/

/*
1. He implementat els templates doncs ja que teniem la guia i ho recomanaven per el seguent
exercici he vist convenient invertir el temps en fer codi previament.
2. No perque he buscat a internet pero no he entes el funcionament i ja em funcionava per elements
sueltos aixi que he preferit fer-ho element per element amb el constructor per defecte
3.  int tamany() const; O(1)
    bool esBuida() const; O(1)
    Posicio<Element> principi() const; O(1)
    Posicio<Element> final() const;  O(1)

    // Reverse iteration
    Posicio<Element> rprincipi() const; O(1)
    Posicio<Element> rfinal() const; O(1)
    void inserirDespres(Posicio<Element> &position, const Element &element); O(1)
    void inserirAbans(Posicio<Element> &position, const Element &element); O(1)
    void inserirPrincipi(const Element &element); O(1)
    void inserirFinal(const Element &element); O(1)

    void elimina(Posicio<Element> &position); O(1)
    tot i que per passar la posicio a eliminar previament hem de fer un loop que en el pitjor
    dels casos sera O(n)
4. si haguessim implementat nodes simples el codi hauria sigut mes curt i senzill pero ens hauria estalviat memoria, molt poca,
ja que estem treballant amb poques dades però bueno. Com que no estem tractant amb un numero molt gran de dades i no ens hem de
preocupar per la memoria, els encadanaments dobles han sigut una bona opcio pero l'unic benefici es la accessibilitat als nodes anteriors.


#include <vector>
#include <cstdlib>
#include <string>

#include "Llista.h"
#include "Clinica.h"
#include "PilaEstatica.h"

int main()
{
    int opcio;
    cout << "Quin exercici vols probar: ";
    cin >> opcio;
    switch (opcio)
    {
    case 1:
        mainExercici1();
        break;
    case 2:
        mainExercici2();
        break;
    case 3:
        mainExercici3();
    }
}

int mainExercici1()
{
    int tamany = -1, option, element;
    vector<string> arr_options = {"Inserir element a la pila", "Treure element de la pila", "Consultar el top de la pila", "Imprimir tot el contingut de la PilaEstatica", "Imprimir la posició del top de la pila", "Sortir"};

    while (tamany < 0)
    {
        cout << "Crear una PilaEstatica de mida ";
        cin >> tamany;
        if (tamany < 0)
            cout << "Tamany negatiu introduit\n";
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

int mainExercici2()
{
    try
    {
        Llista<string> l;
        string element;
        Posicio<string> pos = l.rprincipi();
        char option;
        int tamany = -1, index;
        while (tamany < 0)
        {
            cout << "Quants elements vols inserir? ";
            cin >> tamany;
            if (tamany < 0)
                cout << "Tamany negatiu introduit\n";
        }
        for (int i = 0; i < tamany; i++)
        {
            cout << "Introdueix una paraula: ";
            cin >> element;
            cout << "Inserir al principi? (s/n) ";
            cin >> option;
            if (option == 'n')
            {
                cout << "Inserir al final? (s/n) ";
                cin >> option;
                if (option == 'n')
                {
                    cout << "A quina posicio vols inserir? ";
                    cin >> index;
                    if (index > l.tamany())
                    {
                        __throw_out_of_range("Aquesta posicio no es accesible");
                    }
                    cout << "Inserir abans de la posicio? (s/n) ";
                    cin >> option;
                    la posicio 0 pertany al sentinella cap
la posicio 1 es el primer on tenim un element
pos = l.principi();
for (int i = 0; i < index; i++)
    pos = pos.next();
if (option == 'n')
    l.inserirDespres(pos, element);
else
    l.inserirAbans(pos, element);
}
else l.inserirFinal(element);
}
else
{
    l.inserirPrincipi(element);
}
}
cout << "Iteració amb position endavant: " << endl;
for (Posicio<string> i = l.principi(); i != l.final(); i = i.next())
    cout << i.element() << endl;

cout << "Iteració amb position endarrere: " << endl;
for (Posicio<string> i = l.rfinal(); i != l.rprincipi(); i = i.anterior())
    cout << i.element() << endl;
}
catch (exception &e)
{
    cout << e.what() << "\n";
}
return 0;
}

int mainExercici3()
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
* /*/