#pragma once
#include "Scene/Scene.h"
#include <raylib.h>
#include "Core/Input.h"
#include "Core/Timer.h"

namespace CameraController {



	void OnUpdate(Scene* scene)
	{
		Camera2D& Camera = scene->GetNativeCamera();
		Vector2 deltaPosition = { 0, 0 };
		float distance = FM::Timer::Get().GetDeltaTime() * 1000;
		if (Input::IsKeyDown(KEY_A)) { deltaPosition.x = -distance; }
		if (Input::IsKeyDown(KEY_D)) { deltaPosition.x = distance;  }
		if (Input::IsKeyDown(KEY_S)) { deltaPosition.y = distance;  }
		if (Input::IsKeyDown(KEY_W)) { deltaPosition.y = -distance; }
		Camera.zoom += Input::Mouse::Scroll() * distance / 45;
		Camera.target = Vector2Add(Camera.target, deltaPosition);
	}

}