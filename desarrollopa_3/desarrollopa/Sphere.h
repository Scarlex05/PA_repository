#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Sphere : public Solid
{
private:

	float radius;
	int slices;
	int slacks;

public:

	Sphere() : radius(0.3), slices(10), slacks(8), Solid()
	{}

	inline float GetRadius() { return this->radius; }
	inline int GetSlices() { return this->slices; }
	inline int GetSlacks() { return this->slacks; }

	void SetRadius(float radiusToSet) { this->radius = radiusToSet; }
	void SetSlices(int slicesToSet) { this->slices = slicesToSet; }
	void SetSlacks(int slacksToSet) { this->slacks = slacksToSet; }

	void Render();

};

