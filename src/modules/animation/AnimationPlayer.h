#pragma once
#include "raylib/raylib.h"
#include "Entity/Entity.h"
#include "Core/Timer.h"
#include <cstdint>
#include <vector>

class SpriteSheet
{
private:

	Image m_Image;
	Vector2 m_FrameSize;
	uint32_t m_FrameCount;
	std::vector<Texture> m_Frames;

	void Init()
	{
		for(uint16_t frame = 0; frame < m_FrameCount; frame++)
		{
			Rectangle rect
			{
				frame * m_FrameSize.x,
				0,
				m_FrameSize.x,
				m_FrameSize.y,
			};
			m_Frames.push_back(LoadTextureFromImage(ImageFromImage(m_Image, rect)));
		}
	}

	void UnloadFrames()
	{
		for (auto& texure : m_Frames)
		{
			UnloadTexture(texure);
		}
		m_Frames.clear();
	}

public:

	SpriteSheet() = default;

	~SpriteSheet()
	{
		//UnloadFrames();
	}

	SpriteSheet(const char* fileName, Vector2 frameSize, uint32_t frameCount)
		: m_FrameSize(frameSize), m_FrameCount(frameCount)
	{
		m_Image = LoadImage(fileName);
		Init();
	}

	Texture2D& GetFrame(uint16_t frame)
	{
		return m_Frames.at(frame);
	}

	Image GetImageFrame(uint16_t frame)
	{
		Rectangle rect
		{
			frame * m_FrameSize.x,
			0,
			m_FrameSize.x,
			m_FrameSize.y,
		};
		return ImageFromImage(m_Image, rect);
	}

	void DrawFrame(uint16_t frame, Vector2 position)
	{
		DrawTextureV(GetFrame(frame), position, WHITE);
	}

	uint16_t GetFrameCount() { return m_FrameCount; }

	void FlipHorizontal()
	{
		UnloadFrames();
		ImageFlipHorizontal(&m_Image);
		Init();
	}
	void FlipVertical()
	{
		UnloadFrames();
		ImageFlipVertical(&m_Image);
		Init();
	}

	bool operator==(const SpriteSheet& c2) const
	{
		return (m_Image.data == c2.m_Image.data);
	}

	void Scale(float scalar)
	{
		ImageResize(&m_Image, m_Image.width * scalar, m_Image.height * scalar);
		m_FrameSize.x *= scalar;
		m_FrameSize.y *= scalar;
		UnloadFrames();
		Init();
	}

};

struct AnimationComponent
{
	SpriteSheet Sheet;
	uint16_t Speed = 5; 
	double CurrentFrame;
	bool Drawing;
	bool Changing;

	void SetSpriteSheet(SpriteSheet sheet)
	{
		if (sheet != Sheet)
		{
			Sheet = sheet;
			Play();	
		}
	}
	void Play() { Drawing = true; Changing = true; CurrentFrame = 0; }
	void Pause() { Drawing = true; Changing = false; }
	void Continue() { Drawing = true; Changing = true; }
	void Stop() { Drawing = false; Changing = false;  CurrentFrame = 0; }
};

class AnimationController {

private:

	static AnimationController s_Instance;

	uint32_t m_CurrentFrame = 0;


public:

	static AnimationController& Get() { return s_Instance; }

	void Update(entt::registry& registry)
	{
		auto view = registry.view<AnimationComponent, TransformComponent>();
		for (auto& entity : view)
		{
			auto& animationComponent = view.get<AnimationComponent>(entity);
			auto& position = view.get<TransformComponent>(entity);
			if (animationComponent.Changing)
			{
				animationComponent.CurrentFrame += FM::Timer::Get().GetDeltaTime() * animationComponent.Speed;
				if (animationComponent.CurrentFrame > animationComponent.Sheet.GetFrameCount())
				{
					animationComponent.CurrentFrame = 0.0f;
				}
				
			}
			if (animationComponent.Drawing)
			{
				animationComponent.Sheet.DrawFrame(animationComponent.CurrentFrame, position.GetPosition());
			}
		}
	}

};
