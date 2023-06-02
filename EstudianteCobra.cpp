#include "EstudianteCobra.h"

EstudianteCobra::EstudianteCobra(const std::string& nombre, int edad, Cinta* cinta)
    : Estudiante(nombre, edad, cinta), fuerzaPiernas(0) {
    generarAtributos();
}

void EstudianteCobra::generarAtributos() {
    // Generar valores aleatorios para fuerza y resistencia
    fuerza = rand() % 31;
    resistencia = rand() % 31;
    overall = fuerza + fuerzaPiernas;
}

int EstudianteCobra::getFuerzaPiernas() const {
    return fuerzaPiernas;
}

void EstudianteCobra::setFuerzaPiernas(int fuerzaPiernas) {
    this->fuerzaPiernas = fuerzaPiernas;
    // Recalcular el overall cuando se modifica la fuerza de las piernas
    overall = fuerza + fuerzaPiernas;
}
