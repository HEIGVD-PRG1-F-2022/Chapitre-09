// Fichier pour l'exercice 5 du chapitre 9.
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Identite {
public:
  Identite() = default;

  Identite(const string &prenom, const string &nom);
  //  <à compléter 1>

  string toString() const { return prenom + " " + nom; }

private:
  string prenom;
  string nom;
};

class Personne {
public:
  Personne(const string &prenom, const string &nom);
  // <à compléter 2>

private:
  Identite identite;
};

int main() {
  try {
    {
      cout << "Debut du test 1." << endl
           << "Tentative de construction d'un objet du type Personne." << endl
           << "Parametres fournis: \"John Fitzgerald\", \"Kennedy\"" << endl;
      Personne personne1("John Fitzgerald", "Kennedy");
      cout << "Fin du test 1." << endl;
    }
    {
      cout << endl
           << "Debut du test 2." << endl
           << "Tentative de construction d'un objet du type Personne." << endl
           << "Parametres fournis: \"\", \"Marley\"" << endl;
      Personne personne2("", "Marley");
      cout << "Fin du test 2." << endl;
    }
  } catch (const invalid_argument &) {
    cout << "Exception survenue dans main()." << endl;
  }
  return EXIT_SUCCESS;
}