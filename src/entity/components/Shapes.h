#pragma once
#include "Entity/Entity.h"
#include "Components.h"
#include <raylib.h>
#include <limits>


namespace Shapes
{



class Shape : public BasicComponent{

private:

protected:

	TransformComponent* Position;
	Color m_Color = BLACK;

	float borderPadding = 1;

public:

	/* Constructors */

	Shape(Entity& entity) : BasicComponent(entity), Position(&entity.GetComponent<TransformComponent>()) {}

	/* Destructors */

	~Shape() = default;

	/* Virtual Functions*/

	/* Draw The Shape */
	virtual void Draw(Color color = BLACK) {}

	virtual void DrawWireFrame(Color color = BLACK) {}

	virtual bool PointCollide(float x, float y) { return false; }


	Color GetColor() const { return m_Color; }
	void  SetColor(Color color) { m_Color = color; }
	

	/* DEBUG */

	void DrawCenter(Color color = RED, float radius = 5)
	{
		DrawCircle(Position->GetX(), Position->GetY(), radius, color);
	}

};



class Rectangle : public Shape {

private:

	float m_Width;
	float m_Height;

public:

	Rectangle(Entity& entity) : Shape(entity), m_Width(10), m_Height(10) {}

	Rectangle(Entity& entity,float width, float height) : Shape(entity), m_Width(width), m_Height(height) {}

	/*Custom Functions*/

	void SetSize(float width, float height)
	{
		m_Width = width;
		m_Height = height;
	}

	void SetWidth(float width) { m_Width = width; }

	void SetHeight(float height) { m_Height = height; }

	float GetWidth()  const { return m_Width; }
	float GetHeight()  const { return m_Height; }


	/* Function Implementations */

	virtual void Draw(Color color = BLACK) override
	{
		DrawRectangle(Position->GetX(), Position->GetY(), m_Width, m_Height, color);
	}

	virtual bool PointCollide(float x, float y) override
	{
		float xPos = Position->GetX();
		float yPos = Position->GetY();
		
		if (xPos + borderPadding <= x && x <= xPos + m_Width - borderPadding && yPos + borderPadding <= y && y <= yPos + m_Height - borderPadding)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual void DrawWireFrame(Color color = BLACK) override
	{
		auto& position = m_Entity->GetTransform();

		Vector2 topLeft = { position.GetX(), position.GetY() };
		Vector2 topRight = topLeft; topRight.x += m_Width;
		Vector2 bottomLeft = topLeft; bottomLeft.y += m_Height;
		Vector2 bottomRight = bottomLeft; bottomRight.x += m_Width;

		DrawLineV(topLeft, topRight, color);
		DrawLineV(topLeft, bottomLeft, color);
		DrawLineV(topLeft, bottomRight, color); 
		DrawLineV(bottomLeft, bottomRight, color);
		DrawLineV(topRight, bottomRight, color);
		DrawLineV(bottomLeft, topRight, color);
	}


	/*Conversion function*/

	operator ::Rectangle() const
	{
		return ::Rectangle(m_Entity->GetTransform().GetX() , m_Entity->GetTransform().GetY(), m_Width, m_Height);
	} 


};


}