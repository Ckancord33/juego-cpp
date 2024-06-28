#include "Maquina.h"
#include <unistd.h>

Maquina::Maquina() {
  puntaje = 0;
  posicion = 0;
}

Maquina::~Maquina() {}

void Maquina::cambiarTorreDif(int numero, int *numeros) {
  nTorreCambiada = true;
  nTorre = torre.getNTorre((10 - posicion));
  torre.cambiarTorre(posicion, numero);
  calcularPuntaje(10 - posicion);
  numeros[nTorre - 1] = 0;
  posicion = 0;
}

int Maquina::turno(int numeroDado, int *numeros) {
  imprimirDibujo();
  srand((unsigned)time(0));
  int opc, numeroCambiar;
  if (numeroDado != 0) {
    if ((rand() % 2) == 0) {
      cambiarTorreAleatorio(numeroDado, numeros);
      numeros[(numeroDado - 1)] = 1;
      return 0;
    }else{
      nTorreCambiada = false;
    }
  }
  numeroCambiar = generarNumero(numeros);
  if (numeroCambiar == 5) {
    return 52;
  }
  opc = (rand() % 2);
  if (opc == 1) {
    cambiarTorreAleatorio(numeroCambiar, numeros);
    numeros[(numeroCambiar - 1)] = 1;
    return 0;
  } else {
    return numeroCambiar;
  }
  return 0;
}

int Maquina::turnoDif(int numeroDado, int *numeros) {
  imprimirDibujo();
  int numeroCambiar;
  if (numeroDado != 0) {
    cocinar(numeroDado);
    cambiarTorreDif(numeroDado, numeros);
    numeros[(numeroDado - 1)] = 1;
    return 0;
  }
  numeroCambiar = generarNumero(numeros);
  if (numeroCambiar == 5) {
    return 52;
  }
  cocinar(numeroCambiar);
  cambiarTorreDif(numeroCambiar, numeros);
  numeros[(numeroCambiar - 1)] = 1;
  return 0;
}

void Maquina::imprimirDibujo() {
  cout << "\n\n----------------la maquina esta "
          "cocinando...-----------------\n\n";
  cout << MAGENTA << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠀⡏⠉⠉⣉⠭⢍⠉⠉⡩⠽⢍⠉⠉⠉⡇⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⢰⠈⡇⠀⠀⣿⣷⡄⡇⠸⣿⣷⠀⠇⠀⠀⡇⢳⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⢸⣴⠓⠢⡀⠈⠛⠊⠀⠀⠈⠛⠈⠀⡠⠒⢳⢸⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠈⢹⠀⠀⠈⠂⠀⠒⠒⠒⠀⠀⠐⠋⠀⠀⢸⠁⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠸⠤⣤⡤⠤⢤⣤⣤⣤⣤⣤⠤⢤⣤⠤⠼⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⢠⠎⢡⣛⣶⣾⣷⣿⣶⣶⣾⣶⣛⠊⠑⡄⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⡸⣄⢸⡇⠀⣷⠀⠀⠀⢰⠀⠀⢸⡄⢀⢧⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⣜⠀⢨⢻⡧⠴⠘⠷⣀⠴⠏⡿⠦⢼⠿⠅⠀⣡⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⢀⡰⣁⡹⠃⢸⣇⠀⠀⠀⠋⠀⠀⠁⠀⢠⡄⠈⢯⣈⠧⡀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⣠⠶⢎⠀⢨⠇⠀⢸⢬⠛⣽⣿⣿⣿⣿⣟⣽⢫⡄⠀⠀⡇⠀⢸⠢⢄⠀" << endl;
  usleep(50000);
  cout << "⡔⢁⠤⡀⢹⠁⠀⠀⠸⣬⠯⠬⠿⣭⠭⡭⠭⠬⠭⡅⠀⠀⠈⡏⠁⡠⡄⢡" << endl;
  usleep(50000);
  cout << "⠳⢁⠜⣠⠏⠀⠀⠀⠀⡱⠤⠤⠤⢞⣈⠧⠤⠤⠴⡃⠀⠀⠀⠑⢄⠱⡈⠚" << endl;
  usleep(50000);
  cout << "⠀⠈⠉⠁⠀⠀⠀⠀⠀⢹⠒⠒⠒⢪⢠⡗⠒⠒⠒⡅⠀⠀⠀⠀⠀⠉⠁⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠀⢀⠠⠜⠛⠻⠭⣵⢰⡯⠭⠛⠛⠢⢄⠀⠀⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠰⠁⠀⠀⠀⠀⠀⢸⢼⠀⠀⠀⠀⠀⠀⠑⡄⠀⠀⠀⠀⠀" << endl;
  usleep(50000);
  cout << "⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠀⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀" << RESET << endl;
}

