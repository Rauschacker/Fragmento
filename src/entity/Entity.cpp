#include "Entity.h"
#include "EntityRegistry.h"


Entity::Entity(entt::entity handle, entt::registry* registry)
    : m_EntityHandle(handle), m_Registry(registry)
{
}

void Entity::Update()
{
    //UpdateForces();
    //UpdateVelocity();
    //MovePosition(m_Velocity);
}

