#ifndef NODEBINARI_H
#define NODEBINARI_H
#include <iostream>

template <class Clau, class Valor >
class NodeBinari {
    public:
        NodeBinari(const Clau& key, const Valor& v);
        NodeBinari(const NodeBinari<Clau,Valor >& orig);
        virtual ~NodeBinari();

        /* Modificadors */
        // declareu aquí els modificadors (setters) dels atributs que necessiteu
        void setKey(const Clau& key);
        void setValue(const Valor& value);
        void setLeft(NodeBinari* left);
        void setRight(NodeBinari* right);
        void setParent(NodeBinari* parent);

        /* Consultors */
        const Clau& getKey() const;
        const Valor& getValue() const;
        NodeBinari* getLeft() const;
        NodeBinari* getRight() const;
        NodeBinari* getParent() const; 


        /* Operacions */
        bool isRoot() const;
        bool hasLeft() const;
        bool hasRight() const;
        bool isExternal() const;
        void insertValue(const Valor & v);
        int height() const;
        bool operator==(const NodeBinari<Clau,Valor >& node) const;

    private:
        Clau key;
        Valor value;
        NodeBinari<Clau, Valor>* left;
        NodeBinari<Clau, Valor>* right;
        NodeBinari<Clau, Valor>* parent;
};

#endif //NODEBINARI_H
