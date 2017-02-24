#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "StringFunctions.h"

#include "IsUpperCamelCaseSuite.h"
#include "ConvertToLeetSpeakSuite.h"
#include "StringVectorSuite.h"

#include <iterator>
#include <map>
#include <numeric>
#include <string>

bool runAllTests(int argc, char const *argv[]) {
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);

	const auto runner = cute::makeRunner(lis, argc, argv);

	std::map<std::string, cute::suite> suites{
		{"IsUpperCamelCase", make_suite_IsUpperCamelCaseSuite()},
		{"ConvertToLeetSpeak", make_suite_ConvertToLeetSpeakSuite()},
		{"StringVector", make_suite_StringVectorSuite()},
	};

	return std::accumulate(cbegin(suites), cend(suites), true, [&](bool accumulator, std::pair<std::string, cute::suite> const & suite) {
		return accumulator && runner(suite.second, suite.first.c_str());
	});
}

int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
