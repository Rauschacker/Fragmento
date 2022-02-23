#include "core/Application.h"
#include "scene/Scene.h"

#include "Scenes/enttTest.h"
#include "Scenes/imguiFonts.h"
#include "Scenes/assetsFolderScene.h"
#include "Scenes/spriteTest.h"

#include "Editor/Editor.h"

class Game : public Scene {

private:


public:

	virtual void Init() override
	{
		Application::GetSceneHandler().CreateAndPushScene("gameOfLife", new SpriteTest);
		//Log::info("Start");
	}


};


int main(int argc, char** argv) {
	//Editor::StartEditor(new Game);
	Application::Get().Start(new Game);
}