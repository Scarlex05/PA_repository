#include "Solid.h"

void Solid::Update(const float& time)
{
	//no funcionan los +
	this->SetPosition(this->GetPosition() + this->GetSpeed() * time);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
}
