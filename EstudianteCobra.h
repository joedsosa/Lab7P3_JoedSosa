#ifndef ESTUDIANTECOBRA_H
#define ESTUDIANTECOBRA_H

#include "Estudiante.h"

class EstudianteCobra : public Estudiante {
private:
    int fuerzaPiernas;

public:
    EstudianteCobra(std::string nombre, int edad);
    ~EstudianteCobra();

    int getFuerzaPiernas();
    void setFuerzaPiernas(int fuerzaPiernas);
    double getOverall() const;
    void setOverall(int overall);
};

#endif  // ESTUDIANTECOBRA_H
