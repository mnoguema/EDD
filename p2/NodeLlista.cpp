#include "NodeLlista.h"

// constructor
template <class Element>
NodeLlista<Element>::NodeLlista(Element _element)
{
    this->_element = _element;
    this->_anterior = nullptr;
    this->_seguent = nullptr;
}
// getters
template <class Element>
const Element &NodeLlista<Element>::accedirElement() const
{
    return _element;
}

template <class Element>
NodeLlista<Element> *NodeLlista<Element>::accedirSeguent() const
{
    return _seguent;
}

template <class Element>
NodeLlista<Element> *NodeLlista<Element>::accedirAnterior() const
{
    return _anterior;
}

// setters
template <class Element>
void NodeLlista<Element>::fixarSeguent(NodeLlista *node)
{
    this->_seguent = node;
}

template <class Element>
void NodeLlista<Element>::fixarAnterior(NodeLlista *node)
{
    this->_anterior = node;
}
