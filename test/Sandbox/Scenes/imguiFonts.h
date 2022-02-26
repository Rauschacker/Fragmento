#pragma once
#include "Scene/Scene.h"
#include "utility/Logger.h"
#include "ui/ImGuiPanel.h"
#include "imgui/imgui.h"
//#include "utility/FileLoader.h"
#include "utility/Logger.h"

class ImGuiFontsScene : public Scene {

private:

	ImGuiPanel* panel = (ImGuiPanel*)m_SubSceneHandler.CreateAndPushScene("debug", (SubScene*)new ImGuiPanel);
	ImFont* font1;

public:

	ImGuiFontsScene() : Scene()
	{

	}




	virtual void Init() override
	{

		//panel->AddFunc([this] {EntityList(m_Registry); });
		


		ImGuiIO io = ImGui::GetIO();
		//std::string font = File::GetBasicFonts("calibri.ttf");

		//panel->AddFunc([this]{ImGui::PushFont(font1); });
		panel->AddFunc([this]{ ImGui::Text("Hi my name is Herbert. You will die tongiht"); });
		//panel->AddFunc([this] {ImGui::PopFont(); });
		
	}

	virtual void OnUpdate() override
	{
		CameraController::OnUpdate(this);

	
	}

	virtual void OnDraw() override
	{

	}

	virtual void OnOverlayDraw() override
	{
		ImGui::ShowDemoWindow();
	}


};