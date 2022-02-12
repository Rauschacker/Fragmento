#include "core/Timer.h"

namespace FM {

	Timer Timer::s_Instance;

	void Timer::NewFrame()
	{
		m_DeltaTime[0] = GetTime();
	}

	void Timer::EndFrame()
	{
		m_DeltaTime[1] = GetTime() - m_DeltaTime[0];
	}



}