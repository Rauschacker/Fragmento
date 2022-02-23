#include "scene/Scene.h"
#include "modules/camerController/CameraController.h"
#include "entity/Entity.h"
#include "modules/animation/Animation.h"
#include "utility/FileLoader.h"
#include "entity/components/Components.h"
#include "ui/ImGuiPanel/ImGuiPanel.h"
#include "modules/uiPanels/EntityInfo.h"


class SpriteTest : public Scene
{

private:


	Entity player = CreateEntity("player");
	ImGuiPanel* debug = (ImGuiPanel*)m_SubSceneHandler.CreateAndPushScene("debug", new ImGuiPanel);

public:

	virtual void Init() override
	{

		//Texture texture = LoadTexture(File::GetAssetFile("sprites/god_boop.png").c_str());

		Image image = LoadImage(File::GetAssetFile("sprites/god_boop.png").c_str());

		player.AddComponent<Shapes::Rectangle>(player).SetSize(100, 100);
		player.AddComponent<SpriteComponent>().SetImage(image);


		debug->AddFunc([this] {EntityPanel(&player);});
	
	}

	virtual void OnUpdate() override
	{
		CameraController::OnUpdate(this);
	}

	virtual void OnDraw() override
	{
		auto& rect = player.GetComponent<Shapes::Rectangle>();
		auto& sprite = player.GetComponent<SpriteComponent>();
		//rect.Draw(WHITE);
		sprite.DrawSprite();
		rect.DrawWireFrame();
		///Log::info("test");
	}

};