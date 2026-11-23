#include <iostream>
#include "funcionesGlobales.h"
#include "ArchivoTipoGenero.h"
#include "ArchivoPeliculas.h"
#include "ArchivoFuncion.h"
#include "ArchivoSala.h"
#include "ArchivoTipoSala.h"
using namespace std;

// Muestra los géneros activos y devuelve el ID elegido.
// Devuelve -1 si no hay géneros activos o la selección no es válida.
int seleccionarGenero()
{
    ArchivoTipoGenero arc;
    int opc;
    int cantReg=arc.contarRegistros();
    int activos=0;
    for (int i=0; i<cantReg; i++)
    {
        TipoGenero obj=arc.leerRegistro(i);
        if (obj.getEstado())
        {
            activos++;
            cout << "ID:" << obj.getTipoGenero() << " - "
                 << obj.getNombreGenero() << endl;
        }

    }
    if (activos==0)
    {
        cout<<"NO HAY GENEROS ACTIVOS DISPONIBLES"<<endl;
        return -1;
    }
    cout<<"INGRESE EL ID DEL GENERO: ";
    cin>>opc;
// El usuario puede ingresar un ID que no se mostró.
// Buscamos su posición en el archivo y comprobamos que siga activo.
    int pos = arc.buscarRegistro(opc);
    if (pos < 0)
    {
        cout << "NO EXISTE GENERO CON ESE ID" << endl;
        return -1;
    }
    TipoGenero obj=arc.leerRegistro(pos);
    if (!obj.getEstado())
    {
        cout<<"EL GÉNERO INGRESADO ESTÁ DADO DE BAJA"<<endl;
        return -1;
    }
    return opc;
}

int seleccionarSala()
{
    ArchivoSala arc;
    int opc;
    int cantReg=arc.contarRegistros();
    int activos=0;
    for (int i=0; i<cantReg; i++)
    {
        Sala obj=arc.leerRegistro(i);
        if (obj.getEstado())
        {
            activos++;
            cout <<"SALA: " << obj.getNumSala() << " - " << obj.getNombreSala() << endl;
        }

    }
    if (activos==0)
    {
        cout<<"NO HAY SALAS ACTIVAS DISPONIBLES"<<endl;
        return -1;
    }
    cout<<"INGRESE EL NUMERO DE SALA: ";
    cin>>opc;
    int pos = arc.buscarRegistro(opc);
    if (pos < 0)
    {
        cout << "NO EXISTE SALA CON ESE NUMERO" << endl;
        return -1;
    }
    Sala obj=arc.leerRegistro(pos);
    if (!obj.getEstado())
    {
        cout<<"LA SALA INGRESADA ESTÁ DADA DE BAJA"<<endl;
        return -1;
    }
    return opc;
}

int seleccionarPelicula()
{
    ArchivoPeliculas arc;
    int opc;
    int cantReg=arc.contarRegistros();
    int activos=0;
    for (int i=0; i<cantReg; i++)
    {
        Pelicula obj=arc.leerRegistro(i);
        if (obj.getEstado())
        {
            activos++;
            cout <<"ID: " << obj.getIdPelicula() << " - " << obj.getNombrePelicula() << endl;
        }

    }
    if (activos==0)
    {
        cout<<"NO HAY PELICULAS ACTIVAS DISPONIBLES"<<endl;
        return -1;
    }
    cout<<"INGRESE EL ID DE LA PELICULA: ";
    cin>>opc;
    int pos = arc.buscarRegistro(opc);
    if (pos < 0)
    {
        cout << "NO EXISTE PELICULA CON ESE ID" << endl;
        return -1;
    }
    Pelicula obj=arc.leerRegistro(pos);
    if (!obj.getEstado())
    {
        cout<<"LA PELICULA INGRESADA ESTÁ DADA DE BAJA"<<endl;
        return -1;
    }
    return opc;
}

int seleccionarTipoSala()
{
    ArchivoTipoSala arc;

    int opc;
    int cantReg=arc.contarRegistros();
    int activos=0;
    for (int i=0; i<cantReg; i++)
    {
        TipoSala obj = arc.leerRegistro(i);
        if (obj.getEstado())
        {
            activos++;
            cout << "ID: " << obj.getTipoSala() << " - "
                 << obj.getDescSala() << endl;
        }

    }
    if (activos==0)
    {
        cout<<"NO HAY TIPOS DE SALA ACTIVOS DISPONIBLES"<<endl;
        return -1;
    }
    cout<<"INGRESE EL ID DEL TIPO DE SALA: ";
    cin>>opc;
    int pos = arc.buscarRegistro(opc);
    if (pos < 0)
    {
        cout << "NO EXISTE TIPO DE SALA CON ESE ID" << endl;
        return -1;
    }
    TipoSala obj=arc.leerRegistro(pos);
    if (!obj.getEstado())
    {
        cout<<"EL TIPO DE SALA INGRESADO ESTÁ DADO DE BAJA"<<endl;
        return -1;
    }
    return opc;
}

// Lista las funciones activas y devuelve el ID elegido.
// Devuelve -1 si no hay funciones activas o el ID ingresado no corresponde a una.
int seleccionarFuncion()
{
    ArchivoFuncion arc;
    ArchivoPeliculas arc2;
    int opc;
    int cantReg=arc.contarRegistros();
    int activos=0;
    for (int i=0; i<cantReg; i++)
    {
        Funcion obj=arc.leerRegistro(i);
        if (obj.getEstado())
        {
            // La función guarda el ID de la película.
            // Buscamos ese ID en Peliculas.dat para obtener su posición y leer el nombre.
            activos++;
            int posPelicula = arc2.buscarRegistro(obj.getIdPelicula());

            cout << "ID: " << obj.getIdFuncion() << " - ";

            if (posPelicula >= 0)
            {
                Pelicula peli = arc2.leerRegistro(posPelicula);
                cout << peli.getNombrePelicula();
            }
            else
            {
                cout << "Pelicula no encontrada";
            }

            cout << " - Sala " << obj.getNumSala() << " - ";

            obj.getFechaFuncion().Mostrar();

            cout << " - " << obj.getHoraFuncion() << ":00" << endl;
        }
    }
    if (activos==0)
    {
        cout<<"NO HAY FUNCIONES ACTIVAS DISPONIBLES"<<endl;
        return -1;
    }
    cout<<"INGRESE EL ID DE LA FUNCION: ";
    cin>>opc;
    int pos = arc.buscarRegistro(opc);
    if (pos < 0)
    {
        cout << "NO EXISTE FUNCION CON ESE ID" << endl;
        return -1;
    }
    // Un ID dado de baja sigue existiendo en el archivo y se puede ingresar a mano.
    Funcion obj=arc.leerRegistro(pos);
    if (!obj.getEstado())
    {
        cout<<"LA FUNCION INGRESADA ESTÁ DADA DE BAJA"<<endl;
        return -1;
    }
    return opc;
}




