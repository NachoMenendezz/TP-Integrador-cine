
#ifndef CLSFUNCION_H_INCLUDED
#define CLSFUNCION_H_INCLUDED

#include "clsFecha.h"

class Funcion {
private:
    int idFuncion;
    int idPelicula;
    int numSala;
    Fecha fechaFuncion;
    int horaFuncion;
    bool estado;

public:
    // Constructor
    Funcion();

    // Setters
    void setIdFuncion(int);
    void setIdPelicula(int);
    void setNumSala(int);
    void setFechaFuncion(Fecha);
    void setHoraFuncion(int);
    void setEstado(bool);

    // Getters
    int getIdFuncion();
    int getIdPelicula();
    int getNumSala();
    Fecha getFechaFuncion();
    int getHoraFuncion();
    bool getEstado();

    void Cargar();
    void Mostrar();
};

#endif // CLSFUNCION_H_INCLUDED
