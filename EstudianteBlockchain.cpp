#include "EstudianteBlockchain.h"

EstudianteBlockchain::EstudianteBlockchain(std::string nombre, int edad) : Estudiante(nombre, edad) {
    this->fuerzaBrazos = rand() % 11;
    setOverall(getOverall() + fuerzaBrazos);
}

EstudianteBlockchain::~EstudianteBlockchain() {
}

int EstudianteBlockchain::getFuerzaBrazos() {
    return fuerzaBrazos;
}

void EstudianteBlockchain::setFuerzaBrazos(int fuerzaBrazos) {
    this->fuerzaBrazos = fuerzaBrazos;
    setOverall(getOverall() + fuerzaBrazos);
}

double EstudianteBlockchain::setOverall(int overall) {
    this->overall = overall;

}
int EstudianteBlockchain::getResistencia() const {
    // Implementación del método
    return resistencia;
}
double EstudianteBlockchain::restarResistencia(int cantidad) {
    // Calcular la resistencia total según el nivel de cinta
    double resistenciaTotal = resistencia * nivelCinta;

    // Restar la cantidad de resistencia recibida
    resistenciaTotal -= cantidad;

    // Actualizar la resistencia del estudiante
    resistencia = resistenciaTotal / nivelCinta;

    // Verificar si la resistencia es menor o igual a cero
    if (resistencia <= 0) {
        resistencia = 0;
    }

    // Devolver la resistencia actualizada
    return resistencia;
}

 
