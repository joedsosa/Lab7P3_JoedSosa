#include "Cinta.h"

Cinta::Cinta() {
    nivel = 1;
    setColorCinta();
}

Cinta::~Cinta() {
}

int Cinta::getNivel() {
    return nivel;
}

void Cinta::setNivel(int nivel) {
    this->nivel = nivel;
    setColorCinta();
}

std::string Cinta::getColorCinta() {
    return colorCinta;
}
void Cinta::setColorCinta(const std::string& color) {
    this->colorCinta = color;
}

void Cinta::setColorCinta() {
    switch (nivel) {
    case 1:
        colorCinta = "Blanco";
        break;
    case 2:
        colorCinta = "Amarillo";
        break;
    case 3:
        colorCinta = "Naranja";
        break;
    case 4:
        colorCinta = "Verde";
        break;
    case 5:
        colorCinta = "Azul";
        break;
    case 6:
        colorCinta = "Marrón";
        break;
    case 7:
        colorCinta = "Negro";
        break;
    default:
        colorCinta = "Desconocido";
        break;
    }
}
void Cinta::calcularPorcentajeCinta(int color) {
    // Calcular el porcentaje basado en el color de la cinta
    if (color == 1) {
        porcentajeCinta = 100.0;
    }
    else if (color == 2) {
        porcentajeCinta = 80.0;
    }
    else if (color == 3) {
        porcentajeCinta = 60.0;
    }
    else if (color == 4) {
        porcentajeCinta = 40.0;
    }
    else {
        porcentajeCinta = 0.0;
    }
}
