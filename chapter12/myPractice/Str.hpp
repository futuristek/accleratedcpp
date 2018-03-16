#include "../../chapter11/myPractice/Vec.hpp"
#include <algorithm>
#include <istream>
#include <ostream>

class Str {
private:
	Vec<char> data;

public:
	typedef Vec<char>::size_type size_type;

	Str() { }

	Str(size_type n, char c): data(n, c) { }

	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}

	template<class In> Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	char& operator[] (size_type i) { return data[i]; }
	const char& operator[] (size_type i) const { return data[i]; }

	size_type size() const { return data.size(); }

	friend std::istream& operator>>(std::istream&, Str&);
	friend std::ostream& operator<<(std::ostream&, const Str&);

	/*
	 * In C++, access control is per-class, not per object
	 */
	Str& operator+=(const Str& rhs) {
		std::copy(rhs.data.begin(), rhs.data.end(), std::back_inserter(data));
		return *this;
	}

};

std::istream& operator>>(std::istream& is, Str& s) {
	s.data.clear();

	char c;
	while(is.get(c) && isspace(c))
		;

	if(is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c));
	}

	if(is)
		is.unget();

	return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s) {
	for (Str::size_type i = 0; i < s.size(); ++i) {
		os << s[i];
	}

	return os;
}

Str operator+(const Str& s1, const Str& s2) {
	Str t = s1;
	t += s2;
	return t;
}
