#include "Movie.h"
#include "MinHeap.h"
#include <fstream>

class CercadorMoviesHeap : protected MinHeap<int, Movie>
{
public:
    CercadorMoviesHeap();
    CercadorMoviesHeap(const CercadorMoviesHeap &orig);
    virtual ~CercadorMoviesHeap();
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
};

CercadorMoviesHeap::CercadorMoviesHeap() {}

CercadorMoviesHeap::CercadorMoviesHeap(const CercadorMoviesHeap &orig) {}

CercadorMoviesHeap::~CercadorMoviesHeap() {}

void CercadorMoviesHeap::appendMovies(string filename)
{
    string str, titol;
    ifstream file(filename);
    if (file.fail())
    {
        throw runtime_error("Aquest fitxer no existeix");
    }
    else
    {
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

void CercadorMoviesHeap::insertarMovie(int movieID, string title, float rating)
{
    Movie movie(movieID, title, rating);
    inserir(movieID, movie);
}

void CercadorMoviesHeap::imprimir()
{
    MinHeap<int, Movie>::imprimir();
}

Movie CercadorMoviesHeap::buscarMovie(int movieID)
{
    return cerca(movieID);
}

void CercadorMoviesHeap::eliminarMinimaMovie(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!this->isEmpty())
            this->eliminaMinim();
    }
}

int CercadorMoviesHeap::height() const
{
    return MinHeap<int, Movie>::height();
}
