#include "WorldGrid.h"
#include <raylib.h>
#include <math.h>


static float RECT_SIZE = 100;
static const Color lineColor = { 123, 123, 123, 145 };

static Vector2 GetTopLeft(FMCamera& camera)
{
	
	float x =  ((int)camera.GetTopLeft().x - (int)RECT_SIZE) % (int)RECT_SIZE;
	float y =  ((int)camera.GetTopLeft().y - (int)RECT_SIZE) % (int)RECT_SIZE;

	return {0, 0};
	return {x, y };
}

void DrawWorldGrid(Scene* scene)
{

	FMCamera& camera = scene->GetCamera();
	Camera2D& nativeCamera = camera.GetNativeCamera();

	Vector2 topLeft = GetTopLeft(camera);

	float Length = 250;

	/*Horizontal Lines*/
	for (int y = 0; y < Length; y++) {
		DrawLine(topLeft.x, (y * RECT_SIZE) + topLeft.y, topLeft.x + (Length*RECT_SIZE), (y * RECT_SIZE) + topLeft.y, lineColor);
	}
#if 1
	/*Vertical Lines*/
	for (int x = 0; x < Length; x++) {
		DrawLine((x * RECT_SIZE) + topLeft.x, topLeft.y, (x * RECT_SIZE) + topLeft.x, topLeft.y + (Length * RECT_SIZE), lineColor);
	}
#endif

}