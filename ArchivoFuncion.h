#ifndef ARCHIVOFUNCION_H_INCLUDED
#define ARCHIVOFUNCION_H_INCLUDED#include "clsFuncion.h"
class ArchivoFuncion {private:    char nombreArchivo[30];public:    ArchivoFuncion(const char *n = "Funciones.dat");    Funcion leerRegistro(int pos);    int contarRegistros();    bool grabarRegistro(Funcion obj);    bool modificarRegistro(Funcion obj, int pos);    int buscarRegistro(int id);    void listarRegistros();
    int generarId();};


#endif // ARCHIVOFUNCION_H_INCLUDED
