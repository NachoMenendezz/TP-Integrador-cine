#include <iostream>#include <cstring>#include "menus.h"#include "clsPelicula.h"#include "ArchivoPeliculas.h"#include "clsSala.h"#include "ArchivoSala.h"#include "clsFuncion.h"#include "ArchivoFuncion.h"#include "clsClientes.h"#include "ArchivoCliente.h"#include "clsTipoGenero.h"#include "ArchivoTipoGenero.h"#include "clsTipoSala.h"#include "ArchivoTipoSala.h"#include "clsVentaEntrada.h"#include "ArchivoVentaEntrada.h"using namespace std;void menuPrincipal() {    while (true) {        int opc;        system("cls");        cout << "========================================" << endl;        cout << "        CINEARDOPOLIS - SISTEMA         " << endl;        cout << "========================================" << endl;        cout << " 1. EMPLEADO" << endl;        cout << " 2. CLIENTE" << endl;        cout << " 0. SALIR" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                menuEmpleado();                break;            case 2:                menuCliente();                break;            case 0:                cout << "Gracias por utilizar Cineardopolis." << endl;                return;            default:                cout << "OPCION NO VALIDA." << endl;                system("pause");                break;        }    }}
void menuEmpleado()
{
   while (true) {
        int opc;
        system("cls");
        cout << "========================================" << endl;
        cout << "        MENU EMPLEADO         " << endl;
        cout << "========================================" << endl;
        cout << " 1. Gestión de datos (ABM)" << endl;
        cout << " 2. Listados" << endl;
        cout << " 3. Consultas" << endl;
        cout << "4. Informes " << endl;
        cout << " 0. Volver" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        system("cls");

        switch (opc) {
            case 1:
                menuGestionDatos();
                break;
            case 2:
                menuListados();
                break;
            case 3:
                menuConsultas();
                break;
            case 4:
                menuInformes();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                system("pause");
                break;
        }
    }
}

void menuGestionDatos(){
{
   while (true) {
        int opc;
        system("cls");
        cout << "========================================" << endl;
        cout << "        GESTION DE DATOS        " << endl;
        cout << "========================================" << endl;
        cout << " 1. Peliculas" << endl;
        cout << " 2. Generos" << endl;
        cout << " 3. Salas" << endl;
        cout << "4. Tipos de salas" << endl;
        cout << "5. Funciones" << endl;
        cout << " 0. Volver" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        system("cls");

        switch (opc) {
            case 1:
                menuPeliculas();
                break;
            case 2:
                menuGeneros();
                break;
            case 3:
                menuSalas();
                break;
            case 4:
                menuTipoSalas();
                break;
            case 5:
                menuFunciones();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                system("pause");
                break;
        }
    }
}

}










































//SUBMENÚ PELÍCULASvoid menuPeliculas() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "         GESTION DE PELICULAS           " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR PELICULA" << endl;        cout << " 2 - BAJA PELICULA" << endl;        cout << " 3 - MODIFICAR PELICULA" << endl;        cout << " 4 - LISTAR PELICULAS" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarPelicula();                break;            case 2:                bajaPelicula();                break;            case 3:                modificarPelicula();                break;            case 4:                listarPeliculas();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void listarPeliculas() {    ArchivoPeliculas arc;    arc.listarRegistros();}void agregarPelicula() {    int id;    cout << "INGRESE EL ID DE LA PELICULA: ";    cin >> id;    if (id <= 0) {        cout << "EL ID INGRESADO NO ES VALIDO." << endl;        return;    }    ArchivoPeliculas arc;    int pos = arc.buscarRegistro(id);    if (pos >= 0) {        cout << "EL ID INGRESADO YA EXISTE EN EL ARCHIVO." << endl;        return;    }    Pelicula obj;    obj.setIdPelicula(id);    obj.Cargar();    if (arc.grabarRegistro(obj)) {        cout << "PELICULA GRABADA CON EXITO." << endl;    } else {        cout << "ERROR AL GRABAR LA PELICULA." << endl;    }}void bajaPelicula() {    int id;    cout << "INGRESE EL ID DE LA PELICULA A DAR DE BAJA: ";    cin >> id;    ArchivoPeliculas arc;    int pos = arc.buscarRegistro(id);    if (pos < 0) {        cout << "NO EXISTE LA PELICULA EN EL ARCHIVO." << endl;        return;    }    Pelicula obj = arc.leerRegistro(pos);    obj.setEstado(false);    if (arc.modificarRegistro(obj, pos)) {        cout << "PELICULA DADA DE BAJA CORRECTAMENTE." << endl;    } else {        cout << "ERROR AL MODIFICAR EL ARCHIVO." << endl;    }}void modificarPelicula() {    int id;    cout << "INGRESE EL ID DE LA PELICULA A MODIFICAR: ";    cin >> id;    ArchivoPeliculas arc;    int pos = arc.buscarRegistro(id);    if (pos < 0) {        cout << "NO EXISTE LA PELICULA EN EL ARCHIVO." << endl;        return;    }    Pelicula obj = arc.leerRegistro(pos);    char nuevoNombre[50];    cout << "INGRESE EL NUEVO NOMBRE DE LA PELICULA: ";    cin.ignore();    cin.getline(nuevoNombre, 50);    obj.setNombrePelicula(nuevoNombre);    if (arc.modificarRegistro(obj, pos)) {        cout << "PELICULA MODIFICADA CON EXITO." << endl;    } else {        cout << "ERROR AL MODIFICAR LA PELICULA." << endl;    }}//SUBMENÚ SALASvoid menuSalas() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "           GESTION DE SALAS             " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR SALA" << endl;        cout << " 2 - BAJA SALA" << endl;        cout << " 3 - MODIFICAR SALA" << endl;        cout << " 4 - LISTAR SALAS" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarSala();                break;            case 2:                bajaSala();                break;            case 3:                modificarSala();                break;            case 4:                listarSalas();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void agregarSala() {    int num;    cout << "INGRESE EL NUMERO DE SALA: ";    cin >> num;    if (num <= 0) {        cout << "NUMERO DE SALA INVALIDO." << endl;        return;    }    ArchivoSala arc;    if (arc.buscarRegistro(num) >= 0) {        cout << "LA SALA YA EXISTE." << endl;        return;    }    Sala obj;    obj.setNumSala(num);    obj.Cargar();    if (arc.grabarRegistro(obj)) {        cout << "SALA GRABADA CON EXITO." << endl;    } else {        cout << "ERROR AL GRABAR SALA." << endl;    }}void bajaSala() {    int num;    cout << "INGRESE EL NUMERO DE SALA A DAR DE BAJA: ";    cin >> num;    ArchivoSala arc;    int pos = arc.buscarRegistro(num);    if (pos < 0) {        cout << "SALA NO ENCONTRADA." << endl;        return;    }    Sala obj = arc.leerRegistro(pos);    obj.setEstado(false);    if (arc.modificarRegistro(obj, pos)) {        cout << "SALA DADA DE BAJA CON EXITO." << endl;    } else {        cout << "ERROR AL MODIFICAR SALA." << endl;    }}void modificarSala() {    int num;    cout << "INGRESE EL NUMERO DE SALA A MODIFICAR: ";    cin >> num;    ArchivoSala arc;    int pos = arc.buscarRegistro(num);    if (pos < 0) {        cout << "SALA NO ENCONTRADA." << endl;        return;    }    Sala obj = arc.leerRegistro(pos);    int nuevaCapacidad;    cout << "INGRESE LA NUEVA CAPACIDAD: ";    cin >> nuevaCapacidad;    obj.setCapacidadTotal(nuevaCapacidad);    if (arc.modificarRegistro(obj, pos)) {        cout << "SALA MODIFICADA CON EXITO." << endl;    } else {        cout << "ERROR AL MODIFICAR SALA." << endl;    }}void listarSalas() {    ArchivoSala arc;    arc.listarRegistros();}//SUBMENÚ FUNCIONESvoid menuFunciones() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "         GESTION DE FUNCIONES           " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR FUNCION" << endl;        cout << " 2 - BAJA FUNCION" << endl;        cout << " 3 - MODIFICAR FUNCION" << endl;        cout << " 4 - LISTAR FUNCIONES" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarFuncion();                break;            case 2:                bajaFuncion();                break;            case 3:                modificarFuncion();                break;            case 4:                listarFunciones();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void agregarFuncion() {    int id;    cout << "INGRESE ID DE FUNCION: ";    cin >> id;    ArchivoFuncion arc;    if (arc.buscarRegistro(id) >= 0) {        cout << "EL ID DE FUNCION YA EXISTE." << endl;        return;    }    Funcion obj;    obj.setIdFuncion(id);    obj.Cargar();    if (arc.grabarRegistro(obj)) {        cout << "FUNCION GRABADA CON EXITO." << endl;    } else {        cout << "ERROR AL GRABAR FUNCION." << endl;    }}void bajaFuncion() {    int id;    cout << "INGRESE ID DE FUNCION A DAR DE BAJA: ";    cin >> id;    ArchivoFuncion arc;    int pos = arc.buscarRegistro(id);    if (pos < 0) {        cout << "FUNCION NO ENCONTRADA." << endl;        return;    }    Funcion obj = arc.leerRegistro(pos);    obj.setEstado(false);    if (arc.modificarRegistro(obj, pos)) {        cout << "FUNCION DADA DE BAJA CON EXITO." << endl;    } else {        cout << "ERROR AL MODIFICAR FUNCION." << endl;    }}void modificarFuncion() {    int id;    cout << "INGRESE ID DE FUNCION A MODIFICAR: ";    cin >> id;    ArchivoFuncion arc;    int pos = arc.buscarRegistro(id);    if (pos < 0) {        cout << "FUNCION NO ENCONTRADA." << endl;        return;    }    Funcion obj = arc.leerRegistro(pos);    int hora;    cout << "INGRESE NUEVA HORA DE FUNCION: ";    cin >> hora;    obj.setHoraFuncion(hora);    if (arc.modificarRegistro(obj, pos)) {        cout << "FUNCION MODIFICADA CON EXITO." << endl;    } else {        cout << "ERROR AL MODIFICAR FUNCION." << endl;    }}void listarFunciones() {    ArchivoFuncion arc;    arc.listarRegistros();}