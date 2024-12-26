#pragma once
#include "Vector3D.h" 
#include "Model.h" 
#include "ModelLoader.h"

class Player
{
private:
	Model* playerObj;
	Vector3D position;
	Vector3D orientation;
	Vector3D orientationSpeed;
	float movementSpeed;
	float angleRotation;

public:

	//Getters
	inline Vector3D GetPosition() { return this->position; }
	inline float GetSpeed() { return this->movementSpeed; }
	inline Vector3D GetOrientation() { return this->orientation; }
	inline Vector3D GetOrientationSpeed() { return this->orientationSpeed; }
	inline Model* GetModel() { return this->playerObj; }

	//Setters
	inline void SetPosition(Vector3D coordsToSet) { this->position = coordsToSet; }
	inline void SetSpeed(const float speedToSet) { this->movementSpeed = speedToSet; }
	inline void SetOrientation(Vector3D orientationToSet) { this->orientation = orientationToSet; }
	inline void SetOrientationSpeed(Vector3D orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	inline void SetModel(Model* modelToSet) { this->playerObj = modelToSet; }

	void Init();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py); 
};

