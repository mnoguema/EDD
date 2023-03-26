#ifndef PILAESTATICA_H
#define PILAESTATICA_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>
using namespace std;

class PilaEstatica
{
public:
    PilaEstatica(int tamany_maxim = TAMANY_MAXIM);
    PilaEstatica(const PilaEstatica &origen);
    PilaEstatica(initializer_list<int> elements);
    virtual ~PilaEstatica();
    int tamany() const;
    bool esBuida() const;
    bool esPlena() const;
    int elementFront() const;
    void afegirElement(int e);
    void treureElement();
    void imprimeix() const;

private:
    enum
    {
        TAMANY_MAXIM = 10
    };
    int _capacitat;
    int _front;
    int *_dades;
};
#endif
