#include "ConvertToLeetSpeakSuite.h"
#include "cute.h"

#include "StringFunctions.h"

void test_ConvertToLeetSpeak_WithEmptyString_DoesNotModifyString() {
	std::string empty { };
	std::string copy { empty };
	demo::ConvertToLeetSpeak(copy);
	ASSERT_EQUAL(empty, copy);
}

void test_ConvertToLeetSpeak_WithNoConvertibleChar_DoesNotModifyString() {
	std::string original { "CD" };
	std::string copy { original };
	demo::ConvertToLeetSpeak(copy);
	ASSERT_EQUAL(original, copy);
}

void test_ConvertToLeetSpeak_WithConvertibleChar_ModifiesString() {
	std::string original { "Cevelop" };
	std::string copy { original };
	demo::ConvertToLeetSpeak(copy);
	ASSERT_NOT_EQUAL_TO(original, copy);
}

void test_ConvertToLeetSpeak_HasCorrectReplacementsForLowerCaseChars() {
	std::string characters { "abegijloqstz" };
	std::string expected { "483617109572" };
	demo::ConvertToLeetSpeak(characters);
	ASSERT_EQUAL(expected, characters);
}

void test_ConvertToLeetSpeak_HasCorrectReplacementsForUpperCaseChars() {
	std::string characters { "ABEGIJLOQSTZ" };
	std::string expected { "483617109572" };
	demo::ConvertToLeetSpeak(characters);
	ASSERT_EQUAL(expected, characters);
}

cute::suite make_suite_ConvertToLeetSpeakSuite() {
	cute::suite s { };

	s.push_back(CUTE(test_ConvertToLeetSpeak_WithEmptyString_DoesNotModifyString));
	s.push_back(CUTE(test_ConvertToLeetSpeak_WithNoConvertibleChar_DoesNotModifyString));
	s.push_back(CUTE(test_ConvertToLeetSpeak_WithConvertibleChar_ModifiesString));
	s.push_back(CUTE(test_ConvertToLeetSpeak_HasCorrectReplacementsForLowerCaseChars));
	s.push_back(CUTE(test_ConvertToLeetSpeak_HasCorrectReplacementsForUpperCaseChars));

	return s;
}
