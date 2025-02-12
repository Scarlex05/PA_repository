#pragma once
#include "Scene.h"
#include "Cuboid.h"

class SceneMenu : public Scene //Hereda de Scene
{
private:
	Cuboid button; // Un cubo que hará de botón

public:
	// void AddGameObject(Solid* gameObject); 

    SceneMenu() {
		button.SetPosition(Vector3D (0, 0, 0)); // Ajusta la posición según tu escena
		button.SetWidth(1.0);
		button.SetHeight(0.5);
    }

	bool IsClickInsideButton(int x, int y);

	void Render() override;
	void Update() override;
};

