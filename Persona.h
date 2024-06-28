#ifndef PERSONA_H
#define PERSONA_H
#include "Jugador.h"
#include "Leer.h"
#include <iostream>
#include <string>

class Persona : public Jugador {
private:

public:
  Persona();
  int turnoAleatorio(int, int *);/*Recibe el numero rechazado por el otro jugador y el arreglo de numeros disponibles y
                                  hace un movimiento aleatorio para cambiar el numero generado, ademas puede rechazar
                                  el numero y retornarlo, si el numero generado es  5, entonces retorna 52*/
  int turno(int, int *);/*Hace lo mismo que turno Aleatorio pero pide todos los datos a la persona*/
  void cambiarTorrePersona(int, int *);/*Recibe el numero a cambiar y el arreglo de numeros disponibles, luego cambia
                                        nTorreCambiada a true, pregunta al jugador donde va ha hacer el cambio, luego
                                        llama a calcular puntaje y libera el numero donde se hizo el cambio*/
  void cambiarTorrePrueba(int, int *);/*Recibe el numero a cambiar y el arreglo de numeros disponibles, luego cambia
                                      nTorreCambiada a true, cambia la torre con el numero dado a el valor de 
                                      posicion, llama a calcular puntaje y libera el numero donde se hizo el cambio*/
  int turnoPrueba(int, int *);/*Hace lo mismo que turno pero de manera automatica eligiendo con la inteligencia
                              de cocina*/

  ~Persona();
};
#else
class Persona;
#endif