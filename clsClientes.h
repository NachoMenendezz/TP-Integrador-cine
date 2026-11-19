#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
class Cliente {private:    int dni;    char nombreApellido[50];    int telefono;public:    // Constructor    Cliente();    // Setters    void setDni(int);    void setNombreApellido(const char *);    void setTelefono(int);    // Getters    int getDni();    const char *getNombreApellido();    int getTelefono();    void Cargar();    void Mostrar();};


#endif // CLSCLIENTES_H_INCLUDED
