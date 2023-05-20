#ifndef NODEBINARI_H
#define NODEBINARI_H
#include <iostream>

template <class Clau, class Valor>
class NodeBinari
{
public:
    NodeBinari(const Clau &key, const Valor &v);
    NodeBinari(const NodeBinari<Clau, Valor> &orig);
    virtual ~NodeBinari();

    /* Modificadors */
    // declareu aquí els modificadors (setters) dels atributs que necessiteu
    void setKey(const Clau &key);
    void setValue(const Valor &value);
    void setLeft(NodeBinari<Clau, Valor> *left);
    void setRight(NodeBinari<Clau, Valor> *right);
    //        void setParent(NodeBinari<Clau, Valor>* parent);

    /* Consultors */
    const Clau &getKey() const;
    const Valor &getValue() const;
    NodeBinari<Clau, Valor> *getLeft() const;
    NodeBinari<Clau, Valor> *getRight() const;
    NodeBinari<Clau, Valor> *getParent() const;

    /* Operacions */
    bool isRoot() const;
    bool hasLeft() const;
    bool hasRight() const;
    bool isExternal() const;
    void insertValue(const Valor &v);
    int height() const;
    bool operator==(const NodeBinari<Clau, Valor> &node) const;

private:
    Clau key;
    Valor value;
    NodeBinari<Clau, Valor> *left;
    NodeBinari<Clau, Valor> *right;
    NodeBinari<Clau, Valor> *parent;
};

template <class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const Clau &key, const Valor &v)
{
    this->key = key;
    this->value = v;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const NodeBinari<Clau, Valor> &orig)
{
    this->key = orig.key;
    this->value = orig.value;
    if (orig.left != nullptr)
    {
        left = new NodeBinari<Clau, Valor>(*orig.left);
        left->parent = this;
    }
    if (orig.right != nullptr)
    {
        right = new NodeBinari<Clau, Valor>(*orig.right);
        right->parent = this;
    }
}

template <class Clau, class Valor>
NodeBinari<Clau, Valor>::~NodeBinari()
{
    delete left;
    delete right;
}

/* ------------------MODIFICADORS---------------------------- */
template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::setKey(const Clau &key)
{
    this->key = key;
}
template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::setValue(const Valor &value)
{
    this->value = value;
}
template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::setLeft(NodeBinari<Clau, Valor> *left)
{
    this->left = left;
    if (left != nullptr)
        this->left->parent = this;
}
template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::setRight(NodeBinari<Clau, Valor> *right)
{
    this->right = right;
    if (right != nullptr)
        this->right->parent = this;
}
// template<class Clau, class Valor>
// void NodeBinari<Clau, Valor>::setParent(NodeBinari* parent) {
//     this->parent = parent;
// }

/* ---------------------CONSULTORS------------------------ */
template <class Clau, class Valor>
const Clau &NodeBinari<Clau, Valor>::getKey() const
{
    return key;
}
template <class Clau, class Valor>
const Valor &NodeBinari<Clau, Valor>::getValue() const
{
    return value;
}
/**pregunatar alex si han de ser const----const*/
template <class Clau, class Valor>
NodeBinari<Clau, Valor> *NodeBinari<Clau, Valor>::getLeft() const
{
    return left;
}
template <class Clau, class Valor>
NodeBinari<Clau, Valor> *NodeBinari<Clau, Valor>::getRight() const
{
    return right;
}
template <class Clau, class Valor>
NodeBinari<Clau, Valor> *NodeBinari<Clau, Valor>::getParent() const
{
    return parent;
}

/* --------------------------OPERACIONS------------------------ */
/* Si no te pare aleshores es el root */
template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isRoot() const
{
    return parent == nullptr;
}
/* cert si te un fill esquerre */
template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasLeft() const
{
    return left != nullptr;
}
/* cert si te un fill dret */
template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasRight() const
{
    return right != nullptr;
}
/* sera una fulla si ja no te cap fill */
template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isExternal() const
{
    return !hasLeft() && !hasRight();
}
template <class Clau, class Valor>
void NodeBinari<Clau, Valor>::insertValue(const Valor &v)
{
    value = v;
}
/* recorrem tota la part dreta del arbre i tota la part esquerra recursivament i agafem la més gran */
template <class Clau, class Valor>
int NodeBinari<Clau, Valor>::height() const
{
    if (this == nullptr)
        return 0;
    else if (isExternal())
        return 1;
    else
    {
        int leftHeight = hasLeft() ? left->height() : 0;
        int rightHeight = hasRight() ? right->height() : 0;
        return 1 + std::max(leftHeight, rightHeight);
    }
}

/* cert si tenen la mateixa clau i mateixos valors */
template <class Clau, class Valor>
bool NodeBinari<Clau, Valor>::operator==(const NodeBinari<Clau, Valor> &node) const
{
    return key == node.getKey() && value == node.getValue();
}

#endif // NODEBINARI_H
