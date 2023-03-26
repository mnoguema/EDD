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
*/

#include <iostream>
#include <cstdlib>
#include <string>

#include "Llista.h"

using namespace std;

int main()
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
        while (l.tamany() < tamany)
        {
            cout << "Introdueix una paraula: ";
            cin >> element;
            cout << "Inserir al principi? (s/n) ";
            cin >> option;
            if (tolower(option) == 'n')
            {
                cout << "Inserir al final? (s/n) ";
                cin >> option;
                if (tolower(option) == 'n')
                {
                    cout << "A quina posicio vols inserir? ";
                    cin >> index;
                    if (index > l.tamany())
                        __throw_out_of_range("Aquesta posicio no es accesible");
                    cout << "Inserir abans de la posicio? (s/n) ";
                    cin >> option;
                    /*la posicio 0 pertany al sentinella cap*/
                    /*la posicio 1 es el primer on tenim un element*/
                    pos = l.principi();
                    for (int i = 0; i < index; i++)
                        pos = pos.next();
                    if (tolower(option) == 'n')
                        l.inserirDespres(pos, element);
                    else
                        l.inserirAbans(pos, element);
                }
                else
                    l.inserirFinal(element);
            }
            else
            {
                l.inserirPrincipi(element);
            }
            cout << "vols canviar o eliminar algun valor ?" << endl;
            cin >> option;
            if (tolower(option) == 's')
            {
                cout << "quina posicio?: ";
                cin >> index;
                if (index > l.tamany())
                    __throw_out_of_range("Aquesta posicio no es accesible");
                for (int i = 0; i < index; i++)
                    pos = pos.next();
                l.elimina(pos);
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
