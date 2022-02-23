#include "gtest/gtest.h"
#include "utility/FileLoader.h"


TEST(Utility, BasicAssertions) {
	// Expect two strings not to be equal.
	EXPECT_STRNE("hello", "world");
	// Expect equality.
	EXPECT_EQ(7 * 6, 42);
}


TEST(FileLoader, BasicAssertions) {
	

	EXPECT_STREQ(File::GetRoot().string().c_str(), "F:\\Dev\\active\\FragmentoCmake\\build");
	//EXPECT_STREQ(File::GetAssetFile("").c_str(), "F:\\Dev\\active\\FragmentoCmake\\build\\assets");

}