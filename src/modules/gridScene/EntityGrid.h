#pragma once
#include "Scene/Scene.h"
#include "Scene/SceneHandler.h"
#include "Entity/Entity.h"
#include "Entity/Components/Shapes.h"
#include "Core/Input.h"
#include <optional>
#include <vector>
#include "entt/entt.hpp"

enum class Directions
{
	Top,
	Left,
	Bottom,
	Right
};

struct GridNode
{
	Vector2 Position;
	std::optional<GridNode*> Top = std::nullopt;
	std::optional<GridNode*> Right = std::nullopt;
	std::optional<GridNode*> Bottom = std::nullopt;
	std::optional<GridNode*> Left = std::nullopt;
	Entity entity;

	int16_t GetRow() { return Position.y; }
	int16_t GetColumn() { return Position.x; }

	void SetRow(int16_t row) { Position.y = row; }
	void SetColumn(int16_t column) { Position.x = column; }

	std::optional<GridNode*> GetNode(Directions direction)
	{
		if (direction == Directions::Right)		{ return Right; }
		if (direction == Directions::Left)		{ return Left;}
		if (direction == Directions::Top)		{return Top;}
		if (direction == Directions::Bottom)	{return Bottom;}
	}

	std::vector<GridNode*> GetNodeNeighbours()
	{
		std::vector<GridNode*> nodes;
		if (Top.has_value())
		{
			nodes.push_back(Top.value());
			std::optional<GridNode*> topLeft = Top.value()->GetNode(Directions::Left);
			std::optional<GridNode*> topRight = Top.value()->GetNode(Directions::Right);
			if (topLeft.has_value()) { nodes.push_back(topLeft.value()); }
			if (topRight.has_value()) { nodes.push_back(topRight.value()); }
		}

		if (Bottom.has_value())
		{ 
			nodes.push_back(Bottom.value());
			std::optional<GridNode*> bottomLeft = Bottom.value()->GetNode(Directions::Left);
			std::optional<GridNode*> bottomRight = Bottom.value()->GetNode(Directions::Right);
			if (bottomLeft.has_value()) { nodes.push_back(bottomLeft.value()); }
			if (bottomRight.has_value()) { nodes.push_back(bottomRight.value()); }
		}
		if (Right.has_value()) { nodes.push_back(Right.value()); }
		if (Left.has_value()) { nodes.push_back(Left.value()); }
		return nodes;
	}

	Entity GetEntity()
	{
		return entity;
	}

};


class EntityGrid : public EntityRegistry
{

private:

	float Padding = 0;
	Vector2 m_NodeSize = { 100, 100 };
	Vector2 m_GridSize = { 0, 0 };

	void InitNodes()
	{
		int rows = GetRows();
		int columns = GetColumns();
		for (int x = 0; x < columns; x++)
		{
			for (int y = 0; y < rows; y++)
			{
				std::string entityName = std::string("GridNode (" + std::to_string(x) + "|" + std::to_string(y) + ")");
				Entity node = CreateEntity(entityName);

				TransformComponent& position = node.GetTransform();
				position.SetX(x * (m_NodeSize.x + Padding));
				position.SetY(y * (m_NodeSize.y + Padding));

				auto& rect = node.AddComponent<Shapes::Rectangle>(node);
				rect.SetWidth(m_NodeSize.x);
				rect.SetHeight(m_NodeSize.y);

				auto& nodeComponent = node.AddComponent<GridNode>();
				nodeComponent.SetRow(y);
				nodeComponent.SetColumn(x);


				nodeComponent.entity = node;
			}
		}

		/*Init Node Neighbours*/

		for (auto [entity, node] : m_Registry.view<GridNode>().each())
		{
			std::optional<Entity> leftEntity = GetNode(node.GetColumn()-1, node.GetRow());
			if (leftEntity.has_value())
			{
				node.Left = &leftEntity.value().GetComponent<GridNode>();
			}
			std::optional<Entity> RightEntity = GetNode(node.GetColumn() + 1, node.GetRow());
			if (RightEntity.has_value())
			{
				node.Right = &RightEntity.value().GetComponent<GridNode>();
			}
			std::optional<Entity> topEntity = GetNode(node.GetColumn(), node.GetRow() -1);
			if (topEntity.has_value())
			{
				node.Top = &topEntity.value().GetComponent<GridNode>();
			}
			std::optional<Entity> bottomEntity = GetNode(node.GetColumn(), node.GetRow() + 1);
			if (bottomEntity.has_value())
			{
				node.Bottom = &bottomEntity.value().GetComponent<GridNode>();
			}

		}

	}

public:

	EntityGrid()  {}

	EntityGrid(Vector2 GridSize, Vector2 NodeSize, float Padding = 0) :  m_GridSize(GridSize), m_NodeSize(NodeSize),  Padding(Padding)
	{
		InitNodes();
	}

	const int GetRows() const { return m_GridSize.y; }
	const int GetColumns() const { return m_GridSize.x; }
	

	entt::registry& GetRegistry()
	{
		return m_Registry;
	}

	void DrawGrid(Color color)
	{
		auto view = m_Registry.view<TransformComponent, GridNode, Shapes::Rectangle>();
		view.each([](const auto& pos, auto& node, Shapes::Rectangle& rect)
		{
				rect.Draw();
		}); 
	}

	std::optional<Entity> GetNode(int column, int row)
	{
		auto view = m_Registry.view<GridNode>();
		for (auto& entity : view)
		{
			auto& node = view.get<GridNode>(entity);
			if (node.GetRow() == row && node.GetColumn() == column)
			{
				return std::make_optional(GetEntity(entity));
			}
		}
		return std::nullopt;
	}

	std::optional<Entity> GetNode(GridNode& node, int dcol, int drow)
	{
		
		return GetNode(node.GetColumn() + dcol, node.GetRow() + drow);
	}


	std::vector<Entity> GetNeighbours(const GridNode& node)
	{
		std::vector<Entity> Entites;
	
		if (node.Left.has_value()) { Entites.push_back(node.Left.value()->entity); }
		if (node.Right.has_value()) { Entites.push_back(node.Right.value()->entity); }
		if (node.Top.has_value()) { Entites.push_back(node.Top.value()->entity); }
		if (node.Bottom.has_value()) { Entites.push_back(node.Bottom.value()->entity); }
		

		return Entites;
	}

	std::vector<Entity> GetWithingRangeRectangle(const GridNode& node, int distance)
	{
		std::vector<Entity> Entities;
		return Entities;
	}



	/*Utility Functions*/

	std::optional<Entity> GetHoveredNode(Scene* scene)
	{
		std::optional<Entity> resultNode = std::nullopt;
	
		
		for (auto [entity, node, rect] : m_Registry.view<GridNode, Shapes::Rectangle>().each())
		{
			if (rect.PointCollide(Input::Mouse::GetWorldX(scene), Input::Mouse::GetWorldY(scene)))
			{
				resultNode = std::make_optional(node.entity);
			}
		}
	
		return resultNode;
	}




};

