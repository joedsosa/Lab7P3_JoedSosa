#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
using namespace std;
#include <iostream>
#include <string>
#include "cinta.h"
#include <string>
class Estudiante {
public:
    Estudiante(const string& nombre, int edad, Cinta* cinta);
    virtual ~Estudiante();

    string getNombre() const;
    int getEdad() const;
    Cinta* getCinta() const;
    int getFuerza() const;
    int getResistencia() const;
    int getOverall() const;
    int getVida() const;
    void mostrarInformacion() const;
    void setNombre(const string& nombre);
    void setEdad(int edad);
    void setCinta(Cinta* cinta);
    void setFuerza(int fuerza);
    void setResistencia(int resistencia);
    void setOverall(int overall);
    

    virtual void generarAtributos() = 0;

protected:
    string nombre;
    int edad;
    Cinta* cinta;
    int fuerza;
    int resistencia;
    int overall;
    const int vida;
};

#endif
