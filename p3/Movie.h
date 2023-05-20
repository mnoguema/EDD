#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
using namespace std;

class Movie
{
public:
    Movie();
    Movie(int id, string titol, float rating);
    Movie(const Movie &orig);
    //virtual ~Movie();

    int getID() const;
    string getTitle() const;
    float getRating() const;

    void setID(int id);
    void setTitle(string titol);
    void setRating(float rating);

    string toString() const;
    void print();

private:
    int id;
    string titol;
    float rating;
};

/*----------------------------CONSTRUCTORS----------------------------------*/
Movie::Movie()
{
    this->id = 0;
    this->titol = "";
    this->rating = -1;
}

Movie::Movie(int id, string titol, float rating)
{
    this->id = id;
    this->titol = titol;
    this->rating = rating;
}

Movie::Movie(const Movie &orig)
{
    this->id = orig.getID();
    this->titol = orig.getTitle();
    this->rating = orig.getRating();
}

/*---------------------------------MODIFICADORS--------------------------------*/
int Movie::getID() const { return id; }

string Movie::getTitle() const { return titol; }

float Movie::getRating() const { return rating; }

/*---------------------------------CONSULTORS-----------------------------------*/
void Movie::setID(int id) { this->id = id; }

void Movie::setTitle(string titol) { this->titol = titol; }

void Movie::setRating(float rating) { this->rating = rating; }

/*----------------------------------strings--------------______*/
string Movie::toString() const
{
    return to_string(this->id) + "::" + this->titol + "::" + to_string(this->rating);
}

void Movie::print()
{
    cout << "( " << this->id << "::" << this->titol << "::" << this->rating << ")" << endl;
}

#endif // MOVIE_H