#include "Scene/Scene.h"
#include "Scene/SceneHandler.h"
#include "Entity/Entity.h"
#include "Entity/Components/Components.h"
//#include "Modules/Animation/AnimationPlayer.h"
#include "Core/Input.h"
#include "Entity/Components/PlayerController2D.h"
#include "Core/Window.h"

Scene::Scene() : BasicScene()
{

}

void Scene::Update()
{
	//m_PhysicsController.Update();
}

void Scene::Draw()
{
}

void Scene::Draw3D()
{
}

SceneHandler<SubScene>& Scene::GetSubSceneHandler(){ return m_SubSceneHandler; }
