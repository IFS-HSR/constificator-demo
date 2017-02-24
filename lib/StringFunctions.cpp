#include "../lib/StringFunctions.h"

#include <algorithm>
#include <array>
#include <utility>


namespace {

using Entry = std::pair<char, char>;

std::array<Entry, 12> constexpr kLeetReplacements = {{
		{'a', '4'},
		{'b', '8'},
		{'e', '3'},
		{'g', '6'},
		{'i', '1'},
		{'j', '7'},
		{'l', '1'},
		{'o', '0'},
		{'q', '9'},
		{'s', '5'},
		{'t', '7'},
		{'z', '2'},
}};

char GetLeetChar(char const c) {
	auto found = find_if(kLeetReplacements.cbegin(), kLeetReplacements.cend(), [=](Entry const & e) {
		return e.first == std::tolower(c);
	});

	if (found != kLeetReplacements.cend()) {
		return found->second;
	}

	return c;
}

}

namespace demo {

bool IsUpperCamelCase(std::string & in) {

	if (in.length() == 0 || std::islower(in[0])) {
		return false;
	}

	for (auto ch : in) {
		if (ch == '_') {
			return false;
		}
	}

	return true;
}

void ConvertToLeetSpeak(std::string & inout) {

	for_each(begin(inout), end(inout), [](char & ch) {
		ch = GetLeetChar(ch);
	});

}

}
