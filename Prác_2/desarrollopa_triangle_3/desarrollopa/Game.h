#pragma once
#include "Display.h"
#include "Scene.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Player.h" 

using namespace std;

class Game
{
private:

	vector<Scene*> scenes;
	Scene* activeScene;

public:

	Game():activeScene(nullptr) {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

