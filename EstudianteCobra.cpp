
#include "EstudianteCobra.h"

EstudianteCobra::EstudianteCobra(const std::string& nombre, int edad, CintaCobra* cinta)
    : Estudiante(nombre, edad, cinta) {
}

void EstudianteCobra::generarAtributosAleatorios() {
    Estudiante::generarAtributosAleatorios();
    fuerzaPiernas = rand() % 11;
    overall += fuerzaPiernas;
}
