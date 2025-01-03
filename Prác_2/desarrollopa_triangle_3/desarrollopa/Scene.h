#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Player.h"

using namespace std;

class Scene
{
private:
	vector<Solid*> gameObjects;
	Player* player;
	Camera camera;
	Vector3D boundary;
	bool drawBoundary;
	void checkBoundary();
	void renderBoundary();

protected:
	void checkBoundary(Solid*);

public:

	Scene(Vector3D boundaryArgument = Vector3D(14, 7, 4)) : boundary(boundaryArgument)
	{
		this->drawBoundary = true;
		this->camera.SetPosition(Vector3D(boundary.GetX() / 2, boundary.GetY() / 2, boundary.GetZ() * 3.5));
	}

	inline Vector3D GetBoundary() { return this->boundary; }
	inline bool GetDrawBoundary() { return this->drawBoundary; }
	inline Player* GetPlayer() { return this->player; }
	inline void SetDrawBoundary(bool drawBoundaryToSet) { this->drawBoundary = drawBoundaryToSet; }


	void AddGameObject(Solid* gameObject);
	void AddPlayer(Player* playerToSet) { this->player = playerToSet; };

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

