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

void consultarPeliculasPorGenero()
{
    bool mostroPelicula=false;
    int id=seleccionarGenero();
    if (id==-1)
    {
        return;
    }
    ArchivoPeliculas arc;
    Pelicula obj;
    int cantReg = arc.contarRegistros();
    for (int i=0; i<cantReg; i++)
    {
        obj=arc.leerRegistro(i);
        if (obj.getEstado() && obj.getTipoGenero() == id)
        {
            mostroPelicula=true;
            obj.Mostrar();
        }
    }
    if (!mostroPelicula){
        cout<<"NO HAY PELICULAS ACTIVAS CON ESE GENERO";
    }
}

void consultarPeliculasPorNombre(){
char nombreBuscado[50];
bool mostroPelicula=false;
cout<<"INGRESE NOMBRE DE LA PELICULA:"<<endl;
cin.ignore();
cin.getline(nombreBuscado,50);
ArchivoPeliculas arc;
Pelicula obj;
int cantReg=arc.contarRegistros();
for (int i=0;i<cantReg;i++){
    obj=arc.leerRegistro(i);
    if (obj.getEstado()&&strcmp(obj.getNombrePelicula(), nombreBuscado) == 0){
        mostroPelicula=true;
        obj.Mostrar();
    }
}
if (!mostroPelicula){cout<<"NO HAY PELICULAS ACTIVAS CON ESE NOMBRE";}
}
void consultarSalasPorNumeroSala(){
int numBuscado;
bool mostroSala=false;
cout<<"INGRESE NUMERO DE SALA: ";
cin>>numBuscado;
ArchivoSala arc;
Sala obj;
int pos = arc.buscarRegistro(numBuscado);
if (pos >= 0) {
    obj = arc.leerRegistro(pos);
    if (obj.getEstado()) {
        mostroSala = true;
        obj.Mostrar();
    }
}
if (!mostroSala){cout<<"NO EXISTEN SALAS CON ESE NUMERO";}
}
void consultarSalasPorTipoSala(){
bool mostroSala=false;
    int id=seleccionarTipoSala();
    if (id==-1)
    {
        return;
    }
    ArchivoSala arc;
    Sala obj;
    int cantReg = arc.contarRegistros();
    for (int i=0; i<cantReg; i++)
    {
        obj=arc.leerRegistro(i);
        if (obj.getEstado() && obj.getTipoSala() == id)
        {
            mostroSala=true;
            obj.Mostrar();
        }
    }
    if (!mostroSala){
        cout<<"NO HAY SALAS ACTIVAS CON ESE TIPO";
    }
}
void consultarFuncionesPorFecha(){
ArchivoFuncion arc;
Funcion obj;
Fecha fechaBuscada;
bool mostroFuncion=false;
cout<<"INGRESE FECHA DE FUNCION: "<<endl;
fechaBuscada.Cargar();
if (!fechaBuscada.esValida()) {
    cout << "LA FECHA INGRESADA NO ES VALIDA" << endl;
    return;
}
int cantReg=arc.contarRegistros();
for (int i = 0; i < cantReg; i++) {
    obj = arc.leerRegistro(i);
    Fecha fechaFuncion = obj.getFechaFuncion();

    if (obj.getEstado()
        && fechaFuncion.getDia() == fechaBuscada.getDia()
        && fechaFuncion.getMes() == fechaBuscada.getMes()
        && fechaFuncion.getAnio() == fechaBuscada.getAnio()) {
        mostroFuncion = true;
        obj.Mostrar();
    }
}
if (!mostroFuncion){cout<<"NO EXISTEN FUNCIONES ACTIVAS EN ESA FECHA";}
}

void consultarFuncionesPorPelicula(){
int id=seleccionarPelicula();
bool mostroFuncion=false;
if (id==-1){return;}
ArchivoFuncion arc;
Funcion obj;
int cantReg=arc.contarRegistros();
for (int i=0;i<cantReg;i++){
    obj = arc.leerRegistro(i);
    if (obj.getEstado()&& obj.getIdPelicula()== id){
        obj.Mostrar();
        mostroFuncion=true;
    }
}
if (!mostroFuncion){cout<<"NO EXISTEN FUNCIONES ACTIVAS PARA ESA PELICULA";}
}
void consultarFuncionesPorSala(){
int numSala=seleccionarSala();
bool mostroFuncion=false;
if (numSala==-1){return;}
ArchivoFuncion arc;
Funcion obj;
int cantReg=arc.contarRegistros();
for (int i=0;i<cantReg;i++){
    obj=arc.leerRegistro(i);
    if (obj.getEstado()&&obj.getNumSala()==numSala){
        obj.Mostrar();
        mostroFuncion=true;
    }
}
if (!mostroFuncion){cout<<"NO HAY FUNCIONES ACTIVAS EN ESA SALA";}
}
void consultarFuncionesPorDisponibilidad(){
int id=seleccionarFuncion();
if (id==-1){return;}
ArchivoFuncion arc;
Funcion func;
Sala sala;
ArchivoSala arc2;
ArchivoVentaEntrada arc3;
int entradasVendidas=0;
int pos=arc.buscarRegistro(id);
if (pos>=0){func=arc.leerRegistro(pos);}
int posSala=arc2.buscarRegistro(func.getNumSala());
if (posSala>=0)
    {
        VentaEntrada venta;
        sala=arc2.leerRegistro(posSala);
        if (!sala.getEstado()){
            cout<<"LA SALA DE LA FUNCION ESTA DADA DE BAJA";
            return;
        }
        int cantReg=arc3.contarRegistros();
        for (int i=0;i<cantReg;i++){
         venta=arc3.leerRegistro(i);
         if (venta.getIdFuncion()==id){
            entradasVendidas+=venta.getCantEntradasVendidas();
         }
        }
        cout<<"LA FUNCION "<<id<<" TIENE "<<sala.getCapacidadTotal()-entradasVendidas<<" BUTACAS DISPONIBLES";
}
}

void consultarClientesPorDni(){
ArchivoCliente arc;
Cliente obj;
int dniBuscado;
cout<<"INGRESE NUMERO DE DNI: ";
cin>>dniBuscado;
int pos=arc.buscarRegistro(dniBuscado);
if (pos>=0){
    obj=arc.leerRegistro(pos);
    obj.Mostrar();
}
else cout<<"NO EXISTE CLIENTE CON ESE DNI"<<endl;


}
void consultarClientesPorNombreApellido(){
char nombreBuscado[50];
bool mostroCliente=false;
cout<<"INGRESE NOMBRE Y APELLIDO DEL CLIENTE:"<<endl;
cin.ignore();
cin.getline(nombreBuscado,50);
ArchivoCliente arc;
Cliente obj;
int cantReg=arc.contarRegistros();
for (int i=0;i<cantReg;i++){
    obj=arc.leerRegistro(i);
    if (strcmp(obj.getNombreApellido(), nombreBuscado) == 0){
        mostroCliente=true;
        obj.Mostrar();
    }
}
if (!mostroCliente){cout<<"NO HAY CLIENTES CON ESE NOMBRE";}
}
void consultarVentasPorRangoFecha(){
cout<<"INGRESE FECHA DESDE:"<<endl;
Fecha fechaDesde;
fechaDesde.Cargar();
cout<<"INGRESE FECHA HASTA:"<<endl;
Fecha fechaHasta;
fechaHasta.Cargar();

}
void consultarVentasPorDni();
void consultarVentasPorFuncion();
void consultarVentasPorPelicula();

