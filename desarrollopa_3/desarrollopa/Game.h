#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Display.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Scene.h"

using namespace std;

class Game
{
private:

	Scene mainScene;

public:

	Game() {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

