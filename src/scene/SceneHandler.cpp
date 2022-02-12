#include "Scene/SceneHandler.h"
#include "Scene/Scene.h"
#include <iostream>
#include "imgui/imgui.h"
#include "utility/Logger.h"

void SceneHandler<Scene>::Update()
{
	{
		InputHandled = ImGui::GetIO().WantCaptureMouse;
		// Log::info("InputHandled: {}", InputHandled);
		for (Scene* scene : m_SceneStack.GetStack())
		{
			if (scene->GetState() & SceneState::Updating)
			{
				scene->Update();
				scene->OnUpdate();
				//scene->GetSubSceneHandler().Update();
			}
		}
	}
}

void SceneHandler<SubScene>::Update()
{
	{
		for (SubScene* scene : m_SceneStack.GetStack())
		{
			if (scene->GetState() & SceneState::Updating)
			{
				//scene->Update();
				scene->OnUpdate();
			}


		}
	}
}


void SceneHandler<Scene>::OnDraw()
{
	for (Scene* scene : m_SceneStack.GetStack())
	{
		auto state = scene->GetState();
		if (state & SceneState::Visible)
		{
			if (state & SceneState::Render3D)
			{
				BeginMode3D(scene->GetCamera3D());
				scene->Draw3D();
				scene->OnDraw3D();
				EndMode3D();
			}
			else
			{
				BeginMode2D(scene->GetNativeCamera());
				scene->Draw();
				scene->OnDraw();
				scene->GetSubSceneHandler().OnDraw();
				EndMode2D();
			}
			scene->OnOverlayDraw();
			for (SubScene* subScene : scene->GetSubSceneHandler().GetSceneStack())
			{
				subScene->OnOverlayDraw();
			}
		}
	}
}

template<>
void SceneHandler<SubScene>::OnDraw()
{
	for (SubScene* scene : m_SceneStack.GetStack())
	{
		auto state = scene->GetState();
		if (state & SceneState::Visible)
		{
			if (state & SceneState::Render3D)
			{
			}
			else
			{
				scene->OnDraw();
			}
		}
	}
}