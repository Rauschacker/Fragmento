#pragma once 
#include <raylib.h>
#include <rlgl.h>
//#include <raygui.h>
#include "imgui/imgui.h"
#include "rlImGui/rlImGui.h"

/*
#include "imgui/imgui.h"
#include "GLFW/glfw3.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
*/


class ImGuiWrapper {


private:

	friend class Application;

	static ImGuiWrapper s_Instance;

	void Init();

	void AfterRender();

public:



	static ImGuiWrapper& Get() { return s_Instance; }

};