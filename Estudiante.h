#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Cinta.h"
#include <string>
using namespace std;
class Estudiante {
private:
    string nombre;
    int edad;
    int fuerza;
    int resistencia;
    int overall;
    int vida;
    Cinta* cinta;

public:
    Estudiante(const string& nombre, int edad, Cinta* cinta);
    void generarAtributosAleatorios();
    void calcularOverall();
    void mostrarInformacion();
    void recibirAtaque(int ataque);
    void otorgarAscenso();
    void otorgarDescenso();
    int getOverall() const;
    int getVida() const;
    std::string getNombre() const;
};

#endif


