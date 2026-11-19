
#include <iostream>
#include "clsFuncion.h"

using namespace std;

// CONSTRUCTOR
Funcion::Funcion() {
    idFuncion = 0;
    idPelicula = 0;
    numSala = 0;
    fechaFuncion = Fecha();
    horaFuncion = 0;
    estado = false;
}

// SETTERS

void Funcion::setIdFuncion(int id) {
    idFuncion = id;
}

void Funcion::setIdPelicula(int pelicula) {
    idPelicula = pelicula;
}

void Funcion::setNumSala(int sala) {
    numSala = sala;
}

void Funcion::setFechaFuncion(Fecha fecha) {
    fechaFuncion = fecha;
}

void Funcion::setHoraFuncion(int hora) {
    horaFuncion = hora;
}

void Funcion::setEstado(bool est) {
    estado = est;
}

// GETTERS

int Funcion::getIdFuncion() {
    return idFuncion;
}

int Funcion::getIdPelicula() {
    return idPelicula;
}

int Funcion::getNumSala() {
    return numSala;
}

Fecha Funcion::getFechaFuncion() {
    return fechaFuncion;
}

int Funcion::getHoraFuncion() {
    return horaFuncion;
}

bool Funcion::getEstado() {
    return estado;
}

// CARGAR

void Funcion::Cargar() {
    // EL ID DE LA FUNCION SE SOLICITA Y VERIFICA
    // EN EL MENU DE ALTA ANTES DE CARGAR LOS DEMAS DATOS.

    // LA PELICULA Y LA SALA SE SELECCIONAN DESDE EL MENU,
    // VERIFICANDO QUE EXISTAN Y ESTEN ACTIVAS.
    // SUS IDENTIFICADORES SE ASIGNAN MEDIANTE LOS SETTERS.

    cout << "INGRESE LA FECHA DE LA FUNCION:" << endl;
    fechaFuncion.Cargar();

    // VALIDAR QUE LA FECHA INGRESADA SEA CORRECTA
    // Y QUE NO SEA UNA FECHA ANTERIOR A LA ACTUAL.

    cout << "INGRESE EL HORARIO DE LA FUNCION (12, 14, 16, 18, 20 O 22): ";
    cin >> horaFuncion;

    // VALIDAR QUE EL HORARIO SEA UNO DE LOS PERMITIDOS.

    // VALIDAR QUE NO EXISTA OTRA FUNCION ACTIVA
    // EN LA MISMA SALA, FECHA Y HORARIO.

    estado = true;
}

// MOSTRAR

void Funcion::Mostrar() {
    cout << "ID FUNCION: " << idFuncion << endl;
    cout << "ID PELICULA: " << idPelicula << endl;
    cout << "NUMERO DE SALA: " << numSala << endl;

    cout << "FECHA DE LA FUNCION: ";
    fechaFuncion.Mostrar();
    cout << endl;

    cout << "HORARIO: " << horaFuncion << ":00" << endl;
}
