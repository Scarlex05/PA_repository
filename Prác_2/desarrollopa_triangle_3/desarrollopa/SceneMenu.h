#pragma once
#include <GL/glut.h>
#include "Scene.h"
#include "Cuboid.h"

class SceneMenu : public Scene //Hereda de Scene
{
private:
	Cuboid button; // Un cubo que hará de botón

public:
	// void AddGameObject(Solid* gameObject); 

    SceneMenu() {
		button.SetPosition(Vector3D (0, 0, -5));
		button.SetWidth(5.0);
		button.SetHeight(1.);
    }

	bool IsClickInsideButton(int x, int y);

	void Render() override;
	void Update() override;
};

