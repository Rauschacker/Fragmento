#pragma once
#include "Scene/Scene.h"
#include "Modules/CamerController/CameraController.h"
#include "entity/Entity.h"
#include "modules/uiPanels/EntityInfo.h"
#include "modules/gridScene/EntityGrid.h"
#include "modules/entityGrid/EntityGrid.h"
#include "entity/EntityObserver.h"
#if 0
class GameOfLife : public Scene {

private:


	Entity test = CreateEntity("test");
	EntityGrid grid;
	EntityObserver observer;

public:

	virtual void Init() override
	{
		observer.Connect(&m_Registry);
		grid = {{ 10, 10 }, { 10, 10 }, 5};
	}

	virtual void OnUpdate() override
	{
		CameraController::OnUpdate(this);
	}

	virtual void OnDraw() override
	{
		grid.DrawGrid(GREEN);
	}

	virtual void OnOverlayDraw() override
	{
		EntityInfo::Render(test);
	}


};
#endif 