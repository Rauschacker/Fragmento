#include "Components.h"
#include "Entity/Entity.h"

BoundBox::BoundBox(Entity& entity) : m_Entity(&entity), Position(&entity.GetComponent<TransformComponent>()) {}

void BoundBox::Clamp()
{

	float clampedX = std::clamp(Position->GetX(), x, x + width);
	float clampedY = std::clamp(Position->GetY(), y, y + height);
	Position->SetX(clampedX);
	Position->SetY(clampedY);
	
}