#include "EstudianteBlockchain.h"
#include "EstudianteBlockchain.h"
#include <iostream>
using namespace std;
EstudianteBlockchain::EstudianteBlockchain(const string& nombre, int edad, CintaBlockchain* cinta)
    : Estudiante(nombre, edad, cinta) {
}

void EstudianteBlockchain::generarAtributosAleatorios() {
    Estudiante::generarAtributosAleatorios();
    fuerzaBrazos = rand() % 11;
    overall += fuerzaBrazos;
}
