#include "IsUpperCamelCaseSuite.h"
#include "StringFunctions.h"

#include "cute.h"

void test_IsUpperCamelCase_WithEmptyString_ReturnsFalse() {
	std::string empty { };
	ASSERT(!demo::IsUpperCamelCase(empty));
}

void test_IsUpperCamelCase_WithAllLowerCaseString_ReturnsFalse() {
	std::string allLower { "alllowercase" };
	ASSERT(!demo::IsUpperCamelCase(allLower));
}

void test_IsUpperCamelCase_WithStringContainingUnderline_ReturnsFalse() {
	std::string containingUnderline { "GoodSo_farItWas" };
	ASSERT(!demo::IsUpperCamelCase(containingUnderline));
}

void test_IsUpperCamelCase_WithStringStartingWithLowercase_ReturnsFalse() {
	std::string startingLower { "thisIsSadlyNotUpperCamelCase" };
	ASSERT(!demo::IsUpperCamelCase(startingLower));
}

void test_IsUpperCamelCase_WithStringConsistingOfSingelUpperCaseChar_ReturnsTrue() {
	std::string singleUpper { "Z" };
	ASSERT(demo::IsUpperCamelCase(singleUpper));
}

void test_IsUpperCamelCase_WithUpperCamelCaseString_ReturnTrue() {
	std::string upperCamelCase { "ThisIsActualUpperCamelcase" };
	ASSERT(demo::IsUpperCamelCase(upperCamelCase));
}

cute::suite make_suite_IsUpperCamelCaseSuite() {
	cute::suite s { };

	s.push_back(CUTE(test_IsUpperCamelCase_WithEmptyString_ReturnsFalse));
	s.push_back(CUTE(test_IsUpperCamelCase_WithAllLowerCaseString_ReturnsFalse));
	s.push_back(CUTE(test_IsUpperCamelCase_WithStringContainingUnderline_ReturnsFalse));
	s.push_back(CUTE(test_IsUpperCamelCase_WithStringStartingWithLowercase_ReturnsFalse));
	s.push_back(CUTE(test_IsUpperCamelCase_WithStringConsistingOfSingelUpperCaseChar_ReturnsTrue));
	s.push_back(CUTE(test_IsUpperCamelCase_WithUpperCamelCaseString_ReturnTrue));

	return s;
}
