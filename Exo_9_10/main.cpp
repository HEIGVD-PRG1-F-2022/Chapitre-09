#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

using ullong = unsigned long long;

class Argument_Non_Valide : public logic_error {
public:
  explicit Argument_Non_Valide(const string &what_arg)
      : logic_error(what_arg) {}
  explicit Argument_Non_Valide(const char *what_arg) : logic_error(what_arg) {}
};

class Debordement : public runtime_error {
public:
  explicit Debordement(const string &what_arg) : runtime_error(what_arg) {}
  explicit Debordement(const char *what_arg) : runtime_error(what_arg) {}
};

int sommeNPremiersEntiers(int n);
void test(int n);

int main() {
  test(-1);
  test(0);
  test(1);
  test(2);
  test(3);
  test(4);
  test(5);
  test(65533);
  test(65534);
  test(65535);
  test(65536);
  return EXIT_SUCCESS;
}

int sommeNPremiersEntiers(int n) {
  if (n < 0)
    throw Argument_Non_Valide("Argument non valide: n doit etre >= 0");

  const int limit = numeric_limits<int>::max();

  if (n == limit || n / 2 > limit / (n + 1)) {
    throw Debordement("La valeur donnee est trop grande");
  }

  // En fait on ne peut pas calculer n * (n+1) dans un int,
  // vu que ça déborde, même si le résultat / 2 passera. Alors
  // il faut diviser avant, et ajouter le terme en cas d'erreur.
  return n / 2 * (n + 1) + (n % 2) * (n + 1) / 2;
}

void test(int n) {
  cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
  try {
    cout << " = " << sommeNPremiersEntiers(n) << endl;
  } catch (const exception &e) {
    cout << ": " << e.what() << endl;
  }
}
