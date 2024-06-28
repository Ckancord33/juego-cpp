#include "Juego.h"

using namespace std;

Juego::Juego() {
  for (int i = 0; i < 50; i++) {
    numeros[i] = 0;
  }
  ganador = "";
  sentenciaP = false;
  sentenciaM = false;

  colorTorreMaquina = "\033[0m";
  colorTorre = "\033[0m";
  colorPuntos = "\033[92m";
  colorSeleccion = "\033[34m";
  disenoTorre = " ";
}

void Juego::crearTorre() {
  maquina = Maquina();
  persona = Persona();
  maquina.crearTorre(numeros);
  persona.crearTorre(numeros);
}

void Juego::mostrarTorre() {
  int *torrePersona = persona.getTorre();
  int *jugada = persona.getJugada();
  int *torreMaquina = maquina.getTorre();

  cout << "/*TORRE 1*/\t\t  /*TORRE 2*/\n"
       << colorTorreMaquina << "/*MAQUINA*/\t" << RESET << colorTorre
       << "\t  /*JUGADOR*/\n"
       << RESET << endl;
  for (int i = 0; i < 10; i++) {
    if (torrePersona[i] < 10) {
      cout << colorTorreMaquina << "\t‖**‖\t\t" << RESET;
      if (jugada[i] == 1)
        cout << colorPuntos << "\t" << disenoTorre
             << "‖0" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else if (jugada[i] == 2)
        cout << colorSeleccion << "\t" << disenoTorre
             << "‖0" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else
        cout << colorTorre << "\t" << disenoTorre
             << "‖0" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
    } else {
      cout << colorTorreMaquina << "\t‖**‖\t\t" << RESET;
      if (jugada[i] == 1)
        cout << colorPuntos << "\t" << disenoTorre
             << "‖" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else if (jugada[i] == 2)
        cout << colorSeleccion << "\t" << disenoTorre
             << "‖" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else
        cout << colorTorre << "\t" << disenoTorre
             << "‖" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
    }
  }
  cout << colorSeleccion << "\nGANASTE: " << persona.getPuntajeJugada() << "pt"
       << colorPuntos << "\nSCORE TOTAL: " << persona.getPuntaje() << "pt"
       << "\n"
       << RESET << endl;

  cout << "\nNUMEROS DE LA MAQUINA:\n";
  for (int i = 0; i < 10; i++) {
    cout << torreMaquina[i] << "\t";
  }
  cout << "\n\n";
}

void Juego::mostrarTorrePrueba() {
  int *torrePersona = persona.getTorre();
  int *torreMaquina = maquina.getTorre();
  int *jugada = persona.getJugada();

  cout << "/*TORRE 1*/\t\t  /*TORRE 2*/\n"
       << colorTorreMaquina << "/*MAQUINA*/\t" << RESET << colorTorre
       << "\t  /*JUGADOR*/\n"
       << RESET << endl;
  for (int i = 0; i < 10; i++) {
    if (torrePersona[i] < 10) {
      cout << colorTorreMaquina << "\t‖**‖\t\t" << RESET;
      if (jugada[i] == 1)
        cout << colorPuntos << "\t" << disenoTorre
             << "‖0" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else if (jugada[i] == 2)
        cout << colorSeleccion << "\t" << disenoTorre
             << "‖0" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else
        cout << colorTorre << "\t" << disenoTorre
             << "‖0" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
    } else {
      cout << colorTorreMaquina << "\t‖**‖\t\t" << RESET;
      if (jugada[i] == 1)
        cout << colorPuntos << "\t" << disenoTorre
             << "‖" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else if (jugada[i] == 2)
        cout << colorSeleccion << "\t" << disenoTorre
             << "‖" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
      else
        cout << colorTorre << "\t" << disenoTorre
             << "‖" + to_string(torrePersona[i]) + "‖" << disenoTorre << "\n"
             << RESET;
    }
  }
  cout << "\nSCORE TOTAL MAQUINA : " << maquina.getPuntaje()
       << "\nSCORE TURNO: " << persona.getPuntajeJugada()
       << "\nSCORE TOTAL: " << persona.getPuntaje() << endl;
  cout << "\nNUMEROS DE LA MAQUINA:\n";
  for (int i = 0; i < 10; i++) {
    cout << torreMaquina[i] << "\t";
  }
  cout << "\n\n";
  cout << "\nNUMEROS OCUPADOS:\n";
  for (int i = 0; i < 50; i++) {
    cout << numeros[i] << "\t\t";
  }
  cout << "\n\n";
}
bool Juego::comprobarGanador(int contador, int win) {
  if (contador == 50) {
    if (persona.getPuntaje() > maquina.getPuntaje()) {
      ganador = "Persona";
      return true;
    }
    if (persona.getPuntaje() < maquina.getPuntaje()) {
      ganador = "Maquina";
      return true;
    } else {
      ganador = "Empate";
      return true;
    }
  }
  int *torrePersona = persona.getTorre();
  int *torreMaquina = maquina.getTorre();
  bool maquinaGana, personaGana;
  maquinaGana = true;
  for (int i = 0; i < 9; i++) {
    if (torreMaquina[i] > torreMaquina[i + 1]) {
      maquinaGana = false;
    }
  }
  personaGana = true;
  for (int i = 0; i < 9; i++) {
    if (torrePersona[i] > torrePersona[i + 1]) {
      personaGana = false;
    }
  }
  if (persona.getPuntajeJugada() == 5) {
    personaGana = true;
  }
  if (maquina.getPuntajeJugada() == 5) {
    maquinaGana = true;
  }

  for (int i = 0; i < 9; i++) {
    if (torreMaquina[i] == 5) {
      personaGana = true;
      sentenciaM = true;
    }
  }
  for (int i = 0; i < 9; i++) {
    if (torrePersona[i] == 5) {
      maquinaGana = true;
      sentenciaP = true;
    }
  }
  if (win == 51) {
    maquinaGana = true;
    sentenciaP = true;
  }
  if (win == 52) {
    personaGana = true;
    sentenciaM = true;
  }
  if (maquinaGana == true and personaGana == false) {
    ganador = "Maquina";
    return true;
  }
  if (maquinaGana == false and personaGana == true) {
    ganador = "Persona";
    return true;
  } else
    return false;
}

bool Juego::mostrarGanador(int contador) {

  if (ganador == "Persona") {
    if (sentenciaM == true) {
      cout << "¡¡¡GANASTE LA MAQUINA SACO 5!!!\n";
      results();
      return 1;
    }
    if (contador == 50) {
      cout << "¡¡¡GANASTE POR PUNTAJE!!!\n";
      results();
      return 1;
    }

    if (persona.getPuntajeJugada() == 5) {
      cout << "¡¡¡GANASTE POR EL COMODIN EN PUNTAJE!!!\n";
      results();
      return 1;
    } else {
      cout << "GANASTE POR ORGANIZAR LA TORRE!!!\n";
      results();
      return 1;
    }
    cout << "GANADOR: " << GREEN << "JUGADOR" << RESET << endl;
  }
  if (ganador == "Maquina") {
    if (sentenciaP == true) {
      cout << "¡¡¡PERDISTE SACASTE EL NUMERO 5!!!\n";
      results();
      return 1;
    }
    if (contador == 50) {
      cout << "PERDISTE POR PUNTAJE\n\n";
      results();
      return 1;
    }
    if (maquina.getPuntajeJugada() == 5) {
      cout << "¡¡¡PERDISTE, LA MAQUINA GANO POR EL COMODIN DE PUNTAJE!!!\n";
      results();
      return 1;
    } else {
      cout << "PERDISTE, LA MAQUINA ORGANIZO LA TORRE PRIMERO\n\n";
      results();
      return 1;
    }
    cout << "GANADOR: " << RED << "MAQUINA" << RESET << endl;
  }
  if (ganador == "Empate") {
    cout << "ES UN EMPATE, AMBOS TIENEN LA MISMA CANTIDAD DE PUNTOS\n"
         << "GANADOR: " << LIGHTGREEN << "EMPATE" << RESET << endl;
    results();
    return 1;
  }
  return 1;
}
void Juego::turnos(int dificultad) {
  int contador = 1;
  int numeroRechazado = 0;
  if (dificultad == 1) {
    do {
      cout << "Turno °" << contador << "\n" << endl;
      mostrarTorre();
      if (comprobarGanador(contador, 0)) {
        break;
      }
      persona.setNTorreCambiada(maquina.getNtorreCambiada());
      if(maquina.getNtorreCambiada()){
        persona.setNTorre(maquina.getNtorre());
      }
      numeroRechazado = persona.turno(numeroRechazado, numeros);
      if (numeroRechazado == 51) {
        if (comprobarGanador(contador, 51)) {
          break;
        }
      }
      cout<< "\n" ;
      mostrarTorre();
      if (comprobarGanador(contador, 0)) {
        break;
      }
      maquina.setNTorreCambiada(persona.getNtorreCambiada());
      if(persona.getNtorreCambiada()){
        maquina.setNTorre(persona.getNtorre());
      }
      numeroRechazado = maquina.turno(numeroRechazado, numeros);
      if (numeroRechazado == 52) {
        if (comprobarGanador(contador, 52)) {
          break;
        }
      }
      contador++;

    } while (contador <= 50);
    mostrarGanador(contador);
  }
  if (dificultad == 2) {
    do {
      cout << "Turno °" << contador << "\n" << endl;
      mostrarTorre();
      if (comprobarGanador(contador, 0)) {
        break;
      }
      persona.setNTorreCambiada(maquina.getNtorreCambiada());
      if(maquina.getNtorreCambiada()){
        persona.setNTorre(maquina.getNtorre());
      }
      numeroRechazado = persona.turno(numeroRechazado, numeros);
      cout<< "\n" ;
      mostrarTorre();
      if (numeroRechazado == 51) {
        comprobarGanador(contador, 51);
        break;
      }
      if (comprobarGanador(contador, 0)) {
        break;
      }
      maquina.setNTorreCambiada(persona.getNtorreCambiada());
      if(persona.getNtorreCambiada()){
        maquina.setNTorre(persona.getNtorre());
      }
      numeroRechazado = maquina.turnoDif(numeroRechazado, numeros);
      if (numeroRechazado == 52) {
        comprobarGanador(contador, 52);
        break;
      }
      contador++;

    } while (contador <= 50);
    mostrarGanador(contador);
  }
}
void Juego::turnosPrueba() {
  int contador = 0;
  int numeroRechazado = 0;
  do {
    cout << "\nTurno °" << contador + 1 << "\n" << endl;
    mostrarTorrePrueba();
    if (comprobarGanador(contador, 0)) {
      break;
    }
    persona.setNTorreCambiada(maquina.getNtorreCambiada());
    if(maquina.getNtorreCambiada()){
      persona.setNTorre(maquina.getNtorre());
    }
    numeroRechazado = persona.turnoAleatorio(numeroRechazado, numeros);
    cout<< "\n" ;
    mostrarTorrePrueba();
    if (numeroRechazado == 51) {
      comprobarGanador(contador, 51);
      break;
    }
    if (comprobarGanador(contador, 0)) {
      break;
    }
    maquina.setNTorreCambiada(persona.getNtorreCambiada());
    if(persona.getNtorreCambiada()){
      maquina.setNTorre(persona.getNtorre());
    }
    numeroRechazado = maquina.turno(numeroRechazado, numeros);
    if (numeroRechazado == 52) {
      comprobarGanador(contador, 52);
      break;
    }
    contador++;

  } while (contador <= 50);
  mostrarGanador(contador);
}
string Juego::getGanador() { return ganador; }

void Juego::results() {
  int *torreMaquina = maquina.getTorre();
  cout << LIGHTGREEN << "\n\t\tSCORE FINAL:\n"
       << RESET << "\nMaquina: " << maquina.getPuntaje()
       << "\nPersona: " << persona.getPuntaje() << endl;
  cout << "\nNUMEROS DE LA MAQUINA:\n";
  for (int i = 0; i < 10; i++) {
    cout << torreMaquina[i] << "\t";
  }
  cout << "\n";
}

void Juego::setColor(string color, string color2, string color3,
                     string color4) {
  colorTorre = color;
  colorTorreMaquina = color2;
  colorSeleccion = color3;
  colorPuntos = color4;
}
void Juego::setDiseno(string diseno) { disenoTorre = diseno; }

Juego::~Juego() {}
