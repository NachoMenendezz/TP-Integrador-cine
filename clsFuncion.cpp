
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
    // El alta asigna el ID, la película y la sala antes de llamar a Cargar().
    cout << "INGRESE LA FECHA DE LA FUNCION:" << endl;
    fechaFuncion.Cargar();

    while (!fechaFuncion.esValida()) {
        cout << "FECHA INVALIDA. INGRESELA NUEVAMENTE." << endl;
        fechaFuncion.Cargar();
    }

    cout << "INGRESE EL HORARIO DE LA FUNCION (12, 14, 16, 18, 20 O 22): ";
    cin >> horaFuncion;

    while (horaFuncion < 12 || horaFuncion > 22 || horaFuncion % 2 != 0) {
        cout << "HORARIO INVALIDO. INGRESE 12, 14, 16, 18, 20 O 22: ";
        cin >> horaFuncion;
    }

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
