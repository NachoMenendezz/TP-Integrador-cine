#include <iostream>
#include "clsSala.h"
#include "ArchivoTipoSala.h"

using namespace std;

Sala::Sala() {
    numSala = 0;
    tipoSala = 0;
    capacidadTotal = 0;
    estado = false;
}

// SETTERS
void Sala::setNumSala(int num) {
    numSala = num;
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

    cout << "INGRESE LA CAPACIDAD TOTAL DE LA SALA: ";
    cin >> capacidadTotal;

    while (capacidadTotal <= 0) {
        cout << "INGRESE UNA CAPACIDAD MAYOR A CERO: ";
        cin >> capacidadTotal;
    }

    estado = true;
}
// MOSTRAR
void Sala::Mostrar()
{
    cout << "NUMERO DE SALA: " << numSala << endl;

    ArchivoTipoSala arcTipos;
    int posTipo = arcTipos.buscarRegistro(tipoSala);

    if (posTipo >= 0)
    {
        TipoSala tipo = arcTipos.leerRegistro(posTipo);
        cout << "TIPO DE SALA: " << tipo.getDescSala() << endl;
    }
    else
    {
        cout << "ID TIPO DE SALA: " << tipoSala << endl;
    }

    cout << "CAPACIDAD TOTAL: " << capacidadTotal << endl;
}
