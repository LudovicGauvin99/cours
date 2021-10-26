#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>

class Personne
{
private:
    std::string name;
    std::string prenom;
    int age;
public:
    Personne();
    Personne(std::string newname, std::string newprenom, int newage);
    void setName(std::string newName);
    void setPrenom(std::string newPrenom);
    void setAge(int newAge);
    std::string getName();
    std::string getPrenom();
    int getAge();
    ~Personne();
};

#endif