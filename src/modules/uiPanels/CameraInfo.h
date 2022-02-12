#pragma once
#include "ui/GuiWrapper.h"
#include <raylib.h>
#include <string>


void CameraInfo(const Camera2D& camera)
{

	ImGui::Begin("Camera Info");
	ImGui::Text("Target");
	ImGui::Text(std::string("x: " + std::to_string(camera.target.x)).c_str()); ImGui::SameLine();
	ImGui::Text(std::string("y: " + std::to_string(camera.target.y)).c_str());
	ImGui::Text("Offset");
	ImGui::Text(std::string("x: " + std::to_string(camera.offset.x)).c_str()); ImGui::SameLine();
	ImGui::Text(std::string("y: " + std::to_string(camera.offset.y)).c_str());
	ImGui::Text("Zoom");
	ImGui::Text(std::string("x: " + std::to_string(camera.zoom)).c_str());
	ImGui::Text("Rotation");
	ImGui::Text(std::string("x: " + std::to_string(camera.rotation)).c_str());

	ImGui::End();

}