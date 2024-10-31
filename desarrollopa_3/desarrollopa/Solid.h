#pragma once
#include "Vector3D.h"
#include "Color.h"

class Solid
{
private:
	Vector3D position;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Color color;
public:
	Solid():position(Vector3D(0.0, 0.0, -2.0)), 
		orientation(Vector3D(0, 0, 0)),
		orientationSpeed(Vector3D(0, 0, 0)),
		color(Color(0.2, 0.3, 0.4, 1.0)) {}

	inline Vector3D GetPosition() { return this->position; }
	inline Vector3D GetOrientation() { return this->orientation; }
	inline Vector3D GetOrientationSpeed() { return this->orientationSpeed; }
	inline Color GetColor() { return this->color; }

	void SetPosition(Vector3D coordsToSet) { this->position = coordsToSet; }
	void SetOrientation(Vector3D orientationToSet) { this->orientation = orientationToSet; }
	void SetOrientationSpeed(Vector3D orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	void SetColor(Color colorToSet) { this->color = colorToSet; }

	virtual void Render() = 0;
	virtual void Update();
};

