#ifndef ESTUDIANTEBLOCKCHAIN_H
#define ESTUDIANTEBLOCKCHAIN_H

#include "Estudiante.h"

class EstudianteBlockchain : public Estudiante {
private:
    int fuerzaBrazos;

public:
    EstudianteBlockchain(const std::string& nombre, int edad, CintaBlockchain* cinta);
    void generarAtributosAleatorios() override;
};

#endif
