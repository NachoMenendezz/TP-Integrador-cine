
#ifndef CLSVENTAENTRADA_H_INCLUDED
#define CLSVENTAENTRADA_H_INCLUDED

#include "clsFecha.h"

class VentaEntrada {
private:
    int idVenta;
    int idFuncion;
    Fecha diaCompra;
    int dniComprador;
    int cantEntradasVendidas;

public:
    // Constructor
    VentaEntrada();

    // Setters
    void setIdVenta(int);
    void setIdFuncion(int);
    void setDiaCompra(Fecha);
    void setDniComprador(int);
    void setCantEntradasVendidas(int);

    // Getters
    int getIdVenta();
    int getIdFuncion();
    Fecha getDiaCompra();
    int getDniComprador();
    int getCantEntradasVendidas();

    void Cargar();
    void Mostrar();
};

#endif // CLSVENTAENTRADA_H_INCLUDED
