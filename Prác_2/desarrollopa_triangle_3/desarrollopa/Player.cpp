#include "Player.h"

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
	//lo colocamos m?s cerca del centro de la escena
	tank->SetPosition(Vector3D(4, 4, 0));
	tank->SetOrientation(Vector3D(0, 0, 180)); //180 para que mire hacia arriba
	tank->SetColor(Color(0.0, 1.0, 0.0, 1.0));

	this->SetModel(tank); 
}


void Player::Update() 
{
    this->playerObj->SetPosition(this->position);
    this->playerObj->SetOrientation(this->orientation);
}

void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
    switch (key) {
    case 'w': // Mover hacia adelante (incrementa en el eje Y)
        this->position.SetY(this->position.GetY() + movementSpeed);
        break;

    case 's': // Mover hacia atrás (decrementa en el eje Y)
        this->position.SetY(this->position.GetY() - movementSpeed);
        break;

    case 'a': // Girar a la izquierda (incrementa orientación en Z)
        this->orientation.SetZ(this->orientation.GetZ() - 5.0f);
        if (this->orientation.GetZ() < 0) {
            this->orientation.SetZ(this->orientation.GetZ() + 360.0f);
        }
        break;

    case 'd': // Girar a la derecha (decrementa orientación en Z)
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
