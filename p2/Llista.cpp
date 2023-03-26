#include "Llista.h"

/* constructor
 primer creem els nodes buit del cap i la cua i els assenyalem entre ells */
template <class Element>
Llista<Element>::Llista()
{
    _cap = new NodeLlista<Element>(Element());
    _cua = new NodeLlista<Element>(Element());

    _cap->fixarSeguent(_cua);
    _cua->fixarAnterior(_cap);

    _tamany = 0;
}

/* anem recorrent la llista i anem inserint al final */
template <class Element>
Llista<Element>::Llista(initializer_list<Element> elements) : Llista()
{
    for (const Element &e : elements)
        inserirFinal(e);
}

template <class Element>
Llista<Element>::Llista(const Llista<Element> &origen) : Llista()
{
    for (Posicio<Element> pos = origen._cap; pos != origen._cua; pos++)
        this->inserirFinal(pos.element());
}

// destructor
template <class Element>
Llista<Element>::~Llista()
{
    NodeLlista<Element> *ptr = _cap;
    while (ptr != nullptr)
    {
        delete ptr;
        ptr = ptr->accedirSeguent();
    }
    _cua = nullptr;
    _tamany = 0;
}
// retornem el tamany de la llista
template <class Element>
int Llista<Element>::tamany() const
{
    return _tamany;
}

// si no tenim cap element es buida
template <class Element>
bool Llista<Element>::esBuida() const
{
    return _tamany == 0;
}

// primer element no nul
template <class Element>
Posicio<Element> Llista<Element>::principi() const
{
    if (_tamany == 0)
        throw std::invalid_argument("L'estructura esta buida!");
    else
        return Posicio<Element>(_cap->accedirSeguent());
}

// cua
template <class Element>
Posicio<Element> Llista<Element>::final() const
{
    if (_tamany == 0)
        throw std::invalid_argument("L'estructura esta buida!");
    else
        return Posicio<Element>(_cua);
}

// cap
template <class Element>
Posicio<Element> Llista<Element>::rprincipi() const
{
    return Posicio<Element>(_cap);
}

// ultim element que no es null
template <class Element>
Posicio<Element> Llista<Element>::rfinal() const
{
    return Posicio<Element>(_cua->accedirAnterior());
}

// creem un nou node i assignem els punters d'abans i despres perque no s'assenyalin entre ells i s'assenyalin amb el node nou
template <class Element>
void Llista<Element>::inserirDespres(Posicio<Element> &position, const Element &element)
{
    NodeLlista<Element> *node = new NodeLlista<Element>(element);

    position.next().fixarAnterior(node);
    position.fixarSeguent(node);

    _tamany++;
}

// creem un nou node i assignem els punters d'abans i despres perque no s'assenyalin entre ells i s'assenyalin amb el node nou
template <class Element>
void Llista<Element>::inserirAbans(Posicio<Element> &position, const Element &element)
{
    NodeLlista<Element> *node = new NodeLlista<Element>(element);

    position.anterior().fixarSeguent(node);
    position.fixarAnterior(node);

    _tamany++;
}

// creem un nou node i assignem els cap i el node de despres perque no s'assenyalin entre ells i s'assenyalin amb el node nou
template <class Element>
void Llista<Element>::inserirPrincipi(const Element &element)
{
    NodeLlista<Element> *node = new NodeLlista<Element>(element);
    node->fixarSeguent(_cap->accedirSeguent());
    node->fixarAnterior(_cap);

    _cap->accedirSeguent()->fixarAnterior(node);
    _cap->fixarSeguent(node);
    _tamany++;
}

// creem un nou node i assignem el node d'abans i la cua perque no s'assenyalin entre ells i s'assenyalin amb el node nou
template <class Element>
void Llista<Element>::inserirFinal(const Element &element)
{
    NodeLlista<Element> *node = new NodeLlista<Element>(element);
    node->fixarSeguent(_cua);
    node->fixarAnterior(_cua->accedirAnterior());

    _cua->accedirAnterior()->fixarSeguent(node);
    _cua->fixarAnterior(node);

    _tamany++;
}

template <class Element>
void Llista<Element>::elimina(Posicio<Element> &position)
{
    /* canviem les direccions amb el metode elimina de la classe Posicio */
    /* eliminem el node que volem eliminar i reduim el tamany */
    delete position.elimina();
    _tamany--;
}
