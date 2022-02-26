#pragma once
#include "scene/Scene.h"
#include "ui/GuiWrapper.h"
#include <functional>



class ImGuiPanel : public SubScene{

private:
	friend class ImGuiPanelController;
	std::vector<std::function<void()>> m_Funcs;


public:

	void AddFunc(std::function<void()> func)
	{
		m_Funcs.push_back(func);
	}

	//virtual void OnDraw() override final {}
	
	static ImGuiPanel* Create(Scene* sceneRef)
	{
		return (ImGuiPanel*)sceneRef->m_SubSceneHandler.CreateAndPushScene("imguiPanel", new ImGuiPanel);
	}

protected:
	
	virtual void OnOverlayDraw() override
	{
		ImGui::Begin("Panel");
		for (auto& func : m_Funcs)
		{
			func();
		}
		ImGui::End();
	}




};