#include "Persona.h"
using namespace std;



Persona::Persona() { posicion = 0; }


int Persona::turnoAleatorio(int numeroDado, int *numeros) {
  
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
    return 51;
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

void Persona::cambiarTorrePrueba(int numero, int *numeros) {
  nTorreCambiada = true;
  cocinar(numero);
  nTorre = torre.getNTorre((10 - posicion));
  torre.cambiarTorre(posicion, numero);
  calcularPuntaje(10 - posicion);
  numeros[nTorre - 1] = 0;
}


int Persona::turnoPrueba(int numeroDado, int *numeros) {
  int numeroCambiar;
  numeroCambiar = generarNumero(numeros);
  if(numeroCambiar==5){
    cout<<"Numero generado: 5 \n"; return 51;
  }
  cambiarTorrePrueba(numeroCambiar, numeros);
  numeros[(numeroCambiar - 1)] = 1;
  return 0;
}

void Persona::cambiarTorrePersona(int numero, int *numeros) {
  int posicion = 0;
  nTorreCambiada = true;
  do {
    try {
      posicion=stoi(leer("Digite la ubicacion donde va a colocar el numero generado: "));
      if (posicion < 1 || posicion > 10)
        throw "Posición invalida";
    }catch (const char *error) {
      cout <<RED<< error <<RESET<< endl;
    }
    catch(invalid_argument &error){
      cout <<RED<<"El dato no es un numero. Error de tipo:  "<<error.what()<<RESET<<endl;
    }

  } while (posicion < 1 || posicion > 10);

  nTorre = torre.getNTorre((10 - posicion));
  torre.cambiarTorre(posicion, numero);
  calcularPuntaje(10 - posicion);
  numeros[nTorre - 1] = 0;
}

int Persona::turno(int numeroDado, int *numeros) {
  int opc;
  string opc2, opc3;
  int numeroCambiar;
  cout << "----------------ES TU TURNO!!-----------------\n\n";
  if (numeroDado != 0) {
    do {
      try {
        opc3 = leer("La maquina rechazo el numero '" + to_string(numeroDado) +
                    "' ¿Desea usar el numero?(S/N): ");
        if (opc3 != "s" and opc3 != "S" and opc3 != "n" and opc3 != "N") {
          throw "Ingrese una opcion valida\n";
        }
      } catch (const char *error) {
        cout << RED << error << RESET;
      }
    } while (opc3 != "s" and opc3 != "S" and opc3 != "n" and opc3 != "N");
    if (opc3 == "s" or opc3 == "S") {
      cambiarTorrePersona(numeroDado, numeros);
      numeros[(numeroDado - 1)] = 1;
      return 0;
    } else{
       nTorreCambiada = false;
    }
  }
  numeroCambiar = generarNumero(numeros);
  cout << "El numero generado es: " + to_string(numeroCambiar) + "\n";
  if(numeroCambiar==5){
    return 51;
  }
  do {
    try {
      opc = stoi(
          leer("1-Conservar el numero\n2-Deseo generar otro número\nDigite: "));
      if (opc != 1 and opc != 2) {
        throw "Ingrese una opcion valida\n";
      }
    } catch (const char *error) {
      cout << RED << error << RESET;
    } catch (invalid_argument &error) {
      cout << RED << "El dato no es un numero. Error de tipo: " << error.what()
           << RESET << endl;
    }
  } while (opc != 1 and opc != 2);

  if (opc == 1) {
    cambiarTorrePersona(numeroCambiar, numeros);
    numeros[(numeroCambiar - 1)] = 1;
    return 0;
  } else {
    nTorreCambiada = false;
    numeroCambiar = generarNumero(numeros);
    cout << "El numero generado es: " + to_string(numeroCambiar) + "\n";
    if(numeroCambiar==5){
      return 51;
    }
     do {
      opc2 = leer("Desea generar un cambio de bloque? (S/N): ");
      try {
        if (opc2 != "s" and opc2 != "S" and opc2 != "n" and opc2 != "N") {
          throw "Opcion invalida, intente nuevamente\n";
        }
      } catch (const char *error) {
        cout << RED << error << RESET;
      } catch (invalid_argument &error) {
        cout << RED << "El dato no es un letra " << error.what() << RESET
             << endl;
      }
    } while (opc2 != "s" and opc2 != "S" and opc2 != "n" and opc2 != "N");

    if (opc2 == "S" or opc2 == "s") {
      cambiarTorrePersona(numeroCambiar, numeros);
      numeros[numeroCambiar - 1] = 1;
      return 0;
    } else {
      cout << "El numero rechazado '" << numeroCambiar
           << "' se le ofrecera a la maquina\n\n";
      return numeroCambiar;
    }
  }
}

Persona::~Persona() {}