#pragma once

#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <GL/glut.h>
#include "Vector3D.h"

class Text {
private:
    float red, green, blue, alpha; // Colores del texto
    Vector3D position;        // Posici�n del texto en el espacio 3D 
    void* font;              // Puntero a la fuente (por ejemplo, GLUT_BITMAP_8_BY_13)
    std::string text; 

public:
    // Constructor
    Text() : red(1.f), green(0.f), blue(0.f), alpha(1.f),
        position(5.f, 4.f, 0.f), font(GLUT_BITMAP_8_BY_13), text("") {}

    // Funciones para establecer atributos
    inline void SetColor(float r, float g, float b, float a) { red = r; green = g; blue = b; alpha = a; };
    inline void SetPosition(Vector3D coordsToSet) { this->position = coordsToSet; }
    inline void SetText(const std::string& textToRender) { text = textToRender; } 

    inline std::string GetText() { return this->text; }

    // Funci�n para dibujar el texto
    void Render();
};

#endif

