#pragma once
#include "Scene.h"
#include "GuiWrapper.h"


class TransformComponentPanel : public Scene {


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
		ImGui::Begin("Transform");


		ImGui::End();
		
	}



};
