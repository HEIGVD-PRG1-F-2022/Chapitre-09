// Fichier pour l'exercice 5 du chapitre 9.
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Identite {
public:
  Identite() = default;

  Identite(const string &prenom, const string &nom) : prenom(prenom), nom(nom) {
    if (prenom.empty()) {
      throw invalid_argument("Exception survenue dans Identite::Identite():\n"
                             "prenom ne peut pas etre une chaine vide.");
    }
    if (nom.empty()) {
      throw invalid_argument("Exception survenue dans Identite::Identite():\n"
                             "nom ne peut pas etre une chaine vide.");
    }
    cout << "Dans Identite::Identite(): " << this->toString() << endl;
  }

  [[nodiscard]] string toString() const { return prenom + " " + nom; }

private:
  const string prenom;
  const string nom;
};

class Personne {
public:
  Personne(const string &prenom, const string &nom) try
      : identite(prenom, nom) {
    cout << "Dans Personne::Personne(): " << this->identite.toString() << endl;
  } catch (invalid_argument &arg) {
    cout << arg.what() << endl;
    cout << "Exception survenue dans Personne::Personne()." << endl;
  }

private:
  const Identite identite;
};

int main() {
  try {
    {
      cout << "Debut du test 1." << endl
           << "Tentative de construction d'un objet du type Personne." << endl;
      Personne personne1("John Fitzgerald", "Kennedy");
      cout << "Fin du test 1." << endl;
    }
    {
      cout << endl
           << "Debut du test 2." << endl
           << "Tentative de construction d'un objet du type Personne." << endl;
      Personne personne2("", "Marley");
      cout << "Fin du test 2." << endl;
    }
  } catch (const invalid_argument &) {
    cout << "Exception survenue dans main()." << endl;
  }
  return EXIT_SUCCESS;
}