#pragma once
#include <raylib.h>

class Scene;

namespace Input
{
	bool IsKeyPressed(int key);

	bool IsKeyDown(int key);

	bool IsKeyReleased(int key);

	bool IsKeyUp(int key);

}

namespace Input {
namespace Mouse {


	bool Pressed(int key);

	float GetRelativeX();
	float GetRelativeY();

	float Scroll();


	float CameraGetRelativeX(Scene* scene);
	float CameraGetRelativeY(Scene* scene);

	float GetWorldX(Scene* scene);
	float GetWorldY(Scene* scene);

}
}


namespace Key
{
}