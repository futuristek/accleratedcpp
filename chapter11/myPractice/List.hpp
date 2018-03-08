#include <memory>

template <class T> class List {
public:
	typedef std::size_t size_type;
	typedef T value_type;
    typedef T* iterator;
    typedef T* const const_iterator;

	List() { create(); }
	List(size_type n, const T& val = T()) { create(n, val); }
	List(const List& l) { create(l.begin(), end()); }

	iterator begin() {	return &(head->val); }
	const_iterator begin() const { return &(head->val); }
	iterator end() { return &(tail->val); }
	const_iterator end() const { return &(tail->val); }

	void push_back(const T& val) { append(val); }

	iterator insert(iterator, const T&);
	iterator erase(iterator);
	void clear();

	size_type size() const { return tail - head; }

	List& operator= (const List&);

	~List() { uncreate(); }
private:

	struct Node {
		T val;
		Node* pre;
		Node* next;
	};

    Node* head;
	Node* tail;

	void create() { head = tail = 0; }
	void create(size_type n, const T& val);
	void create(const_iterator i, const_iterator j);
	void uncreate();
	void append(const T&);
};

template <class T>
void List<T>::create(size_type n, const T& val) {
    if (n < 1)
        return;

    head = new Node;
    head->val = val;
    head->pre = 0;
    head->next = 0;

    Node* pre = head;

    for (size_type i = 1; i < n; ++i) {
        Node* node = new Node;
        node->val = val;
        node->pre = pre;
        node->next = 0;
        pre->next = node;
        pre = node;
    }
}

template<class T>
void List<T>:: create(const_iterator i, const_iterator j) {
    create(j - i, T());
    const_iterator ptr = i;
    iterator this_ptr = head;
    while (ptr != 0 ) {
        head-> 
        ptr = ptr->next;
    }
}

template <class T>
List<T>& List<T>::operator= (const List<T>& rhs) {
    if(&rhs != this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}
