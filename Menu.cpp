#include "Menu.h"
#include <unistd.h>


Menu::Menu() {
  moneda = 100000;
  mod[0] = "\033[0m";
  mod[1] =  "\033[0m";
  mod[2] = "\033[34m";
  mod[3] = "\033[92m";
  mod[4] = " ";
}

void Menu::crearJuego(){
  Juego *juego = new Juego();
  menuJuego(juego);
}


void Menu::menuJuego(Juego *juego) {
  int opc;
  cout << "\n\t\t ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
  cout << "\t\t ※※※※※ " << LIGHTYELLOW << " 𝕋 𝕠 𝕨 𝕖 𝕣 𝔹 𝕝 𝕒 𝕤 𝕥 𝕖 𝕣" << RESET <<" ※※※※※" << endl;
  cout<< "\t\t ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n" << endl;

  do {
    try {
      opc =
          stoi(leer("1-Iniciar Juego\n2-Tienda Tematicas\n3-Instrucciones\n4-Creditos\n\nSeleccione: "));
      if (opc != 1 and opc != 2 and opc != 3 and opc != 4) {
        throw "Ingrese una opcion valida\n";
      }
    } catch (const char *error) {
      cout << RED << error << RESET;
    } catch (invalid_argument &error) {
      cout << RED << "Ingrese solo números, error: " << error.what() << RESET
           << endl;
    }
  } while (opc != 1 and opc != 2 and opc != 3 and opc != 4);
  if (opc == 1) {
    menuVs(juego);
  } else if (opc == 2) {
    menuTienda(juego);
    menuJuego(juego);
  } else if (opc == 3) {
    instrucciones();
    menuJuego(juego);
  } else if(opc == 4){
    cout << "\n\t\t\t ※※※※※※※※※※※※※※※※※※※※" << endl;
    cout << "\t\t\t ※※※※※ " << STYLE << "CREADORES" << RESET <<"※※※※※" << endl;
    cout<< "\t\t\t ※※※※※※※※※※※※※※※※※※※※\n" << endl;
    cout<< "\n\t ⁂ Samuel Arenas Valencia 2341928 \n\t ⁂ Juan Manuel Ampudia Jaramillo 2342174 \n\t ⁂ Nicolas Cordoba Osorio 2343576 \n\n"; 
    leer("digite cualquier tecla para volver al menu: ");
    menuJuego(juego);
  }
}

void Menu::menuVs(Juego *juego) {
  int modo;
  do {
    cout<< "\n\t\t" << STYLE << "⁌⁌⁌⁌MODOS DE JUEGO⁍⁍⁍⁍"<<RESET << "\n\n1-Jugador vs Maquina\n2-Modo de prueba/simulación\n3-Volver al Menú"<<endl;
    try {
      modo = stoi
          (leer("Digite: "));
      if (modo != 1 and modo != 2 and modo !=3) {
        throw "Ingrese una opcion valida\n";
      }
    } catch (const char *error) {
      cout << RED << error << RESET;
    } catch (invalid_argument &error) {
      cout << RED << "Ingrese solo números, error: " << error.what() << RESET
           << endl;
    }
  } while (modo != 1 and modo != 2 and modo != 3);
  if (modo == 1) {
    menuDif(juego);
    menuJuego(juego);
  } else if (modo == 2) {
    testMethod();
    menuJuego(juego);
  } else if(modo == 3){
    menuJuego(juego);
  }
  
}

void Menu::menuDif(Juego *juego) {
  int dif;
  string ganador;
  do {
    cout <<"\n\t\t"<< STYLE <<"⁌⁌⁌⁌DIFICULTAD⁍⁍⁍⁍"<< RESET  <<LIGHTGREEN << "\n\n1- Modo Plebeyo\n"
          << ORANGE <<"2- Modo Guerrero\n" << RESET << "3- Volver al Menú" <<endl;
    try {
      dif = stoi(leer("Digite: "));

      if (dif != 1 and dif != 2 and dif != 3) {
        throw "Ingrese una opcion valida\n";
      }
    } catch (const char *error) {
      cout << RED << error << RESET;
    } catch (invalid_argument &error) {
      cout << RED << "Ingrese solo números, error: " << error.what() << RESET
           << endl;
    }
  } while (dif != 1 and dif != 2 and dif != 3);
  if (dif == 1) {
    cout<< "\n\t\t ※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
    cout << "\t\t ※※※※※ TOWER BLASTER ※※※※※" << endl;
    cout<< "\t\t ※※※※※※※※※※※※※※※※※※※※※※※※※\n" << endl;
    juego -> setColor(mod[0], mod[1], mod[2], mod[3]);
    juego -> setDiseno(mod[4]);
    juego->crearTorre();
    juego->turnos(1);
    ganador = juego->getGanador();
    if(ganador == "Persona"){
      moneda += 1000;
    }
    delete juego;
    crearJuego();
   
  }
  if (dif == 2) {
    cout<< "\n\t\t ※※※※※※※※※※※※※※※※※※※※※※※" << endl;
    cout << "\t\t ※※※※※ TOWER BLASTER ※※※※※" << endl;
    cout<< "\t\t ※※※※※※※※※※※※※※※※※※※※※※※\n" << endl;
    juego -> setColor(mod[0], mod[1], mod[2], mod[3]);
    juego -> setDiseno(mod[4]);
    juego->crearTorre();
    juego->turnos(2);
    ganador = juego->getGanador();
    if(ganador == "Persona"){
      moneda += 1000;
    }
    delete juego;
    crearJuego();
  }
  if(dif == 3){
    menuJuego(juego);
  }
}

void Menu::menuTienda(Juego *juego){
  int opc;
  cout<< "\n\t\t ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
  cout << "\t\t ※※※※※ «TIENDA TEMATICAS» ※※※※※" << endl;
  cout<< "\t\t ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;

  cout << "\nCOINS: " << LIGHTYELLOW << "௹  "<< moneda << RESET <<endl;

  cout << "\nTEMATICAS:\n" << "\n1- DEFAULT" << LIGHTGREEN << "\n2. ⨠ NEON (GRATIS) " << RESET << "\n3- ❄ INVIERNO (௹  800)" << ORANGE <<"\n4- ♪ MUSICAL (௹  1500)" << RESET << BLUE << "\n5- ★ ESPACIAL (௹  2300)" << RESET << "\n\n6- Volver al Menú"<<endl;
  
  do{
    try {
        opc = stoi(leer("\nCOMPRAR O SELECCIONAR: "));

        if (opc != 1 and opc != 2 and opc != 3 and opc != 4 and opc != 5 and opc !=6) {
          throw "Ingrese una opcion valida\n";
        }
      } catch (const char *error) {
        cout << RED << error << RESET;
      } catch (invalid_argument &error) {
        cout << RED << "Ingrese solo números, error: " << error.what() << RESET
             << endl;
      }
    } while (opc != 1 and opc != 2 and opc != 3 and opc != 4 and opc != 5 and opc != 6);

  if(opc == 1){
    mod[0] = "\033[0m";
    mod[1] =  "\033[0m";
    mod[2] = "\x1b[93m";
    mod[3] = "\033[92m";
    mod[4] = " ";
    cout << "\nMODO DEFAULT COLOCADO CON EXITO!\n" ;
  } else if( opc == 2){
    mod[0] = "\033[36m";
    mod[1] =  "\033[35m";
    mod[2] = "\033[37m";
    mod[3] = "\033[92m";
    mod[4] = "⪀";
    cout << "\nMODO NEON COLOCADO CON EXITO!\n" ;
  } else if(opc == 3){
    if(moneda >= 800){
      mod[0] = "\033[94m";
      mod[1] =  "\033[94m";
      mod[2] = "\033[31m";
      mod[3] = "\033[92m";
      mod[4] = "❄ ";
      moneda -= 800;
      cout << "\nMODO INVIERNO COLOCADO CON EXITO!\n" ;
    }else{
      cout << "\nNO TIENES SUFICIENTES COINS PARA COMPRAR ESTE DISEÑO D:" << endl;
      menuTienda(juego);
    }
  } else if(opc == 4){
    if(moneda >= 1500){
      mod[0] = "\x1b[38;5;214m";
      mod[1] =  "\033[38;5;93m";
      mod[2] = "\033[38;5;208m";
      mod[3] = "\033[34m";
      mod[4] = "♪";
      moneda -= 1500;
      cout << "\nMODO MUSICA COLOCADO CON EXITO!\n" ;
    }else{
      cout << "\nNO TIENES SUFICIENTES COINS PARA COMPRAR ESTE DISEÑO D:" << endl;
      menuTienda(juego);
    }
  } else if (opc == 5){
    if(moneda >= 2300){
      mod[0] = "\x1b[34m";
      mod[1] =  "\x1b[37m";
      mod[2] = "\x1b[35m";
      mod[3] = "\x1b[36m";
      mod[4] = "★";
      moneda -= 2300;
      cout << "\nMODO ESPACIAL COLOCADO CON EXITO!\n" ;
    }else{
      cout << "\nNO TIENES SUFICIENTES COINS PARA COMPRAR ESTE DISEÑO D:" << endl;
      menuTienda(juego);
    }
  } else if(opc == 6){
    return;
  }
  
}


void Menu::instrucciones() {

  cout << CYAN <<"\n\t\t\t\t ※※※※※ INSTRUCCIONES ※※※※※ \n" << RESET << endl;
  
  cout <<"\t\t⁕Bienvenido al tutorial de tower blaster \n a continuación te enseñare como ganamos puntos los jugadores :D\n"
       << endl;
  cout << " \t\t\t\t\t\t /*Torre*/" << endl;
  cout << "\t\t\t\t\t\t\t|01|\n\t\t\t\t\t\t\t|03|\n\t\t\t\t\t\t\t|11|\n\t\t\t\t\t\t\t|16|\n\t\t\t\t\t\t\t|20|\n\t\t\t\t\t\t\t|32|\n\t\t\t\t\t\t\t|07|\n\t\t\t\t\t\t\t|23|\n\t\t\t\t\t\t\t|09|\n\t\t\t\t\t\t\t|50|" << endl;
  cout << "\n\nIniciaras con una torre llena de números aleatorios del 1 al 50, \nse te dara un numero generado que no este en ninguna torre tienes 2 opciones conservarlo o generar otro, \nsi decides conservar el numero debes insertarlo en una posición de tu torre, \npara ganar puntos el número que ingreses debe ser consecutivo al número que le sigue \no al numero que le precede en la torre lo cual sumara a tu puntaje la cadena que formes:"<<CYAN << "\n\nSupongamos que el numero generado para ti es 2 y cambias el 3 en tu torre."<< RESET <<endl;
  cout << " \n\t\t\t\t\t\t /*Torre*/" << endl;
  cout <<LIGHTGREEN<<"\t\t\t\t\t\t\t|01|\n\t\t\t\t\t\t\t|02|"<<RESET<<"\n\t\t\t\t\t\t\t|11|\n\t\t\t\t\t\t\t|16|\n\t\t\t\t\t\t\t|20|\n\t\t\t\t\t\t\t|32|\n\t\t\t\t\t\t\t|07|\n\t\t\t\t\t\t\t|23|\n\t\t\t\t\t\t\t|"
          "09|\n\t\t\t\t\t\t\t|50|\nPUNTAJE GENERADO = 3"
       << endl;
  cout << "Ahora tienes el 1 y el 2 formados consecutivamente, por lo que a tu puntaje final se le añadira 1+2"
       << endl;
  cout<<"\n";
  leer("Presiona una tecla para continuar: ");

  cout << "\nCada partida, tanto tú como la maquina tienen 50 turnos cada uno, \ntu objetivo será conseguir la mayor cantidad de puntos posibles, tal y como explicamos anteriormente, \no construir la torre de manera ascendete antes que tu contricante\nPor ejemplo de la siguiente manera: "<<endl;
  cout << " \n\t\t\t\t\t\t /*Torre*/" << endl;
  cout << "\t\t\t\t\t\t\t|01|\n\t\t\t\t\t\t\t|03|\n\t\t\t\t\t\t\t|11|\n\t\t\t\t\t\t\t|16|\n\t\t\t\t\t\t\t|20|\n\t\t\t\t\t\t\t|32|\n\t\t\t\t\t\t\t|37|\n\t\t\t\t\t\t\t|40|\n\t\t\t\t\t\t\t|43|\n\t\t\t\t\t\t\t|47|" << endl;
  cout<< CYAN << "\nGana entonces aquel quien complete la torre primero o logre la mayor cantidad de puntos en los 50 turnos.\n" << RESET<<endl;

   leer("Presiona una tecla para continuar: ");

  cout << "\nEn el juego hay dos comodines, uno malo y otro bueno, el cual te permitira ganar o perder más rapido." << RED << "\n\nComodin Malo: " << RESET << "Si alguna torre se llegara a generar con el número ‖5‖ o si el número generado aleatoriamente es ‖5‖ la torre que posea el numero perdera automaticamente. " << CYAN << "\n\nComodin Bueno: " << RESET << "Si alguna torre llega armar el puntaje consecutivo de  2 + 3, es decir armar un puntaje de ‖5‖, ganará automaticamente la partida."<< endl;

  cout<< LIGHTGREEN <<"\n\t\t\tYA ESTAS PREPARADO PARA JUGAR TOWER BLASTER, DISFRUTALO!!!!!\n" << RESET << endl;

  leer("Presiona una tecla para volver al menú: ");

}
void Menu::testMethod() {
  int ganadorM = 0, ganadorP = 0;
  int empate = 0;
  cout<< "\n\t\t ※※※※※※※※※※※※※※※※※※※※※※※" << endl;
  cout << "\t\t ※※※※※ TOWER BLASTER ※※※※※" << endl;
  cout<< "\t\t ※※※※※※※※※※※※※※※※※※※※※※※\n" << endl;
  for (int i = 0; i < 1; i++) {
    Juego *juego = new Juego();
    juego -> setColor(mod[0], mod[1], mod[2], mod[3]);
    juego -> setDiseno(mod[4]);
    juego->crearTorre();
    juego->turnosPrueba();
    if (juego->getGanador() == "Maquina") {
      ganadorM++;
    } else if (juego->getGanador() == "Persona") {
      ganadorP++;
    } else {
      empate++;
    }
    delete juego;
    usleep(500000);
  }
  
  cout<< LIGHTGREEN <<"\n\tESTADISTICA FINAL" << RESET << endl;
  cout << "\nMaquina ganadas: " << ganadorM << endl;
  cout << "Jugador ganadas: " << ganadorP << endl;

  cout << "Empates: " << empate << endl;
}
Menu::~Menu() {}
