#include <iostream>
#include <cstring>
#include "listados.h"

#include "clsPelicula.h"
#include "ArchivoPeliculas.h"

#include "clsSala.h"
#include "ArchivoSala.h"

#include "clsFuncion.h"
#include "ArchivoFuncion.h"

#include "clsClientes.h"
#include "ArchivoCliente.h"

#include "clsTipoGenero.h"
#include "ArchivoTipoGenero.h"

#include "clsTipoSala.h"
#include "ArchivoTipoSala.h"

#include "clsVentaEntrada.h"
#include "ArchivoVentaEntrada.h"

using namespace std;

// ===================================================
//             DESARROLLO DE LISTADOS
// ===================================================

// 1. PELÍCULAS ORDENADAS POR NOMBREvoid listarPeliculasPorNombre()
{
    ArchivoPeliculas arc;
    int cant = arc.contarRegistros();

    if (cant <= 0)
    {
        cout << "NO HAY PELICULAS REGISTRADAS." << endl;
        return;
    }

    // Reservamos espacio para todos los registros y copiamos solo las películas activas.
    // contActivos indica cuántas posiciones del vector usamos.
    Pelicula *vec = new Pelicula[cant];
    int contActivos = 0;

    for (int i = 0; i < cant; i++)
    {
        Pelicula obj = arc.leerRegistro(i);
        if (obj.getEstado())
        {
            vec[contActivos] = obj;
            contActivos++;
        }
    }

    if (contActivos == 0)
    {
        cout << "NO HAY PELICULAS ACTIVAS." << endl;
        delete[] vec;
        return;
    }

    // Burbujeo: comparamos películas vecinas. En cada pasada, el título
    // que va más al final queda en su posición definitiva.
    for (int i = 0; i < contActivos - 1; i++)
    {
        // -i evita volver a comparar las posiciones ya ordenadas al final.
        // -1 asegura que j + 1 sea una posición válida del tramo que queda.
        for (int j = 0; j < contActivos - i - 1; j++)
        {
            // strcmp da un valor positivo si el título de la izquierda va después.
            // Intercambiamos las películas completas para conservar sus demás datos.
            if (strcmp(vec[j].getNombrePelicula(), vec[j + 1].getNombrePelicula()) > 0)
            {
                Pelicula aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    // Mostramos las películas en el orden del vector. El archivo queda en su orden original.
    cout << "=== LISTADO DE PELICULAS (ORDENADAS POR NOMBRE) ===" << endl;
    for (int i = 0; i < contActivos; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }

    delete[] vec;
}// 2. GÉNEROS ORDENADOS POR NOMBREvoid listarGenerosPorNombre()
{
    ArchivoTipoGenero arc;
    int cant = arc.contarRegistros();
    if (cant <= 0)
    {
        cout << "NO HAY GENEROS REGISTRADOS." << endl;
        return;
    }
    // Reservamos espacio para todos los registros y copiamos solo los géneros activos.
    TipoGenero *vec = new TipoGenero[cant];
    int contActivos = 0;
    for (int i = 0; i < cant; i++)
    {
        TipoGenero obj = arc.leerRegistro(i);
        if (obj.getEstado())
        {
            vec[contActivos] = obj;
            contActivos++;
        }
    }
    if (contActivos == 0)
    {
        cout << "NO HAY GENEROS ACTIVOS." << endl;
        delete[] vec;
        return;
    }
    // El burbujeo recorre solo las posiciones que llenamos con géneros activos.
    for (int i = 0; i < contActivos - 1; i++)
    {
        for (int j = 0; j < contActivos - i - 1; j++)
        {
            // Si el nombre de la izquierda va después, intercambiamos los géneros completos.
            if (strcmp(vec[j].getNombreGenero(), vec[j + 1].getNombreGenero()) > 0)
            {
                TipoGenero aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    cout << "=== LISTADO DE GENEROS (ORDENADOS POR NOMBRE) ===" << endl;
    for (int i = 0; i < contActivos; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }
    delete[] vec;
}// 3. SALAS ORDENADAS POR NÚMERO DE SALAvoid listarSalasPorNumero()
{
    ArchivoSala arc;
    int cant = arc.contarRegistros();
    if (cant <= 0)
    {
        cout << "NO HAY SALAS REGISTRADAS." << endl;
        return;
    }
    Sala *vec = new Sala[cant];
    int contActivos = 0;
    // Guardamos las salas activas en posiciones consecutivas del vector.
    for (int i = 0; i < cant; i++)
    {
        Sala obj = arc.leerRegistro(i);
        if (obj.getEstado())
        {
            vec[contActivos] = obj;
            contActivos++;
        }
    }
    if (contActivos == 0)
    {
        cout << "NO HAY SALAS ACTIVAS." << endl;
        delete[] vec;
        return;
    }
    for (int i = 0; i < contActivos - 1; i++)
    {
        for (int j = 0; j < contActivos - i - 1; j++)
        {
            // El número de sala es un int. Usamos > para ordenar de menor a mayor.
            if (vec[j].getNumSala() > vec[j + 1].getNumSala())
            {
                Sala aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
    cout << "=== LISTADO DE SALAS (ORDENADAS POR NUMERO) ===" << endl;
    for (int i = 0; i < contActivos; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }
    delete[] vec;
}// 4. TIPOS DE SALA ORDENADOS POR DESCRIPCIÓNvoid listarTiposSalaPorDescripcion()
{
    ArchivoTipoSala arc;
    int cant = arc.contarRegistros();
    if (cant <= 0)
    {
        cout << "NO HAY TIPOS DE SALA REGISTRADOS." << endl;
        return;
    }
    TipoSala *vec = new TipoSala[cant];
    int contActivos = 0;
    for (int i = 0; i < cant; i++)
    {
        TipoSala obj = arc.leerRegistro(i);
        if (obj.getEstado())
        {
            vec[contActivos] = obj;
            contActivos++;
        }
    }
    if (contActivos == 0)
    {
        cout << "NO HAY TIPOS DE SALA ACTIVOS." << endl;
        delete[] vec;
        return;
    }
    // Usamos la descripción como criterio de orden, igual que el nombre en géneros.
    for (int i = 0; i < contActivos - 1; i++)
    {
        for (int j = 0; j < contActivos - i - 1; j++)
        {
            if (strcmp(vec[j].getDescSala(), vec[j + 1].getDescSala()) > 0)
            {
                TipoSala aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
    cout << "=== LISTADO DE TIPOS DE SALA (ORDENADOS POR DESCRIPCIÓN) ===" << endl;
    for (int i = 0; i < contActivos; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }
    delete[] vec;
}// 5. FUNCIONES ORDENADAS POR PELÍCULA, FECHA Y HORA// Devuelve true si a debe ir después de b y el burbujeo tiene que intercambiarlas.
bool compararFunciones(Funcion a, Funcion b)
{
    // El ID de película es el primer criterio y deja juntas sus funciones.
    if (a.getIdPelicula() != b.getIdPelicula())
    {
        return a.getIdPelicula() > b.getIdPelicula();
    }

    // Si son de la misma película, comparamos año, mes y día en ese orden.
    Fecha f1 = a.getFechaFuncion();
    Fecha f2 = b.getFechaFuncion();

    if (f1.getAnio() != f2.getAnio())
    {
        return f1.getAnio() > f2.getAnio();
    }
    if (f1.getMes() != f2.getMes())
    {
        return f1.getMes() > f2.getMes();
    }
    if (f1.getDia() != f2.getDia())
    {
        return f1.getDia() > f2.getDia();
    }

    // Si también coinciden en la fecha, la hora decide el orden.
    return a.getHoraFuncion() > b.getHoraFuncion();
}

void listarFuncionesPorPeliculaYFecha()
{
    ArchivoFuncion arc;
    int cant = arc.contarRegistros();
    if (cant <= 0)
    {
        cout << "NO HAY FUNCIONES REGISTRADAS." << endl;
        return;
    }
    Funcion *vec = new Funcion[cant];
    int contActivos = 0;
    for (int i = 0; i < cant; i++)
    {
        Funcion obj = arc.leerRegistro(i);
        if (obj.getEstado())
        {
            vec[contActivos] = obj;
            contActivos++;
        }
    }
    if (contActivos == 0)
    {
        cout << "NO HAY FUNCIONES ACTIVAS." << endl;
        delete[] vec;
        return;
    }
    // El burbujeo compara vecinos. La auxiliar decide si el par está al revés.
    for (int i = 0; i < contActivos - 1; i++)
    {
        for (int j = 0; j < contActivos - i - 1; j++)
        {
            if (compararFunciones(vec[j], vec[j + 1]))
            {
                Funcion aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
    cout << "=== LISTADO DE FUNCIONES (POR PELICULA, FECHA Y HORA) ===" << endl;
    for (int i = 0; i < contActivos; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }
    delete[] vec;
}// 6. CLIENTES ORDENADOS POR DNIvoid listarClientesPorDNI()
{
    ArchivoCliente arc;
    int cant = arc.contarRegistros();
    if (cant <= 0)
    {
        cout << "NO HAY CLIENTES REGISTRADOS." << endl;
        return;
    }
    // Cliente no tiene baja lógica, así que copiamos todos los registros.
    Cliente *vec = new Cliente[cant];
    for (int i = 0; i < cant; i++)
    {
        vec[i] = arc.leerRegistro(i);
    }
    // El vector se llenó completo, así que ordenamos sus cant posiciones.
    for (int i = 0; i < cant - 1; i++)
    {
        for (int j = 0; j < cant - i - 1; j++)
        {
            if (vec[j].getDni() > vec[j + 1].getDni())
            {
                Cliente aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
    cout << "=== LISTADO DE CLIENTES (ORDENADOS POR DNI) ===" << endl;
    for (int i = 0; i < cant; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }
    delete[] vec;
}// 7. VENTAS ORDENADAS POR DNI DEL COMPRADORvoid listarVentasPorDNI()
{
    ArchivoVentaEntrada arc;
    int cant = arc.contarRegistros();
    if (cant <= 0)
    {
        cout << "NO HAY VENTAS REGISTRADAS." << endl;
        return;
    }
    VentaEntrada *vec = new VentaEntrada[cant];
    for (int i = 0; i < cant; i++)
    {
        vec[i] = arc.leerRegistro(i);
    }
    // Ordenamos todas las ventas por DNI. Las compras de un mismo DNI quedan juntas.
    for (int i = 0; i < cant - 1; i++)
    {
        for (int j = 0; j < cant - i - 1; j++)
        {
            if (vec[j].getDniComprador() > vec[j + 1].getDniComprador())
            {
                VentaEntrada aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
    cout << "=== LISTADO DE VENTAS (ORDENADAS POR DNI COMPRADOR) ===" << endl;
    for (int i = 0; i < cant; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }
    delete[] vec;
}// 8. VENTAS ORDENADAS POR FUNCIÓNvoid listarVentasPorFuncion()
{
    ArchivoVentaEntrada arc;
    int cant = arc.contarRegistros();
    if (cant <= 0)
    {
        cout << "NO HAY VENTAS REGISTRADAS." << endl;
        return;
    }
    VentaEntrada *vec = new VentaEntrada[cant];
    for (int i = 0; i < cant; i++)
    {
        vec[i] = arc.leerRegistro(i);
    }
    // Cada venta ya guarda el ID de su función. Ese dato alcanza para ordenar el listado.
    for (int i = 0; i < cant - 1; i++)
    {
        for (int j = 0; j < cant - i - 1; j++)
        {
            if (vec[j].getIdFuncion() > vec[j + 1].getIdFuncion())
            {
                VentaEntrada aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
    cout << "=== LISTADO DE VENTAS (ORDENADAS POR FUNCION) ===" << endl;
    for (int i = 0; i < cant; i++)
    {
        vec[i].Mostrar();
        cout << "--------------------------------------------------" << endl;
    }
    delete[] vec;
}
