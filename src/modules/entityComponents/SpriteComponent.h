#include "entity/Entity.h"
#include "entity/components/Shapes.h"
#include "raylib.h"


struct SpriteComponent
{
	Texture Sprite;
	Entity EntityRef;


	SpriteComponent(Entity entity): EntityRef(entity)
	{
	}


	void SetTexture(Texture texture) { Sprite = texture; }

	Texture GetTexture() { return  Sprite; }

	void Draw()
	{
		//EntityRef.Require<Shapes::Rectangle>();
	}

};