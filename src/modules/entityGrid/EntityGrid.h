#pragma once
#include "entity/Entity.h"
#include "entity/EntityObserver.h"

#if 0

static struct GiridNode;


class EntityGridObserver : public EntityObserver {


private:


	

public:

	EntityGridObserver(): EntityObserver()
	{
	}
	
	EntityGridObserver(entt::registry* registry) : EntityObserver(registry)
	{
	}

	void Init(entt::registry& registry)
	{
		//Connect<GiridNode>(registry);
	}

};

#endif