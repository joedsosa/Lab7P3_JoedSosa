#include "Estudiante.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Estudiante::Estudiante(const std::string& nombre, int edad, Cinta* cinta) {
    this->nombre = nombre;
    this->edad = edad;
    this->cinta = cinta;
    vida = 100;
}

void Estudiante::generarAtributosAleatorios() {
    fuerza = rand() % 31;
    resistencia = rand() % 31;
    calcularOverall();

    if (dynamic_cast<CintaCobra*>(cinta) != nullptr) {
        int fuerzaPiernas = rand() % 11;
        overall += fuerzaPiernas;
    }

    if (dynamic_cast<CintaBlockchain*>(cinta) != nullptr) {
        int fuerzaBrazos = rand() % 11;
        overall += fuerzaBrazos;
    }
}

void Estudiante::calcularOverall() {
    overall = fuerza + resistencia;
}

void Estudiante::mostrarInformacion() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Cinta: Nivel " << cinta->getNivel() << " - " << cinta->getColorCinta() << std::endl;
    std::cout << "Fuerza: " << fuerza << std::endl;
    std::cout << "Resistencia: " << resistencia << std::endl;
    std::cout << "Overall: " << overall << std::endl;
    std::cout << "Vida: " << vida << std::endl;
}

void Estudiante::recibirAtaque(int ataque) {
    int defensa = resistencia * cinta->getNivel();
    int dañoRecibido = ataque - (ataque * defensa / 100);
    vida -= dañoRecibido;

    if (vida < 0) {
        vida = 0;
    }
}

void Estudiante::otorgarAscenso() {
    if (cinta->getNivel() < 7) {
        cinta->setNivel(cinta->getNivel() + 1);
        cinta->actualizarColorCinta();
    }
}

void Estudiante::otorgarDescenso() {
    if (cinta->getNivel() > 1) {
        cinta->setNivel(cinta->getNivel() - 1);
        cinta->actualizarColorCinta();
    }
}

int Estudiante::getOverall() const {
    return overall;
}

int Estudiante::getVida() const {
    return vida;
}

std::string Estudiante::getNombre() const {
    return nombre;
}
