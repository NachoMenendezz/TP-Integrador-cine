#include <iostream>
#include <cstring>
#include "ArchivoCliente.h"

using namespace std;

ArchivoCliente::ArchivoCliente(const char *n) {
    strcpy(nombreArchivo, n);
}

Cliente ArchivoCliente::leerRegistro(int pos) {
    FILE *p = fopen(nombreArchivo, "rb");
    Cliente obj;
    if (p == nullptr) {
        obj.setDni(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoCliente::contarRegistros() {
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Cliente);
}

bool ArchivoCliente::grabarRegistro(Cliente obj) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoCliente::modificarRegistro(Cliente obj, int pos) {
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

int ArchivoCliente::buscarRegistro(int id) {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        Cliente obj = leerRegistro(i);
        if (obj.getDni() == id) return i;
    }
    return -1;
}

void ArchivoCliente::listarRegistros() {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        Cliente obj = leerRegistro(i);
        obj.Mostrar();
        cout << "************************" << endl;
    }
}
