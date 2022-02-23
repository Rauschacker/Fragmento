#include "scene/Scene.h"

#include "utility/FileLoader.h"
#include "utility/Logger.h"

class assetsFolderScene : public Scene
{
private:


public:


	virtual void Init() override
	{
		fs::path assetPath = File::GetRoot();
		Log::info(File::GetAssetFile(""));
	}


	virtual void OnUpdate() override
	{

	}

	virtual void OnDraw() override
	{

	}

	virtual void OnOverlayDraw() override
	{

	}

};