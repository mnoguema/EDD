#include "ArbreBinari.h"
using namespace std;

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(){
    this->root == nullptr;
    this->_size == 0;
    cout << "Arbre binari creat"<< endl;
}

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(const ArbreBinari<Clau, Valor>& orig){
    this->root= new NodeBinari<Clau, Valor>(*orig.root);
    this->_size = orig._size;
    cout << "Arbre binari copiat"<< endl;
}

template <class Clau, class Valor>
bool ArbreBinari<Clau, Valor>::isEmpty() const{
    return root == nullptr;
}

template <class Clau, class Valor>
int ArbreBinari<Clau,Valor>::height() const{
    if(isEmpty()){
        throw invalid_argument("L'arbre esta buit");
    }
    return root->height();
}

/* si l'arbre no esta buit */
template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::insert(const Clau& clau, const Valor& value){
    NodeBinari<Clau, Valor>** node = &root;
    while(*node){
        if(clau==(*node)->getKey()){
            (*node)->insertValue(value);
            return *node;
        }else if (clau< (*node)->getKey()){
            node = &(*node)->getLeft();
        }else{
            node = &(*node)->getRight();
        }
    }
    *node = new NodeBinari<Clau, Valor>(clau);
    (*node)->insertValue(value);
    _size++;
    return *node;
}

template <class Clau, class Valor>
const Valor& ArbreBinari<Clau,Valor>::valueOf(const Clau& clau) const{
    NodeBinari<Clau,Valor>* node = search(clau);
    if(node==nullptr){
        throw invalid_argument("Clau no trobada");
    }
    return node->getValue();
}
        
template <class Clau, class Valor>
void ArbreBinari<Clau,Valor>::imprimirPreordre(const NodeBinari<Clau,Valor>* n) const{
    if(isEmpty())
        throw invalid_argument("L'arbre esta buit");
    if (n == nullptr){
        printPreOrder(root);
    }else{
        //Preorder -> root, left, right
        cout << n->getKey() << " ";
        if (n->left() != nullptr) printPreOrder(n->left());
        if (n ->right() != nullptr) printPreOrder(n->right());
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau,Valor>::imprimirInordre(const NodeBinari<Clau,Valor>* n) const{
    if (n==nullptr){
        n=root;
    }else{
        imprimirInordre(n->getLeft());        
        cout << n->getValue() << " ";
        imprimirInordre(n->getRight());
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau,Valor>::imprimirPostordre(const NodeBinari<Clau,Valor>* n) const{
    if (n==nullptr){
        n=root;
    }else{
        imprimirPostordre(n->getLeft());
        imprimirPostordre(n->getRight());        
        cout << n->getValue() << " ";
    }    
}
        
// vector<NodeBinari<Clau,Valor>*> obteValorsRang(int k1, int k2) const;
// template <class Clau, class Valor>
// void ArbreBinari<Clau,Valor>::imprimirCami(Clau key) const{
//     NodeBinari<Clau, Valor>* node = search(key);
//     if(node == nullptr)
//         throw invalid_argument("La clau no està al arbre");
//     cout << node->getValue();
// }

/* anem baixant tota la part dreta del arbre ja que es on hi haura els nombres mes petits */
template <class Clau, class Valor>
void ArbreBinari<Clau,Valor>::eliminaMinim(){
    if(!isEmpty()){
        NodeBinari<Clau, Valor>* node = this->root;
        NodeBinari<Clau, Valor>* parent = nullptr;
        while(node->hasLeft()){
            parent=node;
            node=node->getLeft();
        }
        delete node;
        this->_size--;
    }
}

/* tornem el node que te la mateixa clau, si es mes petita anem a l'esquerra i si es mes gran a la dreta */
template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau,Valor>::search(const Clau& k) const{
    NodeBinari<Clau,Valor>* node = root;
    while (node!=nullptr){
        if(k == node->getKey()){
            return node;
        }else{
            node = (k < node->getKey()) ? node->getLeft() : node->getRight();
        }
    }

    return nullptr;
}