#include "core/Window.h"

Window Window::s_Instance;

void Window::Init()
{
	InitWindow(1280, 720, "Fragmento");

}

void Window::UpdateFrameBuffer()
{
	UnloadRenderTexture(frameBuffer);
	LoadRenderTexture(GetWidth(), GetHeight());
}

void Window::SetFrameBuffer(RenderTexture2D buffer)
{
	frameBuffer = buffer;
}

Vector2 Window::GetRelativeTopLeft()
{
	if (mode == WindowRenderMode::Full)
	{
		return GetTopLeft();
	}
	else
	{
		return RelativeWindowPosition;
	}
}