#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "Personne.h"
#include <string>

class Employe:public Personne
{
private:
    float salaire;
public:
    Employe(/* args */);
    Employe(std::string newname, std::string newprenom, int newage, float newSalaire);
    std::string getName();
    ~Employe();
};

#endif