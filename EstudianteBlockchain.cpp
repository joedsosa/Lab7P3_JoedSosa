#include "EstudianteBlockchain.h"
#include <iostream>

EstudianteBlockchain::EstudianteBlockchain(const std::string& nombre, int edad, const std::string& colorCinta, int nivelCinta)
    : Estudiante(nombre, edad), cinta(colorCinta, nivelCinta) {}

Cinta EstudianteBlockchain::getCinta() const {
    return cinta;
}

void EstudianteBlockchain::setCinta(const Cinta& cinta) {
    this->cinta = cinta;
}

void EstudianteBlockchain::mostrarInformacion() const {
    Estudiante::mostrarInformacion();
    std::cout << "Dojo: Blockchain" << std::endl;
    std::cout << "Cinta: " << cinta.getColor() << " (Nivel " << cinta.getNivel() << ")" << std::endl;
}
