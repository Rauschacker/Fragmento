#pragma once
/*most parts from Hazel repo by cherno*/
#include "entt/entt.hpp"
#include "Scene/Scene.h"
#include "Components/Components.h"
#include <iostream>
#include "EntityRegistry.h"




class Entity
{
private:

	friend class EntityPanel;

	entt::entity m_EntityHandle{ entt::null };
	entt::registry* m_Registry = nullptr;

public:
	Entity() = default;
	Entity(entt::entity handle, entt::registry* registry);
	Entity(const Entity& other) = default;

	entt::entity& GetHandle() { return m_EntityHandle; }


	template<typename T, typename... Args> 
	T& AddComponent(Args&&... args)
	{
		T& component = m_Registry->emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
		if (std::is_base_of<BasicComponent, T>::value)
		{
			static_assert(std::is_base_of<BasicComponent, T>::value, "type parameter of this class must derive from BaseClass");
			component.SetEntity(this);
			component.AfterCreation();
		}
		//m_Scene->OnComponentAdded<T>(*this, component);
		return component;
	}

	void Update();

	template<typename T>
	T& GetComponent()
	{
		return m_Registry->get<T>(m_EntityHandle);
	}


	template<typename... Component>
	bool HasComponent()
	{
		return m_Registry->all_of<Component...>(m_EntityHandle);
	}

	template<typename T>
	void RemoveComponent()
	{
		m_Registry->remove<T>(m_EntityHandle);
	}

	operator bool() const { return m_EntityHandle != entt::null; }
	operator entt::entity() const { return m_EntityHandle; }
	operator uint32_t() const { return (uint32_t)m_EntityHandle; }

	bool operator==(const Entity& other) const
	{
		return m_EntityHandle == other.m_EntityHandle && m_Registry == other.m_Registry;
	}

	bool operator!=(const Entity& other) const
	{
		return !(*this == other);
	}

	template<typename T>
	void Require()
	{
		if (!HasComponent<T>)
		{
			AddComponent<T>();
		}
	}

	TransformComponent& GetTransform() { return GetComponent<TransformComponent>(); }
};




