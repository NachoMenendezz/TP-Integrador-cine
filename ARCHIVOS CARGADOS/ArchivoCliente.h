#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
#include "clsClientes.h"

class ArchivoCliente {
private:
    char nombreArchivo[30];

public:
    ArchivoCliente(const char *n = "Clientes.dat");

    Cliente leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Cliente obj);
    bool modificarRegistro(Cliente obj, int pos);
    int buscarRegistro(int id);
    void listarRegistros();
};

#endif // ARCHIVOCLIENTE_H_INCLUDED
