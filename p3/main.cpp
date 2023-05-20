/*
| Operacio               | ArbreBnari       | MInHeap           |
|----------------------- |--------------    |--------------     |
| Insercio petit         | 0 ms             | 0 ms              |
| (movie_rating_smal.txt)|                  |                   |
|------------------------|------------------|-------------------|
| Insercio gran          | 8 ms             | 103 ms            |
| (movie_rating.txt)     |                  |                   |
|------------------------|------------------|-------------------|
| Cerca petit            | 15 ms            | 18 ms             |
| (cercaPelicules.txt)   |                  |                   |
|------------------------|------------------|-------------------|
| Cerca gran             | 18 ms            | 513 ms            |
| (cercaPelicules.txt)   |                  |                   |
|------------------------|------------------|-------------------|

*/

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <exception>
using namespace std;
#include "ArbreBinari.h"
#include "CercadorMoviesAB.h"
#include "CercadorMoviesHeap.h"
#include "Movie.h"
void exercici1()
{
    std::cout << " ------------- cas de prova exercici 1 ----------- " << std::endl;
    ArbreBinari<int, int> tree1;

    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8; i++)
    {
        tree1.insert(testKeys[i], testValues[i]);
    }
    cout << "Pre-ordre = { ";
    tree1.imprimirPreordre();
    cout << "}" << endl;

    cout << "In-ordre = { ";
    tree1.imprimirInordre();
    cout << "}" << endl;

    cout << "Post-ordre = { ";
    tree1.imprimirPostordre();
    cout << "}" << endl;

    cout << "ObteValorsRang = { ";
    vector<NodeBinari<int, int> *> rang = tree1.obteValorsRang(5, 45);
    for (const auto &node : rang)
    {
        cout << node->getKey() << " ";
    }
    cout << "}" << endl;

    ArbreBinari<int, int> tree2(tree1);
    cout << "Post-ordre = { ";
    tree2.imprimirPostordre();
    cout << "}" << endl;

    cout << "ImprimirCami = { ";
    tree2.imprimirCami(40);
    cout << "}" << endl;

    tree2.eliminaMinim();

    cout << "In-ordre = { ";
    tree2.imprimirInordre();
    cout << "}" << endl;
}

enum Menu
{
    Fitxer = 1,
    Imprimir = 2,
    Cercar = 3,
    Profunditat = 4,
    Eliminar = 5,
    Sortir = 6
};

void imprimeixMenu()
{
    cout << "MENU \n"
            "1. Carregar dades d'un fitxer\n"
            "2. Mostrar les dades\n"
            "3. Cercar dades\n"
            "4. Profunditat del arbre\n"
            "5. Eliminar dades\n"
            "6. Sortir\n";
}

void casDeProvaExercici3()
{
    std::cout << " ------------- cas de prova exercici 3 ----------- " << std::endl;
    MinHeap<int, int> heap1;
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8; i++)
    {
        heap1.inserir(testKeys[i], testValues[i]);
    }
    cout << "heap1 ={ \n";
    heap1.imprimir();
    cout << "}" << endl;
    cout << "Mida Heap recent creat: " << heap1.tamany() << endl;
    cout << "Alçada Heap recent creat: " << heap1.height() << endl;
    cout << "Heap recent creat. is esBuit? (0/1): " << heap1.isEmpty() << endl;
    cout << "Clau minima " << heap1.minim() << endl;

    cout << "EliminaMinim" << endl;
    heap1.eliminaMinim();
    cout << "Heap despres eliminar 1. Print: " << endl;
    heap1.imprimir();
    cout << "Mida Heap recent creat: " << heap1.tamany() << endl;
    cout << "Alçada Heap recent creat: " << heap1.height() << endl;
    heap1.eliminaMinim();
    cout << "Heap despres eliminar 2. Print: " << endl;
    heap1.imprimir();
    cout << "Mida Heap recent creat: " << heap1.tamany() << endl;
    cout << "Alçada Heap recent creat: " << heap1.height() << endl;
}

// utilizem templates per recicar el main per Binary tree i el Min Heap
template <class Cercador>
void mainCercador()
{
    std::cout << "\n------------- cas de prova exercici 2 i 4 ----------- " << std::endl;
    Cercador *cercador = new Cercador;
    char fitxer = 'M';
    string filename;
    int opcio;
    do
    {
        imprimeixMenu();
        try
        {
            cout << "Introdueix una opció: ";
            cin >> opcio;
            switch (opcio)
            {
            case Menu::Fitxer:
            {
                try
                {
                    // creem un nou cercador i llegim el fitxer segons entrin una p o una g, per alguna altre opcio ens tornara a demanar un valor
                    cercador = new Cercador();
                    do
                    {
                        cout << "Quin fitxer vols (P/G)?\n";
                        cin >> fitxer;
                        fitxer = toupper(fitxer);
                    } while (fitxer != 'P' && fitxer != 'G');

                    filename = (fitxer == 'P') ? ("movie_rating_small.txt") : ("movie_rating.txt");

                    // creem els objectes chrono i llegim les dades del fitxer
                    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                    cercador->appendMovies(filename);
                    chrono::steady_clock::time_point end = chrono::steady_clock::now();
                    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms." << endl;
                }
                catch (invalid_argument &ex)
                {
                    cout << "ERROR TIPO " << ex.what() << endl;
                }
                break;
            }
            case Menu::Imprimir:
            {
                try
                {
                    cercador->imprimir();
                }
                catch (invalid_argument &ex)
                {
                    cout << "ERROR TIPO " << ex.what() << endl;
                }
                break;
            }
            case Menu::Cercar:
            {
                try
                {
                    // obrim el document on hi ha els id de les pelicules
                    ifstream file("cercaPelicules.txt");
                    if (file.is_open())
                    {
                        int trobats = 0, movieID;
                        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                        // anem llegint els id i si el troba pujem el comptador, si no el troba no fa res i segueix
                        while (file >> movieID)
                        {
                            try
                            {
                                cercador->buscarMovie(movieID);
                                ++trobats;
                            }
                            catch (const std::exception &e)
                            {
                            }
                        }
                        // printem els resultats
                        chrono::steady_clock::time_point end = chrono::steady_clock::now();
                        cout << "Temps transcorregut: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " s." << endl;
                        cout << "Nombre d'elements que estan en el cercador-> " << trobats << endl;
                        break;
                    }
                    else
                    {
                        cout << "Nos'ha pogut obrir el fitxer" << endl;
                    }
                    file.close();
                }
                catch (invalid_argument &ex)
                {
                    cout << "ERROR TIPO " << ex.what() << endl;
                }
                break;
            }
            case Menu::Profunditat:
            {
                try
                {
                    cout << "La profunditat de l'arbre es de " << cercador->height() << endl;
                }
                catch (invalid_argument &ex)
                {
                    cout << "ERROR TIPO " << ex.what() << endl;
                }
                break;
            }
            case Menu::Eliminar:
            {
                try
                {
                    int n;
                    cout << "Quantes pelicules vols esborrar: ";
                    cin >> n;
                    cercador->eliminarMinimaMovie(n);
                }
                catch (const std::exception &ex)
                {
                    cout << "ERROR TIPO " << ex.what() << endl;
                }
                break;
            }
            default:
                cout << "Introdueix una opcio del menu\n";
                break;
            }
        }
        catch (invalid_argument &ex)
        {
            cout << "ERROR TIPO " << ex.what() << endl;
        }
    } while (opcio != Sortir);
}

int main()
{
    try
    {
        exercici1();
        mainCercador<CercadorMoviesAB>();
        casDeProvaExercici3();
        mainCercador<CercadorMoviesHeap>();
    }
    catch (invalid_argument &ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}