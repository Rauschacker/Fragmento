#pragma once
#include <raylib.h>
#include "ui/GuiWrapper.h"
#include "Scene/SceneHandler.h"
#include "Scene/Scene.h"
#include <functional>



class Application {


private:

	void Draw();
	Application();

	void Run();

	SceneHandler<Scene> m_SceneHandler;

public:
	
	static Application& Get()
	{
		static Application s_Instance;
		return s_Instance;
	}
	
	static SceneHandler<Scene>& GetSceneHandler()
	{
		return Get().m_SceneHandler; 
	}

	void Start(Scene* baseScene);

public:
		

};

