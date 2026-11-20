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
    // EL NUMERO DE SALA SE SOLICITA Y VERIFICA
    // EN EL MENU DE ALTA ANTES DE CARGAR LOS DEMAS DATOS.

    cout << "INGRESE EL NOMBRE DE LA SALA: ";
    cin.ignore();
    cin.getline(nombreSala, 30);

    // EL TIPO DE SALA SE SELECCIONA DESDE EL MENU
    // Y SE ASIGNA MEDIANTE setTipoSala().

    // VALIDAR QUE LA CAPACIDAD SEA MAYOR A CERO.
    cout << "INGRESE LA CAPACIDAD TOTAL DE LA SALA: ";
    cin >> capacidadTotal;

    estado = true;
}
// MOSTRAR
void Sala::Mostrar() {
    cout << "NUMERO DE SALA: " << numSala << endl;
    cout << "NOMBRE: " << nombreSala << endl;
    cout << "ID TIPO DE SALA: " << tipoSala << endl;
    cout << "CAPACIDAD TOTAL: " << capacidadTotal << endl;
}
