#include <iostream>
#include "clsVentaEntrada.h"

using namespace std;

// CONSTRUCTOR
VentaEntrada::VentaEntrada() {
    idVenta = 0;
    idFuncion = 0;
    diaCompra = Fecha();
    dniComprador = 0;
    cantEntradasVendidas = 0;
    importeTotal = 0;
}

// SETTERS

void VentaEntrada::setIdVenta(int id) {
    idVenta = id;
}

void VentaEntrada::setIdFuncion(int funcion) {
    idFuncion = funcion;
}

void VentaEntrada::setDiaCompra(Fecha fecha) {
    diaCompra = fecha;
}

void VentaEntrada::setDniComprador(int dni) {
    dniComprador = dni;
}

void VentaEntrada::setCantEntradasVendidas(int cantidad) {
    cantEntradasVendidas = cantidad;
}

void VentaEntrada::setImporteTotal(int Importe){
importeTotal=Importe;
}

// GETTERS

int VentaEntrada::getIdVenta() {
    return idVenta;
}

int VentaEntrada::getIdFuncion() {
    return idFuncion;
}

Fecha VentaEntrada::getDiaCompra() {
    return diaCompra;
}

int VentaEntrada::getDniComprador() {
    return dniComprador;
}

int VentaEntrada::getCantEntradasVendidas() {
    return cantEntradasVendidas;
}

int VentaEntrada::getImporteTotal(){
    return importeTotal;
}



// MOSTRAR

void VentaEntrada::Mostrar() {
    cout << "ID VENTA: " << idVenta << endl;
    cout << "ID FUNCION: " << idFuncion << endl;

    cout << "FECHA DE COMPRA: ";
    diaCompra.Mostrar();
    cout << endl;

    cout << "DNI DEL COMPRADOR: " << dniComprador << endl;
    cout << "CANTIDAD DE ENTRADAS VENDIDAS: "
         << cantEntradasVendidas << endl;
    cout <<"IMPORTE TOTAL: $"<<importeTotal;
}
