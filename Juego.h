#ifndef JUEGO_H
#define JUEGO_H
#include "Maquina.h"
#include "Persona.h"
#include "Leer.h"
#include "Color.h"
#include <iostream>
#include <string>

class Juego {
private:
  int numeros[50];
  Persona persona;
  Maquina maquina;
  string ganador;
  bool sentenciaP;
  bool sentenciaM;

  string colorTorre;
  string colorTorreMaquina; 
  string colorSeleccion;
  string colorPuntos;
  string disenoTorre;
  
public:
  Juego();//Constructor de Juego, inicializa 
  void crearTorre();//crea un objeto maquina y persona y ejecuta crear torre para jugadores
  void mostrarTorre();//muestra las torres,aplica los colores/diseños y imprime con un 0 los numeros menores a 10
  void mostrarTorrePrueba();//muestra las torres,los numeros ocupados del universo, los puntajes de los dos jugadores y los numeros de la maquina.
  void results();//imprime los resultados de la partida (puntajes de ambos y los numeros de la maquina)
  bool comprobarGanador(int,int);//comprueba si alguno de los jugadores cumple los requisitos para ganar la partida y modifica el valor de ganador dependiendo de esto.
  bool mostrarGanador(int);//imprime el ganador de la partida y un mensaje dependiendo de la condicion de su victoria o derrota
  void turnos(int);//en un ciclo de 50 ejecuta los turnos de persona y maquina, comprueba los ganadores en cada ronda y termina el ciclo cuando alguno de los jugadores gane.
  void turnosPrueba();//realiza lo mismo que turno pero el turno de persona se ejecuta de manera automatica
  string getGanador();//devuelve el ganador del juego

  void setColor(string, string, string, string);//cambia los colores de las torres, los puntos, y el color al posicionar un numero en la torre
  void setDiseno(string);//cambia el diseño de la torre

  ~Juego(); //destructor de Juego
};
#else
class Juego;
#endif