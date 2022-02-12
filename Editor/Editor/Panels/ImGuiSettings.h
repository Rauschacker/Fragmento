#pragma once
#include "Scene/Scene.h"
#include "GUI/GuiWrapper.h"

class ImGuiSettings : public Scene {

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
		ImGuiStyle* style = &ImGui::GetStyle();
		ImVec4* colors = style->Colors;
		

		ImGui::Begin("Style Settings");
		if (ImGui::SliderFloat("FrameBorderSize", &style->FrameBorderSize, 0.0f, 100.f));
		if (ImGui::SliderFloat("TabBorderSize", &style->TabBorderSize, 0.0f, 100.f));
		if (ImGui::SliderFloat("WindowRounding", &style->WindowRounding, 0.0f, 100.f));
		if (ImGui::SliderFloat("FrameRounding", &style->FrameRounding, 0.0f, 100.f));

		
		ImGui::End();

	}


};
