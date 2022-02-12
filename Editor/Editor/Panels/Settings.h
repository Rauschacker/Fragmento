#pragma once
#include "Scene/Scene.h"
#include "GUI/GuiWrapper.h"


class Settings : public Scene {


private:

	int item_current = 1;

public:

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
		ImGui::Begin("Settings");


		ImGui::End();

	}



};

