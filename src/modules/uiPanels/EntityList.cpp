#include "EntityList.h"
#include "ui/GuiWrapper.h"
#include "entity/components/Components.h"
#include <vector>
#include <string>

using registry = entt::registry;

inline static std::vector<const char*> GetNames(registry& registry)
{
	std::vector<const char*> names;
	for (auto [entity, tag] : registry.view<TagComponent>().each())
	{
		const char* name = tag.Tag.c_str();
		names.push_back(name);
	}

	// names = { "Test", "Herber", "Karl", "Peter" };

	return names;
}


std::unique_ptr<const char*> GetCharArray(std::vector<const char*> array)
{
	std::unique_ptr<const char*> items(new const char* [array.size()]);


	std::copy(array.begin(), array.end(), items.get());

	return items;;
}

void EntityList(registry& registry)
{
	//ImGui::ShowDemoWindow();
	std::vector<const char*> names = GetNames(registry);
	std::unique_ptr<const char*> charNames = GetCharArray(names);

	static int numba = 1;

	ImGui::Text("EntityList");
	ImGui::ListBox("", &numba, charNames.get(), names.size());
}