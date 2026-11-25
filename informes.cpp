#include <iostream>
#include "informes.h"
#include "ArchivoVentaEntrada.h"
#include "ArchivoPeliculas.h"
#include "ArchivoFuncion.h"
#include "ArchivoTipoSala.h"
#include "ArchivoSala.h"
#include "ArchivoTipoGenero.h"
#include "clsFecha.h"
#include "funcionesGlobales.h"
using namespace std;

void RecaudacionTotalPorPeriodo()
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
    int Rectotal=0;
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
            Rectotal+=venta.getImporteTotal();

        }
    }
    cout << "LA RECAUDACION TOTAL ES DE: $" << Rectotal << endl;
}


void RecaudacionPorPelicula()
{
    ArchivoVentaEntrada arcVenta;
    ArchivoPeliculas arcPeli;
    Pelicula pel;
    VentaEntrada venta;
    ArchivoFuncion arcFunc;
    Funcion func;
    int cantRegPeli=arcPeli.contarRegistros();
    int cantRegVenta = arcVenta.contarRegistros();
    for (int i=0; i<cantRegPeli; i++)
    {
        // Reiniciamos el acumulador y la marca de ventas para cada película.
        // Recorremos todas las ventas antes de mostrar el total de esa película.
        pel = arcPeli.leerRegistro(i);
        int AcumPorPelicula=0;
        bool hayVenta = false;
        int idPeli = pel.getIdPelicula();
        for (int j = 0; j < cantRegVenta; j++)
        {
            venta = arcVenta.leerRegistro(j);
            // La venta guarda el ID de la función. La función guarda el ID de la película.
            int pos = arcFunc.buscarRegistro(venta.getIdFuncion());
            if (pos >= 0)
            {
                func = arcFunc.leerRegistro(pos);
                if (func.getIdPelicula() == idPeli)
                {

                    AcumPorPelicula+=venta.getImporteTotal();
                    hayVenta = true;
                }
            }
        }
        if (!hayVenta)
        {
            cout <<pel.getNombrePelicula()<<" NO TUVO VENTAS"<<endl;
        }
        else cout<<pel.getNombrePelicula()<<" - RECAUDO : $"<<AcumPorPelicula<<endl;
    }
}
void RecaudacionPorTipoSala()
{
    ArchivoVentaEntrada arcVenta;
    VentaEntrada venta;
    ArchivoSala arcSala;
    Sala sala;
    ArchivoTipoSala arcTipoSala;
    TipoSala tipoSala;
    ArchivoFuncion arcFunc;
    Funcion func;
    int cantRegTipoSala=arcTipoSala.contarRegistros();
    int cantRegVenta = arcVenta.contarRegistros();
    for (int i=0; i<cantRegTipoSala; i++)
    {
        // Reiniciamos el acumulador y la marca de ventas para cada tipo de sala.
        // Recorremos todas las ventas antes de mostrar el total de ese tipo de sala.
        tipoSala = arcTipoSala.leerRegistro(i);
        int AcumPorTipo=0;
        bool hayVenta = false;
        int idTipo=tipoSala.getTipoSala();
        for (int j = 0; j < cantRegVenta; j++)
        {
            venta = arcVenta.leerRegistro(j);
            // La venta guarda el ID de la función. La función guarda el numero de sala.
            int posFunc = arcFunc.buscarRegistro(venta.getIdFuncion());
            if (posFunc >= 0)
            {
                func = arcFunc.leerRegistro(posFunc);
                // La función guarda el número de sala. Buscamos ese número
                // para obtener la posición del registro y poder leer su tipo de sala.
                int posSala=arcSala.buscarRegistro(func.getNumSala());
                if (posSala>=0)
                {
                    // Agrupamos las ventas según el tipo que tiene asignado la sala al consultar el informe.
                    sala= arcSala.leerRegistro(posSala);
                    if (sala.getTipoSala()==idTipo)
                    {
                        AcumPorTipo+=venta.getImporteTotal();
                        hayVenta = true;
                    }
                }
            }
        }
        if (!hayVenta)
        {
            cout <<tipoSala.getDescSala()<<" NO TUVO VENTAS"<<endl;
        }
        else cout<<tipoSala.getDescSala()<<" - RECAUDO : $"<<AcumPorTipo<<endl;
    }
}
void CantEntradasVendidasPorPelicula()
{
    ArchivoVentaEntrada arcVenta;
    ArchivoPeliculas arcPeli;
    Pelicula pel;
    VentaEntrada venta;
    ArchivoFuncion arcFunc;
    Funcion func;
    int cantRegPeli=arcPeli.contarRegistros();
    int cantRegVenta = arcVenta.contarRegistros();
    for (int i=0; i<cantRegPeli; i++)
    {
        // Reiniciamos el acumulador y la marca de ventas para cada película.
        // Recorremos todas las ventas antes de mostrar el total de esa película.
        pel = arcPeli.leerRegistro(i);
        int CantPorPeli=0;
        bool hayVenta = false;
        int idPeli = pel.getIdPelicula();
        for (int j = 0; j < cantRegVenta; j++)
        {
            venta = arcVenta.leerRegistro(j);
            // La venta guarda el ID de la función. La función guarda el ID de la película.
            int pos = arcFunc.buscarRegistro(venta.getIdFuncion());
            if (pos >= 0)
            {
                func = arcFunc.leerRegistro(pos);
                if (func.getIdPelicula() == idPeli)
                {

                    CantPorPeli+=venta.getCantEntradasVendidas();
                    hayVenta = true;
                }
            }
        }
        if (!hayVenta)
        {
            cout <<pel.getNombrePelicula()<<" NO TUVO VENTAS"<<endl;
        }
        else cout << pel.getNombrePelicula() << " - ENTRADAS VENDIDAS: " << CantPorPeli << endl;
    }

}
void CantEntradasVendidasPorGenero()
{
    ArchivoVentaEntrada arcVenta;
    VentaEntrada venta;
    ArchivoTipoGenero arcGenero;
    TipoGenero genero;
    ArchivoPeliculas arcPeli;
    Pelicula peli;
    ArchivoFuncion arcFunc;
    Funcion func;
    int cantRegTipoGenero=arcGenero.contarRegistros();
    int cantRegVenta = arcVenta.contarRegistros();
    for (int i=0; i<cantRegTipoGenero; i++)
    {
        // Reiniciamos el acumulador y la marca de ventas para cada tipo de genero
        // Recorremos todas las ventas antes de mostrar el total de cada genero
        genero = arcGenero.leerRegistro(i);
        int CantPorTipo=0;
        bool hayVenta = false;
        int idTipo=genero.getTipoGenero();
        for (int j = 0; j < cantRegVenta; j++)
        {
            venta = arcVenta.leerRegistro(j);
            // La venta guarda el ID de la función. La función guarda el id de pelicula
            int posFunc = arcFunc.buscarRegistro(venta.getIdFuncion());
            if (posFunc >= 0)
            {
                func = arcFunc.leerRegistro(posFunc);
                // Buscamos la película por su ID en el archivo de películas.
                // Al leer ese registro, podemos comparar su género con el que estamos totalizando.
                int posPeli=arcPeli.buscarRegistro(func.getIdPelicula());
                if (posPeli>=0)
                {
                    peli=arcPeli.leerRegistro(posPeli);
                    if (peli.getTipoGenero()==idTipo)
                    {
                        CantPorTipo+=venta.getCantEntradasVendidas();
                        hayVenta = true;
                    }
                }
            }
        }
        if (!hayVenta)
        {
            cout <<genero.getNombreGenero()<<" NO TUVO VENTAS"<<endl;
        }
        else cout<<genero.getNombreGenero()<<" - ENTRADAS VENDIDAS: "<<CantPorTipo<<endl;
    }

}
//// Funcion auxiliar para contar cantidad de entradas vendidas por funcion
//int contarEntradasVendidasPorFuncion(int idFuncion)
//{
//    ArchivoVentaEntrada arc;
//    VentaEntrada venta;
//    int cantReg = arc.contarRegistros();
//    int entradasVendidas=0;
//    // Sumamos las entradas de cada compra de esta función. En la misma sala puede haber otras funciones.
//    for (int i = 0; i < cantReg; i++)
//    {
//        venta = arc.leerRegistro(i);
//        if (venta.getIdFuncion() == idFuncion)
//        {
//            entradasVendidas += venta.getCantEntradasVendidas();
//        }
//    }
//    return entradasVendidas;
//}
void PorcentajeOcupacionFuncYSala()
{
    ArchivoFuncion arcFunc;
    Funcion func;
    ArchivoSala arcSala;
    Sala sala;
    int cantReg=arcFunc.contarRegistros();
    for (int i=0; i<cantReg; i++)
    {
        func=arcFunc.leerRegistro(i);
        // Buscamos la sala por su número para obtener la posición del registro y leer su capacidad.
        int posSala = arcSala.buscarRegistro(func.getNumSala());
        if (posSala>=0)
        {
            sala=arcSala.leerRegistro(posSala);
            if (sala.getCapacidadTotal()>0)
            {
                float porcentaje= 100.0*contarEntradasVendidasPorFuncion(func.getIdFuncion())/sala.getCapacidadTotal();
                cout<<func.getIdFuncion()<<" - "<<func.getNumSala()<<" - "<<porcentaje<<"% de ocupacion"<<endl;
            }
        }
    }
}
void CantTotalEntradasVendidasPorSala()
{
    ArchivoSala arcSala;
    Sala sala;
    ArchivoFuncion arcFunc;
    Funcion func;
    int cantRegSala = arcSala.contarRegistros();
    int cantRegFunc=arcFunc.contarRegistros();
    for (int i=0; i<cantRegSala; i++)
    {
        int totalEntradasSala=0;
        sala=arcSala.leerRegistro(i);
        int idSala=sala.getNumSala();
        // Recorremos las funciones de la sala y sumamos una vez el total de entradas de cada una.
        for (int j=0; j<cantRegFunc; j++)
        {
            func=arcFunc.leerRegistro(j);
            if (func.getNumSala()==idSala)
            {
                totalEntradasSala+=contarEntradasVendidasPorFuncion(func.getIdFuncion());
            }
        }
        cout<<"SALA "<<sala.getNumSala()<<" - "<<totalEntradasSala<<endl;
    }
}

