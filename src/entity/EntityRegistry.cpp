#include "EntityRegistry.h"
#include "Entity/Entity.h"

#include "utility/Logger.h"


Entity EntityRegistry::CreateEntity(const std::string& name)
{
	Entity entity = {m_Registry.create(), &m_Registry };
	entity.AddComponent<TransformComponent>();
	auto& tag = entity.AddComponent<TagComponent>();
	tag.Tag = name.empty() ? "Entity" : name;
	tag.Handle = entity.GetHandle();
	//Log::info("Entity: {} has been created (entt::id = {})", tag.Tag, tag.Handle);
	return entity;
}

Entity EntityRegistry::GetEntity(entt::entity handle)
{
	return {handle, &m_Registry};
}

void EntityRegistry::DestroyEntity(Entity entity)
{
	m_Registry.destroy(entity);
}
