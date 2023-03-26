/*excepcions aqui*/
#ifndef LLISTA_H
#define LLISTA_H

#include "NodeLlista.h"
#include "Posicio.h"

#include <iostream>
#include <initializer_list>
using namespace std;

template <class Element>
class Llista
{
public:
    Llista();
    Llista(initializer_list<Element> elements);
    Llista(const Llista<Element> &origen);
    virtual ~Llista();
    int tamany() const;
    bool esBuida() const;
    Posicio<Element> principi() const; // return first position
    Posicio<Element> final() const;    // return last position

    // Reverse iteration
    Posicio<Element> rprincipi() const; // return first position
    Posicio<Element> rfinal() const;    // return last position
    void inserirDespres(Posicio<Element> &position, const Element &element);
    void inserirAbans(Posicio<Element> &position, const Element &element);
    void inserirPrincipi(const Element &element);
    void inserirFinal(const Element &element);

    void elimina(Posicio<Element> &position);

private:
    NodeLlista<Element> *_cap;
    NodeLlista<Element> *_cua;
    int _tamany;
};

#endif
