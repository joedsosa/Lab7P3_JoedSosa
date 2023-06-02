// Función para mostrar el menú y obtener la opción del usuario
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Estudiante.h"
#include "EstudianteCobra.h"
#include "EstudianteBlockchain.h"
#include "Cinta.h"
using namespace std;
int mostrarMenu() {
    int opcion;
    cout << "=== MENU ===" << endl;
    cout << "1. Agregar estudiante" << endl;
    cout << "2. Modificar estudiante" << endl;
    cout << "3. Eliminar estudiante" << endl;
    cout << "4. Mostrar estudiantes" << endl;
    cout << "5. Realizar torneo" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    return opcion;
}
int generarNumeroAleatorio(int min, int max) {
    return min + (rand() % (max - min + 1));
}
Estudiante* crearEstudianteAleatorio() {
    string nombres[] = { "Juan", "María", "Pedro", "Luisa", "Andrés", "Laura", "Carlos", "Ana" };
    int edades[] = { 18, 19, 20, 21, 22, 23, 24, 25 };

    string nombre = nombres[generarNumeroAleatorio(0, 7)];
    int edad = edades[generarNumeroAleatorio(0, 7)];

    Cinta* cinta = new Cinta();
    Estudiante* estudiante;

    if (generarNumeroAleatorio(0, 1) == 0) {
        estudiante = new EstudianteCobra(nombre, edad, cinta);
    }
    else {
        estudiante = new EstudianteBlockchain(nombre, edad, cinta);
    }

    return estudiante;
}
void agregarEstudiante(vector<Estudiante*>& dojo) {
    Estudiante* estudiante = crearEstudianteAleatorio();
    dojo.push_back(estudiante);
    std::cout << "Nuevo estudiante agregado al dojo." << endl;
}
void modificarEstudiante( vector<Estudiante*>& dojo) {
    int numEstudiantes = dojo.size();
    if (numEstudiantes > 0) {
        std::cout << "Seleccione el índice del estudiante a modificar (0-" << numEstudiantes - 1 << "): ";
        int indice;
        std::cin >> indice;

        if (indice >= 0 && indice < numEstudiantes) {
            Estudiante* estudiante = dojo[indice];
            std::cout << "Ingrese el nuevo nombre del estudiante: ";
            std::string nombre;
            std::cin >> nombre;
            estudiante->setNombre(nombre);

            std::cout << "Ingrese la nueva edad del estudiante: ";
            int edad;
            std::cin >> edad;
            estudiante->setEdad(edad);

            std::cout << "Estudiante modificado exitosamente." << std::endl;
        }
        else {
            std::cout << "Índice inválido." << std::endl;
        }
    }
    else {
        std::cout << "No hay estudiantes en el dojo." << std::endl;
    }
}
void eliminarEstudiante(std::vector<Estudiante*>& dojo) {
    int numEstudiantes = dojo.size();
    if (numEstudiantes > 0) {
        cout << "Seleccione el índice del estudiante a eliminar (0-" << numEstudiantes - 1 << "): ";
        int indice;
        cin >> indice;

        if (indice >= 0 && indice < numEstudiantes) {
            Estudiante* estudiante = dojo[indice];
            dojo.erase(dojo.begin() + indice);
            delete estudiante;
            cout << "Estudiante eliminado exitosamente." << endl;
        }
        else {
            cout << "Índice inválido." << endl;
        }
    }
    else {
            cout << "No hay estudiantes en el dojo." << endl;
    }
}
int main() {
    srand(time(nullptr));

    std::vector< Estudiante*> dojo1;
    std::vector< Estudiante*> dojo2;
    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
        case 1:
            agregarEstudiante(dojo1);
            break;
        case 2:
            modificarEstudiante(dojo1);
            break;
        case 3:
            eliminarEstudiante(dojo1);
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opción inválida." << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (opcion != 0);

    // Liberar memoria de los estudiantes en el dojo
    for (Estudiante* estudiante : dojo1) {
        delete estudiante;
    }
    for (Estudiante* estudiante : dojo2) {
        delete estudiante;
    }

    return 0;


}
