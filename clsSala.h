#ifndef CLSSALA_H_INCLUDED
#define CLSSALA_H_INCLUDED

class Sala {
private:
    int numSala;
    int tipoSala;
    int capacidadTotal;
    bool estado;

public:
    // Constructor
    Sala();

    // Setters
    void setNumSala(int);
    void setTipoSala(int);
    void setCapacidadTotal(int);
    void setEstado(bool);

    // Getters
    int getNumSala();
    int getTipoSala();
    int getCapacidadTotal();
    bool getEstado();

    void Cargar();
    void Mostrar();
};

#endif // CLSSALA_H_INCLUDED
