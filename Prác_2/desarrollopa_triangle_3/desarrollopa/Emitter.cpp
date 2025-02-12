#include "Emitter.h"
#include "iostream"
#include <cmath>

void Emitter::Render()
{
	for (int idx = 0; idx < this->particulas.size(); idx++)
	{
		this->particulas[idx]->Render();
	}
}


void Emitter::Update(const float& time)
{
	
	//vuelves a poner a 0

	for (int idx = 0; idx < this->particulas.size(); idx++)
	{
		this->particulas[idx]->Update(time);
	}
}
	//vuelves a poner a 0

Solid* Emitter::Clone()
{
	return new Emitter(*this);
}