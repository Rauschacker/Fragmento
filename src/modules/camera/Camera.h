#pragma once
#include <raylib.h>
#include <raymath.h>
#include "core/Window.h"



class FMCamera{


private:


	Camera2D m_Camera;


public:

	FMCamera()
	{
		m_Camera.offset = { 0, 0 };
		m_Camera.target = { 0, 0 };
		m_Camera.zoom = 1;
		m_Camera.rotation = 0.0f;
	}

	Camera2D& GetNativeCamera() { return m_Camera; }

	void SetCamera(Camera2D camera) { m_Camera = camera; }


	Vector2 GetTopLeft() { return m_Camera.target; }

	Vector2 GetBottomLeft()
	{
		return GetScreenToWorld2D({0, Window::Get().GetHeight()}, m_Camera);
	}

	Vector2 GetTopRight()
	{
		return GetScreenToWorld2D({ Window::Get().GetWidth(), 0 }, m_Camera);
	}

	Vector2 GetBottomRight()
	{
		return GetScreenToWorld2D({ Window::Get().GetWidth(), Window::Get().GetHeight() }, m_Camera);
	}


	const float GetWorldWidth  ()
	{
		Vector2 topRight = GetTopRight();
		Vector2 topLeft = GetTopLeft();
		return Vector2Distance(topRight, topLeft);
	}

	float GetWorldHeight()
	{
		Vector2 topLeft = GetTopLeft();
		Vector2 bottomLeft = GetBottomLeft();
		return Vector2Distance(topLeft, bottomLeft);
	}

	Vector2 GetSize()
	{

		return { GetWorldWidth(), GetWorldHeight() };

	}


};
