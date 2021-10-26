#include <iostream>
#include "Employe.cpp"
#include "Personne.cpp"
#include <string>

using namespace std;

int main()
{
    // Personne p("Jhon", "Doe", 25);
    Employe e("Jhon", "Doe", 25, 20.0);
    
    std::cout << "nom prenom : " << e.getName() << endl;

}