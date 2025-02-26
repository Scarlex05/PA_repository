#include "Text.h"

void Text::Render()
{
    if (text.empty()) return; //Si est� vac�o, no se hace nada

    glPushMatrix();
    glColor4f(red, green, blue, alpha);  // Establecer el color
    glTranslatef(position.GetX(), position.GetY(), position.GetZ());     // Establecer la posici�n
    glRasterPos3d(0, 0, 0);         // Posicionar el texto
    

    // Dibujar cada caracter del texto
    for (char c : text) {
        glutBitmapCharacter(font, c);
    }

    glPopMatrix();
}
