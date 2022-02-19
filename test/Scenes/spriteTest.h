#include "scene/Scene.h"



class SpriteTest : public Scene
{

private:



public:


	virtual void OnDraw() override
	{
		DrawCircle(10, 10, 10, RED);
	}

};