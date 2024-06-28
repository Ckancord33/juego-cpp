#ifndef MENU_H
#define MENU_H
#include "Color.h"
#include "Juego.h"
#include "Leer.h"
#include "Maquina.h"
#include "Persona.h"

#include <iostream>
#include <string>
using namespace std;
class Menu {
private:
  int moneda;
  string mod[5];
public:
  Menu(); //constructor del objeto Menu, Inicializa
  void crearJuego();//Crea un objeto juego y ejecuta el menu con este como parametro
  void menuJuego(Juego *);//Menu inicial en el que tenemos las opciones para jugar,instrucciones,tienda,creditos.
  void menuVs(Juego *);//ejecuta un menu para elegir si se quiere correr el juego normal o el metodo de prueba
  void menuDif(Juego *);//ejecuta un menu para elegir la dificultad del juego y dependiendo de la dificultad se le pasa un parametro a turnos en juego 
  void menuTienda(Juego *);//Menu para comprar estilos de torre con el atributo moneda
  void instrucciones();//imprime una guia de las reglas y mecanicas del juego
  void testMethod();//realiza una simulacion del juego con turnos aleatorios y muestra cuantas partidas gana cada uno al final del ciclo
  ~Menu();
};
#else
class Menu;
#endif