#ifndef ARBREBINARI_H
#define ARBREBINARI_H
#include <iostream>
#include <vector>
using namespace std;

#include "NodeBinari.h"

template <class Clau, class Valor>
class ArbreBinari
{
public:
    ArbreBinari();
    ArbreBinari(const ArbreBinari<Clau, Valor> &orig);
    virtual ~ArbreBinari();

    bool isEmpty() const;
    int height() const;

    NodeBinari<Clau, Valor> *insert(const Clau &clau, const Valor &value);
    const Valor &valueOf(const Clau &clau) const;
    void imprimirPreordre(const NodeBinari<Clau, Valor> *n = nullptr) const;
    void imprimirInordre(const NodeBinari<Clau, Valor> *n = nullptr) const;
    void imprimirPostordre(const NodeBinari<Clau, Valor> *n = nullptr) const;
    vector<NodeBinari<Clau, Valor> *> obteValorsRang(int k1, int k2) const;
    void imprimirCami(Clau key) const;
    void eliminaMinim();
    NodeBinari<Clau, Valor> *getRoot() const;

protected:
    NodeBinari<Clau, Valor> *root;
    NodeBinari<Clau, Valor> *search(const Clau &k) const;

private:
    int _size;
    void obteValorsRangAux(NodeBinari<Clau, Valor> *n, int k1, int k2, vector<NodeBinari<Clau, Valor> *> &result) const;
    void imprimirCamiAux(const NodeBinari<Clau, Valor> *node) const;

    /* Mètodes auxiliars definiu aquí els que necessiteu */
};

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari()
{
    root = nullptr;
    _size = 0;

    cout << "Arbre binari creat" << endl;
}

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(const ArbreBinari<Clau, Valor> &orig)
{
    root = (orig.root != nullptr) ? (new NodeBinari<Clau, Valor>(*orig.root)) : (nullptr);
    _size = orig._size;
    cout << "Arbre binari copiat" << endl;
}

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::~ArbreBinari()
{
    delete root;
    cout << "Arbre binari destruït\n";
}

template <class Clau, class Valor>
bool ArbreBinari<Clau, Valor>::isEmpty() const
{
    return root == nullptr;
}

template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::height() const
{
    if (isEmpty())
    {
        throw invalid_argument("L'arbre esta buit");
    }
    return root->height();
}

/* si l'arbre no esta buit */
template <class Clau, class Valor>
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::insert(const Clau &clau, const Valor &value)
{
    NodeBinari<Clau, Valor> *node = root;
    NodeBinari<Clau, Valor> *aux;

    if (isEmpty())
    {
        root = new NodeBinari<Clau, Valor>(clau, value);
        cout << "Element " << clau << " inserit" << endl;
        return root;
    }

    while (node != nullptr)
    {
        aux = node;
        if (node->getKey() == clau)
        {
            return node;
        }
        else if (node->getKey() < clau)
        {
            node = node->getRight();
        }
        else
        {
            node = node->getLeft();
        }
    }
    node = new NodeBinari<Clau, Valor>(clau, value);
    (aux->getKey() < clau) ? aux->setRight(node) : aux->setLeft(node);
    _size++;

    // cout << "Element " << clau << " inserit" <<endl;
    return node;
}

template <class Clau, class Valor>
const Valor &ArbreBinari<Clau, Valor>::valueOf(const Clau &clau) const
{
    NodeBinari<Clau, Valor> *node = search(clau);
    if (node == nullptr)
    {
        throw invalid_argument("Clau no trobada");
    }
    return node->getValue();
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPreordre(const NodeBinari<Clau, Valor> *n) const
{
    if (isEmpty())
        throw invalid_argument("L'arbre esta buit");
    if (n == nullptr)
    {
        imprimirPreordre(root);
    }
    else
    {
        // Preordre -> root, left, right
        cout << n->getKey() << " ";
        if (n->getLeft() != nullptr)
            imprimirPreordre(n->getLeft());
        if (n->getRight() != nullptr)
            imprimirPreordre(n->getRight());
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirInordre(const NodeBinari<Clau, Valor> *n) const
{
    if (isEmpty())
        throw invalid_argument("L'arbre esta buit");
    if (n == nullptr)
    {
        imprimirInordre(root);
    }
    else
    {
        // inordre -> left, root, right
        if (n->getLeft() != nullptr)
            imprimirInordre(n->getLeft());
        cout << n->getKey() << " ";
        if (n->getRight() != nullptr)
            imprimirInordre(n->getRight());
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPostordre(const NodeBinari<Clau, Valor> *n) const
{
    if (isEmpty())
        throw invalid_argument("L'arbre esta buit");
    if (n == nullptr)
    {
        imprimirPostordre(root);
    }
    else
    {
        // postordre -> left, right, root
        if (n->getLeft() != nullptr)
            imprimirPostordre(n->getLeft());
        if (n->getRight() != nullptr)
            imprimirPostordre(n->getRight());
        cout << n->getKey() << " ";
    }
}

template <class Clau, class Valor>
vector<NodeBinari<Clau, Valor> *> ArbreBinari<Clau, Valor>::obteValorsRang(int k1, int k2) const
{
    vector<NodeBinari<Clau, Valor> *> v;
    if (isEmpty())
        throw invalid_argument("L'arbre esta buit");
    else
    {
        // si no esta buida comencem des de l'arrel
        obteValorsRangAux(root, k1, k2, v);
        return v;
    }
}

// funcio auxiliar per poder fer recursiva la funcio
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::obteValorsRangAux(NodeBinari<Clau, Valor> *node, int k1, int k2, vector<NodeBinari<Clau, Valor> *> &v) const
{
    // si quan passem el fill dret o esquerra sigui nullptr i estiguem en una fulla, parem
    if (node == nullptr)
    {
        return;
    }
    // recorrer en Inordre perque estiguin de mes petit a mes gran
    obteValorsRangAux(node->getLeft(), k1, k2, v);
    if (node->getKey() >= k1 && node->getKey() <= k2)
    {
        v.push_back(node);
    }
    obteValorsRangAux(node->getRight(), k1, k2, v);
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami(Clau key) const
{
    if (isEmpty())
        throw invalid_argument("L'arbre esta buit");
    else
    {
        NodeBinari<Clau, Valor> *node = search(key);
        imprimirCamiAux(node);
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCamiAux(const NodeBinari<Clau, Valor> *node) const
{
    // si no estem a la root anem pujant i printem els valors per els que passem
    if (node != nullptr)
    {
        imprimirCamiAux(node->getParent());
        cout << node->getKey() << " ";
    }
}

/* anem baixant tota la part dreta del arbre ja que es on hi haura els nombres mes petits */
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminaMinim()
{
    // a la hora d'eliminar el minim pot ser que estiguem en 3 casos
    if (!isEmpty())
    {
        NodeBinari<Clau, Valor> *node = this->root;
        NodeBinari<Clau, Valor> *parent = nullptr;
        // el minim sera el node que estigui mes a la dreta del tot
        while (node->hasLeft())
        {
            parent = node;
            node = node->getLeft();
        }
        // 1. el root no te fills drets
        if (node == root)
        {
            // eliminem el root i el seu fill dret (si en te) passara a ser el root
            root = (node->hasRight()) ? (node->getRight()) : (nullptr);
        }
        else
        {
            // 2. el mes petit te un fill dret aleshores el parent apuntara a aquest
            // 3. el mes petit es fulla l'eliminem i el pare apuntara a nullptr
            (node->hasRight()) ? (parent->setLeft(node->getRight())) : (parent->setLeft(nullptr));
        }

        delete node;
        this->_size--;
    }
    else
    {
        throw invalid_argument("Esta buit");
    }
}

/* tornem el node que te la mateixa clau, si es mes petita anem a l'esquerra i si es mes gran a la dreta */
template <class Clau, class Valor>
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::search(const Clau &k) const
{
    NodeBinari<Clau, Valor> *node = root;
    while (node != nullptr)
    {
        // si la clau del node i la clau son iguals ja esta
        if (k == node->getKey())
        {
            return node;
        }
        else
        {
            // si la clau es mes petita anem a la dreta, altrament a l'esquerra
            node = (k < node->getKey()) ? node->getLeft() : node->getRight();
        }
    }
    // si no l'hem trobat retornem nullptr
    return nullptr;
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::getRoot() const
{
    if (isEmpty())
        throw invalid_argument("L'arbre esta buit");
    return root;
}

#endif // ARBREBINARI_H