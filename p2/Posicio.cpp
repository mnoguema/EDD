#include "Posicio.h"

// constructors
template <class Element>
Posicio<Element>::Posicio(NodeLlista<Element> *node)
{
    this->_node = node;
}

template <class Element>
Posicio<Element>::Posicio(const Posicio &origen)
{
    this->_node = origen._node;
}

// destructor
template <class Element>
Posicio<Element>::~Posicio() {}

// si hi ha seguent node, el retorno si no llencem excepcio de mida
template <class Element>
Posicio<Element> Posicio<Element>::next() const
{
    Posicio<Element> position = Posicio<Element>(_node->accedirSeguent());
    if (position == nullptr)
        throw std::out_of_range("L'estructura esta buida");
    else
        return position;
}

// si existeix el node anterior el retorno i sino llencem excepio
template <class Element>
Posicio<Element> Posicio<Element>::anterior() const
{
    Posicio<Element> position = Posicio<Element>(_node->accedirAnterior());
    if (position == nullptr)
        throw std::out_of_range("L'estructura esta buida");
    else
        return position;
}

template <class Element>
const Element &Posicio<Element>::element() const
{
    return _node->accedirElement();
}

//  canviem les direccions dels nodes veins per tal que cap node apunti al node de la posicio
template <class Element>
NodeLlista<Element> *Posicio<Element>::elimina()
{
    _node->accedirAnterior()->fixarSeguent(_node->accedirSeguent());
    _node->accedirSeguent()->fixarAnterior(_node->accedirAnterior());
    return _node;
}

// que el node nou apunti al que tenim i el que tenim apunti al que ens passen
template <class Element>
void Posicio<Element>::fixarAnterior(NodeLlista<Element> *node)
{
    node->fixarSeguent(_node);
    _node->fixarAnterior(node);
}

template <class Element>
void Posicio<Element>::fixarSeguent(NodeLlista<Element> *node)
{
    node->fixarAnterior(_node);
    _node->fixarSeguent(node);
}

// sobrecarreguem els operadors
template <class Element>
Posicio<Element> Posicio<Element>::operator++() const { return next(); }

template <class Element>
Posicio<Element> Posicio<Element>::operator--() const { return anterior(); }

template <class Element>
bool Posicio<Element>::operator==(const Posicio &other) const { return _node == other._node; }

template <class Element>
bool Posicio<Element>::operator!=(const Posicio &other) const { return _node != other._node; }
