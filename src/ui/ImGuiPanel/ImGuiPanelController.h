#pragma once
#include "Scene/Scene.h"
#include "ImGuiPanel.h"
#include <unordered_map>
#include <string>

using PanelID = int;


class ImGuiPanelController: public Scene
{


private:

	std::map<PanelID, ImGuiPanel*> m_Panels;
	PanelID idCounter = 0;


public:

	PanelID AddPanel(std::string identifier)
	{
		idCounter++;
		m_Panels.emplace(idCounter, new ImGuiPanel);
		return idCounter;
	}

	ImGuiPanel* GetPanel(PanelID id)
	{
		return m_Panels.at(id);
	}

protected:


	virtual void Init() override
	{

	}

	virtual void OnUpdate() override
	{

	}

	virtual void OnOverlayDraw() override
	{
		for (auto& mapPanel : m_Panels)
		{
			auto& panel = mapPanel.second;
			panel->OnStart();
			panel->OnUpdate();
			panel->OnEnd();
		}

	}


};