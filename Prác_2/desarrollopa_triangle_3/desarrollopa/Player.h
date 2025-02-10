#pragma once
#include "Vector3D.h" 
#include "Model.h" 
#include "ModelLoader.h"
#include "Solid.h"

class Player : public Solid // hereda de Solid
{
private:
	Model* playerObj;
	float movementSpeed;


public:

	// Constructor
	Player() : movementSpeed(1.0f), Solid()
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

	~Player();

	inline Model* GetModel() { return this->playerObj; } 
	
	inline void SetModel(Model* modelToSet) { this->playerObj = modelToSet; }

	void Render() override;
	void Update(const float& time) override;
	void ProcessKeyPressed(unsigned char key, int px, int py); 

};
