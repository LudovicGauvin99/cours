#include <iostream>
#include "Personne.h"
#include <string>

using namespace std;

Personne::Personne()
{
    name = "";
    prenom = "";
    age = 0;
}

Personne::Personne(std::string newname, std::string newprenom, int newage)
{
    name = newname;
    prenom = newprenom;
    age = newage;
}

void Personne::setName(std::string newName)
{
    name = newName;
}

void Personne::setPrenom(std::string newPrenom)
{
    prenom = newPrenom;
}

void Personne::setAge(int newAge)
{
    age = newAge;
}

std::string Personne::getName()
{
    return name;
}

std::string Personne::getPrenom()
{
    return prenom;
}

int Personne::getAge()
{
    return age;
}

Personne::~Personne()
{
}

