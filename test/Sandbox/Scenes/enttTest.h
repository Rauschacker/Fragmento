#pragma once
#include "Scene/Scene.h"
#include "Modules/CamerController/CameraController.h"
#include "entity/Entity.h"
#include "modules/uiPanels/EntityInfo.h"
#include "entity/EntityObserver.h"
#include "ui/ImGuiPanel/ImGuiPanel.h"
#include "entity/components/Shapes.h"
#include "modules/uiPanels/EntityList.h"
#include "modules/uiPanels/BasicPanels.h"
#include "utility/Logger.h"

class enttTest : public Scene {

private:


	int entityCount = 7;
	ImGuiPanel* panel = (ImGuiPanel*)m_SubSceneHandler.CreateAndPushScene("debug", (SubScene*)new ImGuiPanel);
	
	std::array<float, 3> rectColor{ 0, 0, 0 };
	Entity testEntity;
	

	int item_current = 0;


public:

	enttTest() : Scene()
	{

	}


	void CreateTestEntity()
	{
		
		testEntity.AddComponent<Shapes::Rectangle>(testEntity, 20, 20);
	}

	virtual void Init() override
	{
		testEntity = CreateEntity("Test");
		CreateTestEntity();

		panel->AddFunc([this]{EntityList(m_Registry);});


		panel->AddFunc([this]
			{
			Color color = testEntity.GetComponent<Shapes::Rectangle>().GetColor();
			color = ColorPicker(color);
			testEntity.GetComponent<Shapes::Rectangle>().SetColor(color); 
			});
	
	}

	virtual void OnUpdate() override
	{
		CameraController::OnUpdate(this);
	}

	virtual void OnDraw() override
	{
		auto& rect = testEntity.GetComponent<Shapes::Rectangle>();
		rect.Draw(rect.GetColor());
	}

	virtual void OnOverlayDraw() override
	{	
	}


};