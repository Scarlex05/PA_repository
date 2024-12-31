#pragma once
#include "Vector3D.h" 
#include "Model.h" 
#include "ModelLoader.h"
#include "Solid.h"

class Player : public Solid // hereda de Solid
{
private:
    Model* playerObj;              
    Vector3D position;             
    Vector3D orientation;          
    Vector3D orientationSpeed;    
    float movementSpeed;           

public:
    // Constructor y Destructor
    Player() : movementSpeed(1.0f), playerObj(nullptr) {}
    ~Player();

    // Getters
    inline Vector3D GetPosition() { return this->position; }
    inline Vector3D GetOrientation() { return this->orientation; }
    inline Vector3D GetOrientationSpeed() { return this->orientationSpeed; }
    inline float GetSpeed() { return this->movementSpeed; }
    inline Model* GetModel() { return this->playerObj; }

    // Setters
    inline void SetPosition(Vector3D coordsToSet) { this->position = coordsToSet; }
    inline void SetOrientation(Vector3D orientationToSet) { this->orientation = orientationToSet; }
    inline void SetOrientationSpeed(Vector3D orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
    inline void SetSpeed(const float speedToSet) { this->movementSpeed = speedToSet; }
    inline void SetModel(Model* modelToSet) { this->playerObj = modelToSet; }

    // Métodos principales
    void Init();                               
    void Render() override;                   
    void Update(const float& time) override;  
    void ProcessKeyPressed(unsigned char key, int px, int py); 
};
