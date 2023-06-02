#include "Cinta.h"

Cinta::Cinta(const std::string& color, int nivel)
    : color(color), nivel(nivel) {}

std::string Cinta::getColor() const {
    return color;
}

int Cinta::getNivel() const {
    return nivel;
}

void Cinta::setColor(const std::string& color) {
    this->color = color;
}

void Cinta::setNivel(int nivel) {
    this->nivel = nivel;
}

void Cinta::ascender() {
    nivel++;
}

void Cinta::descender() {
    if (nivel > 0) {
        nivel--;
    }
}