#pragma once
#include "ui/GuiWrapper.h"
#include <string>
#include "Core/Input.h"

class Scene;

void MouseInfo(Scene* scene)
{

	ImGui::Begin("Mouse Info");
	ImGui::Text("Absolute");
	ImGui::Text(std::string("x: " + std::to_string(GetMouseX())).c_str()); ImGui::SameLine();
	ImGui::Text(std::string("y: " + std::to_string(GetMouseY())).c_str());
	ImGui::Text("Relative");
	ImGui::Text(std::string("x: " + std::to_string((int)Input::Mouse::GetRelativeX())).c_str()); ImGui::SameLine();
	ImGui::Text(std::string("y: " + std::to_string((int)Input::Mouse::GetRelativeY())).c_str());
	ImGui::Text("Camera Relative");
	ImGui::Text(std::string("x: " + std::to_string((int)Input::Mouse::CameraGetRelativeX(scene))).c_str()); ImGui::SameLine();
	ImGui::Text(std::string("y: " + std::to_string((int)Input::Mouse::CameraGetRelativeY(scene))).c_str());
	ImGui::Text("World");
	ImGui::Text(std::string("x: " + std::to_string((int)Input::Mouse::GetWorldX(scene))).c_str()); ImGui::SameLine();
	ImGui::Text(std::string("y: " + std::to_string((int)Input::Mouse::GetWorldY(scene))).c_str());
	ImGui::End();

}