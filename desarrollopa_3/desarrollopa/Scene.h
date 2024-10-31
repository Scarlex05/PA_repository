#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"

using namespace std;

class Scene
{
private:
	vector<Solid*> gameObjects;
	Camera camera;

public:

	Scene()
	{
		this->camera.SetPosition(Vector3D(0, 0, 2));
	}

	void AddGameObject(Solid* gameObject);

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

