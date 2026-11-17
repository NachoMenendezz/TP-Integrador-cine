#ifndef CLSFUNCION_H_INCLUDED
#define CLSFUNCION_H_INCLUDED
/*idFuncion: intidPelicula: intnumSala: intfechaFuncion: FechahoraFuncion: intestado: bool*/class Sala {private:    int idFunción;    int idPelicula;    numSala    char nombreSala[30];    int tipoSala;    int capacidadTotal;    bool estado;public:    // Constructor    Sala();    // Setters    void setNumSala(int);    void setNombreSala(const char *);    void setTipoSala(int);    void setCapacidadTotal(int);    void setEstado(bool);    // Getters    int getNumSala();    const char *getNombreSala();    int getTipoSala();    int getCapacidadTotal();    bool getEstado();    void Cargar();    void Mostrar();};


#endif // CLSFUNCION_H_INCLUDED
