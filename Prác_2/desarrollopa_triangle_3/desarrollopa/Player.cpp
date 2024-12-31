#include "Player.h"

//variable que usaremos para convertir de grados a radianes
//ya que las funciones del movimiento cos y sin esperan radianes
//y las orientaciones del tanque est�n definidas en grados
//la definimos porque no nos dejaba utilizar la biblioteca de cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void Player::Render()
{
    this->playerObj->Render();  
}


void Player::Update(const float& time)
{
    this->playerObj->SetPosition(GetPosition());
    this->playerObj->SetOrientation(GetOrientation());

    this->playerObj->Update(time); 

}

//movimiento del jugador (controles tanque)
void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
    switch (key) {
    case 'w': // Mover hacia adelante seg�n hacia donde est� mirando el jugador 
        this->SetPosition(Vector3D (this->GetPosition().GetX() + movementSpeed * cos(GetOrientation().GetZ() * M_PI / 180.0f),
                this->GetPosition().GetY() + movementSpeed * sin(GetOrientation().GetZ() * M_PI / 180.0f),
                this->GetPosition().GetZ()));
        
        /*this->GetPosition().SetX(this->GetPosition().GetX() + movementSpeed * cos(GetOrientation().GetZ() * M_PI / 180.0f));
        this->GetPosition().SetY(this->GetPosition().GetY() + movementSpeed * sin(GetOrientation().GetZ() * M_PI / 180.0f));*/
        break;

    case 's': // Mover hacia atr�s seg�n hacia donde est� mirando el jugador

        this->SetPosition(Vector3D(this->GetPosition().GetX() - movementSpeed * cos(GetOrientation().GetZ() * M_PI / 180.0f),
            this->GetPosition().GetY() - movementSpeed * sin(GetOrientation().GetZ() * M_PI / 180.0f),
            this->GetPosition().GetZ()));

        //this->GetPosition().SetX(this->GetPosition().GetX() - movementSpeed * cos(GetOrientation().GetZ() * M_PI / 180.0f));
        //this->GetPosition().SetY(this->GetPosition().GetY() - movementSpeed * sin(GetOrientation().GetZ() * M_PI / 180.0f));
        break;

    case 'a': // Girar a la izquierda (rotaci�n antihoraria)
        this->GetOrientation().SetZ(this->GetOrientation().GetZ() - 5.0f);
        if (this->GetOrientation().GetZ() < 0) {
            this->GetOrientation().SetZ(this->GetOrientation().GetZ() + 360.0f);
        }
        break;

    case 'd': // Girar a la derecha (rotaci�n horaria)
        this->GetOrientation().SetZ(this->GetOrientation().GetZ() + 5.0f);
        if (this->GetOrientation().GetZ() >= 360.0f) {
            this->GetOrientation().SetZ(this->GetOrientation().GetZ() - 360.0f);
        }
        break;

    default:
        break;
    }
    std::cout << "x:" << GetPosition().GetX() << "y:" << GetPosition().GetY() << endl;
}
