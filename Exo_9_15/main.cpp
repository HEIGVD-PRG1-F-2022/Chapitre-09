#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;

void onExit() {
  cout << "Appel de exit\n";
}

void onTerminate() {
  cout << "Appel de terminate\n";
  // exit(EXIT_FAILURE); // pour éviter que le programme ne "plante"
}

int main() {

  atexit(onExit);
  set_terminate(onTerminate);

  int n;
  float x;
  double y;

  cout << "Donnez un entier : ";
  cin >> n;

  try {
    switch (n) {
    case 1:
      throw n;
    case 2:
      x = n;
      throw x;
    case 3:
      y = n;
      throw y;
    }
  } catch (int n) {
    cout << "catch(int n) : n = " << n << endl;
  } catch (float x) {
    cout << "catch(float x) : x = " << x << endl;
    exit(EXIT_FAILURE);
  }

  cout << "Fin du programme\n";

  return EXIT_SUCCESS;
}

/**
 1) Donnez un entier : 1
    catch(int n) : n = 1
    Fin du programme
    Appel de exit
    Appuyez sur une touche pour continuer...

 2) Donnez un entier : 2
    catch(float x) : x = 2
    Appel de exit
    Appuyez sur une touche pour continuer...

 3) Donnez un entier : 3 Appel de terminate
    This application has requested the Runtime to terminate it in an unusual way.
      Please contact the application's support team for more information.

 4) Donnez un entier : 4
    Fin du programme
    Appel de exit
    Appuyez sur une touche pour continuer...
*/