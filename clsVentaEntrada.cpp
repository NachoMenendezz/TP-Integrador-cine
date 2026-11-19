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

// CARGAR

void VentaEntrada::Cargar() {
    // EL ID DE LA VENTA SE SOLICITA Y VERIFICA
    // EN EL MENU ANTES DE CARGAR LOS DEMAS DATOS.

    // LA FUNCION Y EL CLIENTE SE SELECCIONAN DESDE EL MENU,
    // VERIFICANDO QUE LA FUNCION EXISTA Y ESTE ACTIVA
    // Y QUE EL DNI CORRESPONDA A UN CLIENTE REGISTRADO.
    // SUS IDENTIFICADORES SE ASIGNAN MEDIANTE LOS SETTERS.

    cout << "INGRESE LA FECHA DE COMPRA:" << endl;
    diaCompra.Cargar();

    // VALIDAR QUE LA FECHA SEA CORRECTA
    // Y QUE NO SEA UNA FECHA FUTURA.

    cout << "INGRESE LA CANTIDAD DE ENTRADAS A COMPRAR: ";
    cin >> cantEntradasVendidas;

    // VALIDAR QUE LA CANTIDAD SEA MAYOR A CERO.
    // VALIDAR QUE NO SUPERE LA CANTIDAD DE ENTRADAS DISPONIBLES
    // PARA LA FUNCION SELECCIONADA.

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
}
