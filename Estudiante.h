#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include "Cinta.h"
class Estudiante {
protected:
    std::string nombre;
    int edad;
    int vida;
    Cinta cinta;

public:
    Estudiante(const std::string& nombre, int edad, const Cinta& cinta);
    virtual ~Estudiante();

    std::string getNombre() const;
    int getEdad() const;
    int getVida() const;
    Cinta getCinta() const;
    void setVida(int vida);

    virtual int getOverall() const = 0;
    virtual int getResistencia() const = 0;
    virtual double getPorcentajeAtaque() const = 0;
    virtual double getPorcentajeDefensa() const = 0;

    int calcularAtaque() const;
    int calcularDefensa() const;
    void recibirAtaque(int ataque);
};

#endif