#ifndef ESTUDIANTEBLOCKCHAIN_H
#define ESTUDIANTEBLOCKCHAIN_H

#include "Estudiante.h"

class EstudianteBlockchain : public Estudiante {
private:
    int fuerzaBrazos;

public:
    EstudianteBlockchain(std::string nombre, int edad);
    ~EstudianteBlockchain();
    double restarResistencia(int cantidad);

    int getFuerzaBrazos();
    void setFuerzaBrazos(int fuerzaBrazos);
    int getResistencia() const;
    double setOverall(int overall);
};

#endif  // ESTUDIANTEBLOCKCHAIN_H
