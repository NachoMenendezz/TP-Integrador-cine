#include <iostream>
#include <cstring>
#include "clsSala.h"

using namespace std;

Sala::Sala() {
    numSala = 0;
    nombreSala[0] = '\0';
    tipoSala = 0;
    capacidadTotal = 0;
    estado = false;
}

// SETTERS
void Sala::setNumSala(int num) {
    numSala = num;
}
void Sala::setNombreSala(const char *nombre) {
    strcpy(nombreSala, nombre);
}
void Sala::setTipoSala(int tipo) {
    tipoSala = tipo;
}
void Sala::setCapacidadTotal(int capacidad) {
    capacidadTotal = capacidad;
}
void Sala::setEstado(bool est) {
    estado = est;
}

// GETTERS
int Sala::getNumSala() {
    return numSala;
}
const char *Sala::getNombreSala() {
    return nombreSala;
}
int Sala::getTipoSala() {
    return tipoSala;
}
int Sala::getCapacidadTotal() {
    return capacidadTotal;
}
bool Sala::getEstado() {
    return estado;
}

// CARGAR
void Sala::Cargar() {
    // El alta asigna el número generado y el tipo seleccionado antes de llamar a Cargar().
    cout << "INGRESE EL NOMBRE DE LA SALA: ";

    // Consume el Enter que dejó la selección del tipo de sala.
    cin.ignore();
    cin.getline(nombreSala, 30);

    while (nombreSala[0] == '\0') {
        cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
        cin.getline(nombreSala, 30);
    }

    cout << "INGRESE LA CAPACIDAD TOTAL DE LA SALA: ";
    cin >> capacidadTotal;

    while (capacidadTotal <= 0) {
        cout << "INGRESE UNA CAPACIDAD MAYOR A CERO: ";
        cin >> capacidadTotal;
    }

    estado = true;
}
// MOSTRAR
void Sala::Mostrar() {
    cout << "NUMERO DE SALA: " << numSala << endl;
    cout << "NOMBRE: " << nombreSala << endl;
    cout << "ID TIPO DE SALA: " << tipoSala << endl;
    cout << "CAPACIDAD TOTAL: " << capacidadTotal << endl;
}
