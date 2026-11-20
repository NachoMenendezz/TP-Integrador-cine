#ifndef ARCHIVOSALA_H_INCLUDED
#define ARCHIVOSALA_H_INCLUDED#include "clsSala.h"class ArchivoSala {private:    char nombreArchivo[30];public:    ArchivoSala(const char *n = "Salas.dat");    Sala leerRegistro(int pos);    int contarRegistros();    bool grabarRegistro(Sala obj);    bool modificarRegistro(Sala obj, int pos);    int buscarRegistro(int id);    void listarRegistros();};
#endif // ARCHIVOSALA_H_INCLUDED
