#ifndef ESTUDIANTEBLOCKCHAIN_H
#define ESTUDIANTEBLOCKCHAIN_H

#include "Estudiante.h"
#include "Cinta.h"

class EstudianteBlockchain : public Estudiante {
private:
    Cinta cinta;

public:
    EstudianteBlockchain(const std::string& nombre, int edad, const std::string& colorCinta, int nivelCinta);

    Cinta getCinta() const;
    void setCinta(const Cinta& cinta);

    void mostrarInformacion() const override;
};

#endif