#ifndef ESTUDIANTEBLOCKCHAIN_H
#define ESTUDIANTEBLOCKCHAIN_H

#include "estudiante.h"

class EstudianteBlockchain : public Estudiante {
public:
    EstudianteBlockchain(const std::string& nombre, int edad, Cinta* cinta);

    void generarAtributos() override;
    int getFuerzaBrazos() const;
    void setFuerzaBrazos(int fuerzaBrazos);

private:
    int fuerzaBrazos;
};

#endif
