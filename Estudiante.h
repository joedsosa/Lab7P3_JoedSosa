#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include "Cinta.h"

class Estudiante {
protected: 
    std::string nombre;
    int edad;
    Cinta* cinta;
    int fuerza;
    int resistencia;
    int overall;
    const int vida = 100;
    int nivelCinta;

public:
    Estudiante(std::string nombre, int edad);
    virtual ~Estudiante();
    void actualizarColorCinta();

    
    std::string getNombre();
    void setNombre(std::string nombre);

    int getEdad();
    void setEdad(int edad);

    Cinta* getCinta();
    void setCinta(Cinta* cinta);

    int getFuerza();
    void setFuerza(int fuerza);

    int getResistencia();
    void setResistencia(int resistencia);
    Estudiante& operator++();  
    Estudiante& operator--();  
    int getOverall();

    int getVida();
};

#endif  // ESTUDIANTE_H
