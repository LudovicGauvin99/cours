#include <iostream>
#include "employe.h"
#include <string>

using namespace std;

Employe::Employe(std::string newname, std::string newprenom, int newage, float newSalaire) : Personne(newname, newprenom, newage)
{
    salaire = newSalaire;
}

Employe::Employe() : Personne()
{
    salaire = 0.0;
}

std::string Employe::getName()
{
    string resultat = this->Personne::getName() + " " + this->Personne::getPrenom();
    return resultat;
}

Employe::~Employe()
{
}
