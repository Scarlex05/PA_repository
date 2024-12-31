#include "Player.h"

//variable que usaremos para convertir de grados a radianes
//ya que las funciones del movimiento cos y sin esperan radianes
//y las orientaciones del tanque están definidas en grados
//la definimos porque no nos dejaba utilizar la biblioteca de cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void Player::Render()
{
    this->playerObj->Render();  
}


void Player::Update() 
{
    this->playerObj->Update(0.1f); 
}

//movimiento del jugador (controles tanque)
void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
    switch (key) {
    case 'w': // Mover hacia adelante según hacia donde esté mirando el jugador 
        this->GetPosition().SetX(this->GetPosition().GetX() + movementSpeed * cos(GetOrientation().GetZ() * M_PI / 180.0f));
        this->GetPosition().SetY(this->GetPosition().GetY() + movementSpeed * sin(GetOrientation().GetZ() * M_PI / 180.0f));
        break;

    case 's': // Mover hacia atrás según hacia donde esté mirando el jugador
        this->GetPosition().SetX(this->GetPosition().GetX() - movementSpeed * cos(GetOrientation().GetZ() * M_PI / 180.0f));
        this->GetPosition().SetY(this->GetPosition().GetY() - movementSpeed * sin(GetOrientation().GetZ() * M_PI / 180.0f));
        break;

    case 'a': // Girar a la izquierda (rotación antihoraria)
        this->GetOrientation().SetZ(this->GetOrientation().GetZ() - 5.0f);
        if (this->GetOrientation().GetZ() < 0) {
            this->GetOrientation().SetZ(this->GetOrientation().GetZ() + 360.0f);
        }
        break;

    case 'd': // Girar a la derecha (rotación horaria)
        this->GetOrientation().SetZ(this->GetOrientation().GetZ() + 5.0f);
        if (this->GetOrientation().GetZ() >= 360.0f) {
            this->GetOrientation().SetZ(this->GetOrientation().GetZ() - 360.0f);
        }
        break;

    default:
        break;
    }

    this->Update(); 
}
