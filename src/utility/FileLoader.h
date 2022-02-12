#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace File
{

static fs::path GetRoot()
{
	
	fs::path path = fs::current_path().parent_path();
	return path;
}


static fs::path GetAsset()
{
	
	fs::path assetPath = GetRoot().append("assets");
	return assetPath;
}


static fs::path GetFont(std::string font)
{
	return GetAsset().append("fonts").append(font);
}

static std::string GetBasicFonts(std::string font)
{
	return "C:\\WINDOWS\\FONTS\\" + font;
}

}