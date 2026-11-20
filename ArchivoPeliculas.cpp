#include <iostream>
#include <cstring>
#include "ArchivoPeliculas.h"

using namespace std;

ArchivoPeliculas::ArchivoPeliculas(const char *n) {
    strcpy(nombreArchivo, n);
}

Pelicula ArchivoPeliculas::leerRegistro(int pos) {
    FILE *p = fopen(nombreArchivo, "rb");
    Pelicula obj;
    if (p == nullptr) {
        obj.setIdPelicula(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoPeliculas::contarRegistros() {
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Pelicula);
}

bool ArchivoPeliculas::grabarRegistro(Pelicula obj) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoPeliculas::modificarRegistro(Pelicula obj, int pos) {
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

int ArchivoPeliculas::buscarRegistro(int id) {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        Pelicula obj = leerRegistro(i);
        if (obj.getIdPelicula() == id) return i;
    }
    return -1;
}

void ArchivoPeliculas::listarRegistros() {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        Pelicula obj = leerRegistro(i);
        if (obj.getEstado()) {
            obj.Mostrar();
            cout << "************************" << endl;
        }
    }
}
