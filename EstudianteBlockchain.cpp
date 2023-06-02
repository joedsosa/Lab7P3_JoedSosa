#include "estudianteblockchain.h"

EstudianteBlockchain::EstudianteBlockchain(const std::string& nombre, int edad, Cinta* cinta)
    : Estudiante(nombre, edad, cinta), fuerzaBrazos(0) {
    generarAtributos();
}

void EstudianteBlockchain::generarAtributos() {
    // Generar valores aleatorios para fuerza y resistencia
    fuerza = rand() % 31;
    resistencia = rand() % 31;
    overall = fuerza + fuerzaBrazos;
}

int EstudianteBlockchain::getFuerzaBrazos() const {
    return fuerzaBrazos;
}

void EstudianteBlockchain::setFuerzaBrazos(int fuerzaBrazos) {
    this->fuerzaBrazos = fuerzaBrazos;
    // Recalcular el overall cuando se modifica la fuerza de los brazos
    overall = fuerza + fuerzaBrazos;
}
