#include "StringVector.h"

#include "StringVectorSuite.h"
#include "cute.h"

void test_EmptyStringVector_IsEmpty_ReturnsTrue() {
	ASSERT(demo::StringVector { }.empty());
}

void test_EmptyStringVector_Size_ReturnsZero() {
	ASSERT_EQUAL(0, demo::StringVector { }.size());
}

void test_StringVector_CreatedAt_IsNotAfter() {
	auto vector = demo::StringVector { };
	ASSERT_GREATER_EQUAL(demo::StringVector::clock_type::now(), vector.created());
}

void test_StringVector_ConstructedWithSizeTen_Size_ReturnsTen() {
	ASSERT_EQUAL(10, demo::StringVector { 10 }.size());
}

void test_StringVector_ConstructedWithThreeElements_Size_ReturnsThree() {
	auto vector = demo::StringVector { "Seven", "of", "Nine" };
	ASSERT_EQUAL(3, vector.size());
}

void test_StringVector_ConstructedWithTwoRepetitions_Size_ReturnsTwo() {
	auto vector = demo::StringVector { "Worf", 2 };
	ASSERT_EQUAL(2, vector.size());
}

void test_StringVector_WithNonZeroSize_Empty_ReturnsFalse() {
	auto vector = demo::StringVector { "Data" };
	ASSERT(vector.size());
	ASSERT(!vector.empty());
}

void test_StringVector_Add_Size_IncreasedByOne() {
	auto vector = demo::StringVector { "Leah" };
	auto oldSize = vector.size();

	vector.add("Brahms");
	auto newSize = vector.size();

	ASSERT_EQUAL(1, newSize - oldSize);
}

void test_StringVector_RemoveOneContainedElement_ChangesSize() {
	auto vector = demo::StringVector { "DaiMon", "Bok" };
	ASSERT_EQUAL(2, vector.size());
	vector.remove("DaiMon");
	ASSERT_EQUAL(1, vector.size());
}

void test_StringVector_RemoveMultipleContainedElements_ChangesSize() {
	auto vector = demo::StringVector { "Locutus", "Hugh", "Locutus" };
	ASSERT_EQUAL(3, vector.size());
	vector.remove("Locutus");
	ASSERT_EQUAL(1, vector.size());
}

void test_StringVector_ContainingNeedle_Has_ReturnsTrue() {
	auto vector = demo::StringVector { "Catherine" };
	ASSERT(vector.has("Catherine"));
}

void test_StringVector_NotContainingNeedle_Has_ReturnsTrue() {
	auto vector = demo::StringVector { "Kes" };
	ASSERT(!vector.has("T'Pel"));
}

void test_StringVector_ContainingPrefix_Get_ReturnsValue() {
	auto vector = demo::StringVector { "Lwaxana", "Deanna", "Ishara" };
	ASSERT_EQUAL("Deanna", vector.get("Dea"));
}

void test_StringVector_NotContainingPrefix_Get_Throws() {
	auto vector = demo::StringVector { "William", "Jean-Luc", "Sarek" };
	ASSERT_THROWS(vector.get("Geor"), std::out_of_range);
}

void test_StringVector_AfterClear_Size_ReturnsZero() {
	auto vector = demo::StringVector { "Tkon", "Iconia" };
	vector.clear();
	ASSERT(!vector.size());
}

void test_StringVector_AfterClear_Empty_ReturnsTrue() {
	auto vector = demo::StringVector { "Promellians", "Menthars" };
	vector.clear();
	ASSERT(vector.empty());
}

cute::suite make_suite_StringVectorSuite() {
	cute::suite s { };

	s.push_back(CUTE(test_EmptyStringVector_IsEmpty_ReturnsTrue));
	s.push_back(CUTE(test_EmptyStringVector_Size_ReturnsZero));
	s.push_back(CUTE(test_StringVector_CreatedAt_IsNotAfter));
	s.push_back(CUTE(test_StringVector_ConstructedWithSizeTen_Size_ReturnsTen));
	s.push_back(CUTE(test_StringVector_ConstructedWithThreeElements_Size_ReturnsThree));
	s.push_back(CUTE(test_StringVector_ConstructedWithTwoRepetitions_Size_ReturnsTwo));
	s.push_back(CUTE(test_StringVector_WithNonZeroSize_Empty_ReturnsFalse));
	s.push_back(CUTE(test_StringVector_Add_Size_IncreasedByOne));
	s.push_back(CUTE(test_StringVector_RemoveOneContainedElement_ChangesSize));
	s.push_back(CUTE(test_StringVector_RemoveMultipleContainedElements_ChangesSize));
	s.push_back(CUTE(test_StringVector_ContainingNeedle_Has_ReturnsTrue));
	s.push_back(CUTE(test_StringVector_NotContainingNeedle_Has_ReturnsTrue));
	s.push_back(CUTE(test_StringVector_ContainingPrefix_Get_ReturnsValue));
	s.push_back(CUTE(test_StringVector_NotContainingPrefix_Get_Throws));
	s.push_back(CUTE(test_StringVector_AfterClear_Empty_ReturnsTrue));
	s.push_back(CUTE(test_StringVector_AfterClear_Size_ReturnsZero));

	return s;
}
