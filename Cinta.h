#ifndef CINTA_H
#define CINTA_H

#include <string>

class Cinta {
private:
    int nivel;
    std::string colorCinta;

public:
    Cinta();
    int getNivel() const;
    std::string getColorCinta() const;
    void setNivel(int nivel);
    void actualizarColorCinta();
};

#endif
