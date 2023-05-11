#ifndef ARBREBINARI_H
#define ARBREBINARI_H
#include <iostream>
#include <vector>

#include "NodeBinari.h"

template <class Clau, class Valor>
class ArbreBinari {
    public:
        ArbreBinari();
        ArbreBinari(const ArbreBinari<Clau, Valor>& orig);
        virtual ~ArbreBinari();

        bool isEmpty() const;
        int height() const;

        NodeBinari<Clau,Valor>* insert(const Clau& clau, const Valor& value);
        const Valor& valueOf(const Clau& clau) const;
        void imprimirPreordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
        void imprimirInordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
        void imprimirPostordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
        // vector<NodeBinari<Clau,Valor>*> obteValorsRang(int k1, int k2) const;
        // void imprimirCami(Clau key) const;
        void eliminaMinim();
    protected:
        NodeBinari<Clau,Valor>* root;
        NodeBinari<Clau,Valor>* search(const Clau& k) const;
    private:
        int _size;
 /* Mètodes auxiliars definiu aquí els que necessiteu */
};
#endif //ARBREBINARI_H