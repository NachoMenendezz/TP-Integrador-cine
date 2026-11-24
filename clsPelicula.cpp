#include <iostream>
#include <cstring>
#include "clsPelicula.h"

using namespace std;

Pelicula::Pelicula() {
    idPelicula = 0;
    tipoGenero = 0;
    clasificacionPelicula = 0;
    nombrePelicula[0] = '\0';
    apellidoNombreDirector[0] = '\0';
    fechaEstreno = Fecha();
    estado = false;
}

// SETTERS

void Pelicula::setIdPelicula(int id) {
    idPelicula = id;
}

void Pelicula::setTipoGenero(int genero) {
    tipoGenero = genero;
}

void Pelicula::setClasificacionPelicula(int clasificacion) {
    clasificacionPelicula = clasificacion;
}

void Pelicula::setNombrePelicula(const char *nombre) {
    strcpy(nombrePelicula, nombre);
}

void Pelicula::setApellidoNombreDirector(const char *director) {
    strcpy(apellidoNombreDirector, director);
}

void Pelicula::setEstado(bool est) {
    estado = est;
}

void Pelicula::setFechaEstreno(Fecha fecha) {
    fechaEstreno = fecha;
}

// GETTERS

int Pelicula::getIdPelicula() {
    return idPelicula;
}

int Pelicula::getTipoGenero() {
    return tipoGenero;
}

int Pelicula::getClasificacionPelicula() {
    return clasificacionPelicula;
}

const char *Pelicula::getNombrePelicula() {
    return nombrePelicula;
}

const char *Pelicula::getApellidoNombreDirector() {
    return apellidoNombreDirector;
}

Fecha Pelicula::getFechaEstreno() {
    return fechaEstreno;
}

bool Pelicula::getEstado() {
    return estado;
}

// CARGAR

void Pelicula::Cargar() {
    // EL ID SE GENERA AUTOMATICAMENTE EN EL ALTA
    // Y SE ASIGNA ANTES DE CARGAR EL RESTO DE LOS DATOS.

    cout << "INGRESE EL NOMBRE DE LA PELICULA: ";
    cin.ignore();
    cin.getline(nombrePelicula, 50);
    // VALIDAR QUE EL NOMBRE NO ESTE VACIO.
    while (nombrePelicula[0] == '\0') {
    cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
    cin.getline(nombrePelicula, 50);
    }
    cout << "INGRESE EL NOMBRE Y APELLIDO DEL DIRECTOR: ";
    cin.getline(apellidoNombreDirector, 50);
    // VALIDAR QUE EL NOMBRE DEL DIRECTOR NO ESTE VACIO.
    while (apellidoNombreDirector[0] == '\0') {
    cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
    cin.getline(apellidoNombreDirector, 50);
    }
    // EL GENERO SE SELECCIONA DESDE EL MENU
    // Y SE ASIGNA MEDIANTE setTipoGenero().

    // VALIDAR QUE LA CLASIFICACION SEA 1, 2 O 3.
    cout << "INGRESE LA CLASIFICACION (1: ATP, 2: +14, 3: +18): ";
    cin >> clasificacionPelicula;
    while (clasificacionPelicula<1||clasificacionPelicula>3){
        cout<<"CLASIFICACION NO VALIDA. INGRESE UN NUMERO DEL 1 AL 3: ";
        cin>>clasificacionPelicula;
    }
    // CARGAR FECHA DE ESTRENO.
    fechaEstreno.Cargar();
    // VALIDAR QUE LA FECHA INGRESADA SEA CORRECTA.
    while (!fechaEstreno.esValida()) {
    cout << "FECHA INVALIDA. INGRESELA NUEVAMENTE." << endl;
    fechaEstreno.Cargar();
}


    estado = true;
}

// MOSTRAR

void Pelicula::Mostrar() {
    cout << "ID PELICULA: " << idPelicula << endl;
    cout << "NOMBRE: " << nombrePelicula << endl;
    cout << "DIRECTOR: " << apellidoNombreDirector << endl;
    cout << "ID GENERO: " << tipoGenero << endl;
    cout << "CLASIFICACION: ";
    switch (clasificacionPelicula){
    case 1:cout<<"ATP";
    break;
    case 2:cout<<"+14";
    break;
    case 3:cout<<"+18";
    break;
    default:
    cout << "NO VALIDA";
    break;
    }
    cout <<endl;
    cout << "FECHA DE ESTRENO: "
         << fechaEstreno.getDia() << "/"
         << fechaEstreno.getMes() << "/"
         << fechaEstreno.getAnio() << endl;
}
