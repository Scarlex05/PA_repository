#include "Game.h"
#include <iostream>


void Game::Init()
{
	cout << "[GAME] Init..." << endl;
	Scene* scene0 = new Scene(); //Menú de juego
	Scene* scene1 = new Scene(); //Juego
	Scene* scene2 = new Scene(); //Pantalla de perder/ganar

	// Crear el jugador
	Player* player1 = new Player(); 
	player1->Init();

	// Añadir el jugador a la escena como objeto del juego
	scene2->AddPlayer(player1);

	this->scenes.push_back(scene0);
	this->scenes.push_back(scene1);
	this->activeScene = scene1; //Se irá cambiando una vez el menú esté realizado
}

void Game::Render()
{
	this->activeScene->Render();
}

void Game::Update()
{
	//cout << "[GAME] Update..." << endl;

	this->activeScene->Update();
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "tecla pulsada: " << key << endl;

	/*int index = (key - '0') - 1;
	if (index < this->scenes.size())
	{
		this->activeScene = this->scenes[index];
	}*/
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
