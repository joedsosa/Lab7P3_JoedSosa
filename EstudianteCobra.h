#ifndef ESTUDIANTECOBRA_H
#define ESTUDIANTECOBRA_H

#include "estudiante.h"

class EstudianteCobra : public Estudiante {
public:
    EstudianteCobra(const std::string& nombre, int edad, Cinta* cinta);

    void generarAtributos() override;
    int getFuerzaPiernas() const;
    void setFuerzaPiernas(int fuerzaPiernas);

private:
    int fuerzaPiernas;
};

#endif
