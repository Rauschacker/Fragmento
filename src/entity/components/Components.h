#pragma once
#include <raylib.h>
#include <raymath.h>
#include <string>
#include "entt/entt.hpp"
#include <optional>

class Entity;



struct BasicComponent
{

	Entity* m_Entity;

	void SetEntity(Entity* entity) { m_Entity = entity; }

	BasicComponent() = default;

	BasicComponent(Entity& entity) : m_Entity(&entity) {}

	/*needs replacement*/
	virtual void AfterCreation() {}

};

struct TagComponent: BasicComponent
{
	std::string Tag;
	entt::entity Handle;
};

struct TransformComponent : BasicComponent
{
	Vector3 Position = { 0.0f, 0.0f, 0.0f };
	Vector3 Translation = { 0.0f, 0.0f, 0.0f };
	Vector3 Rotation = { 0.0f, 0.0f, 0.0f };
	Vector3 Scale = { 1.0f, 1.0f, 1.0f };

	TransformComponent() = default;
	TransformComponent(const TransformComponent&) = default;
	TransformComponent(const Vector3& translation)
		: Translation(translation) {}
	TransformComponent(const Vector2& Position)
		: Position({Position.x, Position.y, 0}) {}

	float GetX() { return Position.x; }
	float GetY() { return Position.y; }
	float GetZ() { return Position.z; }
	Vector2 GetPosition() { return { Position.x, Position.y }; }
	Vector3 GetPosition3D() { return Position; }

	void SetX(float x) { Position.x = x; }
	void SetY(float y) { Position.y = y; }
	void SetZ(float z) { Position.z = z; }
	void SetPosition(Vector2 position) { Position = { position.x, position.y, Position.z }; }
	void SetPosition(float x, float y) { Position = { x, y, Position.z }; }
	void SetPosition(Vector3 position) { Position = position; }

	void MoveX(float x) { Position.x += x; }
	void MoveY(float y) { Position.y += y; }
	void MoveZ(float z) { Position.z += z; }
	void MovePosition(Vector2 position) { Position = Vector3Add(Position, { position.x, position.y, 0 }); }
	void MovePosition(Vector3 position) { Position = Vector3Add(Position, position); }

};

class BoundBox: public BasicComponent
{
	
	
private:
	float x;
	float y;
	float height;
	float width;
	TransformComponent* Position;

public:

	BoundBox() = default;
 	BoundBox(Entity& entity) : BasicComponent(entity) {}

	void Clamp();
	

};

class SpriteComponent : public BasicComponent
{
	Image m_Image;
	Texture m_Texture;
	std::optional<Texture> m_PreviousTexture = std::nullopt;

public:

	void SetImage(Image imgage) { m_Image = imgage; }

	void DrawSprite();


};





