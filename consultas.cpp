#include <iostream>
#include "consultas.h"
#include <cstring>
#include "funcionesGlobales.h"
#include "ArchivoCliente.h"
#include "ArchivoFuncion.h"
#include "ArchivoPeliculas.h"
#include "ArchivoSala.h"
#include "ArchivoTipoGenero.h"
#include "ArchivoVentaEntrada.h"
#include "ArchivoTipoSala.h"
using namespace std;

// ===================================================
//             DESARROLLO DE CONSULTAS
// ===================================================

//1. CONSULTAS DE PELICULAS POR GENERO
void consultarPeliculasPorGenero()
{
    bool mostroPelicula = false;
    int id = seleccionarGenero();
    if (id == -1)
    {
        return;
    }
    ArchivoPeliculas arc;
    Pelicula obj;
    int cantReg = arc.contarRegistros();

    // El selector valida el género elegido. El estado de cada película se comprueba acá.
    // Recorremos todo el archivo porque un género puede tener varias películas.
    for (int i = 0; i < cantReg; i++)
    {
        obj = arc.leerRegistro(i);
        if (obj.getEstado() && obj.getTipoGenero() == id)
        {
            mostroPelicula = true;
            obj.Mostrar();
        }
    }
    if (!mostroPelicula)
    {
        cout << "NO HAY PELICULAS ACTIVAS CON ESE GENERO";
    }
}

//2. CONSULTAS DE PELICULAS POR NOMBRE
void consultarPeliculasPorNombre()
{
    char nombreBuscado[50];
    bool mostroPelicula = false;
    cout << "INGRESE NOMBRE DE LA PELICULA:" << endl;

    // El submenú lee la opción con >>. Consumimos el Enter antes de leer el título con espacios.
    cin.ignore();
    cin.getline(nombreBuscado, 50);
    ArchivoPeliculas arc;
    Pelicula obj;
    int cantReg = arc.contarRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        obj = arc.leerRegistro(i);
        // strcmp devuelve 0 cuando el título coincide exactamente, incluidas las mayúsculas.
        if (obj.getEstado() && strcmp(obj.getNombrePelicula(), nombreBuscado) == 0)
        {
            mostroPelicula = true;
            obj.Mostrar();
        }
    }
    if (!mostroPelicula)
    {
        cout << "NO HAY PELICULAS ACTIVAS CON ESE NOMBRE";
    }
}

//3. CONSULTA DE SALAS POR NUMERO DE SALA
void consultarSalasPorNumeroSala()
{
    int numBuscado;
    bool mostroSala = false;
    cout << "INGRESE NUMERO DE SALA: ";
    cin >> numBuscado;
    ArchivoSala arc;
    Sala obj;
    // El número identifica una sola sala. buscarRegistro devuelve su posición en el archivo.
    // La posición 0 corresponde al primer registro.
    int pos = arc.buscarRegistro(numBuscado);
    if (pos >= 0)
    {
        obj = arc.leerRegistro(pos);

        // Una sala dada de baja sigue guardada en el archivo.
        if (obj.getEstado())
        {
            mostroSala = true;
            obj.Mostrar();
        }
    }

    if (!mostroSala)
    {
        cout << "NO EXISTEN SALAS CON ESE NUMERO";
    }
}

//4. CONSULTA DE SALAS POR TIPO DE SALA
void consultarSalasPorTipoSala()
{
    bool mostroSala = false;
    int id = seleccionarTipoSala();
    if (id == -1)
    {
        return;
    }
    // El selector devuelve el ID del tipo. Buscamos todas las salas que lo tienen asignado.
    ArchivoSala arc;
    Sala obj;
    int cantReg = arc.contarRegistros();
    for (int i = 0; i < cantReg; i++)
    {
        obj = arc.leerRegistro(i);
        if (obj.getEstado() && obj.getTipoSala() == id)
        {
            mostroSala = true;
            obj.Mostrar();
        }
    }
    if (!mostroSala)
    {
        cout << "NO HAY SALAS ACTIVAS CON ESE TIPO";
    }
}

//5. CONSULTA DE FUNCIONES POR FECHA
void consultarFuncionesPorFecha()
{
    ArchivoFuncion arc;
    Funcion obj;
    Fecha fechaBuscada;
    bool mostroFuncion = false;
    cout << "INGRESE FECHA DE FUNCION: " << endl;
    fechaBuscada.Cargar();
    if (!fechaBuscada.esValida())
    {
        cout << "LA FECHA INGRESADA NO ES VALIDA" << endl;
        return;
    }
    int cantReg = arc.contarRegistros();
    for (int i = 0; i < cantReg; i++)
    {
        obj = arc.leerRegistro(i);
        Fecha fechaFuncion = obj.getFechaFuncion();

        // Comparamos día, mes y año para mostrar todas las funciones activas de esa fecha.
        if (obj.getEstado()
                && fechaFuncion.getDia() == fechaBuscada.getDia()
                && fechaFuncion.getMes() == fechaBuscada.getMes()
                && fechaFuncion.getAnio() == fechaBuscada.getAnio())
        {
            mostroFuncion = true;
            obj.Mostrar();
        }
    }
    if (!mostroFuncion)
    {
        cout << "NO EXISTEN FUNCIONES ACTIVAS EN ESA FECHA";
    }
}

//6. CONSULTA DE FUNCIONES POR PELICULA
void consultarFuncionesPorPelicula()
{
    int id = seleccionarPelicula();
    bool mostroFuncion = false;
    if (id == -1)
    {
        return;
    }
    ArchivoFuncion arc;
    Funcion obj;
    int cantReg = arc.contarRegistros();
    // El selector valida la película. Acá filtramos las funciones activas asociadas a su ID.
    for (int i = 0; i < cantReg; i++)
    {
        obj = arc.leerRegistro(i);
        if (obj.getEstado() && obj.getIdPelicula() == id)
        {
            obj.Mostrar();
            mostroFuncion = true;
        }
    }

    if (!mostroFuncion)
    {
        cout << "NO EXISTEN FUNCIONES ACTIVAS PARA ESA PELICULA";
    }
}


//7. CONSULTA DE FUNCIONES POR SALA
void consultarFuncionesPorSala()
{
    int numSala = seleccionarSala();
    bool mostroFuncion = false;
    if (numSala == -1)
    {
        return;
    }
    ArchivoFuncion arc;
    Funcion obj;
    int cantReg = arc.contarRegistros();
    // Recorremos todo el archivo porque una sala puede tener varias funciones activas.
    for (int i = 0; i < cantReg; i++)
    {
        obj = arc.leerRegistro(i);
        if (obj.getEstado() && obj.getNumSala() == numSala)
        {
            obj.Mostrar();
            mostroFuncion = true;
        }
    }
    if (!mostroFuncion)
    {
        cout << "NO HAY FUNCIONES ACTIVAS EN ESA SALA";
    }
}

//8. CONSULTA DE FUNCIONES POR DISPONIBILIDAD
void consultarFuncionesPorDisponibilidad()
{
    int id = seleccionarFuncion();
    if (id == -1)
    {
        return;
    }
    ArchivoFuncion arc;
    Funcion func;
    Sala sala;
    ArchivoSala arc2;
    ArchivoVentaEntrada arc3;
    int entradasVendidas = 0;
    // El selector devuelve el ID de la función. Buscamos su posición para leerla.
    int pos = arc.buscarRegistro(id);
    if (pos >= 0)
    {
        func = arc.leerRegistro(pos);
    }
    // La función guarda el número de sala. La capacidad se obtiene del registro de esa sala.
    int posSala = arc2.buscarRegistro(func.getNumSala());
    if (posSala >= 0)
    {
        VentaEntrada venta;
        sala = arc2.leerRegistro(posSala);
        // Una sala dada de baja sigue en el archivo, por eso comprobamos su estado.
        if (!sala.getEstado())
        {
            cout << "LA SALA DE LA FUNCION ESTA DADA DE BAJA";
            return;
        }
        int cantReg = arc3.contarRegistros();
        // Sumamos las entradas de cada compra de esta función. En la misma sala puede haber otras funciones.
        for (int i = 0; i < cantReg; i++)
        {
            venta = arc3.leerRegistro(i);
            if (venta.getIdFuncion() == id)
            {
                entradasVendidas += venta.getCantEntradasVendidas();
            }
        }
        cout << "LA FUNCION " << id << " TIENE "
             << sala.getCapacidadTotal() - entradasVendidas
             << " BUTACAS DISPONIBLES";
    }
}

//9. CONSULTA DE CLIENTES POR DNI
void consultarClientesPorDni()
{
    ArchivoCliente arc;
    Cliente obj;
    int dniBuscado;
    cout << "INGRESE NUMERO DE DNI: ";
    cin >> dniBuscado;
    // El DNI identifica a un solo cliente. buscarRegistro devuelve su posición en el archivo.
    int pos = arc.buscarRegistro(dniBuscado);
    if (pos >= 0)
    {
        obj = arc.leerRegistro(pos);
        obj.Mostrar();
    }
    else
    {
        cout << "NO EXISTE CLIENTE CON ESE DNI" << endl;
    }
}

//10. CONSULTA DE CLIENTES POR NOMBRE Y APELLIDO
void consultarClientesPorNombreApellido()
{
    char nombreBuscado[50];
    bool mostroCliente = false;
    cout << "INGRESE NOMBRE Y APELLIDO DEL CLIENTE:" << endl;
    // Consumimos el Enter que quedó al elegir la opción del submenú con >>.
    // getline permite leer el nombre completo con espacios.
    cin.ignore();
    cin.getline(nombreBuscado, 50);
    ArchivoCliente arc;
    Cliente obj;
    int cantReg = arc.contarRegistros();
    // Puede haber varios clientes con el mismo nombre y apellido.
    for (int i = 0; i < cantReg; i++)
    {
        obj = arc.leerRegistro(i);

        // strcmp devuelve 0 si el texto coincide exactamente y distingue mayúsculas.
        if (strcmp(obj.getNombreApellido(), nombreBuscado) == 0)
        {
            mostroCliente = true;
            obj.Mostrar();
        }
    }
    if (!mostroCliente)
    {
        cout << "NO HAY CLIENTES CON ESE NOMBRE";
    }
}

//11. CONSULTA DE VENTAS POR RANGO DE FECHAS DE COMPRA
void consultarVentasPorRangoFecha()
{
    cout << "INGRESE FECHA DESDE:" << endl;
    Fecha fechaDesde;
    fechaDesde.Cargar();
    if (!fechaDesde.esValida())
    {
        cout << "LA FECHA INGRESADA NO ES VALIDA";
        return;
    }
    cout << "INGRESE FECHA HASTA:" << endl;
    Fecha fechaHasta;
    fechaHasta.Cargar();
    if (!fechaHasta.esValida())
    {
        cout << "LA FECHA INGRESADA NO ES VALIDA";
        return;
    }
    // Si ambas fechas son iguales, el rango abarca un solo día.
    if (esPosterior(fechaDesde, fechaHasta))
    {
        cout << "LAS FECHAS SE INGRESARON EN ORDEN INVERTIDO";
        return;
    }
    bool mostroVenta = false;
    ArchivoVentaEntrada arc;
    VentaEntrada venta;
    int cantReg = arc.contarRegistros();
    for (int i = 0; i < cantReg; i++)
    {
        venta = arc.leerRegistro(i);
        Fecha fechaCompra = venta.getDiaCompra();
        // La compra entra si no es anterior a "desde" ni posterior a "hasta".
        // esPosterior devuelve false para fechas iguales, por eso se incluyen ambos extremos.
        if (!esPosterior(fechaDesde, fechaCompra)
                && !esPosterior(fechaCompra, fechaHasta))
        {
            mostroVenta = true;
            venta.Mostrar();
        }
    }
    if (!mostroVenta)
    {
        cout << "NO HAY VENTAS EN ESE RANGO";
    }
}

//12. CONSULTA DE VENTAS POR DNI
void consultarVentasPorDni()
{
    ArchivoVentaEntrada arc;
    VentaEntrada venta;
    bool mostroVenta = false;
    int dniBuscado;
    cout << "INGRESE NUMERO DE DNI: ";
    cin >> dniBuscado;
    // buscarRegistro usa el ID de venta. Para buscar por DNI, recorremos
    // todo el archivo porque un mismo cliente puede tener varias compras.
    int cantReg = arc.contarRegistros();
    for (int i = 0; i < cantReg; i++)
    {
        venta = arc.leerRegistro(i);
        if (venta.getDniComprador() == dniBuscado)
        {
            venta.Mostrar();
            mostroVenta = true;
        }
    }

    if (!mostroVenta)
    {
        cout << "NO EXISTEN VENTAS HECHAS POR ESE DNI";
    }
}

//13. CONSULTA DE VENTAS POR FUNCION
void consultarVentasPorFuncion()
{
    // El selector actual permite elegir una función activa y devuelve su ID.
    int id = seleccionarFuncion();
    if (id == -1)
    {
        return;
    }
    ArchivoVentaEntrada arc;
    VentaEntrada venta;
    bool mostroVenta = false;
    int cantReg = arc.contarRegistros();
    // Una función puede tener varias compras. Mostramos todas las ventas con ese ID.
    for (int i = 0; i < cantReg; i++)
    {
        venta = arc.leerRegistro(i);
        if (venta.getIdFuncion() == id)
        {
            venta.Mostrar();
            mostroVenta = true;
        }
    }
    if (!mostroVenta)
    {
        cout << "NO HAY VENTAS PARA ESA FUNCION";
    }
}

//14. CONSULTA DE VENTAS POR PELICULA
void consultarVentasPorPelicula()
{
    int idPelicula = seleccionarPelicula();
    if (idPelicula == -1)
    {
        return;
    }
    ArchivoVentaEntrada arc;
    VentaEntrada venta;
    ArchivoFuncion arc2;
    Funcion func;
    bool mostroVenta = false;
    int cantReg = arc.contarRegistros();

    for (int i = 0; i < cantReg; i++)
    {
        venta = arc.leerRegistro(i);
        // La venta guarda el ID de la función. La función guarda el ID de la película.
        int pos = arc2.buscarRegistro(venta.getIdFuncion());
        if (pos >= 0)
        {
            func = arc2.leerRegistro(pos);
            if (func.getIdPelicula() == idPelicula)
            {
                venta.Mostrar();
                mostroVenta = true;
            }
        }
    }
    if (!mostroVenta)
    {
        cout << "NO EXISTEN VENTAS PARA ESTA PELICULA";
    }
}
