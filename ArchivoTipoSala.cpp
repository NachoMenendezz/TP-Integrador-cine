#include <iostream>
#include <cstring>
#include "ArchivoTipoSala.h"

using namespace std;

ArchivoTipoSala::ArchivoTipoSala(const char *n) {
    strcpy(nombreArchivo, n);
}

TipoSala ArchivoTipoSala::leerRegistro(int pos) {
    FILE *p = fopen(nombreArchivo, "rb");
    TipoSala obj;
    if (p == nullptr) {
        obj.setTipoSala(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoTipoSala::contarRegistros() {
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(TipoSala);
}

bool ArchivoTipoSala::grabarRegistro(TipoSala obj) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoTipoSala::modificarRegistro(TipoSala obj, int pos) {
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

int ArchivoTipoSala::buscarRegistro(int id) {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        TipoSala obj = leerRegistro(i);
        if (obj.getTipoSala() == id) return i;
    }
    return -1;
}

void ArchivoTipoSala::listarRegistros() {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        TipoSala obj = leerRegistro(i);
        if (obj.getEstado()) {
            obj.Mostrar();
            cout << "************************" << endl;
        }
    }
}

// Devuelve el mayor código de tipo de sala registrado más uno.
// Incluye los tipos dados de baja para evitar reutilizar sus códigos.
int ArchivoTipoSala::generarId() {
    int maxId = 0;
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        TipoSala obj = leerRegistro(i);

        if (obj.getTipoSala() > maxId) {
            maxId = obj.getTipoSala();
        }
    }

    return maxId + 1;
}

// Busca un tipo de sala activo con la misma descripción.
// Al modificar, excluye el tipo de sala que se está editando.
bool ArchivoTipoSala::existeDescripcionActiva(const char *descripcion, int idExcluir) {
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        TipoSala obj = leerRegistro(i);

        if (obj.getEstado() &&
            obj.getTipoSala() != idExcluir &&
            strcmp(obj.getDescSala(), descripcion) == 0) {
            return true;
        }
    }

    return false;
}
