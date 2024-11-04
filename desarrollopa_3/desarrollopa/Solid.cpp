#include "Solid.h"

void Solid::Update()
{
	this->orientation = this->orientation + this->orientationSpeed;

	this->position.Add(this->velocidad);

	//this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed());
}
