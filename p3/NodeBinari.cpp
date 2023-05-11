#include "NodeBinari.h"
using namespace std;

template<class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const Clau& key, const Valor& v){
    this->key==key;
    this->value == v;
    this->left == nullptr;
    this->right == nullptr;
    this->parent == nullptr;
}

template<class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const NodeBinari<Clau,Valor>& orig){
    this->key = orig.key;
    this->value = orig.value;
    this->left == nullptr;
    this->right == nullptr;
    this->parent == nullptr;
}

/*#template<class Clau, class Valor>
virtual NodeBinari::~NodeBinari();*/

/* ------------------MODIFICADORS---------------------------- */
template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setKey(const Clau& key) { 
    this->key = key; 
}
template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setValue(const Valor& value) { 
    this->value = value; 
}
template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setLeft(NodeBinari* left) { 
    this->left = left; 
}
template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setRight(NodeBinari* right) { 
    this->right = right;
}
template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setParent(NodeBinari* parent) { 
    this->parent = parent; 
}

/* ---------------------CONSULTORS------------------------ */
template<class Clau, class Valor>
const Clau& NodeBinari<Clau, Valor>::getKey() const{
    return key;
}
template<class Clau, class Valor>
const Valor& NodeBinari<Clau, Valor>::getValue() const{
    return value;
}
/**pregunatar alex si han de ser const----const*/
template<class Clau, class Valor>
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getLeft() const { 
    return left; 
    }
template<class Clau, class Valor>
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getRight() const { 
    return right; 
    }
template<class Clau, class Valor>
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getParent() const { 
    return parent; 
    }


/* --------------------------OPERACIONS------------------------ */
/* Si no te pare aleshores es el root */
template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isRoot() const { 
    return parent == nullptr; 
}
/* cert si te un fill esquerre */
template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasLeft() const { 
    return left != nullptr; 
}
/* cert si te un fill dret */
template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasRight() const { 
    return right != nullptr; 
}
/* sera una fulla si ja no te cap fill */
template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isExternal() const { 
    return !hasLeft() && !hasRight(); 
}
template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::insertValue(const Valor& v) { 
    value = v; 
}
/* recorrem tota la part dreta del arbre i tota la part esquerra recursivament i agafem la més gran */
template<class Clau, class Valor>
int NodeBinari<Clau, Valor>::height() const {
        int leftHeight = hasLeft() ? left->height() : -1;
        int rightHeight = hasRight() ? right->height() : -1;
        return 1 + std::max(leftHeight, rightHeight);
    }
/* cert si tenen la mateixa clau i mateixos valors */
template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::operator==(const NodeBinari<Clau, Valor>& node) const {
        return key == node.getKey() && value == node.getValue();
}



