#pragma once
#include "entt/entt.hpp"

class Entity;

class EntityRegistry{


private:

	
	friend class Entity;
	EntityRegistry* thisPointer = this;

public:
	entt::registry m_Registry;

	template<typename... Component>
	entt::basic_view<entt::entity, entt::exclude_t<>, Component...> GetView()
	{
		return m_Registry.view<Component...>();
	}

	entt::registry& GetRegistry() { return m_Registry; }


	Entity CreateEntity(const std::string& name = std::string());
	Entity GetEntity(entt::entity handle);
	void DestroyEntity(Entity entity);

};