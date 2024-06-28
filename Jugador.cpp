#include "Jugador.h"


Jugador::Jugador() {
  puntaje = 0;
  puntajeJugada = 0;
  nTorre = 0;
  nTorreCambiada = false;
}

Jugador::~Jugador() { puntaje = 0; }

void Jugador::crearTorre(int *numeros) { torre = Torre(numeros); }

int *Jugador::getTorre() {
  int *nTorres = torre.getTorre();
  return nTorres;
}

void Jugador::cambiarTorreAleatorio(int numero, int *numeros) {
  nTorreCambiada = true;
  srand((unsigned)time(0));
  posicion = rand() % 10 + 1;
  nTorre = torre.getNTorre((10 - posicion));
  torre.cambiarTorre(posicion, numero);
  calcularPuntaje(10 - posicion);
  numeros[nTorre - 1] = 0;
}

int Jugador::generarNumero(int *numeros) {
  bool repetido = false;
  int numeroCambiar;

  srand((unsigned)time(0) + 1);
  if (nTorreCambiada == true){
    return nTorre;
  }else if (nTorreCambiada == false){
    do {
      numeroCambiar = (rand() % 50) + 1;
      if (numeros[numeroCambiar - 1] == 0) {
        repetido = false;
        return numeroCambiar;
      } else {
        repetido = true;
      }
    } while (repetido);
  }
  return 0;
}

void Jugador::calcularPuntaje(int posicion) {
  int contador = 0;
  puntajeJugada = 0;

  for (int i = 0; i < 10; i++) {
    jugada[i] = 0;
  }

  jugada[posicion] = 2;

  if (torre.getNTorre(posicion) - 1 == torre.getNTorre(posicion - 1) ||
      torre.getNTorre(posicion) + 1 == torre.getNTorre(posicion + 1)) {
    puntajeJugada += torre.getNTorre(posicion);
    jugada[posicion] = 1;

    for (int i = posicion - 1; i >= 0; i--) {
      if (torre.getNTorre(i) + 1 == torre.getNTorre(i + 1) && contador == 0) {
        puntajeJugada += torre.getNTorre(i);
        jugada[i] = 1;
      } else
        contador++;
    }
    contador = 0;
    for (int i = posicion + 1; i < 10; i++) {
      if (torre.getNTorre(i) - 1 == torre.getNTorre(i - 1) && contador == 0) {
        puntajeJugada += torre.getNTorre(i);
        jugada[i] = 1;
      } else
        contador++;
    }
  }
  puntaje += puntajeJugada;
}

void Jugador::cocinar(int generado) {
  int *torreMaquina = getTorre();
  if (torreMaquina[0] > generado) {
    posicion = 10;
    return;
  }
  if (torreMaquina[9] < generado) {
    posicion = 1;
    return;
  }

  for (int i = 1; i < 5; i++) {
    if ((torreMaquina[i] > generado) ||
        (torreMaquina[i - 1] > torreMaquina[i])) {
      posicion = 10 - i;
      return;
    }
  }
  for (int i = 8; i >= 5; i--) {
    if (torreMaquina[i] < generado || torreMaquina[i + 1] < torreMaquina[i]) {
      posicion = 10 - i;
      return;
    }
  }
  posicion = 1;
}

int Jugador::getPuntaje() { return puntaje; }

int Jugador::getPuntajeJugada() { return puntajeJugada; }

int *Jugador::getJugada() { return jugada; }


void Jugador::setNTorreCambiada(bool nTorreCambiada) {
  this -> nTorreCambiada = nTorreCambiada;
}

bool Jugador::getNtorreCambiada() { return nTorreCambiada; }

void Jugador::setNTorre(int nTorre){
  this -> nTorre = nTorre;
}
int Jugador::getNtorre(){
  return nTorre;
}