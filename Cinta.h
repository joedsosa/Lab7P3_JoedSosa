#ifndef CINTA_H
#define CINTA_H

#include <string>

class Cinta {
private:
    std::string color;
    int nivel;

public:
    Cinta(const std::string& color, int nivel);

    std::string getColor() const;
    int getNivel() const;
    void setColor(const std::string& color);
    void setNivel(int nivel);
    void ascender();
    void descender();
};
#endif

