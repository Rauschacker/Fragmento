#pragma once
#include <unordered_map>
#include <string>
#include <stack>
#include <functional>
#include "Scene/SceneState.h"

extern class Scene;
extern class BasicScene;
extern class SubScene;
extern class Application;


template<typename SceneType>
class SceneMap{

private:

	std::unordered_map<std::string, SceneType*> m_Scenes;

public:

	SceneType* CreateScene(std::string sceneName, SceneType* scene)
	{
		m_Scenes.emplace(sceneName, scene);
		SceneType* sceneRef = GetScene(sceneName);
		sceneRef->Init();
		sceneRef->SetHandle(sceneName);
		return sceneRef;
	}

	void DestroyScene(std::string sceneName)
	{
		m_Scenes.erase(sceneName);
	}

	SceneType* GetScene(std::string sceneName)
	{
		return m_Scenes.at(sceneName);
	}

	uint32_t GetSceneMapCount()
	{
		return m_Scenes.size();
	}
};


template<typename SceneType>
class SceneStack {

private:

	std::vector<SceneType*> m_SceneStack;

public:


	SceneType* GetCurrentScene()
	{
		return m_SceneStack.back();
	}

	void PushScene(SceneType* scene, SceneState state = SceneStates::Active)
	{
		scene->GetState() = state;
		m_SceneStack.push_back(scene);
	}
	
	void PopScene()
	{
		SceneType* currentScene = GetCurrentScene();
		currentScene->GetState().remove(SceneState::Visible);
		currentScene->GetState().remove(SceneState::Updating);
		m_SceneStack.pop_back();
	}

	uint32_t GetSceneStackCount()
	{
		return m_SceneStack.size();
	}

	std::vector<SceneType*> GetStack() { return m_SceneStack; }

};

template<typename SceneType>
class SceneHandler {


private:

	SceneMap<SceneType> m_SceneMap;
	SceneStack<SceneType> m_SceneStack;
	bool InputHandled = false;
	

	void Init()
	{

	}

public:

	SceneHandler() { Init(); }

	bool IsInputHandled() { return InputHandled; }

	void Update();
	

	void OnDraw();
	

	SceneType* CreateScene(std::string sceneName, SceneType* scene)
	{
		return m_SceneMap.CreateScene(sceneName, scene);
	}

	void DestroyScene(std::string sceneName)
	{
		m_SceneMap.DestroyScene(sceneName);
	}

	SceneType* GetScene(std::string SceneName)
	{
		return m_SceneMap.GetScene(SceneName);
	}

	SceneType* GetCurrentScene()
	{
		return m_SceneStack.GetCurrentScene();
	}

	void PushScene(std::string scenename, SceneState state = SceneStates::Active)
	{
		m_SceneStack.PushScene(GetScene(scenename), state);
	}
	void PopScene()
	{
		m_SceneStack.PopScene();
	}

	SceneType* CreateAndPushScene(std::string scenename, SceneType* scene, SceneState state = SceneStates::Active)
	{
		SceneType* sceneRef = CreateScene(scenename, scene);
		PushScene(scenename, state);
		return sceneRef;
	}

	uint32_t GetSceneStackCount() { return m_SceneStack.size(); }
	uint32_t GetSceneMapCount() { return m_SceneMap.GetSceneMapCount(); }

	std::string GetActiveSceneName()
	{
		std::string activeSceneKey = "None";
		const Scene* activeScene = m_SceneStack.back();
		/* LOL*/
		return activeSceneKey;
	}

	std::vector<SceneType*> GetSceneStack()
	{
		return m_SceneStack.GetStack();
	}

private:
	friend class SceneHiearchyPanel;


};