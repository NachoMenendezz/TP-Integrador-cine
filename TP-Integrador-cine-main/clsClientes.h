#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
class Cliente {private:    int DNI;    char NombreApellido[50];    int Telefono;    bool Estado;public:    // Constructor    Cliente();    // Setters    void setDNI(int);    void setNombreApellido(const char *);    void setTelefono(int);    void setEstado(bool);    // Getters    int getDNI();    const char *getNombreApellido();    int getTelefono();    bool getEstado();    void Cargar();    void Mostrar();};


#endif // CLSCLIENTES_H_INCLUDED
