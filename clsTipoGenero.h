#ifndef CLSTIPOGENERO_H_INCLUDED
#define CLSTIPOGENERO_H_INCLUDED

class TipoGenero {
private:
    int tipoGenero;
    char nombreGenero[50];
    bool estado;

public:
    // Constructor
    TipoGenero();

    // Setters
    void setTipoGenero(int);
    void setNombreGenero(const char *);
    void setEstado(bool);

    // Getters
    int getTipoGenero();
    const char *getNombreGenero();
    bool getEstado();

    void Cargar();
    void Mostrar();
};

#endif // CLSTIPOGENERO_H_INCLUDED
