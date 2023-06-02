#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Estudiante.h"
#include "EstudianteBlockchain.h"
#include "EstudianteCobra.h"

// Funciones auxiliares
//void mostrarMenu();
//void agregarEstudiante(std::vector<Estudiante*>& estudiantes);
//void mostrarEstudiantes(const std::vector<Estudiante*>& estudiantes);
//void modificarEstudiante(std::vector<Estudiante*>& estudiantes);
//void eliminarEstudiante(std::vector<Estudiante*>& estudiantes);
//void simularTorneo(const std::vector<Estudiante*>& estudiantes);


void mostrarMenu() {
    std::cout << "----- Menú Principal -----" << std::endl;
    std::cout << "1. Agregar Estudiante" << std::endl;
    std::cout << "2. Mostrar Estudiantes" << std::endl;
    std::cout << "3. Modificar Estudiante" << std::endl;
    std::cout << "4. Eliminar Estudiante" << std::endl;
    std::cout << "5. Simular Torneo" << std::endl;
    std::cout << "6. Salir" << std::endl;
}

void agregarEstudiante(std::vector<Estudiante*>& estudiantes) {
    std::string nombre;
    int edad, opcionDojo;

    std::cout << "----- Agregar Estudiante -----" << std::endl;
    std::cout << "Ingrese el nombre del estudiante: ";
    std::cin >> nombre;
    std::cout << "Ingrese la edad del estudiante: ";
    std::cin >> edad;

    std::cout << "Seleccione el Dojo del estudiante:" << std::endl;
    std::cout << "1. Dojo Blockchain" << std::endl;
    std::cout << "2. Dojo Cobra" << std::endl;
    std::cout << "Ingrese una opción: ";
    std::cin >> opcionDojo;

    if (opcionDojo == 1) {
        std::string colorCinta;
        int nivelCinta;

        std::cout << "Ingrese el color de la cinta del estudiante: ";
        std::cin >> colorCinta;
        std::cout << "Ingrese el nivel de la cinta del estudiante: ";
        std::cin >> nivelCinta;

        Estudiante* estudiante = new EstudianteBlockchain(nombre, edad, colorCinta, nivelCinta);
        estudiantes.push_back(estudiante);

        std::cout << "Estudiante agregado correctamente." << std::endl;
    }
    else if (opcionDojo == 2) {
        std::string colorCinta;
        int nivelCinta;

        std::cout << "Ingrese el color de la cinta del estudiante: ";
        std::cin >> colorCinta;
        std::cout << "Ingrese el nivel de la cinta del estudiante: ";
        std::cin >> nivelCinta;

        Estudiante* estudiante = new EstudianteCobra(nombre, edad, colorCinta, nivelCinta);
        estudiantes.push_back(estudiante);

        std::cout << "Estudiante agregado correctamente." << std::endl;
    }
    else {
        std::cout << "Opción inválida. No se pudo agregar el estudiante." << std::endl;
    }
}

void mostrarEstudiantes(const std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados." << std::endl;
        return;
    }

    std::cout << "----- Estudiantes Registrados -----" << std::endl;
    for (int i = 0; i < estudiantes.size(); i++) {
        std::cout << "Estudiante #" << i + 1 << std::endl;
        estudiantes[i]->mostrarInformacion();
        std::cout << std::endl;
    }
}

void modificarEstudiante(std::vector<Estudiante*>& estudiantes) {
    int opcionEstudiante;

    std::cout << "----- Modificar Estudiante -----" << std::endl;
    std::cout << "Elige un estudiante: ";
    std::cin >> opcionEstudiante;

    if (opcionEstudiante >= 1 && opcionEstudiante <= estudiantes.size()) {
        Estudiante* estudiante = estudiantes[opcionEstudiante - 1];

        int opcion;
        do {
            std::cout << "---- MODIFICAR ESTUDIANTE ----" << std::endl;
            std::cout << "1. Modificar Nombre" << std::endl;
            std::cout << "2. Modificar Edad" << std::endl;
            std::cout << "3. Regresar al Menú Principal" << std::endl;
            std::cout << "Ingrese una opción: ";
            std::cin >> opcion;
            std::cout << std::endl;
            std::string nombre;
            switch (opcion) {
            case 1:
                
                std::cout << "Ingrese el nuevo nombre: ";
                std::cin >> nombre;
                estudiante->setNombre(nombre);
                std::cout << "Nombre modificado correctamente." << std::endl;
                break;
            case 2:
                int nuevaEdad;
                std::cout << "Ingrese la nueva edad: ";
                std::cin >> nuevaEdad;
                estudiante->setEdad(nuevaEdad);
                std::cout << "Edad modificada correctamente." << std::endl;
                break;
            case 3:
                std::cout << "Regresando al Menú Principal..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Inténtalo nuevamente." << std::endl;
                break;
            }

            std::cout << std::endl;
        } while (opcion != 3);
    }
    else {
        std::cout << "Opción inválida." << std::endl;
    }
}

void eliminarEstudiante(std::vector<Estudiante*>& estudiantes) {
    int opcionEstudiante;

    std::cout << "----- Eliminar Estudiante -----" << std::endl;
    std::cout << "Elige un estudiante: ";
    std::cin >> opcionEstudiante;

    if (opcionEstudiante >= 1 && opcionEstudiante <= estudiantes.size()) {
        Estudiante* estudiante = estudiantes[opcionEstudiante - 1];
        estudiantes.erase(estudiantes.begin() + opcionEstudiante - 1);
        delete estudiante;

        std::cout << "Estudiante eliminado correctamente." << std::endl;
    }
    else {
        std::cout << "Opción inválida." << std::endl;
    }
}

void simularTorneo(const std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.size() < 8) {
        std::cout << "No hay suficientes estudiantes para simular el torneo." << std::endl;
        return;
    }

    std::vector<Estudiante*> participantes = estudiantes;  // Copiar la lista de estudiantes

    // Verificar que haya exactamente 4 estudiantes por cada Dojo
    int numDojoCobra = 0;
    int numDojoBlockchain = 0;

    for (const auto& estudiante : estudiantes) {
        if (dynamic_cast<EstudianteCobra*>(estudiante)) {
            ++numDojoCobra;
        }
        else if (dynamic_cast<EstudianteBlockchain*>(estudiante)) {
            ++numDojoBlockchain;
        }
    }

    if (numDojoCobra != 4 || numDojoBlockchain != 4) {
        std::cout << "No se cumplen las condiciones necesarias para simular el torneo." << std::endl;
        return;
    }

    std::cout << "¡Comienza el Torneo!" << std::endl;

    while (participantes.size() > 1) {
        // Seleccionar dos participantes al azar
        int index1 = rand() % participantes.size();
        Estudiante* participante1 = participantes[index1];
        participantes.erase(participantes.begin() + index1);

        int index2 = rand() % participantes.size();
        Estudiante* participante2 = participantes[index2];
        participantes.erase(participantes.begin() + index2);

        // Simular el enfrentamiento
        std::cout << std::endl;
        std::cout << "¡Enfrentamiento!" << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "Participante 1: " << participante1->getNombre() << std::endl;
        std::cout << "Participante 2: " << participante2->getNombre() << std::endl;
        std::cout << "----------------" << std::endl;

        while (participante1->getVida() > 0 && participante2->getVida() > 0) {
            // Calcular ataque de participante 1
            double porcentajeAtaque1 = participante1->getCinta().getPorcentajeAtaque();
            int ataque1 = static_cast<int>(participante1->getOverall() * porcentajeAtaque1);

            // Calcular defensa de participante 2
            double porcentajeDefensa2 = participante2->getCinta().getPorcentajeDefensa();
            int defensa2 = static_cast<int>(participante2->getResistencia() * porcentajeDefensa2);

            // Calcular daño
            int danio1 = ataque1 - defensa2;
            if (danio1 < 0) {
                danio1 = 0;
            }

            // Actualizar vida de participante 2
            int nuevaVida2 = participante2->getVida() - danio1;
            if (nuevaVida2 < 0) {
                nuevaVida2 = 0;
            }
            participante2->setVida(nuevaVida2);

            std::cout << participante1->getNombre() << " ataca a " << participante2->getNombre() << " causando un daño de " << danio1 << std::endl;
            std::cout << participante2->getNombre() << " tiene una vida restante de " << nuevaVida2 << std::endl;
            std::cout << std::endl;

            // Intercambiar roles
            std::swap(participante1, participante2);
        }

        // Determinar al ganador del enfrentamiento
        Estudiante* ganador = (participante1->getVida() > 0) ? participante1 : participante2;
        std::cout << "¡El ganador del enfrentamiento es " << ganador->getNombre() << "!" << std::endl;

        // Agregar al ganador de vuelta a la lista de participantes
        participantes.push_back(ganador);
    }

    // Determinar al ganador del torneo
    Estudiante* ganadorTorneo = participantes[0];
    std::cout << std::endl;
    std::cout << "¡El ganador del Torneo es " << ganadorTorneo->getNombre() << " del Dojo " << ganadorTorneo->getDojo() << "!" << std::endl;
}

int main() {
    std::srand(std::time(nullptr));  // Inicializar semilla aleatoria

    std::vector<Estudiante*> estudiantes;

    int opcion;
    do {
        mostrarMenu();
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;
        std::cout << std::endl;

        switch (opcion) {
        case 1:
            agregarEstudiante(estudiantes);
            break;
        case 2:
            mostrarEstudiantes(estudiantes);
            break;
        case 3:
            modificarEstudiante(estudiantes);
            break;
        case 4:
            eliminarEstudiante(estudiantes);
            break;
        case 5:
            simularTorneo(estudiantes);
            break;
        case 6:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opción inválida. Inténtalo nuevamente." << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (opcion != 6);

    // Liberar memoria de los estudiantes
    for (auto& estudiante : estudiantes) {
        delete estudiante;
    }

    return 0;
}

