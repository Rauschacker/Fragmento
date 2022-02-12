#pragma once

#include <raylib.h>



namespace FM {


	class Timer
	{
	private:

		friend class Application;

		Timer() = default;
		static Timer s_Instance;

		double m_DeltaTime[2] = { 0, 0.0000001 };
		double m_ElapsedTime = GetTime();

		void NewFrame();

		void EndFrame();


	public:

		static Timer& Get() { return s_Instance; }

		double GetDeltaTime() { return m_DeltaTime[1]; }

		double GetElapsedTime() { return m_ElapsedTime = GetTime(); }

		double GetFPS() { return 1.f / m_DeltaTime[1]; }


	};

}