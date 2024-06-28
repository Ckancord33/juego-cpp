#include "Torre.h"
using namespace std;
#include <string>

Torre::Torre(){
}

Torre::Torre(int *numeros) {
  int contador = 0;
  int numeroRandom = 0;
  
  srand((unsigned)time(0));
  
  while (contador < 10) {
    numeroRandom = (rand() % 50) + 1;
    if (numeros[numeroRandom -1] == 0) {
       torre[contador] = numeroRandom;
       contador++;
       numeros[numeroRandom -1] = 1;
    }
  }
  
}

int *Torre::getTorre() { return torre; }

int Torre::getNTorre(int n){
  return torre[n];
}

void Torre::cambiarTorre(int pos, int numero) {
  torre[10 - pos] = numero;
}

Torre::~Torre() {}