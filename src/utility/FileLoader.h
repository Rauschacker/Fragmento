#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace File
{

	fs::path GetRoot();

	fs::path GetAssetFolder();

	std::string GetAssetFile(std::string file);

	fs::path GetFont(std::string font);

	std::string GetBasicFonts(std::string font);


}