#pragma once
#include "entt/entt.hpp"
#include "entity/Entity.h"
#include <cstdint>

class Entity;


class EntityObserver{

private:

	
	entt::observer m_Observer;


public:

	EntityObserver() = default;


	template<typename... Component>
	void Connect(entt::registry& registry)
	{
		m_Observer.connect(registry, entt::collector.group<Component...>());
	}

	template<typename Func>
	void Each(Func func)
	{
		m_Observer.each(func);
	}

	uint16_t GetSize()
	{
		return m_Observer.size();
	}

	/*Just temporary*/
	entt::observer& GetObserver() { return m_Observer; }

};