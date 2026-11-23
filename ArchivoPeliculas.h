#ifndef ARCHIVOPELICULAS_H_INCLUDED
#define ARCHIVOPELICULAS_H_INCLUDED

#include "clsPelicula.h"

class ArchivoPeliculas {
private:
    char nombreArchivo[30];

public:
    ArchivoPeliculas(const char *n = "Peliculas.dat");

    Pelicula leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Pelicula obj);
    bool modificarRegistro(Pelicula obj, int pos);
    int buscarRegistro(int id);
    void listarRegistros();
    int generarId();
};

#endif // ARCHIVOPELICULAS_H_INCLUDED
