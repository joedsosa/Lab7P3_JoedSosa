#ifndef CINTA_H
#define CINTA_H

#include <string>

class Cinta {
private:
    int nivel;
    std::string colorCinta;
    double porcentajeCinta;

public:
    Cinta();
    ~Cinta();

    int getNivel();
    void setNivel(int nivel);
    void setColorCinta(const std::string& color);
    void getPorcentajeCinta(int color);
    std::string getColorCinta();
    void setColorCinta();
};

#endif  // CINTA_H
