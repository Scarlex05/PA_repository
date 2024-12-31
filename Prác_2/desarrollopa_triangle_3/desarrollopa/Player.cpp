#include "Player.h"

//variable que usaremos para convertir de grados a radianes
//ya que las funciones del movimiento cos y sin esperan radianes
//y las orientaciones del tanque están definidas en grados
//la definimos porque no nos dejaba utilizar la biblioteca de cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Player::~Player() {  //destructor
    if (playerObj) {
        delete playerObj; // Libera memoria
        playerObj = nullptr;
    }
}


void Player::Init() 
{
	//Instanciamos un loader para leer el archivo obj
	ModelLoader* loader = new ModelLoader();

	//fijamos la escala para ajustar el tamaño
	loader->SetScale(0.5);
	loader->LoadModel("..\\3dModels\\Tank.obj");

	//una vez cargado el modelo, instanciamos un Model usando memoria din?mica
	Model* playerObj = new Model();

	//Asignamos el modelo del loader a lo apuntado por el puntero llamado bolt
	*playerObj = loader->GetModel();

    // Ajustamos posición, orientación y color del modelo
    playerObj->SetPosition(Vector3D(4, 4, 0));
    playerObj->SetOrientation(Vector3D(0, 0, 180)); //180 para que mire hacia arriba
    playerObj->SetColor(Color(0.0, 1.0, 0.0, 1.0));

	this->SetModel(playerObj);

    // Liberamos el loader para evitar fugas de memoria
    delete loader;
}

void Player::Render() {
    if (playerObj) {
        playerObj->Render();
    }
}

void Player::Update(const float& time) {
    Solid::Update(time); // Llama al Update de Solid
    if (playerObj) {
        playerObj->SetPosition(position);
        playerObj->SetOrientation(orientation);
    }
}

//movimiento del jugador (controles tanque)
void Player::ProcessKeyPressed(unsigned char key, int px, int py) {
    switch (key) {
    case 'w': // Mover hacia adelante
        position.SetX(position.GetX() + movementSpeed * cos(orientation.GetZ() * M_PI / 180.0f));
        position.SetY(position.GetY() + movementSpeed * sin(orientation.GetZ() * M_PI / 180.0f));
        break;

    case 's': // Mover hacia atrás
        position.SetX(position.GetX() - movementSpeed * cos(orientation.GetZ() * M_PI / 180.0f));
        position.SetY(position.GetY() - movementSpeed * sin(orientation.GetZ() * M_PI / 180.0f));
        break;

    case 'a': // Girar a la izquierda
        orientation.SetZ(orientation.GetZ() - 5.0f);
        if (orientation.GetZ() < 0) {
            orientation.SetZ(orientation.GetZ() + 360.0f);
        }
        break;

    case 'd': // Girar a la derecha
        orientation.SetZ(orientation.GetZ() + 5.0f);
        if (orientation.GetZ() >= 360.0f) {
            orientation.SetZ(orientation.GetZ() - 360.0f);
        }
        break;

    default:
        break;
    }

}
