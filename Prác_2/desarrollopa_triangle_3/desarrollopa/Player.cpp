#include "Player.h"

//variable que usaremos para convertir de grados a radianes
//ya que las funciones del movimiento cos y sin esperan radianes
//y las orientaciones del tanque están definidas en grados
//la definimos porque no nos dejaba utilizar la biblioteca de cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void Player::Init() 
{
	//Instanciamos un loader para leer el archivo obj
	ModelLoader* loader = new ModelLoader();

	//fijamos la escala para ajustar el tamaño
	loader->SetScale(0.5);
	loader->LoadModel("..\\3dModels\\Tank.obj");

	//una vez cargado el modelo, instanciamos un Model usando memoria din?mica
	Model* tank = new Model();

	//Asignamos el modelo del loader a lo apuntado por el puntero llamado bolt
	*tank = loader->GetModel();

    // Ajustamos posición, orientación y color del modelo
	tank->SetPosition(Vector3D(4, 4, 0));
	tank->SetOrientation(Vector3D(0, 0, 180)); //180 para que mire hacia arriba
	tank->SetColor(Color(0.0, 1.0, 0.0, 1.0));

	this->SetModel(tank); 

    // Liberamos el loader para evitar fugas de memoria
    delete loader;
}


void Player::Update() 
{
    this->playerObj->SetPosition(this->position);
    this->playerObj->SetOrientation(this->orientation);
}

//movimiento del jugador (controles tanque)
void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
    switch (key) {
    case 'w': // Mover hacia adelante según hacia donde esté mirando el jugador 
        this->position.SetX(this->position.GetX() + movementSpeed * cos(orientation.GetZ() * M_PI / 180.0f));
        this->position.SetY(this->position.GetY() + movementSpeed * sin(orientation.GetZ() * M_PI / 180.0f));
        break;

    case 's': // Mover hacia atrás según hacia donde esté mirando el jugador
        this->position.SetX(this->position.GetX() - movementSpeed * cos(orientation.GetZ() * M_PI / 180.0f));
        this->position.SetY(this->position.GetY() - movementSpeed * sin(orientation.GetZ() * M_PI / 180.0f));
        break;

    case 'a': // Girar a la izquierda (rotación antihoraria)
        this->orientation.SetZ(this->orientation.GetZ() - 5.0f);
        if (this->orientation.GetZ() < 0) {
            this->orientation.SetZ(this->orientation.GetZ() + 360.0f);
        }
        break;

    case 'd': // Girar a la derecha (rotación horaria)
        this->orientation.SetZ(this->orientation.GetZ() + 5.0f);
        if (this->orientation.GetZ() >= 360.0f) {
            this->orientation.SetZ(this->orientation.GetZ() - 360.0f);
        }
        break;

    default:
        break;
    }

    this->Update(); 
}
