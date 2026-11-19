#include <iostream>#include <cstring>#include "clsClientes.h"using namespace std;// CONSTRUCTORCliente::Cliente() {    dni = 0;    nombreApellido[0] = '\0';    telefono = 0;}// SETTERSvoid Cliente::setDni(int DNI) {    dni = DNI;}void Cliente::setNombreApellido(const char *nombape) {    strcpy(nombreApellido, nombape);}void Cliente::setTelefono(int tel) {    telefono = tel;}
// GETTERSint Cliente::getDni() {    return dni;}const char *Cliente::getNombreApellido() {    return nombreApellido;}int Cliente::getTelefono() {    return telefono;}// CARGARvoid Cliente::Cargar() {
    // EL DNI SE SOLICITA Y VERIFICA EN EL MENU DE ALTA
    // ANTES DE CARGAR EL RESTO DE LOS DATOS.
    // VALIDAR QUE NO EXISTA OTRO CLIENTE CON EL MISMO DNI.

    cout << "INGRESE EL NOMBRE Y APELLIDO: ";
    cin.ignore();
    cin.getline(nombreApellido, 50);

    // VALIDAR QUE EL NOMBRE Y APELLIDO NO ESTEN VACIOS.

    cout << "INGRESE EL NUMERO DE TELEFONO: ";
    cin >> telefono;

    // VALIDAR QUE EL TELEFONO SEA VALIDO.
}// MOSTRARvoid Cliente::Mostrar() {        cout << "DNI DEL CLIENTE : " << dni << endl;        cout << "NOMBRE Y APELLIDO  : " << nombreApellido << endl;        cout << "TELEFONO: " << telefono << endl;}