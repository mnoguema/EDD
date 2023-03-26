#ifndef POSICIO_H
#define POSICIO_H

#include "NodeLlista.h"

template <class Element>
class Posicio
{
public:
    Posicio(NodeLlista<Element> *node); // inicialitza la classe Posicio amb el node que rep com a paràmetre.
    Posicio(const Posicio &origen);
    virtual ~Posicio();
    Posicio<Element> next() const; // retorna la següent posició a l’actual
    // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.
    Posicio<Element> anterior() const; // retorna l’anterior posició
    const Element &element() const;    // retorna el contingut de l’actual posició
    NodeLlista<Element> *elimina();
    void fixarAnterior(NodeLlista<Element> *node); // assigna l’adreça de l’anterior node
    void fixarSeguent(NodeLlista<Element> *node);  // assigna l’adreça del següent node

    Posicio<Element> operator++() const;         // sobrecarrega operador ++
    Posicio<Element> operator--() const;         // sobrecarrega operador --
    bool operator==(const Posicio &other) const; // sobrecarrega operador ==
    bool operator!=(const Posicio &other) const; // sobrecarrega operador !=
    /*const Element &operator*() const;  */      // sobrecarrega operador contingut

private:
    NodeLlista<Element> *_node;
};

#endif
