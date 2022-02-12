#pragma once
#include "Scene/Scene.h"
#include "Scene/SceneHandler.h"
#include "GUI/GuiWrapper.h"
#include <vector>
#include "Entity/Entity.h"
#include "ImGuiPanel.h"
#include "SceneHiearchyPanel.h"
#include "Components/ComponentPanel.h"
#include "Entity/Components/Components.h"
#include <optional>

class EntityPanel : public ImGuiPanel {


private:

	int item_current = 0;
	int selected_item = 0;

	std::optional<Scene*> selectedScene;
	entt::entity selectedEntityHandle = entt::null;

	std::vector<std::string>  entityNames;
	std::vector<Entity>  entityRefs;



	SceneHiearchyPanel* sceneHiearchyPanel;
	ImGuiChildPanel* componentPanel;

	char entityName[50];

public:

	virtual void Init() override
	{
		Scene* HiearchyPanel = Application::GetSceneHandler().GetScene("scene_hiearchy_panel");
		sceneHiearchyPanel = (SceneHiearchyPanel*)HiearchyPanel;
		componentPanel = AddChildPanel((ImGuiChildPanel*)(new ComponentPanel));
	}

	virtual void OnUpdate() override
	{
		UpdateEntityNames();
		UpdateSelectedEntity();
		componentPanel->OnUpdate();
	}

	virtual void OnDraw() override
	{

	}
	
	std::optional<Entity> GetSelectedEntity()
	{
		UpdateSelectedEntity();
		if (selectedEntityHandle != entt::null && selectedScene.has_value())
		{
			return Entity{ selectedEntityHandle , selectedScene.value() };
		}
		else
		{
			return std::nullopt;
		}
			
	}

	void UpdateSelectedEntity()
	{
		if (selectedScene.has_value())
		{
			if (entityRefs.size() > 0)
			{
				selectedEntityHandle = entityRefs[item_current];
			}
			else
			{
				selectedEntityHandle = entt::null;
			}

		}
		
	}

	void UpdateEntityNames()
	{
		selectedScene = sceneHiearchyPanel->GetSelectedScene();
		entityNames.clear();
		entityRefs.clear();
		if (!selectedScene.has_value()) { return; }
		auto view = selectedScene.value()->m_Registry.view<TagComponent>();
		for (auto& entity : view)
		{
			auto& tag = view.get<TagComponent>(entity);
			entityNames.push_back(tag.Tag);
			entityRefs.push_back(GetEntity(tag.Handle));
		}


	}

	virtual void OnOverlayDraw() override
	{
		ImGui::Begin("Entities");
		Panel();
		EntitySettings();
		ImGui::End();

	}

	void Panel()
	{
		char** items = new char* [entityNames.size()];
		for (size_t i = 0; i < entityNames.size(); i++) {
			items[i] = new char[entityNames[i].size() + 1];
			strcpy(items[i], entityNames[i].c_str());
		}

		if(selectedScene.has_value())
		{
			ImGui::Text("Entities: ");
			ImGui::SameLine();
			ImGui::Text((selectedScene.value()->Handle).c_str());
			if (ImGui::BeginListBox("Entity Hiearchy", ImVec2(-FLT_MIN, 10 * ImGui::GetTextLineHeightWithSpacing())))
			{
				for (int n = 0; n < entityNames.size(); n++)
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
		else
		{
			ImGui::Text("No Scene Selcted");
		}

	}

	void EntitySettings()
	{
		componentPanel->OnImGuiRender();
	}

};