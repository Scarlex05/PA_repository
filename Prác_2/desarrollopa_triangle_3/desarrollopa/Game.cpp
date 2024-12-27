#include "Game.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;


void Game::Init()
{
	cout << "[GAME] Init..." << endl;
	Scene* scene1 = new Scene(); //Menú de juego
	Scene* scene2 = new Scene(); //Juego
	Scene* scene3 = new Scene(); //Pantalla de perder/ganar

	// Crear el jugador
	Player* player1 = new Player(); 
	player1->Init(); 

	// Añadir el jugador a la escena como objeto del juego
	scene2->AddPlayer(player1); 

	this->scenes.push_back(scene1);
	this->scenes.push_back(scene2);
	this->activeScene = scene2; //Se irá cambiando una vez el menú esté realizado
}

void Game::Render()
{
	this->activeScene->Render();
}

void Game::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		//this->activeScene->Update(TIME_INCREMENT); 
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	//this->activeScene->Update();
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
