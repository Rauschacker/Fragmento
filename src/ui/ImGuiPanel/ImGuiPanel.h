#pragma once
#include "ui/GuiWrapper.h"
#include <functional>



class ImGuiPanel : SubScene{

private:
	friend class ImGuiPanelController;
	std::vector<std::function<void()>> m_Funcs;



public:

	void AddFunc(std::function<void()> func)
	{
		m_Funcs.push_back(func);
	}

	//virtual void OnDraw() override final {}

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