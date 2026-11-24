#include <iostream>
#include <cstring>
#include "clsTipoGenero.h"

using namespace std;

TipoGenero::TipoGenero() {
    tipoGenero = 0;
    nombreGenero[0] = '\0';
    estado = false;
}

// SETTERS

void TipoGenero::setTipoGenero(int id) {
    tipoGenero = id;
}

void TipoGenero::setNombreGenero(const char *nombre) {
    strcpy(nombreGenero, nombre);
}

void TipoGenero::setEstado(bool est) {
    estado = est;
}

// GETTERS

int TipoGenero::getTipoGenero() {
    return tipoGenero;
}

const char *TipoGenero::getNombreGenero() {
    return nombreGenero;
}

bool TipoGenero::getEstado() {
    return estado;
}

// CARGAR

void TipoGenero::Cargar() {
    // El ID se genera y se asigna en el alta antes de llamar a Cargar().
    cout << "INGRESE EL NOMBRE DEL GENERO: ";
    cin.ignore();
    cin.getline(nombreGenero, 50);

    while (nombreGenero[0] == '\0') {
        cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
        cin.getline(nombreGenero, 50);
    }

    estado = true;
}

// MOSTRAR

void TipoGenero::Mostrar() {
    cout << "ID GENERO: " << tipoGenero << endl;
    cout << "NOMBRE: " << nombreGenero << endl;
}

