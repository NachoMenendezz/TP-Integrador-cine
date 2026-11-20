#ifndef ARCHIVOTIPOGENERO_H_INCLUDED
#define ARCHIVOTIPOGENERO_H_INCLUDED
#include "clsTipoGenero.h"class ArchivoTipoGenero {private:    char nombreArchivo[30];public:    ArchivoTipoGenero(const char *n = "TipoGenero.dat");    TipoGenero leerRegistro(int pos);    int contarRegistros();    bool grabarRegistro(TipoGenero obj);    bool modificarRegistro(TipoGenero obj, int pos);    int buscarRegistro(int id);    void listarRegistros();};
#endif // ARCHIVOTIPOGENERO_H_INCLUDED
