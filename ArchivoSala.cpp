#include <iostream>#include <cstring>#include "ArchivoSala.h"using namespace std;ArchivoSala::ArchivoSala(const char *n) {    strcpy(nombreArchivo, n);}Sala ArchivoSala::leerRegistro(int pos) {    FILE *p = fopen(nombreArchivo, "rb");    Sala obj;    if (p == nullptr) {        obj.setNumSala(-1);        return obj;    }    fseek(p, pos * sizeof obj, 0);    fread(&obj, sizeof obj, 1, p);    fclose(p);    return obj;}int ArchivoSala::contarRegistros() {    FILE *p = fopen(nombreArchivo, "rb");    if (p == nullptr) {        return 0;    }    fseek(p, 0, 2);    int bytes = ftell(p);    fclose(p);    return bytes / sizeof(Sala);}bool ArchivoSala::grabarRegistro(Sala obj) {    FILE *p = fopen(nombreArchivo, "ab");    if (p == nullptr) {        return false;    }    bool escribio = fwrite(&obj, sizeof obj, 1, p);    fclose(p);    return escribio;}bool ArchivoSala::modificarRegistro(Sala obj, int pos) {    FILE *p = fopen(nombreArchivo, "rb+");    if (p == nullptr) {        return false;    }    fseek(p, pos * sizeof obj, 0);    bool modifico = fwrite(&obj, sizeof obj, 1, p);    fclose(p);    return modifico;}int ArchivoSala::buscarRegistro(int id) {    int cantReg = contarRegistros();    for (int i = 0; i < cantReg; i++) {        Sala obj = leerRegistro(i);        if (obj.getNumSala() == id) return i;    }    return -1;}void ArchivoSala::listarRegistros() {    int cantReg = contarRegistros();    for (int i = 0; i < cantReg; i++) {        Sala obj = leerRegistro(i);        if (obj.getEstado()) {            obj.Mostrar();            cout << "************************" << endl;        }    }}
// Devuelve el mayor número de sala registrado más uno.
// Incluye las salas dadas de baja para evitar reutilizar sus números.
int ArchivoSala::generarId() {
    int maxId = 0;
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        Sala obj = leerRegistro(i);

        if (obj.getNumSala() > maxId) {
            maxId = obj.getNumSala();
        }
    }

    return maxId + 1;
}
