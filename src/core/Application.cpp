#include "Core/Application.h"
#include "Core/Window.h"
#include "Core/Timer.h"
#include <iostream>
//#include "Utility/Logger.h"
#include "ui/GuiWrapper.h"


Application::Application()
{	
	SetExitKey(0);
	Window::Get().Init();
	ImGuiWrapper::Get().Init();
	Window::Get().frameBuffer = LoadRenderTexture(Window::Get().GetWidth(), Window::Get().GetHeight());
}

void Application::Start(Scene* baseScene)
{
	m_SceneHandler.CreateAndPushScene("base", baseScene, SceneState::HiearchyPanelHidden);
	Run();
}

void Application::Run()
{	

	while (!WindowShouldClose())
	{
		FM::Timer::Get().NewFrame();
		BeginRLImGui();
		Application::GetSceneHandler().Update();
		if (Window::Get().mode == WindowRenderMode::Viewport)
		{
			BeginTextureMode(Window::Get().frameBuffer);
			Draw();
			EndTextureMode();
			BeginDrawing();
			DrawTexture(Window::Get().frameBuffer.texture, 0, 0, WHITE);
		}
		else
		{
			BeginDrawing();
			Draw();
			DrawTexture(Window::Get().frameBuffer.texture, 0, 0, WHITE);
		}
		EndRLImGui();
		ImGuiWrapper::Get().AfterRender();
		EndDrawing();
		FM::Timer::Get().EndFrame();
	}

	CloseWindow();	
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(DARKGRAY);
	GetSceneHandler().OnDraw();	
}

