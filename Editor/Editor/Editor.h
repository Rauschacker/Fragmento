#include "core/Application.h"
#include "scene/Scene.h"

#include "Editor/Panels/Dockspace.h"	
#include "Editor/Panels/MainMenuBar.h"	
#include "Editor/Panels/GameViewPort.h"

namespace Editor
{


	class Editor : public Scene {

	private:


	public:

		virtual void Init() override
		{
			//Application::GetSceneHandler().CreateAndPushScene("dock_space", new DockSpace, SceneStates::EditorScene);
			//Application::GetSceneHandler().CreateAndPushScene("main_menu_bar", new DockSpace, SceneStates::EditorScene);
			Application::GetSceneHandler().CreateAndPushScene("main_menu_bar", new MainMenuBar, SceneStates::EditorScene);
			Application::GetSceneHandler().CreateAndPushScene("main_menu_bar", new GameViewPort, SceneStates::EditorScene);
			//Application::GetSceneHandler().CreateAndPushScene("game_view_port", new GameViewPort, SceneStates::EditorScene);
			//Application::GetSceneHandler().CreateAndPushScene("scene_hiearchy_panel", new SceneHiearchyPanel, SceneStates::EditorScene);
			//Application::GetSceneHandler().CreateAndPushScene("entity_panel", new EntityPanel, SceneStates::EditorScene);
			//Application::GetSceneHandler().CreateAndPushScene("test_Scene", new TestScene);
		}


	};


	void StartEditor(Scene* startScene)
	{
		Application::GetSceneHandler().CreateAndPushScene("editor", new Editor);
		Application::Get().Start(startScene);
	}




}


