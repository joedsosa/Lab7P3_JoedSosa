#ifndef ESTUDIANTECOBRA_H
#define ESTUDIANTECOBRA_H

#include "Estudiante.h"
#include "Cinta.h"

class EstudianteCobra : public Estudiante {
private:
    Cinta cinta;

public:
    EstudianteCobra(const std::string& nombre, int edad, const std::string& colorCinta, int nivelCinta);

    Cinta getCinta() const;
    void setCinta(const Cinta& cinta);

    void mostrarInformacion() const override;
};

#endif