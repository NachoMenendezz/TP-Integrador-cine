#include <iostream>
#include <cstring>
#include "ArchivoVentaEntrada.h"

using namespace std;

ArchivoVentaEntrada::ArchivoVentaEntrada(const char *n) {
    strcpy(nombreArchivo, n);
}

VentaEntrada ArchivoVentaEntrada::leerRegistro(int pos) {
    FILE *p = fopen(nombreArchivo, "rb");
    VentaEntrada obj;
    if (p == nullptr) {
        obj.setIdVenta(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoVentaEntrada::contarRegistros() {
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(VentaEntrada);
}

bool ArchivoVentaEntrada::grabarRegistro(VentaEntrada obj) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoVentaEntrada::modificarRegistro(VentaEntrada obj, int pos) {
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool modifico = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return modifico;
}

int ArchivoVentaEntrada::buscarRegistro(int id) {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        VentaEntrada obj = leerRegistro(i);
        if (obj.getIdVenta() == id) return i;
    }
    return -1;
}

void ArchivoVentaEntrada::listarRegistros() {
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        VentaEntrada obj = leerRegistro(i);
        obj.Mostrar();
        cout << "************************" << endl;
    }
}

// Devuelve el mayor ID de venta registrado más uno.
// Si todavía no hay ventas, el primer ID es 1.
int ArchivoVentaEntrada::generarId() {
    int maxId = 0;
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        VentaEntrada obj = leerRegistro(i);

        if (obj.getIdVenta() > maxId) {
            maxId = obj.getIdVenta();
        }
    }

    return maxId + 1;
}
