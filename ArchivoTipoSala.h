#ifndef ARCHIVOTIPOSALA_H_INCLUDED
#define ARCHIVOTIPOSALA_H_INCLUDED
#include "clsTipoSala.h"

class ArchivoTipoSala {
private:
    char nombreArchivo[30];

public:
    ArchivoTipoSala(const char *n = "TipoSala.dat");

    TipoSala leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(TipoSala obj);
    bool modificarRegistro(TipoSala obj, int pos);
    int buscarRegistro(int id);
    void listarRegistros();
    int generarId();
    bool existeDescripcionActiva(const char *descripcion, int idExcluir = -1);
};

#endif // ARCHIVOTIPOSALA_H_INCLUDED
