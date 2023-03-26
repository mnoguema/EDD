#ifndef NODELLISTA_H
#define NODELLISTA_H

#include <stdexcept>

template <class Element>
class NodeLlista
{
private:
    Element _element;
    NodeLlista<Element> *_anterior;
    NodeLlista<Element> *_seguent;

public:
    NodeLlista<Element>(Element _element);
    const Element &accedirElement() const;
    NodeLlista *accedirSeguent() const;
    void fixarSeguent(NodeLlista *node);
    NodeLlista *accedirAnterior() const;
    void fixarAnterior(NodeLlista *node);
};

#endif