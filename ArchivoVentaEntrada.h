#ifndef ARCHIVOVENTAENTRADA_H_INCLUDED
#define ARCHIVOVENTAENTRADA_H_INCLUDED
#include "clsVentaEntrada.h"

class ArchivoVentaEntrada {
private:
    char nombreArchivo[30];

public:
    ArchivoVentaEntrada(const char *n = "VentasEntradas.dat");

    VentaEntrada leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(VentaEntrada obj);
    bool modificarRegistro(VentaEntrada obj, int pos);
    int buscarRegistro(int id);
    void listarRegistros();
};

#endif // ARCHIVOVENTAENTRADA_H_INCLUDED
