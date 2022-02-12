#pragma once
#include "Scene/Scene.h"
#include "GUI/GuiWrapper.h"
#include "Core/Window.h"
#include "Utility/ImageLoader.h"
#include "ImGuiPanel.h"



class GameViewPort : public ImGuiPanel {


private:

	RenderTexture2D frameBuffer;
	Texture texture;
	float windowWidth = Window::Get().GetWidth();
	float windowHeight = Window::Get().GetHeight();

	Vector2 BottomLeft;

	virtual void Init() override
	{
		//UpdateWindowPosition();
		Window::Get().mode = WindowRenderMode::Viewport;
	}

	void UpdateWindowPosition()
	{
		ImVec2 bottomLeft = ImGui::GetWindowContentRegionMin();
		BottomLeft.x = bottomLeft.x;
		BottomLeft.y = bottomLeft.y;
		Vector2& relativePosition = Window::Get().RelativeWindowPosition;
		relativePosition.x = BottomLeft.x;
		relativePosition.y = BottomLeft.y;
	}

	virtual void OnUpdate() override
	{
		//UpdateWindowPosition();
		UnloadRenderTexture(frameBuffer);
		frameBuffer = LoadRenderTexture(windowWidth, windowHeight);
		Window::Get().SetFrameBuffer(frameBuffer);
	}

	virtual void OnDraw() override
	{
		
	}

	virtual void OnOverlayDraw() override
	{
#if 0	
		ImGui::Begin("Viewport", &show, ImGuiWindowFlags_NoScrollbar);
		ImVec2 winSize = ImGui::GetWindowSize();
		
		windowWidth = winSize.x;
		windowHeight = winSize.y;
		texture = Window::Get().frameBuffer.texture;
		RLImGuiImage(&texture);
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddImage(
			&texture,
			ImVec2(ImGui::GetCursorScreenPos()),
			ImVec2(ImGui::GetCursorScreenPos().x + Window::Get().GetWidth() / 2,
				ImGui::GetCursorScreenPos().y + Window::Get().GetHeight() / 2), ImVec2(0, 1), ImVec2(1, 0));
		ImGui::End();
#else

		texture = Window::Get().frameBuffer.texture;
		RLImGuiImage(&texture);
		ImGuiWindowFlags flags =
			ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoScrollbar;
		ImGui::Begin("GameWindow", &show, flags);
		{
			// Using a Child allow to fill all the space of the window.
			// It also alows customization
			ImGui::BeginChild("GameRender");
			// Get the size of the child (i.e. the whole draw size of the windows).
			ImVec2 wsize = ImGui::GetWindowSize();
			// Because I use the texture from OpenGL, I need to invert the V from the UV.
			ImGui::Image(&texture, wsize, ImVec2(0, 1), ImVec2(1, 0));
			ImGui::EndChild();
		}
		ImGui::End();

#endif

	}



};
/*
class GameViewPort : public ImGuiPanel {


private:

	Texture texture;
	RenderTexture2D frameBuffer;
	float windowWidth = Window::Get().GetWidth();
	float windowHeight = Window::Get().GetHeight();
	float x = 500;
	float y = 500;
	float r = 10;

	virtual void Init() override
	{
		texture = FMLoadTexture("debug/god_boop.png");
		

	}

	virtual void OnUpdate() override
	{
		UnloadRenderTexture(frameBuffer);
		frameBuffer = LoadRenderTexture(windowWidth, windowHeight);
		Window::Get().SetFrameBuffer(frameBuffer);
	}

	virtual void OnDraw() override
	{
		ImGui::Begin("ControllStuff");
		ImGui::SliderFloat("x", &x, 0, 500);
		ImGui::SliderFloat("y", &y, 0, 500);
		ImGui::SliderFloat("r", &r, 0, 500);
		ImGui::End();
		DrawCircle(x, y, r, RED);
	}

	virtual void OnOverlayDraw() override
	{
		ImGui::Begin("Viewport", &show, ImGuiWindowFlags_NoScrollbar);
		ImVec2 winSize = ImGui::GetWindowSize();
		windowWidth = winSize.x;
		windowHeight = winSize.y;
		texture = Window::Get().frameBuffer.texture;
		RLImGuiImage(&texture);
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddImage(
			&texture,
			ImVec2(ImGui::GetCursorScreenPos()),
			ImVec2(ImGui::GetCursorScreenPos().x + Window::Get().GetWidth() / 2,
				ImGui::GetCursorScreenPos().y + Window::Get().GetHeight() / 2), ImVec2(0, 1), ImVec2(1, 0));

		//we are done working with this window
		ImGui::End();
		
	
	}
	


};
*/