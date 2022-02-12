#pragma once
#include "Scene/Scene.h"
#include "Scene/SceneHandler.h"
#include "ui/GuiWrapper.h"

class MainMenuBar : public Scene{

	virtual void Init() override
	{

	}

	virtual void OnUpdate() override
	{

	}

	virtual void OnDraw() override
	{

	}

	virtual void OnOverlayDraw() override
	{
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{

				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Settings"))
			{
				if(ImGui::MenuItem("More"))
				{
					//Application::GetSceneHandler().PushScene("settings");
				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}

	}


};