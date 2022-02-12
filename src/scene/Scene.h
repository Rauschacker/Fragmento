#pragma once
#include "entt/entt.hpp"
#include <raylib.h>
#include "Entity/Components/Components.h"
#include "Core/Input.h"
#include "Scene/SceneState.h"
#include "Scene/SceneHandler.h"	
//#include "Physics/PhysicsController.h"
#include "Entity/EntityRegistry.h"
#include "modules/camera/Camera.h"

class Entity;

class BasicScene
{

protected:
	std::string Handle;
	SceneState m_SceneState;

public:

	BasicScene() = default;
	BasicScene(std::string Handle) : Handle(Handle) {}


	virtual void Init() {}
	virtual void OnUpdate() {}
	virtual void OnDraw() {}
	virtual void OnDraw3D() {}
	virtual void OnOverlayDraw() {}

	SceneState& GetState() { return m_SceneState; }

	/*should be an private member*/
	void SetHandle(std::string handle) { Handle = handle; }

private:


};

class SubScene : public BasicScene
{

public:
	SubScene() : BasicScene() {}

	SubScene(std::string Handle) : BasicScene(Handle) { }


};

class Scene : public EntityRegistry, public BasicScene{

private:

	FMCamera  m_Camera;
	Camera3D m_Camera3D = { 0 };
	
	SceneState m_SceneState;
	
public:

	Scene(std::string Handle) : BasicScene(Handle) { }

	template<typename... Component>
	entt::basic_view<entt::entity, entt::exclude_t<>, Component...> GetView()
	{
		return m_Registry.view<Component...>();
	}

	entt::registry&	GetRegistry() { return m_Registry; }

	SceneHandler<SubScene> m_SubSceneHandler;
	//PhysicsController m_PhysicsController;

	Scene();



	Camera3D& GetCamera3D() { return m_Camera3D; }
	Camera2D& GetNativeCamera() { return m_Camera.GetNativeCamera(); }
	FMCamera& GetCamera() { return m_Camera; }
	void SetCamera(Camera2D camera) { m_Camera.SetCamera(camera); }

protected:

	void Update();
	void Draw();
	void Draw3D();


private:

	SceneHandler<SubScene>& GetSubSceneHandler();

	friend class Entity;
	friend class SceneHandler<Scene>;
	friend class EntityPanel;

};

