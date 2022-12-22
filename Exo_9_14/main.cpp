#include <cstdlib>
#include <iostream>

using namespace std;

void onExit() {
  cout << "Appel de exit\n";
}

int main() {
  atexit(onExit);

  int n;

  cout << "Donnez un entier : ";
  cin >> n;
  try {
    cout << "Debut du premier bloc try\n";
    if (n)
      throw n;
    cout << "Fin du premier bloc try\n";
  } catch (int n) {
    if (n == 1)
      cout << "catch 1 : n = " << n << endl;
    else
      exit(EXIT_FAILURE);
  }

  cout << "... suite du programme\n";

  try {
    cout << "Debut du second bloc try\n";
    throw n;
    cout << "Fin du second bloc try\n";
  } catch (int n) {
    cout << "catch 2 : n = " << n << endl;
  }

  cout << "Fin du programme\n";

  return EXIT_SUCCESS;
}

/**
 1) Donnez un entier : 1
    Debut du premier bloc try
    catch 1 : n = 1
    ... suite du programme
    Debut du second bloc try
    catch 2 : n = 1
    Fin du programme
    Appel de exit
    Appuyez sur une touche pour continuer...

 2) Donnez un entier : 0
    Debut du premier bloc try
    Fin du premier bloc try
    ... suite du programme
    Debut du second bloc try
    catch 2 : n = 0
    Fin du programme
    Appel de exit
    Appuyez sur une touche pour continuer...

 3) Donnez un entier : 2
    Debut du premier bloc try
    Appel de exit
    Appuyez sur une touche pour continuer...
*/