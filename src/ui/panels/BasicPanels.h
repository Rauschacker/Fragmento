#include "ui/GuiWrapper.h"
#include "raylib.h"
#include <array>
#include "entity/Entity.h"
#include "entity/components/Shapes.h"


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

void TagPanel(Entity* entity)
{
	if (ImGui::TreeNode("Tag"))
	{
		ImGui::Text("Name: "); ImGui::SameLine();
		ImGui::Text(entity->GetComponent<TagComponent>().Tag.c_str());
		ImGui::TreePop();
	}

}

void TransformPanel(Entity* entity)
{
	if(ImGui::TreeNode("Transform"))
	{
		auto& transform = entity->GetComponent<TransformComponent>();

		/*Transform*/
		float position[3] = { transform.Position.x, transform.Position.y , transform.Position.z };
		ImGui::Text("Position"); ImGui::SameLine();
		ImGui::DragFloat3("", (float*)position);
		transform.SetPosition({ position[0], position[1], position[2] });

		/*Scale*/
		float scale[3] = { transform.Scale.x, transform.Scale.y , transform.Scale.z };
		ImGui::Text("Scale \t"); ImGui::SameLine();
		ImGui::DragFloat3("", (float*)scale);
		transform.Scale = { scale[0], scale[1], scale[2] };
		ImGui::TreePop();
	}
	
}

void RectanglePanel(Entity* entity)
{
	auto& rect = entity->GetComponent<Shapes::Rectangle>();

	
	if (ImGui::TreeNode("Rectangle"))
	{
		/*Transform*/
		float position[2] = { rect.GetWidth(), rect.GetHeight()};
		ImGui::Text("Size"); ImGui::SameLine();
		ImGui::DragFloat2("", (float*)position);
		rect.SetWidth(position[0]);
		rect.SetHeight(position[1]);
		ImGui::TreePop();
	}
}


void EntityPanel(Entity* entity)
{
	TagPanel(entity);
	TransformPanel(entity);
	if (entity->HasComponent<Shapes::Rectangle>()) { RectanglePanel(entity);}
}

