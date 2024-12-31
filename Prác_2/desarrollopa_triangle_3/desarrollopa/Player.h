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

    inline Model* GetModel() { return this->playerObj; }

    inline void SetModel(Model* modelToSet) { this->playerObj = modelToSet; }

    // Métodos principales
    void Init();                               
    void Render() override;                   
    void Update(const float& time) override;  
    void ProcessKeyPressed(unsigned char key, int px, int py); 
};
