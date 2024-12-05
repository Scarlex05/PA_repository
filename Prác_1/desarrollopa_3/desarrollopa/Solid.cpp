#include "Solid.h"
#include "iostream"

void Solid::Update()
{
	this->orientation = this->orientation + this->orientationSpeed;

	this->position = this->position.Add(this->velocidad);

	//this->SetOrientation(this->GetOrie())ntation() + this->GetOrientationSpeed());
}
