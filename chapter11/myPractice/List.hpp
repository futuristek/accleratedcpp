#include <memory>

template <class T> class List {
public:
	typedef std::size_t size_type;
	typedef T value_type;

	typedef struct {
		T val;
		T* pre;
		T* next;
	} Node;

	class iterator {
	private:
		Node* node;

	public:
		iterator() { node = 0; }
		T& operator* () { return node->val; }

	class const_iterator {

	};

	List() { create(); }
	List(size_type n, const T& val = T()) { create(n, val); }
	List(const List& l) { create(l.begin(), end()); }

	iterator begin() {	return head; }
	const_iterator begin() const { return head; }
	iterator end() { return tail; }
	const_iterator end() const { return tail; }

	void push_back(const T& val) { append(val); }

	iterator insert(iterator, const T&);
	iterator erase(iterator);
	void clear();

	size_type size() { return tail - head; }

	List& operator= (const List&);

	~List() { uncreate(); }
private:
	iterator head;
	iterator tail;

	//memory management implementation
	void create();
	void create(size_type, const T&);
	void create(iterator, iterator);
	void uncreate();
	void append(const T&);
};
