#include "Dojo.h"
#include "Dojo.h"
#include <iostream>

Dojo::Dojo() {}

Dojo::~Dojo() {
    for (Estudiante* estudiante : estudiantes) {
        delete estudiante;
    }
    estudiantes.clear();
}

void Dojo::agregarEstudiante(Estudiante* estudiante) {
    estudiantes.push_back(estudiante);
}

void Dojo::modificarEstudiante(int indice, Estudiante* estudiante) {
    if (indice >= 0 && indice < estudiantes.size()) {
        delete estudiantes[indice];
        estudiantes[indice] = estudiante;
    }
}

void Dojo::eliminarEstudiante(int indice) {
    if (indice >= 0 && indice < estudiantes.size()) {
        delete estudiantes[indice];
        estudiantes.erase(estudiantes.begin() + indice);
    }
}

void Dojo::mostrarEstudiantes() const {
    for (int i = 0; i < estudiantes.size(); i++) {
        std::cout << "Estudiante " << i + 1 << ":" << std::endl;
        estudiantes[i]->mostrarInformacion();
        std::cout << std::endl;
    }
}

Estudiante* Dojo::getEstudiante(int indice) const {
    if (indice >= 0 && indice < estudiantes.size()) {
        return estudiantes[indice];
    }
    return nullptr;
}

int Dojo::getCantidadEstudiantes() const {
    return estudiantes.size();
}
