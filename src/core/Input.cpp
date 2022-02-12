#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>"

#include "core/Input.h"
#include "core/Window.h"
#include "core/Application.h"

#include "Scene/SceneHandler.h"
#include "Scene/Scene.h"


namespace Input
{
bool IsKeyPressed(int key)
{
	return (::IsKeyPressed(key) && !Application::GetSceneHandler().IsInputHandled());
}

bool IsKeyDown(int key)
{
	return (::IsKeyDown(key) && !Application::GetSceneHandler().IsInputHandled());
}

bool IsKeyReleased(int key)
{
	return (::IsKeyReleased(key) && !Application::GetSceneHandler().IsInputHandled());
}

bool IsKeyUp(int key)
{
	return (::IsKeyUp(key) && !Application::GetSceneHandler().IsInputHandled());
}

}

namespace Input{
namespace Mouse{


bool Pressed(int key)
{
	return ::IsMouseButtonPressed(key);
}
	  
float GetRelativeX()
{
	return Window::Get().GetRelativeTopLeft().x + GetMouseX();
}


float GetRelativeY()
{
	return Window::Get().GetRelativeTopLeft().y + GetMouseY();
}

Vector2 GetRelative()
{
	return { GetRelativeX(), GetRelativeY() };
}

float Scroll()
{
	return GetMouseWheelMove();
}

float CameraGetRelativeX(Scene* scene)
{

	return GetRelativeX() + scene->GetNativeCamera().target.x;
}

float CameraGetRelativeY(Scene* scene)
{
	return GetRelativeY() + scene->GetNativeCamera().target.y;
}



Vector2 GetWorld(Scene* scene)
{
	return GetScreenToWorld2D(GetRelative(), scene->GetNativeCamera());
}

float GetWorldX(Scene* scene)
{
	return GetWorld(scene).x;
}

float GetWorldY(Scene* scene)
{
	return GetWorld(scene).y;
}


}
}