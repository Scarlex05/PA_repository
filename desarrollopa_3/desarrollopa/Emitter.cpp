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

void Emitter::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	//currentTime es el tiempo desde 1970 (tiempo donde windows comenzó a contar) y se lo resta a initialMilliseconds
	//que es el tiempo en milisegundos hasta ahora, y eso se lo resta al tiempo transcurrido desde al última iteración
	//de una partícula y se compara con el periodo de emisión
	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > this->configuracion->GetmiliSeconds())
	{
		Solid* particle = this->configuracion->GetParticula()->Clone();
		this->angulo += 10.0f;
		double radianes = angulo * (3.141592653979323846267 / 180.0);
		double seno = sin(radianes);
		double coseno = cos(radianes);
		particle->SetOrientation(Vector3D(seno, coseno, 0)); 
		particle->SetVelocidad(Vector3D(0, .01, 0));
		particle->SetOrientationSpeed(Vector3D(0, 0, 1));
		particle->SetColor(Color((float)rand()/RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1));


		this->particulas.push_back(particle);
		//this->particulas[this->particulas.size() - 1]->);
		//this->particulas[this->particulas.size() - 1];

		//se reinicia
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

		cout << this->lastUpdatedTime << endl;
	}
	//vuelves a poner a 0

	for (int idx = 0; idx < this->particulas.size(); idx++)
	{
		this->particulas[idx]->Update();
	}
}


Solid* Emitter::Clone()
{
	return new Emitter(*this);
}
