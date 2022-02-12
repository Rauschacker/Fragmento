#define RAYGUI_IMPLEMENTATION
#include "GuiWrapper.h"

#include "utility/FileLoader.h"
#include "utility/Logger.h"


ImGuiWrapper ImGuiWrapper::s_Instance;


void ImGuiWrapper::Init()
{
	SetupRLImGui(true);
	ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
	ImGuiIO& io = ImGui::GetIO(); 
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
	io.ConfigFlags |= ImGuiDockNodeFlags_PassthruCentralNode;
	auto font = ImGui::GetIO().Fonts->AddFontFromFileTTF(File::GetFont("roboto/Roboto-Black.ttf").string().c_str(), 18);
	ImGui::GetIO().FontDefault = font;
	FinishRLGLImguSetup();
}

void ImGuiWrapper::AfterRender()
{
	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();
}