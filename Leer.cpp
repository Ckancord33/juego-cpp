#include "Leer.h"

string leer(string mensaje) {
  string aux;
  cout << mensaje;
  getline(cin, aux);
  return aux;
}