#include <cstddef>
#include <memory>
#include <algorithm>
#ifdef DEBUG
#include <iostream>
#endif

template <class T> class Vec {
public:
	//interface
	typedef std::size_t size_type;
	typedef T value_type;
	typedef T* iterator;
	typedef const T* const_iterator;

	Vec() {create();}
	Vec(size_type n, const T& val = T()) { create(n, val); }
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator= (const Vec&);

	void push_back(const T& val) {
		if (avail == limit)
			grow();

		unchecked_append(val);
	}

	size_t size() const { return avail - data; }
	size_t capacity() const { return limit - data; }

	T& operator[] (size_type i) { return data[i]; }
	const T& operator[] (size_type i) const { return data[i]; } //two const usages, when error happens?

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	iterator erase(iterator);
	void clear();
	~Vec() { uncreate(); }
private:
	iterator data; //first element in the Vec
	iterator avail; //one past the last initialized element in the Vec
	iterator limit; //one past the last memory slot in the Vec

	std::allocator<T> alloc;

	void create();
	void create(size_type, const T&);
	void create(const T*, const T*);
	void uncreate();

	void grow();
	void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator= (const Vec& rhs) {
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());

	}
	return *this;
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator pos) {
	if (pos < data || pos >= avail) {
		return avail;
	}

	iterator idx = pos + 1;
	while (idx != avail) {
		*(idx - 1) = *idx;
		idx++;
	}

	alloc.destroy(idx);
	avail--;

	return pos;
}

template <class T>
void Vec<T>::clear() {
	for (iterator it = data; it < avail; ++it) {
		alloc.destroy(it);
	}
	avail = data;
}

template <class T>
void Vec<T>::create() {
	data = avail = limit = 0;
	#ifdef DEBUG
	std::cout << "Default create" << std::endl;
	#endif
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n);
	avail = limit = data + n;
	std::uninitialized_fill(data, avail, val);
	#ifdef DEBUG
	std::cout << "Create vector of size " << n << " of value " << val  << std::endl;
	#endif
}

template <class T>
void Vec<T>::create(const T* i, const T* j) {
	data = alloc.allocate(j - i);
	avail = limit = std::uninitialized_copy(i, j, data);
	#ifdef DEBUG
	std::cout << "Create vector from ranged copies" << std::endl;
	#endif
}

template <class T>
void Vec<T>::uncreate() {
	if (data) {
		iterator it = avail;
		while (it != data) {
			alloc.destroy(it);
			--it;
		}
		alloc.deallocate(data, limit - data);
#ifdef DEBUG
		std::cout << "Uncreate vector" << std::endl;
#endif
	}

	data = avail = limit = 0;
}

template <class T>
void Vec<T>::grow() {
	size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;

#ifdef DEBUG
	std::cout << "Grow vector" << std::endl;
#endif
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}
