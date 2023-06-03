#include <iostream>
#include <vector>
#include <cstdlib>  // Para la función rand()
#include "EstudianteCobra.h"
#include "EstudianteBlockchain.h"

// Función para mostrar el menú y obtener la opción del usuario
int mostrarMenu() {
    int opcion;
    std::cout << "----------- Menú -----------\n";
    std::cout << "1. Crear Estudiante\n";
    std::cout << "2. Modificar Estudiante\n";
    std::cout << "3. Eliminar Estudiante\n";
    std::cout << "4. Listar Estudiantes\n";
    std::cout << "5. Promover Cinta del Estudiante\n";
    std::cout << "6. Degradar Cinta del Estudiante\n";
    std::cout << "7. Simulación\n";
    std::cout << "8. Salir\n";
    std::cout << "Ingrese una opción: ";
    std::cin >> opcion;
    return opcion;
}
void crearEstudiante(std::vector<Estudiante*>& estudiantes) {
    int opcionDojo;
    std::cout << "De qué Dojo es el estudiante?\n";
    std::cout << "1. Dojo Cobra\n";
    std::cout << "2. Dojo Blockchain\n";
    std::cout << "Ingrese una opción: ";
    std::cin >> opcionDojo;

    std::string nombre;
    int edad;
    std::cout << "Ingrese el nombre del estudiante: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese la edad del estudiante: ";
    std::cin >> edad;

    if (opcionDojo == 1) {
        EstudianteCobra* estudiante = new EstudianteCobra(nombre, edad);
        estudiantes.push_back(estudiante);
    }
    else if (opcionDojo == 2) {
        EstudianteBlockchain* estudiante = new EstudianteBlockchain(nombre, edad);
        estudiantes.push_back(estudiante);
    }

    std::cout << "Estudiante creado exitosamente!\n";
}
void modificarEstudiante(std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    int opcionEstudiante;
    std::cout << "Elija el estudiante que desea modificar:\n";
    for (int i = 0; i < estudiantes.size(); i++) {
        std::cout << i + 1 << ". " << estudiantes[i]->getNombre() << std::endl;
    }
    std::cout << "Ingrese una opción: ";
    std::cin >> opcionEstudiante;

    if (opcionEstudiante >= 1 && opcionEstudiante <= estudiantes.size()) {
        Estudiante* estudiante = estudiantes[opcionEstudiante - 1];
        std::string nuevoNombre;
        int nuevaEdad;
        std::cout << "Ingrese el nuevo nombre del estudiante: ";
        std::cin.ignore();
        std::getline(std::cin, nuevoNombre);
        std::cout << "Ingrese la nueva edad del estudiante: ";
        std::cin >> nuevaEdad;
        estudiante->setNombre(nuevoNombre);
        estudiante->setEdad(nuevaEdad);
        std::cout << "Estudiante modificado exitosamente!\n";
    }
    else {
        std::cout << "Opción inválida.\n";
    }
}
// Función para eliminar un estudiante existente
void eliminarEstudiante(std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    int opcionEstudiante;
    std::cout << "Elija el estudiante que desea eliminar:\n";
    for (int i = 0; i < estudiantes.size(); i++) {
        std::cout << i + 1 << ". " << estudiantes[i]->getNombre() << std::endl;
    }
    std::cout << "Ingrese una opción: ";
    std::cin >> opcionEstudiante;

    if (opcionEstudiante >= 1 && opcionEstudiante <= estudiantes.size()) {
        Estudiante* estudiante = estudiantes[opcionEstudiante - 1];
        delete estudiante;
        estudiantes.erase(estudiantes.begin() + opcionEstudiante - 1);
        std::cout << "Estudiante eliminado exitosamente!\n";
    }
    else {
        std::cout << "Opción inválida.\n";
    }
}
// Función para listar los estudiantes registrados
void listarEstudiantes(const std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    std::cout << "----- Lista de Estudiantes -----\n";
    for (int i = 0; i < estudiantes.size(); i++) {
        Estudiante* estudiante = estudiantes[i];
        std::cout << "Estudiante " << i + 1 << ":\n";
        std::cout << "Nombre: " << estudiante->getNombre() << std::endl;
        std::cout << "Edad: " << estudiante->getEdad() << std::endl;
        std::cout << "Cinta: " << estudiante->getCinta()->getColorCinta() << std::endl;
        std::cout << "Overall: " << estudiante->getOverall() << std::endl;
        std::cout << "--------------------------------\n";
    }
}
void promoverCinta(std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    int opcionEstudiante;
    std::cout << "Elija el estudiante al que desea promover la cinta:\n";
    for (int i = 0; i < estudiantes.size(); i++) {
        std::cout << i + 1 << ". " << estudiantes[i]->getNombre() << std::endl;
    }
    std::cout << "Ingrese una opción: ";
    std::cin >> opcionEstudiante;

    if (opcionEstudiante >= 1 && opcionEstudiante <= estudiantes.size()) {
        Estudiante* estudiante = estudiantes[opcionEstudiante - 1];
        if (estudiante++) {
            std::cout << "La cinta del estudiante ha sido promovida.\n";
            std::cout << "Ahora es cinta: " << estudiante->getCinta()->getColorCinta() << std::endl;
        }
        else {
            std::cout << "El estudiante ya tiene la cinta máxima.\n";
        }
    }
    else {
        std::cout << "Opción inválida.\n";
    }
}

// Función para degradar la cinta de un estudiante
void degradarCinta(std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    int opcionEstudiante;
    std::cout << "Elija el estudiante al que desea degradar la cinta:\n";
    for (int i = 0; i < estudiantes.size(); i++) {
        std::cout << i + 1 << ". " << estudiantes[i]->getNombre() << std::endl;
    }
    std::cout << "Ingrese una opción: ";
    std::cin >> opcionEstudiante;

    if (opcionEstudiante >= 1 && opcionEstudiante <= estudiantes.size()) {
        Estudiante* estudiante = estudiantes[opcionEstudiante - 1];
        if (estudiante--) {
            std::cout << "La cinta del estudiante ha sido degradada.\n";
            std::cout << "Ahora es cinta: " << estudiante->getCinta()->getColorCinta() << std::endl;
        }
        else {
            std::cout << "El estudiante ya tiene la cinta mínima.\n";
        }
    }
    else {
        std::cout << "Opción inválida.\n";
    }
}

void simulacion(std::vector<Estudiante*>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }

    int numDojoCobra = 0;
    int numDojoBlockchain = 0;
    for (Estudiante* estudiante : estudiantes) {
        if (dynamic_cast<EstudianteCobra*>(estudiante)) {
            numDojoCobra++;
        }
        else if (dynamic_cast<EstudianteBlockchain*>(estudiante)) {
            numDojoBlockchain++;
        }
    }

    if (numDojoCobra < 4 || numDojoBlockchain < 4) {
        std::cout << "No hay suficientes estudiantes en los dojos para realizar la simulación.\n";
        return;
    }

    // Obtener los estudiantes de cada dojo
    std::vector<EstudianteCobra*> dojoCobraEstudiantes;
    std::vector<EstudianteBlockchain*> dojoBlockchainEstudiantes;
    for (Estudiante* estudiante : estudiantes) {
        if (EstudianteCobra* cobraEstudiante = dynamic_cast<EstudianteCobra*>(estudiante)) {
            dojoCobraEstudiantes.push_back(cobraEstudiante);
        }
        else if (EstudianteBlockchain* blockchainEstudiante = dynamic_cast<EstudianteBlockchain*>(estudiante)) {
            dojoBlockchainEstudiantes.push_back(blockchainEstudiante);
        }
    }

    // Validar si hay suficientes estudiantes en cada dojo
    if (dojoCobraEstudiantes.size() < 4 || dojoBlockchainEstudiantes.size() < 4) {
        std::cout << "No hay suficientes estudiantes en los dojos para realizar la simulación.\n";
        return;
    }

    // Realizar la simulación de enfrentamientos
    std::cout << "Simulación en progreso...\n";

    // Mientras haya estudiantes en ambos dojos
    while (!dojoCobraEstudiantes.empty() && !dojoBlockchainEstudiantes.empty()) {
        // Seleccionar un estudiante aleatorio de cada dojo
        int indexCobra = rand() % dojoCobraEstudiantes.size();
        int indexBlockchain = rand() % dojoBlockchainEstudiantes.size();

        EstudianteCobra* estudianteCobra = dojoCobraEstudiantes[indexCobra];
        EstudianteBlockchain* estudianteBlockchain = dojoBlockchainEstudiantes[indexBlockchain];

        // Calcular el ataque del estudiante Cobra
        double porcentajeCintaCobra = estudianteCobra->getCinta()->getPorcentajeCinta();
        double ataqueCobra = estudianteCobra->getOverall() * porcentajeCintaCobra;

        // Calcular la defensa del estudiante Blockchain
        double porcentajeCintaBlockchain = estudianteBlockchain->getCinta()->getPorcentajeCinta();
        double defensaBlockchain = estudianteBlockchain->getOverall() * porcentajeCintaBlockchain;

        // Calcular el daño
        double danio = ataqueCobra - defensaBlockchain;
        if (danio < 0) {
            danio = 0;  // No puede ser negativo
        }

        // Restar el daño a la resistencia del estudiante Blockchain
        estudianteBlockchain->restarResistencia(danio);

        // Mostrar el resultado del enfrentamiento
        std::cout << "Estudiante Cobra: " << estudianteCobra->getNombre() << " | "
            << "Estudiante Blockchain: " << estudianteBlockchain->getNombre() << std::endl;
    }
}
int main() {
    std::vector<Estudiante*> estudiantes;

    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
        case 1:
            crearEstudiante(estudiantes);
            break;
        case 2:
            modificarEstudiante(estudiantes);
            break;
        case 3:
            eliminarEstudiante(estudiantes);
            break;
        case 4:
            listarEstudiantes(estudiantes);
            break;
        case 5:
            promoverCinta(estudiantes);
            break;
        case 6:
            degradarCinta(estudiantes);
            break;
        case 7:
            simulacion(estudiantes);
            break;
        case 8:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }

        std::cout << std::endl;

    } while (opcion != 8);

    // Liberar la memoria de los estudiantes
    for (Estudiante* estudiante : estudiantes) {
        delete estudiante;
    }
    estudiantes.clear();

    return 0;
}


