 #ifndef JUGADOR_H
#define JUGADOR_H
#include "Torre.h"
#include "Leer.h"
#include "Color.h"

class Jugador{
  protected:
  Torre torre;
  int puntaje;
  int puntajeJugada;
  int jugada[10];
  int posicion;
  int nTorre;
  bool nTorreCambiada;

  public:
  Jugador();/*Constructor de Jugador, inicializa puntaje, puntajeJugada, jugada, posicion, 
              nTorre, nTorreCambiada.*/
  virtual void crearTorre(int *);/*Recibe el arreglo de los numeros disponibles y llama al
                                  constructor de torre con el arreglo de enteros para
                                  Inicializar el atributo de torre*/
  virtual int* getTorre();/*Retorna la torre, el arreglo de 10 numeros a travez de un puntero */
  virtual void cambiarTorreAleatorio(int, int *);/*Recibe un numero y el arreglo de los
                                                  numeros disponibles, aleatoriamente cambia en
                                                  una de las posiciones de la torre el numero y
                                                  habilita el numero cambiado en el arreglo de
                                                  numeros disponibles*/

  virtual int generarNumero(int *);/*Recibe el arreglo de los numeros disponibles y genera un numero
                                    aleatorio de los numeros disponibles, en caso de que se halla
                                    hecho un cambio de torre el turno anterior, devuelve el numero
                                    de la posicion donde se cambio*/
  virtual int turno(int,int*) = 0;
  virtual void calcularPuntaje(int);/*Recibe la posicion donde se hizo un cambio en la torre, luego
                                    comprueba que el numero donde se hizo el cambio es consecutivo
                                    con el numero siguiente o consecutivo con el numero anterior,
                                    si lo es recorre desde la posicion el arreglo hacia arriba y hacia
                                    abajo para seguir buscando los numeros consecutivos. Cada numero
                                    consecutivo se suma a puntajeJugada, y tambien se coloca un 1 a la
                                    arreglo juagada en la posicion donde hay un numero consecutivo. Al
                                    final suma puntajeJugada a puntaje*/    
  virtual int getPuntaje();/*Retorna el puntaje total*/
  virtual int getPuntajeJugada();/*retorna el puntaje de una jugada*/
  virtual int* getJugada();/*Retorna el arreglo de jugada*/
  virtual void cocinar(int);/*Recibe el numero q se quiere cambiar, recorre el arreglo por arriba 
                             hasta la mitad y pone el numero si es mas chico, y luego lo hace por abajo
                             hasta la mitad y pone los numeros mas grandes, haciendo una especie de 
                             sandwich, al final retorna la posicion donde se debe cambiar el numero*/
  virtual void setNTorreCambiada(bool);/*Recibe un booleano y lo coloca en el atributo nTorreCambiada*/
  virtual bool getNtorreCambiada();/*Retorna el valor de nTorreCambiada*/

  virtual void setNTorre(int);/*Recibe un entero y lo coloca en el atributo nTorre*/
  virtual int getNtorre();/*Retorna el valor de nTorre*/
  
  ~Jugador();/*Destructor de Jugador*/
};
#else
class Jugador;
#endif