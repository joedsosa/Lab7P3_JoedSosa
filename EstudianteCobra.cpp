#include "EstudianteCobra.h"
#include <iostream>

EstudianteCobra::EstudianteCobra(const std::string& nombre, int edad, const std::string& colorCinta, int nivelCinta)
    : Estudiante(nombre, edad), cinta(colorCinta, nivelCinta) {}

Cinta EstudianteCobra::getCinta() const {
    return cinta;
}

void EstudianteCobra::setCinta(const Cinta& cinta) {
    this->cinta = cinta;
}

void EstudianteCobra::mostrarInformacion() const {
    Estudiante::mostrarInformacion();
    std::cout << "Dojo: Cobra" << std::endl;
    std::cout << "Cinta: " << cinta.getColor() << " (Nivel " << cinta.getNivel() << ")" << std::endl;
}