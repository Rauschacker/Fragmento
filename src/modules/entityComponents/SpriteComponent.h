#include "entity/Entity.h"
#include "entity/components/Shapes.h"
#include "raylib.h"


struct SpriteComponent
{
	Texture Texture;
	Entity EntityRef;


	SpriteComponent(Entity entity): EntityRef(entity)
	{

	}


	void Draw()
	{

	}

};