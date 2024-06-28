#ifndef MAQUINA_H
#define MAQUINA_H
#include "Jugador.h"
#include "Leer.h"

class Maquina : public Jugador {
private:

public:
  Maquina();
  int turnoDif(int, int *);/*Recibe el numero rechazado por el otro jugador y el arreglo de numeros disponibles y
                            piensa para cambiar el numero generado en la mejor posicion, si el numero generado
                            es  5, entonces retorna 52*/
  void cambiarTorreDif(int, int *);/*Recibe el numero a cambiar y el arreglo de numeros disponibles, luego cambia
                                    nTorreCambiada a true, cambia la torre con el numero dado a el valor de 
                                    posicion, llama a calcular puntaje y libera el numero donde se hizo el cambio*/
  
  int turno(int, int *);//Hace lo mismo que turno dificil pero sin pensar y con movimientos aleatorios
  void imprimirDibujo();//Imprime un dibujo bonito con un sleep :D

  ~Maquina();//Destructor de Maquina
};
#else
class Maquina;
#endif