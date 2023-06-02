#include "Cinta.h"

Cinta::Cinta() : nivel(1), colorCinta("") {
    actualizarColorCinta();
}

int Cinta::getNivel() const {
    return nivel;
}

std::string Cinta::getColorCinta() const {
    return colorCinta;
}

void Cinta::setNivel(int nivel) {
    this->nivel = nivel;
    actualizarColorCinta();
}

void Cinta::actualizarColorCinta() {
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
        colorCinta = "";
        break;
    }
}
