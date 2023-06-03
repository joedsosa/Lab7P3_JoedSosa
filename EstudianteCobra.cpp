#include "EstudianteCobra.h"

EstudianteCobra::EstudianteCobra(std::string nombre, int edad) : Estudiante(nombre, edad) {
    this->fuerzaPiernas = rand() % 11;
    this->setOverall(this->getOverall() + fuerzaPiernas);
}

EstudianteCobra::~EstudianteCobra() {
}

int EstudianteCobra::getFuerzaPiernas() {
    return fuerzaPiernas;
}

void EstudianteCobra::setFuerzaPiernas(int fuerzaPiernas) {
    this->fuerzaPiernas = fuerzaPiernas;
    this->setOverall(this->getOverall() + fuerzaPiernas);
}
double EstudianteCobra::getOverall() const {
    // Implementación del método
    return overall;
}