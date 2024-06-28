#ifndef TORRE_H
#define TORRE_H
#include <iostream>
#include <string>
using namespace std;

class Torre{

  private:

  int torre[10];
  public:

  Torre();//Constructor vacio de Torre
  Torre(int *);/*Constructor de torre, recibe un arreglo de enteros que representa
                los numeros disponibles del juego, crea la torre con los numero disponibles
                y inahibilita los numeros con los hace la torre en el arreglo de enteros
                original*/
  int* getTorre();/*Retorna la torre, el arreglo de 10 numeros a travez de un puntero */
  int getNTorre(int);/*Retorna el numero de la torre en la posicion indicada por el 
                      parametro*/
  void cambiarTorre(int, int );/*Recibe la posicion donde se quiere cambiar un 
                                numero en la torre y el numero por el que se 
                                va a cambiar*/
  ~Torre();/*Destructor de torre*/
};

#else
class Torre;
#endif