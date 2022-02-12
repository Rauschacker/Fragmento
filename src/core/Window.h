#pragma once
#include <raylib.h>


enum class WindowRenderMode
{
	Viewport,
	Full
};

class Window {

private:

	WindowRenderMode mode = WindowRenderMode::Full;
	RenderTexture2D frameBuffer;
	Vector2 RelativeWindowPosition = { 0, 0 };
	Vector2 RelativeSize = { (float)GetScreenWidth(),  (float)GetScreenHeight() };

	void UpdateFrameBuffer();
	void SetFrameBuffer(RenderTexture2D frameBuffer);


public:

	static Window& Get() { return s_Instance; }
		
	float GetWidth() {
		if (mode == WindowRenderMode::Full)
		{
			return GetScreenWidth();
		}
		else
		{
			RelativeSize.x;
		}
		
	}

	float GetHeight() {
		if (mode == WindowRenderMode::Full)
		{
			return GetScreenHeight();
		}
		else
		{
			RelativeSize.y;
		}
	}

	Vector2 GetSize()
	{
		return { GetWidth(), GetHeight() };
	}


	
	Vector2 GetRelativeTopLeft();

	Vector2 GetCenter()			{ return { GetWidth() / 2.f	, GetHeight() / 2.f		}; }
	Vector2 GetTopLeft()		{ return { 0.f				, 0.f					}; }
	Vector2 GetTopRight()		{ return { GetWidth()		, 0.f					}; }
	Vector2 GetBottomLeft()		{ return { 0.f				, GetHeight()			}; }
	Vector2 GetBottomRight()	{ return { GetWidth()		, GetHeight()			}; }


private:
	Window() {}
	void Init();
	static Window s_Instance;
	friend class Application;
	friend class GameViewPort;
};
