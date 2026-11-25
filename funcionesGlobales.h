#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
#include "clsFecha.h"

int seleccionarGenero();
int seleccionarPelicula();
int seleccionarSala();
int seleccionarTipoSala();
int seleccionarFuncion();
bool esPosterior(Fecha fec1, Fecha fec2);
int contarEntradasVendidasPorFuncion(int idFuncion);
#endif // FUNCIONESGLOBALES_H_INCLUDED
