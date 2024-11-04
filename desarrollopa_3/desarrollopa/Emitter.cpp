#include "Emitter.h"

void Emitter::Render()
{
	for (int idx = 0; idx < this->particulas.size(); idx++)
	{
		this->particulas[idx]->Render();
	}
}

void Emitter::Update()
{
	{
		milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		//currentTime es el tiempo desde 1970 (tiempo donde windows comenzó a contar) y se lo resta a initialMilliseconds
		//que es el tiempo en milisegundos hasta ahora, y eso se lo resta al tiempo transcurrido desde al última iteración
		//de una partícula y se compara con el periodo de emisión
		if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > this->configuracion->GetmiliSeconds())
		{

			this->particulas.push_back(this->configuracion->GetParticula()->Clone());
			this->particulas[this->particulas.size() - 1]->SetVelocidad(Vector3D(0, 0, 0));

			//se reinicia 
			this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		}
		//vuelves a poner a 0
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}
}


Solid* Emitter::Clone()
{
	return new Emitter(*this);
}
