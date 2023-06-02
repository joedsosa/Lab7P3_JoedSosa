#ifndef DOJO_H
#define DOJO_H

#include <vector>
#include "Estudiante.h"

class Dojo {
private:
    std::vector<Estudiante*> estudiantes;

public:
    Dojo();
    ~Dojo();

    void agregarEstudiante(Estudiante* estudiante);
    void modificarEstudiante(int indice, Estudiante* estudiante);
    void eliminarEstudiante(int indice);
    void mostrarEstudiantes() const;

    Estudiante* getEstudiante(int indice) const;
    int getCantidadEstudiantes() const;
};

#endif  // DOJO_H
