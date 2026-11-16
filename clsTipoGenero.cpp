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
    // EL ID SE SOLICITA Y VERIFICA EN EL MENU DE ALTA
    // ANTES DE CARGAR EL RESTO DE LOS DATOS.

    cout << "INGRESE EL NOMBRE DEL GENERO: ";
    cin.ignore();
    cin.getline(nombreGenero, 50);

    // VALIDAR QUE EL NOMBRE NO ESTE VACIO.
    // VALIDAR QUE NO EXISTA OTRO GENERO ACTIVO CON EL MISMO NOMBRE.

    estado = true;
}

// MOSTRAR

void TipoGenero::Mostrar() {
    cout << "ID GENERO: " << tipoGenero << endl;
    cout << "NOMBRE: " << nombreGenero << endl;
}

