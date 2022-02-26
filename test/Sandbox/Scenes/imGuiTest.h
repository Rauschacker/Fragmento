#include "scene/Scene.h"
#include "ui/ImGuiPanel.h"
#include "entity/components/Shapes.h"
#include "ui/panels/BasicPanels.h"

class ImGuiTestScene : public Scene{


private:

	Entity player = CreateEntity("player");
	ImGuiPanel* panel = ImGuiPanel::Create(this);

	

public:


	virtual void Init() override
	{
		player.AddComponent<Shapes::Rectangle>();
		panel->AddFunc([this] {ImguiRender(); });
	}

	void ImguiRender()
	{
		EntityPanel(&player);
		ImGui::ShowDemoWindow();
	}

	virtual void OnUpdate() override
	{
		player.GetComponent<Shapes::Rectangle>().Draw(WHITE);
	}


};
