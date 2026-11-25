
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
    int importeTotal;

public:
    // Constructor
    VentaEntrada();

    // Setters
    void setIdVenta(int);
    void setIdFuncion(int);
    void setDiaCompra(Fecha);
    void setDniComprador(int);
    void setCantEntradasVendidas(int);
    void setImporteTotal(int);

    // Getters
    int getIdVenta();
    int getIdFuncion();
    Fecha getDiaCompra();
    int getDniComprador();
    int getCantEntradasVendidas();
    int getImporteTotal();
    void Mostrar();
};

#endif // CLSVENTAENTRADA_H_INCLUDED
