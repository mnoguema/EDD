#include <vector>
#include <string>
#include <iostream>
#include "NodeHeap.h"
#include <stdexcept>
#include <math.h>

using namespace std;

template <class Clau, class Valor>
class MinHeap
{
public:
    MinHeap();                             // constructor
    MinHeap(const MinHeap<Clau, Valor> &); // constructor còpia
    int tamany();                          // retorna el nombre d'elements que hi ha al heap
    bool isEmpty();                        // retorna cert si és buit, fals en cas contrari
    void inserir(const Clau &clau, const Valor &valor);
    Clau minim();                  // retorna la clau mínima
    Valor valorMinim();            // retorna el valor de la clau mínima
    void eliminaMinim();           // elimina el node amb valor minim
    void imprimir();               // Imprimeix per pantalla tot el Heap, una línia per a cada nivell de l'arbre
    Valor cerca(const Clau &clau); // cerca al heap una clau donada
    int height() const;            // retorna l'alçada del heap

private:
    vector<NodeHeap<Clau, Valor>> data;
    int mida;
    void upHeap();
    void downHeap();
    void swap(int p1, int p2);
};

template <class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap()
{
    mida = 0;
}

template <class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap(const MinHeap<Clau, Valor> &orig)
{
    data = orig.data;
    mida = orig.mida;
}

template <class Clau, class Valor>
int MinHeap<Clau, Valor>::tamany()
{
    return this->mida;
}

template <class Clau, class Valor>
bool MinHeap<Clau, Valor>::isEmpty()
{
    return mida == 0;
}

template <class Clau, class Valor>
void MinHeap<Clau, Valor>::inserir(const Clau &clau, const Valor &valor)
{
    // si no hi ha cap node, l'afegim al vector de dades
    if (isEmpty())
    {
        data.push_back(NodeHeap<Clau, Valor>(clau, valor));
    }
    else
    {
        bool trobat = false;
        int i = 0;
        // recorrer tot el vector fins que acabem o trobem el valor
        while (!trobat && i < tamany())
        {
            trobat = (data[i].getKey() == clau);
            i++;
        }
        // si el valor no hi era afegim el node al vector i reordenem el heap
        if (!trobat)
        {
            data.push_back(NodeHeap<Clau, Valor>(clau, valor));
            upHeap();
        }
        else
        {
            data[i - 1].setKey(clau);
            data[i - 1].setValue(valor);
        }
    }
    mida++;
}

template <class Clau, class Valor>
Clau MinHeap<Clau, Valor>::minim()
{
    if (isEmpty())
        throw new out_of_range("El heap esta buit");
    return data[0].getKey();
}

template <class Clau, class Valor>
Valor MinHeap<Clau, Valor>::valorMinim()
{
    if (isEmpty())
        throw new out_of_range("El heap esta buit");
    return data[0].getValue();
}

template <class Clau, class Valor>
void MinHeap<Clau, Valor>::eliminaMinim()
{
    if (isEmpty())
        throw new out_of_range("El heap esta buit");
    // posem el mes petit al final i l'eliminem, despres reeordenem el heap
    swap(0, data.size() - 1);
    data.pop_back();
    mida--;
    downHeap();
}

template <class Clau, class Valor>
void MinHeap<Clau, Valor>::imprimir()
{
    if (isEmpty())
    {
        throw invalid_argument("Encara no hi ha dades");
    }
    else
    {
        int print = 0, nivell = 1;
        // recorrem tot els nodes i canviem de paragram quan estiguem al node 2*nivell
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i].getKey() << " ";
            print++;
            if (print == nivell)
            {
                cout << endl;
                nivell *= 2;
                print = 0;
            }
        }
    }
}

template <class Clau, class Valor>
Valor MinHeap<Clau, Valor>::cerca(const Clau &clau)
{
    bool trobat = false;
    int i = 0;
    while (!trobat && i < data.size())
    {
        trobat = data[i].getKey() == clau;
        i++;
    }
    if (!trobat)
        throw invalid_argument("Clau no trobada");
    else
        return data[i - 1].getValue();
}

template <class Clau, class Valor>
int MinHeap<Clau, Valor>::height() const
{
    // formula per l'alçada
    return (int)(log2(data.size())) + 1;
}

template <class Clau, class Valor>
void MinHeap<Clau, Valor>::upHeap()
{
    bool trobat = false;
    int posicio = data.size() - 1;
    while (!trobat && posicio > 0)
    {
        int parent = (posicio - 1) / 2;
        // si el pare es mes petit els intercanviem, si no no fem res
        if (data[parent].getKey() > data[posicio].getKey())
        {
            swap(posicio, parent);
            posicio = parent;
        }
        else
            trobat = true;
    }
}

template <class Clau, class Valor>
void MinHeap<Clau, Valor>::downHeap()
{

    int i = 0;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    while (left < data.size() || right < data.size())
    {
        // mirem si el de l'esquerra es mes petit i intercanviem
        if (left < data.size() && data[left].getKey() < data[i].getKey())
        {
            i = left;
        }
        // mirem si el de la dreta es mes petit i intercanviem
        if (right < data.size() && data[right].getKey() < data[i].getKey())
        {
            i = right;
        }
        // actualitzem la posicio actual i els nodes fills
        if (i != 0)
        {
            swap(0, i);
            i = 0;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
        else
        {
            break;
        }
    }
}

template <class Clau, class Valor>
void MinHeap<Clau, Valor>::swap(int p1, int p2)
{
    NodeHeap<Clau, Valor> aux = data[p1];
    data[p1] = data[p2];
    data[p2] = aux;
}
