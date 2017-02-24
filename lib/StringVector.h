#ifndef STRINGVECTOR_H_
#define STRINGVECTOR_H_

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <vector>

namespace demo {

struct StringVector {
	using clock_type = std::chrono::steady_clock;

	explicit StringVector(std::size_t size = 0) :
			m_data { size } {
	}

	StringVector(std::initializer_list<std::string> items) :
			m_data { items } {
	}

	StringVector(std::string const & item, std::size_t copies) :
			m_data { copies, item } {
	}

	void add(std::string const & item) {
		m_data.push_back(item);
	}

	void remove(std::string const & item) {
		m_data.erase(std::remove(begin(m_data), end(m_data), item), end(m_data));
	}

	bool has(std::string const & item) {
		return find(item) != cend(m_data);
	}

	std::string get(std::string const & prefix) {
		auto entry = find_if(cbegin(m_data), cend(m_data), [&](std::string const & e) {
			return !e.find(prefix);
		});

		if (entry != cend(m_data)) {
			return *entry;
		}

		throw std::out_of_range { "'" + prefix + "' is not contained in this vector" };
	}

	std::size_t size() {
		return m_data.size();
	}

	bool empty() {
		return m_data.empty();
	}

	void clear() {
		m_data.clear();
	}

	clock_type::time_point const & created() {
		return m_createdAt;
	}

private:
	std::vector<std::string>::const_iterator find(std::string const & needle) {
		return std::find(cbegin(m_data), cend(m_data), needle);
	}

	std::vector<std::string> m_data;

	clock_type::time_point m_createdAt { clock_type::now() };
};

}

#endif
