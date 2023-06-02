#include "Estudiante.h"

Estudiante :: Estudiante(const std::string& nombre, int edad, const Cinta& cinta)
    : nombre(nombre), edad(edad), vida(100), cinta(cinta) {}

Estudiante::~Estudiante() {}

std::string Estudiante::getNombre() const {
    return nombre;
}

int Estudiante::getEdad() const {
    return edad;
}

int Estudiante::getVida() const {
    return vida;
}

Cinta Estudiante::getCinta() const {
    return cinta;
}

void Estudiante::setVida(int vida) {
    this->vida = vida;
}

int Estudiante::calcularAtaque() const {
    int overallFuerza = getOverall();
    double porcentajeAtaque = getPorcentajeAtaque();
    return static_cast<int>(overallFuerza * porcentajeAtaque);
}

int Estudiante::calcularDefensa() const {
    int resistencia = getResistencia();
    double porcentajeDefensa = getPorcentajeDefensa();
    return static_cast<int>(resistencia * porcentajeDefensa);
}

void Estudiante::recibirAtaque(int ataque) {
    int defensa = calcularDefensa();
    int danio = ataque - defensa;
    if (danio < 0) {
        danio = 0;
    }
    vida -= danio;
    if (vida < 0) {
        vida = 0;
    }
}
