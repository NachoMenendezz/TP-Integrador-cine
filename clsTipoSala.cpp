#include <iostream>#include <cstring>#include "clsTipoSala.h"using namespace std;// CONSTRUCTORTipoSala::TipoSala() {    tipoSala = 0;    descSala[0] = '\0';    precio = 0;    estado = false;}// SETTERSvoid TipoSala::setTipoSala(int tipo) {    tipoSala = tipo;}void TipoSala::setDescSala(const char *desc) {    strcpy(descSala, desc);}void TipoSala::setPrecio(int p) {    precio = p;}void TipoSala::setEstado(bool est) {    estado = est;}// GETTERSint TipoSala::getTipoSala() {    return tipoSala;}const char *TipoSala::getDescSala() {    return descSala;}int TipoSala::getPrecio() {    return precio;}bool TipoSala::getEstado() {    return estado;}// CARGARvoid TipoSala::Cargar() {
    // El alta genera y asigna el código antes de llamar a Cargar().
    cout << "INGRESE LA DESCRIPCION: ";
    cin.ignore();
    cin.getline(descSala, 30);

    while (descSala[0] == '\0') {
        cout << "LA DESCRIPCION NO PUEDE ESTAR VACIA. INGRESELA NUEVAMENTE: ";
        cin.getline(descSala, 30);
    }

    cout << "INGRESE EL PRECIO BASE DE LA ENTRADA: $";
    cin >> precio;

    while (precio <= 0) {
        cout << "INGRESE UN PRECIO MAYOR A CERO: $";
        cin >> precio;
    }

    estado = true;
}// MOSTRARvoid TipoSala::Mostrar() {    cout << "ID TIPO SALA : " << tipoSala << endl;    cout << "DESCRIPCION  : " << descSala << endl;    cout << "PRECIO BASE  : $" << precio << endl;}