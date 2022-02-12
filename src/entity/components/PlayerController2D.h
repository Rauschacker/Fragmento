#pragma once
#include "Entity/Components/Components.h"
#include "Entity/Entity.h"
#include "Core/Timer.h"
#include "Core/Input.h"

enum class PlayerControllerState
{
	Idle,
	MovingRight,
	MovingLeft,
	Jumping,
};

struct PlayerControllerComponent
{
	KeyboardKey MoveRight = KEY_D;
	KeyboardKey MoveLeft = KEY_A;
	float Speed = 250;
};

class PlayerControllerController {


private:


public:

	static PlayerControllerController s_Instance;

	static PlayerControllerController& Get()
	{ 
		static PlayerControllerController s_Instance;
		return s_Instance; 
	}

	void Update(entt::registry& registry)
	{
		auto view = registry.view<TransformComponent, PlayerControllerComponent>();
		for (auto& entity : view)
		{
			auto& playerController = view.get<PlayerControllerComponent>(entity);
			auto& playerPosition = view.get<TransformComponent>(entity);
			HandleInput(playerPosition, playerController);
		}
	}

	void HandleInput(TransformComponent& position, PlayerControllerComponent& playerController)
	{
		float deltaTime = FM::Timer::Get().GetDeltaTime();
		float speed = playerController.Speed;
		if (Input::IsKeyDown(playerController.MoveRight))
		{
			position.MoveX(deltaTime * speed);
		}
		if (Input::IsKeyDown(playerController.MoveLeft))
		{
			position.MoveX(-deltaTime * speed);
		}


		
	}

};