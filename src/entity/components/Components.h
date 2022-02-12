#pragma once
#include <raylib.h>
#include <raymath.h>
#include <string>
#include "entt/entt.hpp"

class Entity;

struct TagComponent
{
	std::string Tag;
	entt::entity Handle;
};

struct TransformComponent
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

class BoundBox
{
	
	
private:
	float x;
	float y;
	float height;
	float width;
	Entity* m_Entity;
	TransformComponent* Position;

public:
	BoundBox(Entity& entity);

	void Clamp();
	

};



