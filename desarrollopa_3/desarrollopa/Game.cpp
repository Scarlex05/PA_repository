#include "Game.h"
#include <iostream>
#include "Emitter.h"

void Game::Init()
{
	cout << "[GAME] Init..." << endl;

	//Teapot* teapot1 = new Teapot();
	//teapot1->SetPosition(Vector3D(0.0, 0.0,0.0));
	//teapot1->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	//teapot1->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	//this->mainScene.AddGameObject(teapot1);

	Emitter* emitter = new Emitter();
	emitter->SetPosition(Vector3D(0.0, 0.0, 0.0));
	this->mainScene.AddGameObject(emitter);

}

void Game::Render()
{
	this->mainScene.Render();
}

void Game::Update()
{
	//cout << "[GAME] Update..." << endl;
	this->mainScene.Update();
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	//this->display1.ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
