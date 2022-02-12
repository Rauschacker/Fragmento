#pragma once
#include "Scene/Scene.h"
#include "Scene/SceneHandler.h"
#include "GUI/GuiWrapper.h"
#include "Core/Application.h"
#include <vector>
#include <optional>

class SceneHiearchyPanel : public Scene {


private:

	int item_current = -1;
	int selected_item = -1;
	std::vector<std::string>  sceneNames;

	
public:

	virtual void Init() override
	{
		UpdateSceneNames();
	}

	virtual void OnUpdate() override
	{
		UpdateSceneNames();
	}

	virtual void OnDraw() override
	{

	}

	std::optional<Scene*> GetSelectedScene()
	{
		if (item_current > -1)
		{
			return Application::GetSceneHandler().GetScene(sceneNames[item_current]);
		}
		else
		{
			return std::nullopt;
		}
		
	}

	void UpdateSceneNames()
	{
		sceneNames.clear();
		for (auto& kv : Application::GetSceneHandler().m_Scenes) {
			if (!(kv.second->GetState() & SceneState::HiearchyPanelHidden))
			{
				sceneNames.push_back(kv.first);
			}
			
		}
	}

	virtual void OnOverlayDraw() override
	{
			ImGui::Begin("Scene Hiearchy");
			ScenePanel();
			SeceneSettings();
			ImGui::End();
		
	}

	void ScenePanel()
	{

		char** items = new char* [sceneNames.size()];
		for (size_t i = 0; i < sceneNames.size(); i++) {
			items[i] = new char[sceneNames[i].size() + 1];
			strcpy(items[i], sceneNames[i].c_str());
		}

		bool show = 1;
		ImGui::ShowDemoWindow(&show);



		ImGui::Text("Scenes");
		if (ImGui::BeginListBox("Scene Hiearchy", ImVec2(-FLT_MIN, 10 * ImGui::GetTextLineHeightWithSpacing())))
		{
			for (int n = 0; n < sceneNames.size(); n++)
			{
				const bool is_selected = (item_current == n);
				if (ImGui::Selectable(items[n], is_selected))
					item_current = n;

				// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndListBox();
		}

	}

	void SeceneSettings()
	{
		ImGui::Text("Options");
		ImGui::Button("Delete");
	}

};
