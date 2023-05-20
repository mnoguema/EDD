#include "Movie.h"
#include "ArbreBinari.h"
#include <fstream>

class CercadorMoviesAB : protected ArbreBinari<int, Movie>
{
public:
    CercadorMoviesAB();
    CercadorMoviesAB(const CercadorMoviesAB &orig);
    virtual ~CercadorMoviesAB();
    void appendMovies(string filename);
    void insertarMovie(int movieID, string title, float rating);
    string mostrarMovie(int movieID);
    void mostrarMovieInorder();
    Movie buscarMovie(int movieID);
    float buscarRatingMovie(int movieID);
    void eliminarMinimaMovie(int n);
    int height() const;

    void imprimir();

private:
    // Aqui posareu tots els mètodes auxiliars
    int imprimir40(NodeBinari<int, Movie> *node = nullptr, int k = 0);
};

CercadorMoviesAB::CercadorMoviesAB() {}

CercadorMoviesAB::CercadorMoviesAB(const CercadorMoviesAB &orig) {}

CercadorMoviesAB::~CercadorMoviesAB() {}

void CercadorMoviesAB::appendMovies(string filename)
{
    string str, titol;
    // obrim el fitxer i comprovem que l'hem obert be
    ifstream file(filename);
    if (file.fail())
    {
        throw runtime_error("Aquest fitxer no existeix");
    }
    else
    {
        // mentre hi hagi text ens guardem l'id : el titol : rating
        // inserim la pelicula
        while (!file.eof())
        {
            getline(file, str, ':');
            int id = stoi(str);

            getline(file, titol, ':');

            getline(file, str);
            float rating = stof(str);

            insertarMovie(id, titol, rating);
        }
    }
    file.close();
}

void CercadorMoviesAB::insertarMovie(int movieID, string title, float rating)
{
    Movie movie(movieID, title, rating);
    insert(movieID, movie);
}

string CercadorMoviesAB::mostrarMovie(int movieID)
{
    return valueOf(movieID).toString();
}

Movie CercadorMoviesAB::buscarMovie(int movieID)
{
    return valueOf(movieID);
}

float CercadorMoviesAB::buscarRatingMovie(int movieID)
{
    return valueOf(movieID).getRating();
}

void CercadorMoviesAB::eliminarMinimaMovie(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!ArbreBinari<int, Movie>::isEmpty())
            ArbreBinari<int, Movie>::eliminaMinim();
    }
}

int CercadorMoviesAB::height() const
{
    return ArbreBinari<int, Movie>::height();
}

void CercadorMoviesAB::imprimir()
{
    if (isEmpty())
        throw out_of_range("Arbre buit");
    else
    {
        int k = imprimir40(root, 0);
        while (k >= 40)
        {
            string r;
            cout << "Vols imprimir més pelis? (y/n): " << endl;
            cin >> r;
            if (r == "n" || r == "N")
            {
                break;
            }
            else
            {
                k = imprimir40(root, 0);
            }
        }
    }
}

int CercadorMoviesAB::imprimir40(NodeBinari<int, Movie> *node, int k)
{
    if (node == nullptr)
    {
        return k;
    }
    // apliquem l'agoritme de inordre
    if (node->hasLeft())
        k = imprimir40(node->getLeft(), k);

    if (k < 40)
    {
        cout << mostrarMovie(node->getKey()) << endl;
        k++;
    }

    if (node->hasRight())
        k = imprimir40(node->getRight(), k);

    return k;
}