#include "Solid.h"

void Solid::Update()
{
	this->orientation = this->orientation + this->orientationSpeed;

	//this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed());
}
