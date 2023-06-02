#ifndef ESTUDIANTECOBRA_H
#define ESTUDIANTECOBRA_H

#include "Estudiante.h"

class EstudianteCobra : public Estudiante {
private:
    int fuerzaPiernas;

public:
    EstudianteCobra(const std::string& nombre, int edad, CintaCobra* cinta);
    void generarAtributosAleatorios() override;
};

#endif
