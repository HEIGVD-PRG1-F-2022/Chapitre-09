#include <cstdlib>
#include <iostream>
using namespace std;

void f();

int main() {
  try {
    f();
  } catch (int n) {
    cout << "Exception int dans main : " << n << endl;
  } catch (...) {
    cout << "Exception autre que int dans main" << endl;
  }

  cout << "Fin main\n";
  return EXIT_SUCCESS;
}

void f() {
  try {
//    double x = 1.;
//    throw x;
    int n = 1;
    throw n;
  } catch (int n) {
    cout << "Exception int dans f : " << n << endl;
    throw;
  }
}

/**
 1) Exception int dans f : 1
    Exception int dans main : 1
    Fin main

 2) Exception autre que int dans main
    Fin main
*/