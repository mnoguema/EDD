#include "PilaEstatica.h"
#include <iostream>
using namespace std;

// constructor amb tamany maxim fixat
PilaEstatica::PilaEstatica(int tamany_maxim)
{
    this->_capacitat = tamany_maxim;
    this->_front = -1;
    this->_dades = new int[this->_capacitat];
    cout << "Estructura creada\n";
}

PilaEstatica::PilaEstatica(const PilaEstatica &origen)
{
    this->_capacitat = origen._capacitat;
    this->_front = origen._front;
    this->_dades = new int[this->_capacitat];
    for (int i = 0; i < this->_capacitat; i++)
    {
        this->_dades[i] = origen._dades[i];
    }
}

PilaEstatica::PilaEstatica(initializer_list<int> elements)
{
    for (int element : elements)
        afegirElement(element);
}
// destructor
PilaEstatica::~PilaEstatica()
{
    delete[] this->_dades;
}
// getter mida
int PilaEstatica::tamany() const
{
    return this->_front + 1;
}

// retorna cert si la Pila esta buida
bool PilaEstatica::esBuida() const
{
    return this->_front < 0;
}
// retorna cert si la Pila ha arribat a la capacitat maxima
bool PilaEstatica::esPlena() const
{
    return _front == _capacitat - 1;
}

// retornem el front de la pila si no esta buida
int PilaEstatica::elementFront() const
{
    if (!this->esBuida())
        return this->_dades[_front];
    else
        throw invalid_argument("La Pila està buida\n");
}

// afegim un element més al principi del array el qual augmentem de mida si la pila no esta plena
void PilaEstatica::afegirElement(int e)
{
    if (!this->esPlena())
    {
        this->_front++;
        this->_dades[this->_front] = e;
        cout << "Element " << e << " agregat\n";
    }
    else
        throw invalid_argument("La Pila està plena\n");
}

// si la pila no es buida anem al anterior front (penultim element inserit)
void PilaEstatica::treureElement()
{
    if (!this->esBuida())
        this->_front--;
    else
        throw invalid_argument("La Pila està buida\n");
}

void PilaEstatica::imprimeix() const
{
    if (!this->esBuida())
    {
        cout << "[ ";
        {
            for (int i = 0; i < this->_front; i++)
                cout << this->_dades[i] << " , ";
            cout << this->_dades[_front] << "]" << endl;
        }
    }
    else
        throw new invalid_argument("La Pila està buida\n");
}