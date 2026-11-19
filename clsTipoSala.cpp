#include <iostream>#include <cstring>#include "clsTipoSala.h"using namespace std;// CONSTRUCTORTipoSala::TipoSala() {    tipoSala = 0;    descSala[0] = '\0';    precio = 0.00;    estado = false;}// SETTERSvoid TipoSala::setTipoSala(int tipo) {    tipoSala = tipo;}void TipoSala::setDescSala(const char *desc) {    strcpy(descSala, desc);}void TipoSala::setPrecio(float p) {    precio = p;}void TipoSala::setEstado(bool est) {    estado = est;}// GETTERSint TipoSala::getTipoSala() {    return tipoSala;}const char *TipoSala::getDescSala() {    return descSala;}float TipoSala::getPrecio() {    return precio;}bool TipoSala::getEstado() {    return estado;}// CARGARvoid TipoSala::Cargar() {
    // EL TIPO DE SALA SE SOLICITA Y VERIFICA EN EL MENU DE ALTA
    // ANTES DE CARGAR EL RESTO DE LOS DATOS.
    cout << "INGRESE LA DESCRIPCION: ";
    cin.ignore();
    cin.getline(descSala, 30);

    // VALIDAR QUE LA DESCRIPCION NO ESTE VACIA.
    // VALIDAR QUE NO EXISTA OTRO TIPO DE SALA ACTIVO CON LA MISMA DESCRIPCION.

    cout << "INGRESE EL PRECIO BASE DE LA ENTRADA: $";
    cin >> precio;

    // VALIDAR QUE EL PRECIO NO SEA NEGATIVO.

    estado = true;
}// MOSTRARvoid TipoSala::Mostrar() {    if (estado) {        cout << "ID TIPO SALA : " << tipoSala << endl;        cout << "DESCRIPCION  : " << descSala << endl;        cout << "PRECIO BASE  : $" << precio << endl;    }}