#include "FileLoader.h"
#include "utility/Logger.h"

namespace File
{

	fs::path FindRootPath()
	{
		fs::path path = fs::current_path(); // .parent_path();


		for (int i = 0; i < 5; i++)
		{
			//Log::info(path.string());
			for (const auto& entry : fs::directory_iterator(path))
			{
				//Log::info(entry.path().string());
				if (entry.path().filename() == "assets")
				{
					return path;
				}
				//Log::info(entry.path().filename().string());

			}
			path = path.parent_path();

		}
		return path;
	}


	fs::path GetRoot()
	{
		static fs::path rootPath = FindRootPath();
		return rootPath;
	}


	fs::path GetAssetFolder()
	{
		fs::path assetPath = GetRoot().append("assets");
		return assetPath;
	}

	std::string GetAssetFile(std::string file)
	{
		return GetAssetFolder().append(file).string();
	}

	fs::path GetFont(std::string font)
	{
		return GetAssetFolder().append("fonts").append(font);
	}

	std::string GetBasicFonts(std::string font)
	{
		return "C:\\WINDOWS\\FONTS\\" + font;
	}


}