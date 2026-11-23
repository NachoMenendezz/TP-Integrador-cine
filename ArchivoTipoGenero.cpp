#include <iostream>#include <cstring>#include "ArchivoTipoGenero.h"using namespace std;ArchivoTipoGenero::ArchivoTipoGenero(const char *n) {    strcpy(nombreArchivo, n);}TipoGenero ArchivoTipoGenero::leerRegistro(int pos) {    FILE *p = fopen(nombreArchivo, "rb");    TipoGenero obj;    if (p == nullptr) {        obj.setTipoGenero(-1);        return obj;    }    fseek(p, pos * sizeof obj, 0);    fread(&obj, sizeof obj, 1, p);    fclose(p);    return obj;}int ArchivoTipoGenero::contarRegistros() {    FILE *p = fopen(nombreArchivo, "rb");    if (p == nullptr) {        return 0;    }    fseek(p, 0, 2);    int bytes = ftell(p);    fclose(p);    return bytes / sizeof(TipoGenero);}bool ArchivoTipoGenero::grabarRegistro(TipoGenero obj) {    FILE *p = fopen(nombreArchivo, "ab");    if (p == nullptr) {        return false;    }    bool escribio = fwrite(&obj, sizeof obj, 1, p);    fclose(p);    return escribio;}bool ArchivoTipoGenero::modificarRegistro(TipoGenero obj, int pos) {    FILE *p = fopen(nombreArchivo, "rb+");    if (p == nullptr) {        return false;    }    fseek(p, pos * sizeof obj, 0);    bool modifico = fwrite(&obj, sizeof obj, 1, p);    fclose(p);    return modifico;}int ArchivoTipoGenero::buscarRegistro(int id) {    int cantReg = contarRegistros();    for (int i = 0; i < cantReg; i++) {        TipoGenero obj = leerRegistro(i);        if (obj.getTipoGenero() == id) return i;    }    return -1;}void ArchivoTipoGenero::listarRegistros() {    int cantReg = contarRegistros();    for (int i = 0; i < cantReg; i++) {        TipoGenero obj = leerRegistro(i);        if (obj.getEstado()) {            obj.Mostrar();            cout << "************************" << endl;        }    }}
// Devuelve el mayor código de género registrado más uno.
// Incluye los géneros dados de baja para evitar reutilizar sus códigos.
int ArchivoTipoGenero::generarId() {
    int maxId = 0;
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        TipoGenero obj = leerRegistro(i);

        if (obj.getTipoGenero() > maxId) {
            maxId = obj.getTipoGenero();
        }
    }

    return maxId + 1;
}
