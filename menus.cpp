#include <iostream>#include <cstring>#include "menus.h"
#include "funcionesGlobales.h"#include "listados.h"
#include "consultas.h"
#include "informes.h"
#include "cliente.h"#include "clsPelicula.h"#include "ArchivoPeliculas.h"#include "clsSala.h"#include "ArchivoSala.h"#include "clsFuncion.h"#include "ArchivoFuncion.h"#include "clsClientes.h"#include "ArchivoCliente.h"#include "clsTipoGenero.h"#include "ArchivoTipoGenero.h"#include "clsTipoSala.h"#include "ArchivoTipoSala.h"#include "clsVentaEntrada.h"#include "ArchivoVentaEntrada.h"using namespace std;//MENÚ PRINCIPALvoid menuPrincipal() {    while (true) {        int opc;        system("cls");        cout << "========================================" << endl;        cout << "        CINEARDOPOLIS - SISTEMA         " << endl;        cout << "========================================" << endl;        cout << " 1. EMPLEADO" << endl;        cout << " 2. CLIENTE" << endl;        cout << " 0. SALIR" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                menuEmpleado();                break;            case 2:                menuCliente();                break;            case 0:                cout << "Gracias por utilizar Cineardopolis." << endl;                return;            default:                cout << "OPCION NO VALIDA." << endl;                system("pause");                break;        }    }}//MENÚ EMPLEADOvoid menuEmpleado() {    while (true) {        int opc;        system("cls");        cout << "========================================" << endl;        cout << "            MENU EMPLEADO               " << endl;        cout << "========================================" << endl;        cout << " 1. Gestion de datos (ABM)" << endl;        cout << " 2. Listados" << endl;        cout << " 3. Consultas" << endl;        cout << " 4. Informes" << endl;        cout << " 0. Volver" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                menuGestionDatos();                break;            case 2:                menuListados();                break;            case 3:                menuConsultas();                break;            case 4:                menuInformes();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                system("pause");                break;        }    }}//GESTIÓN DE DATOS (ABM)void menuGestionDatos() {    while (true) {        int opc;        system("cls");        cout << "========================================" << endl;        cout << "        GESTION DE DATOS (ABM)          " << endl;        cout << "========================================" << endl;        cout << " 1. Peliculas" << endl;        cout << " 2. Generos" << endl;        cout << " 3. Salas" << endl;        cout << " 4. Tipos de salas" << endl;        cout << " 5. Funciones" << endl;        cout << " 0. Volver" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                menuPeliculas();                break;            case 2:                menuGeneros();                break;            case 3:                menuSalas();                break;            case 4:                menuTipoSalas();                break;            case 5:                menuFunciones();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                system("pause");                break;        }    }}//SUBMENÚ PELÍCULAS (ABM)void menuPeliculas() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "         GESTION DE PELICULAS           " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR PELICULA" << endl;        cout << " 2 - BAJA PELICULA" << endl;        cout << " 3 - MODIFICAR PELICULA" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarPelicula();                break;            case 2:                bajaPelicula();                break;            case 3:                modificarPelicula();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void listarPeliculas() {    ArchivoPeliculas arc;    arc.listarRegistros();}void agregarPelicula() {    ArchivoPeliculas arc;
    int id= arc.generarId();    Pelicula obj;    obj.setIdPelicula(id);
    int genero=seleccionarGenero();
    if (genero == -1) {
    cout << "ERROR AL AGREGAR PELICULA" << endl;
    return;
    }
    obj.setTipoGenero(genero);    obj.Cargar();    if (arc.grabarRegistro(obj)) {        cout << "PELICULA GRABADA CON EXITO." << endl;    } else {        cout << "ERROR AL GRABAR LA PELICULA." << endl;    }}void bajaPelicula() {
    int id = seleccionarPelicula();
    if (id == -1) {
    return;
    }    ArchivoPeliculas arc;    int pos = arc.buscarRegistro(id);    Pelicula obj = arc.leerRegistro(pos);    obj.setEstado(false);    if (arc.modificarRegistro(obj, pos)) {        cout << "PELICULA DADA DE BAJA CORRECTAMENTE." << endl;    } else {        cout << "ERROR AL MODIFICAR EL ARCHIVO." << endl;    }}void modificarPelicula() {   int id = seleccionarPelicula();
    if (id == -1) {
    return;
    }
    ArchivoPeliculas arc;
    int pos = arc.buscarRegistro(id);
    Pelicula obj = arc.leerRegistro(pos);
    int opc;

        system("cls");
        cout<<"=============="<<endl;
        cout<<"1 - Modificar nombre de la pelicula"<<endl;
        cout<<"2 - Modificar nombre y apellido del director"<<endl;
        cout<<"3 - Modificar genero de la pelicula"<<endl;
        cout<<"4 - Modificar clasificacion de la pelicula"<<endl;
        cout<<"5 - Modificar fecha de estreno de la pelicula"<<endl;
        cout<<"0 - Volver"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
    switch (opc)
    {
    case 1: { char nuevoNombre[50];
    cout << "INGRESE EL NUEVO NOMBRE DE LA PELICULA: ";
    cin.ignore();
    cin.getline(nuevoNombre, 50);
    while (nuevoNombre[0] == '\0') {
    cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
    cin.getline(nuevoNombre, 50);
    }
    obj.setNombrePelicula(nuevoNombre);
    break;}
    case 2: {char nuevoNombreApellido[50];
    cout<<"INGRESE EL NUEVO NOMBRE Y APELLIDO DEL DIRECTOR: ";
    cin.ignore();
    cin.getline(nuevoNombreApellido,50);
    while (nuevoNombreApellido[0] == '\0') {
    cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
    cin.getline(nuevoNombreApellido, 50);
    }
    obj.setApellidoNombreDirector(nuevoNombreApellido);
        break;}
    case 3: {
    int nuevoGenero = seleccionarGenero();

    if (nuevoGenero == -1) {
        return;
    }

    obj.setTipoGenero(nuevoGenero);
    break;
}
    case 4: {
    int nuevaClasificacion;

    cout << "INGRESE LA NUEVA CLASIFICACION (1: ATP, 2: +14, 3: +18): ";
    cin >> nuevaClasificacion;

    while (nuevaClasificacion < 1 || nuevaClasificacion > 3) {
        cout << "CLASIFICACION NO VALIDA. INGRESE UN NUMERO DEL 1 AL 3: ";
        cin >> nuevaClasificacion;
    }

    obj.setClasificacionPelicula(nuevaClasificacion);
    break;
}

case 5: {
    Fecha nuevaFecha;

    cout << "INGRESE LA NUEVA FECHA DE ESTRENO:" << endl;
    nuevaFecha.Cargar();

    while (!nuevaFecha.esValida()) {
        cout << "FECHA INVALIDA. INGRESELA NUEVAMENTE." << endl;
        nuevaFecha.Cargar();
    }

    obj.setFechaEstreno(nuevaFecha);
    break;
}
    case 0:
        return;
    default: cout << "OPCION NO VALIDA." << endl;
        return;
    }
    if (arc.modificarRegistro(obj, pos)) {        cout << "PELICULA MODIFICADA CON EXITO." << endl;    } else {        cout << "ERROR AL MODIFICAR LA PELICULA." << endl;    }    system("pause");}//SUBMENÚ GÉNEROS (ABM)void menuGeneros() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "         GESTION DE GENEROS             " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR GENERO" << endl;        cout << " 2 - BAJA GENERO" << endl;        cout << " 3 - MODIFICAR GENERO" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarTipoGenero();                break;            case 2:                bajaTipoGenero();                break;            case 3:                modificarTipoGenero();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void agregarTipoGenero() {
    ArchivoTipoGenero arc;
    TipoGenero obj;

    obj.setTipoGenero(arc.generarId());
    obj.Cargar();
    if (arc.existeNombreActivo(obj.getNombreGenero())) {
    cout << "YA EXISTE UN GENERO ACTIVO CON ESE NOMBRE." << endl;
    return;
}

    if (arc.grabarRegistro(obj)) {
        cout << "GENERO GRABADO CON EXITO." << endl;
    } else {
        cout << "ERROR AL GRABAR EL GENERO." << endl;
    }
}

void bajaTipoGenero() {
    int id = seleccionarGenero();
    if (id == -1) {
        return;
    }

    ArchivoTipoGenero arc;
    int pos = arc.buscarRegistro(id);
    if (pos < 0) {
        cout << "NO SE PUDO ENCONTRAR EL GENERO SELECCIONADO." << endl;
        return;
    }

    TipoGenero obj = arc.leerRegistro(pos);
    obj.setEstado(false);

    if (arc.modificarRegistro(obj, pos)) {
        cout << "GENERO DADO DE BAJA CORRECTAMENTE." << endl;
    } else {
        cout << "ERROR AL DAR DE BAJA EL GENERO." << endl;
    }
}

void modificarTipoGenero() {
    int id = seleccionarGenero();
    if (id == -1) {
        return;
    }

    ArchivoTipoGenero arc;
    int pos = arc.buscarRegistro(id);

    TipoGenero obj = arc.leerRegistro(pos);

    char nuevoNombre[50];
    cout << "INGRESE EL NUEVO NOMBRE DEL GENERO: ";
    cin.ignore();
    cin.getline(nuevoNombre, 50);

    while (nuevoNombre[0] == '\0') {
        cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
        cin.getline(nuevoNombre, 50);
    }
if (arc.existeNombreActivo(nuevoNombre, id)) {
    cout << "YA EXISTE OTRO GENERO ACTIVO CON ESE NOMBRE." << endl;
    return;
}
    obj.setNombreGenero(nuevoNombre);

    if (arc.modificarRegistro(obj, pos)) {
        cout << "GENERO MODIFICADO CON EXITO." << endl;
    } else {
        cout << "ERROR AL MODIFICAR EL GENERO." << endl;
    }
}void listarTipoGeneros() {    ArchivoTipoGenero arc;    arc.listarRegistros();}//SUBMENÚ SALAS (ABM)void menuSalas() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "           GESTION DE SALAS             " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR SALA" << endl;        cout << " 2 - BAJA SALA" << endl;        cout << " 3 - MODIFICAR SALA" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarSala();                break;            case 2:                bajaSala();                break;            case 3:                modificarSala();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void agregarSala()
{
    ArchivoSala arc;

    int num = seleccionarTipoSala();
    if (num == -1)
    {
        return;
    }

    Sala obj;
    obj.setNumSala(arc.generarId());
    obj.setTipoSala(num);
    obj.Cargar();

    if (arc.grabarRegistro(obj))
    {
        cout << "SALA GRABADA CON EXITO. NUMERO DE SALA: "
             << obj.getNumSala() << endl;
    }
    else
    {
        cout << "ERROR AL GRABAR LA SALA." << endl;
    }
}

void bajaSala()
{
    int num = seleccionarSala();
    if (num == -1)
    {
        return;
    }
    ArchivoFuncion arc2;
    Funcion func;
    int cantReg=arc2.contarRegistros();
    for (int i=0;i<cantReg;i++){
        func=arc2.leerRegistro(i);
        if (func.getEstado() && func.getNumSala() == num) {
    cout << "LA SALA TIENE FUNCIONES ACTIVAS" << endl;
    return;
}
    }
    ArchivoSala arc;
    int pos = arc.buscarRegistro(num);
    if (pos < 0)
    {
        cout << "NO SE PUDO ENCONTRAR LA SALA SELECCIONADA." << endl;
        return;
    }

    Sala obj = arc.leerRegistro(pos);
    obj.setEstado(false);

    if (arc.modificarRegistro(obj, pos))
    {
        cout << "SALA DADA DE BAJA CON EXITO." << endl;
    }
    else
    {
        cout << "ERROR AL DAR DE BAJA LA SALA." << endl;
    }
}

void modificarSala()
{
    int num = seleccionarSala();
    if (num == -1)
    {
        return;
    }

    ArchivoSala arc;
    int pos = arc.buscarRegistro(num);
    if (pos < 0)
    {
        cout << "NO SE PUDO ENCONTRAR LA SALA SELECCIONADA." << endl;
        return;
    }

    Sala obj = arc.leerRegistro(pos);

    system("cls");
    cout << "==============" << endl;
    cout << "1 - Modificar nombre de la sala" << endl;
    cout << "2 - Modificar tipo de sala" << endl;
    cout << "3 - Modificar capacidad total de la sala" << endl;
    cout << "0 - Volver" << endl;
    cout << "==============" << endl;
    cout << "INGRESE UNA OPCION: ";
    int opc;
    cin >> opc;

    switch (opc)
    {
    case 1:
    {
        char nuevoNombre[30];

        cout << "INGRESE EL NUEVO NOMBRE DE LA SALA: ";
        cin.ignore();
        cin.getline(nuevoNombre, 30);
        while (nuevoNombre[0] == '\0')
        {
            cout << "EL NOMBRE NO PUEDE ESTAR VACIO. INGRESELO NUEVAMENTE: ";
            cin.getline(nuevoNombre, 30);
        }
        obj.setNombreSala(nuevoNombre);
        break;
    }
    case 2:
    {
        int nuevoTipo = seleccionarTipoSala();
        if (nuevoTipo == -1)
        {
            return;
        }

        obj.setTipoSala(nuevoTipo);
        break;
    }

    case 3:
    {
        int nuevaCapacidad;

        cout << "INGRESE LA NUEVA CAPACIDAD TOTAL: ";
        cin >> nuevaCapacidad;

        while (nuevaCapacidad <= 0)
        {
            cout << "INGRESE UNA CAPACIDAD MAYOR A CERO: ";
            cin >> nuevaCapacidad;
        }

        obj.setCapacidadTotal(nuevaCapacidad);
        break;
    }

    case 0:
        return;

    default:
        cout << "OPCION NO VALIDA." << endl;
        return;
    }

    if (arc.modificarRegistro(obj, pos))
    {
        cout << "SALA MODIFICADA CON EXITO." << endl;
    }
    else
    {
        cout << "ERROR AL MODIFICAR LA SALA." << endl;
    }
}
void listarSalas() {    ArchivoSala arc;    arc.listarRegistros();}//SUBMENÚ TIPOS DE SALA (ABM)void menuTipoSalas() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "        GESTION DE TIPOS DE SALA        " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR TIPO DE SALA" << endl;        cout << " 2 - BAJA TIPO DE SALA" << endl;        cout << " 3 - MODIFICAR TIPO DE SALA" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarTipoSala();                break;            case 2:                bajaTipoSala();                break;            case 3:                modificarTipoSala();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void agregarTipoSala() {
    ArchivoTipoSala arc;
    TipoSala obj;
    obj.setTipoSala(arc.generarId());
    obj.Cargar();
    if (arc.existeDescripcionActiva(obj.getDescSala())) {
        cout << "YA EXISTE UN TIPO DE SALA ACTIVO CON ESA DESCRIPCION." << endl;
        return;
    }

    if (arc.grabarRegistro(obj)) {
        cout << "TIPO DE SALA GRABADO CON EXITO." << endl;
    } else {
        cout << "ERROR AL GRABAR EL TIPO DE SALA." << endl;
    }
}

void bajaTipoSala() {
    int tipo = seleccionarTipoSala();
    if (tipo == -1) {
        return;
    }
    ArchivoTipoSala arc;
    int pos = arc.buscarRegistro(tipo);
    if (pos < 0) {
        cout << "NO SE PUDO ENCONTRAR EL TIPO DE SALA SELECCIONADO." << endl;
        return;
    }
    TipoSala obj = arc.leerRegistro(pos);
    obj.setEstado(false);

    if (arc.modificarRegistro(obj, pos)) {
        cout << "TIPO DE SALA DADO DE BAJA CON EXITO." << endl;
    } else {
        cout << "ERROR AL DAR DE BAJA EL TIPO DE SALA." << endl;
    }
}

void modificarTipoSala() {
    int tipo = seleccionarTipoSala();
    if (tipo == -1) {
        return;
    }
    ArchivoTipoSala arc;
    int pos = arc.buscarRegistro(tipo);
    if (pos < 0) {
        cout << "NO SE PUDO ENCONTRAR EL TIPO DE SALA SELECCIONADO." << endl;
        return;
    }
    TipoSala obj = arc.leerRegistro(pos);
    system("cls");
    cout << "==============" << endl;
    cout << "1 - Modificar descripcion del tipo de sala" << endl;
    cout << "2 - Modificar precio base de la entrada" << endl;
    cout << "0 - Volver" << endl;
    cout << "==============" << endl;
    cout << "INGRESE UNA OPCION: ";
    int opc;
    cin >> opc;

    switch (opc) {
        case 1: {
            char nuevaDescripcion[30];
            cout << "INGRESE LA NUEVA DESCRIPCION: ";
            cin.ignore();
            cin.getline(nuevaDescripcion, 30);
            while (nuevaDescripcion[0] == '\0') {
                cout << "LA DESCRIPCION NO PUEDE ESTAR VACIA. INGRESELA NUEVAMENTE: ";
                cin.getline(nuevaDescripcion, 30);
            }
            if (arc.existeDescripcionActiva(nuevaDescripcion, tipo)) {
                cout << "YA EXISTE OTRO TIPO DE SALA ACTIVO CON ESA DESCRIPCION." << endl;
                return;
            }
            obj.setDescSala(nuevaDescripcion);
            break;
        }
        case 2: {
            int nuevoPrecio;
            cout << "INGRESE EL NUEVO PRECIO BASE DE LA ENTRADA: $";
            cin >> nuevoPrecio;
            while (nuevoPrecio <= 0) {
                cout << "INGRESE UN PRECIO MAYOR A CERO: $";
                cin >> nuevoPrecio;
            }
            obj.setPrecio(nuevoPrecio);
            break;
        }
        case 0:
            return;
        default:
            cout << "OPCION NO VALIDA." << endl;
            return;
    }
    if (arc.modificarRegistro(obj, pos)) {
        cout << "TIPO DE SALA MODIFICADO CON EXITO." << endl;
    } else {
        cout << "ERROR AL MODIFICAR EL TIPO DE SALA." << endl;
    }
}void listarTipoSalas() {    ArchivoTipoSala arc;    arc.listarRegistros();}//SUBMENÚ FUNCIONES (ABM)void menuFunciones() {    int opc;    while (true) {        system("cls");        cout << "========================================" << endl;        cout << "         GESTION DE FUNCIONES           " << endl;        cout << "========================================" << endl;        cout << " 1 - AGREGAR FUNCION" << endl;        cout << " 2 - BAJA FUNCION" << endl;        cout << " 3 - MODIFICAR FUNCION" << endl;        cout << " 0 - VOLVER" << endl;        cout << "========================================" << endl;        cout << "INGRESE UNA OPCION: ";        cin >> opc;        system("cls");        switch (opc) {            case 1:                agregarFuncion();                break;            case 2:                bajaFuncion();                break;            case 3:                modificarFuncion();                break;            case 0:                return;            default:                cout << "OPCION NO VALIDA." << endl;                break;        }        system("pause");    }}void agregarFuncion() {
    int idPelicula = seleccionarPelicula();
    if (idPelicula == -1) {
        return;
    }
    int numSala = seleccionarSala();
    if (numSala == -1) {
        return;
    }
    ArchivoFuncion arc;
    Funcion obj;
    obj.setIdFuncion(arc.generarId());
    obj.setIdPelicula(idPelicula);
    obj.setNumSala(numSala);
    obj.Cargar();

    Fecha fecha = obj.getFechaFuncion();
int hora = obj.getHoraFuncion();

// Fecha mínima fija para la demostración del TP.
if (fecha.getAnio() < 2026 ||
    (fecha.getAnio() == 2026 && fecha.getMes() < 11) ||
    (fecha.getAnio() == 2026 && fecha.getMes() == 11 && fecha.getDia() < 24)) {
    cout << "LA FECHA DE LA FUNCION DEBE SER EL 24/11/2026 O POSTERIOR." << endl;
    return;
}

if (arc.existeTurnoOcupado(numSala, fecha, hora)) {
    cout << "LA SALA YA TIENE UNA FUNCION ACTIVA EN ESE TURNO." << endl;
    return;
}
    if (arc.grabarRegistro(obj)) {
        cout << "FUNCION GRABADA CON EXITO." << endl;
    } else {
        cout << "ERROR AL GRABAR LA FUNCION." << endl;
    }
}

void bajaFuncion() {
    int id = seleccionarFuncion();
    if (id == -1) {
        return;
    }

    ArchivoFuncion arc;
    int pos = arc.buscarRegistro(id);
    if (pos < 0) {
        cout << "NO SE PUDO ENCONTRAR LA FUNCION SELECCIONADA." << endl;
        return;
    }

    Funcion obj = arc.leerRegistro(pos);
    obj.setEstado(false);

    if (arc.modificarRegistro(obj, pos)) {
        cout << "FUNCION DADA DE BAJA CON EXITO." << endl;
    } else {
        cout << "ERROR AL DAR DE BAJA LA FUNCION." << endl;
    }
}void modificarFuncion() {
    int id = seleccionarFuncion();
    if (id == -1) {
        return;
    }
    ArchivoFuncion arc;
    int pos = arc.buscarRegistro(id);
    if (pos < 0) {
        cout << "NO SE PUDO ENCONTRAR LA FUNCION SELECCIONADA." << endl;
        return;
    }
    Funcion obj = arc.leerRegistro(pos);
    //system("cls");
    cout << "==============" << endl;
    cout << "1 - Modificar sala de la funcion" << endl;
    cout << "2 - Modificar fecha/horario de la funcion" << endl;
    cout << "0 - Volver" << endl;
    cout << "==============" << endl;
    cout << "INGRESE UNA OPCION: ";
    int opc;
    cin >> opc;
    switch (opc) {
    case 1:
        {
            int nuevaSalaFuncion=seleccionarSala();
            if (nuevaSalaFuncion==-1)
            {
                return;
            }
            if (arc.existeTurnoOcupado(nuevaSalaFuncion,obj.getFechaFuncion(),obj.getHoraFuncion(),id))
            {
                cout << "LA SALA YA TIENE UNA FUNCION ACTIVA EN ESE TURNO." << endl;
                return;
            }
            obj.setNumSala(nuevaSalaFuncion);
            break;
        }
    case 2:
        {
            Fecha nuevaFecha;
            int nuevoHorarioFuncion;
            cout << "INGRESE LA NUEVA FECHA DE LA FUNCION:" << endl;
            nuevaFecha.Cargar();
            while (!nuevaFecha.esValida())
            {
                cout << "FECHA INVALIDA. INGRESELA NUEVAMENTE." << endl;
                nuevaFecha.Cargar();
            }
            if (nuevaFecha.getAnio() < 2026 ||
            (nuevaFecha.getAnio() == 2026 && nuevaFecha.getMes() < 11) ||
            (nuevaFecha.getAnio() == 2026 && nuevaFecha.getMes() == 11 &&
            nuevaFecha.getDia() < 24)){
            cout << "LA FECHA DEBE SER DEL 24/11/2026 EN ADELANTE." << endl;
            return;}

           cout << "INGRESE EL NUEVO HORARIO DE LA FUNCION (12, 14, 16, 18, 20 O 22): ";
            cin >> nuevoHorarioFuncion;

    while (nuevoHorarioFuncion < 12 || nuevoHorarioFuncion > 22 || nuevoHorarioFuncion % 2 != 0)
        {
        cout << "HORARIO INVALIDO. INGRESE 12, 14, 16, 18, 20 O 22: ";
        cin >> nuevoHorarioFuncion;
        }
            if (arc.existeTurnoOcupado(obj.getNumSala(),nuevaFecha,nuevoHorarioFuncion,id))
            {
                cout << "LA SALA YA TIENE UNA FUNCION EN ESA FECHA Y HORARIO." << endl;
                return;
            }
            obj.setFechaFuncion(nuevaFecha);
            obj.setHoraFuncion(nuevoHorarioFuncion);
            break;
        }
        case 0:
            return;
        default:
            cout << "OPCION NO VALIDA." << endl;
            return;
    }
    if (arc.modificarRegistro(obj, pos)) {
    cout << "FUNCION MODIFICADA CON EXITO." << endl;
} else {
    cout << "ERROR AL MODIFICAR LA FUNCION." << endl;
}
}void listarFunciones() {    ArchivoFuncion arc;    arc.listarRegistros();}//               LISTADOS,CONSULTAS y INFORMES// ===================================================//                  SECCIÓN LISTADOS// ===================================================void menuListados() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "            MENU LISTADOS               " << endl;
        cout << "========================================" << endl;
        cout << " 1. PELICULAS" << endl;
        cout << " 2. GENEROS" << endl;
        cout << " 3. SALAS" << endl;
        cout << " 4. TIPOS DE SALA" << endl;
        cout << " 5. FUNCIONES" << endl;
        cout << " 6. CLIENTES" << endl;
        cout << " 7. VENTAS DE ENTRADAS" << endl;
        cout << " 0. VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1: subMenuListarPeliculas(); break;
            case 2: subMenuListarGeneros(); break;
            case 3: subMenuListarSalas(); break;
            case 4: subMenuListarTiposSala(); break;
            case 5: subMenuListarFunciones(); break;
            case 6: subMenuListarClientes(); break;
            case 7: subMenuListarVentas(); break;
            case 0: return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                system("pause");
                break;
        }
    }
}

void subMenuListarPeliculas() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          LISTADO DE PELICULAS          " << endl;
        cout << "========================================" << endl;
        cout << " 1 - ORDENADAS POR NOMBRE" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                listarPeliculasPorNombre();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuListarGeneros() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "           LISTADO DE GENEROS           " << endl;
        cout << "========================================" << endl;
        cout << " 1 - ORDENADOS POR NOMBRE" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1:
                listarGenerosPorNombre();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuListarSalas() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "            LISTADO DE SALAS            " << endl;
        cout << "========================================" << endl;
        cout << " 1 - ORDENADAS POR NUMERO DE SALA" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1:
                listarSalasPorNumero();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuListarTiposSala() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "        LISTADO DE TIPOS DE SALA        " << endl;
        cout << "========================================" << endl;
        cout << " 1 - ORDENADOS POR DESCRIPCION" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1:
                listarTiposSalaPorDescripcion();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuListarFunciones() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          LISTADO DE FUNCIONES          " << endl;
        cout << "========================================" << endl;
        cout << " 1 - ORDENADAS POR PELICULA (FECHA Y HORA)" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1:
                listarFuncionesPorPeliculaYFecha();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuListarClientes() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          LISTADO DE CLIENTES           " << endl;
        cout << "========================================" << endl;
        cout << " 1 - ORDENADOS POR DNI" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1:
                listarClientesPorDNI();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuListarVentas() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "      LISTADO DE VENTAS DE ENTRADAS     " << endl;
        cout << "========================================" << endl;
        cout << " 1 - ORDENADAS POR DNI DEL COMPRADOR" << endl;
        cout << " 2 - ORDENADAS POR FUNCION" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1:
                listarVentasPorDNI();
                break;
            case 2:
                listarVentasPorFuncion();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}void menuConsultas() {    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "            MENU CONSULTAS               " << endl;
        cout << "========================================" << endl;
        cout << " 1. PELICULAS" << endl;
        cout << " 2. SALAS" << endl;
        cout << " 3. FUNCIONES" << endl;
        cout << " 4. CLIENTES" << endl;
        cout << " 5. VENTAS" << endl;
        cout << " 0. VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc) {
            case 1: subMenuConsultaPeliculas(); break;
            case 2: subMenuConsultaSalas(); break;
            case 3: subMenuConsultaFunciones(); break;
            case 4: subMenuConsultaClientes(); break;
            case 5: subMenuListarVentas(); break;
            case 0: return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                system("pause");
                break;
        }
    }}

void subMenuConsultaPeliculas() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          CONSULTA DE PELICULAS          " << endl;
        cout << "========================================" << endl;
        cout << " 1 -  POR NOMBRE" << endl;
        cout << " 2 -  POR GENERO" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                consultarPeliculasPorNombre();
                break;
            case 2:consultarPeliculasPorGenero();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}
void subMenuConsultaSalas() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          CONSULTA DE SALAS          " << endl;
        cout << "========================================" << endl;
        cout << " 1 -  POR NUMERO DE SALA" << endl;
        cout << " 2 -  POR TIPO DE SALA" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                consultarSalasPorNumeroSala();
                break;
            case 2:consultarSalasPorTipoSala();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuConsultaFunciones() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          CONSULTA DE FUNCIONES          " << endl;
        cout << "========================================" << endl;
        cout << " 1 -  POR FECHA" << endl;
        cout << " 2 -  POR PELICULA" << endl;
        cout << " 3 -  POR SALA" << endl;
        cout << " 4 -  POR DISPONIBILIDAD" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                consultarFuncionesPorSala();
                break;
            case 2:consultarFuncionesPorPelicula();
                break;
            case 3:consultarFuncionesPorSala();
                break;
            case 4:consultarFuncionesPorDisponibilidad();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuConsultaClientes() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          CONSULTA DE CLIENTES          " << endl;
        cout << "========================================" << endl;
        cout << " 1 -  POR DNI" << endl;
        cout << " 2 -  POR NOMBRE Y APELLIDO" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                consultarClientesPorDni();
                break;
            case 2:consultarClientesPorNombreApellido();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void subMenuConsultaVentas() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "          CONSULTA DE VENTAS          " << endl;
        cout << "========================================" << endl;
        cout << " 1 -  POR RANGO DE FECHAS DE COMPRA" << endl;
        cout << " 2 -  POR DNI DEL COMPRADOR" << endl;
        cout << " 3 -  POR FUNCION" << endl;
        cout << " 4 -  POR PELICULA" << endl;
        cout << " 0 - VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                consultarVentasPorRangoFecha();
                break;
            case 2:consultarVentasPorDni();
                break;
            case 3:consultarVentasPorFuncion();
                break;
            case 4:consultarVentasPorPelicula();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}

void menuInformes() {    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "            MENU INFORMES               " << endl;
        cout << "========================================" << endl;
        cout << " 1. Recaudacion total por periodo" << endl;
        cout << " 2. Recaudacion por pelicula" << endl;
        cout << " 3. Recaudacion por tipo de sala" << endl;
        cout << " 4. Cantidad entradas vendidas por pelicula" << endl;
        cout << " 5. Cantidad entradas vendidas por genero" << endl;
        cout << " 6. Cantidad entradas vendidas por sala" << endl;
        cout << " 7. Porcentaje de ocupacion por funcion y sala" << endl;
        cout << " 0. Volver" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1: RecaudacionTotalPorPeriodo(); break;
            case 2: RecaudacionPorPelicula(); break;
            case 3: RecaudacionPorTipoSala(); break;
            case 4: CantEntradasVendidasPorPelicula(); break;
            case 5: CantEntradasVendidasPorGenero(); break;
            case 6: CantTotalEntradasVendidasPorSala(); break;
            case 7: PorcentajeOcupacionFuncYSala(); break;
            case 0: return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                system("pause");
                break;
        }
    }}//MENÚ CLIENTEvoid menuCliente() {
    int opc;
    while (true) {
        system("cls");
        cout << "========================================" << endl;
        cout << "              MENU CLIENTE              " << endl;
        cout << "========================================" << endl;
        cout << " 1. COMPRAR ENTRADAS" << endl;
        cout << " 0. VOLVER" << endl;
        cout << "========================================" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1:
                realizarVenta();
                break;
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
                break;
        }
        system("pause");
    }
}