#pragma once
#include "Scene/Scene.h"
#include "ui/GuiWrapper.h"


class DockSpace : public Scene {


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

		ImGui::DockSpaceOverViewport();
	}



};
