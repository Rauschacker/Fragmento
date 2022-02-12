#pragma once
#include "Entity/Entity.h"
#include "ui/GuiWrapper.h"
#include "Scene/Scene.h"


class EntityInfo : public Scene
{

private:
	
	Entity entity;
	

public:

	EntityInfo(Entity entity) : entity(entity) {}


	void OnRender()
	{
		auto& entityPosition = entity.GetComponent<TransformComponent>();
		float position[3] = { entityPosition.Position.x, entityPosition.Position.y , entityPosition.Position.z };
		ImGui::Begin("EntityInfo");
		ImGui::Text("Transform");
		ImGui::InputFloat3("Position", (float*)position);
		entityPosition.SetPosition({ position[0], position[1], position[2] });
		ImGui::End();
	}


	static void Render(Entity entity)
	{
		
		auto& entityPosition = entity.GetComponent<TransformComponent>();
		float position[3] = { entityPosition.Position.x, entityPosition.Position.y , entityPosition.Position.z };
		ImGui::Begin("EntityInfo");
		ImGui::Text("Name: "); ImGui::SameLine();
		ImGui::Text(entity.GetComponent<TagComponent>().Tag.c_str());
		ImGui::Text("Transform");
		ImGui::InputFloat3("Position", (float*)position);
		entityPosition.SetPosition({ position[0], position[1], position[2] });
		ImGui::End();

	}

};
