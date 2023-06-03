#include "Estudiante.h"

Estudiante::Estudiante(std::string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
    this->cinta = nullptr;
    this->fuerza = rand() % 31;
    this->resistencia = rand() % 31;
    this->overall = fuerza + resistencia;
}

Estudiante::~Estudiante() {
    delete cinta;
}

std::string Estudiante::getNombre() {
    return nombre;
}

void Estudiante::setNombre(std::string nombre) {
    this->nombre = nombre;
}

int Estudiante::getEdad() {
    return edad;
}

void Estudiante::setEdad(int edad) {
    this->edad = edad;
}

Cinta* Estudiante::getCinta() {
    return cinta;
}

void Estudiante::setCinta(Cinta* cinta) {
    this->cinta = cinta;
}

int Estudiante::getFuerza() {
    return fuerza;
}

void Estudiante::setFuerza(int fuerza) {
    this->fuerza = fuerza;
}

int Estudiante::getResistencia() {
    return resistencia;
}

void Estudiante::setResistencia(int resistencia) {
    this->resistencia = resistencia;
}

int Estudiante::getOverall() {
    return overall;
}

int Estudiante::getVida() {
    return vida;
}

Estudiante& Estudiante::operator++() {
    if (cinta->getNivel() < 7) {
        cinta->setNivel(cinta->getNivel() + 1);
        actualizarColorCinta();
    }
    return *this;
}
void Estudiante::actualizarColorCinta() {
    switch (cinta->getNivel()) {
    case 1:
        cinta->setColorCinta("Blanco");
        break;
    case 2:
        cinta->setColorCinta("Amarillo");
        break;
    case 3:
        cinta->setColorCinta("Naranja");
        break;
    case 4:
        cinta->setColorCinta("Verde");
        break;
    case 5:
        cinta->setColorCinta("Azul");
        break;
    case 6:
        cinta->setColorCinta("Marrón");
        break;
    case 7:
        cinta->setColorCinta("Negro");
        break;
    default:
        cinta->setColorCinta("Desconocido");
        break;
    }
}

Estudiante& Estudiante::operator--() {
    if (cinta->getNivel() > 1) {
        cinta->setNivel(cinta->getNivel() - 1);
        actualizarColorCinta();
    }
    return *this;
}
