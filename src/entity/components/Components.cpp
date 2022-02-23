#include "Components.h"
#include "Entity/Entity.h"
#include "Shapes.h"
#include "utility/Logger.h"


void BoundBox::Clamp()
{

	float clampedX = std::clamp(Position->GetX(), x, x + width);
	float clampedY = std::clamp(Position->GetY(), y, y + height);
	Position->SetX(clampedX);
	Position->SetY(clampedY);
	
}


void SpriteComponent::DrawSprite()
{
	//Log::info("drawing");
	auto& position = m_Entity->GetTransform();
	auto& rect = m_Entity->GetComponent<Shapes::Rectangle>();

	
	
	Image image = ImageCopy(m_Image);
	ImageResize(&image, rect.GetWidth(), rect.GetHeight());
	Texture m_Texture = LoadTextureFromImage(image);
	
	DrawTexture(m_Texture, position.GetX(), position.GetY(), WHITE);


	if (m_PreviousTexture == std::nullopt)
	{
		m_PreviousTexture = m_Texture;
	}
	else
	{
		UnloadTexture(m_PreviousTexture.value());
		m_PreviousTexture = m_Texture;
	}

	//UnloadTexture(scaledTexture);
	UnloadImage(image);
}
