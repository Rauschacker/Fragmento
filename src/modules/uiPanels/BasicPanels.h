#include "ui/GuiWrapper.h"
#include "imgui/imgui.h"
#include "raylib.h"
#include <array>


Color ColorPicker(const Color& color)
{
	std::array<float, 3> rectColor = {color.r / 255.f, color.g / 255.f , color.b / 255.f } ;
	ImGui::ColorEdit3("Rectangle Color:", rectColor.data());
	Color scaledColor = 
	{
		255 * rectColor[0],
		255 * rectColor[1],
		255 * rectColor[2],
		255
	};
	return scaledColor;
}
