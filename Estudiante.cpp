#include "estudiante.h"

Estudiante::Estudiante(const std::string& nombre, int edad, Cinta* cinta)
    : nombre(nombre), edad(edad), cinta(cinta), fuerza(0), resistencia(0), overall(0), vida(100) {
}

Estudiante::~Estudiante() {
    delete cinta;
}

std::string Estudiante::getNombre() const {
    return nombre;
}

int Estudiante::getEdad() const {
    return edad;
}

Cinta* Estudiante::getCinta() const {
    return cinta;
}

int Estudiante::getFuerza() const {
    return fuerza;
}

int Estudiante::getResistencia() const {
    return resistencia;
}

int Estudiante::getOverall() const {
    return overall;
}

int Estudiante::getVida() const {
    return vida;
}

void Estudiante::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Estudiante::setEdad(int edad) {
    this->edad = edad;
}

void Estudiante::setCinta(Cinta* cinta) {
    this->cinta = cinta;
}

void Estudiante::setFuerza(int fuerza) {
    this->fuerza = fuerza;
}

void Estudiante::setResistencia(int resistencia) {
    this->resistencia = resistencia;
}

void Estudiante::setOverall(int overall) {
    this->overall = overall;
}


