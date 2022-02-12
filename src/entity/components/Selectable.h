#pragma once
#include "Entity/Entity.h"

enum class SelectabelType
{
	Rectangle,
	Circle,
	Polygon,
};

struct Selctable
{
	SelectabelType Type = SelectabelType::Circle;
};

bool IsSelected(Selctable selectable)
{

}

void SelctableOnUpdate(entt::registry registry)
{
	auto view = registry.view<TransformComponent, SelectabelType>();
	for (auto& entity : view)
	{

	}
}