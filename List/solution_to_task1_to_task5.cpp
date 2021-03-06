template <typename T, typename I>
void append(List<T, I>& l1, List<T, I> const& l2) {
	for(I it = l2.begin(); it; ++it)
		l1.insertEnd(*it);
}

// O(n)
template <typename T, typename I>
void reverse(List<T, I>& l) {
	I bit = l.begin();
	// bit е оригиналното начало на списъка
	T x;
	while (l.deleteAfter(x, bit)) // O(1)
		l.insertBegin(x); // O(1)
}

template <typename T, typename I>
void split(List<T, I> const& l, List<T, I>& l1, List<T, I>& l2) {
/*	bool first = true;
	for(I it = l.begin(); it; ++it) {
		if (first)
			l1.insertEnd(*it);
		else
			l2.insertEnd(*it);
		first = !first;
	}*/
	List<T, I> *first = &l1, *second = &l2;
	for(I it = l.begin(); it; ++it) {
		first->insertEnd(*it);
		swap(first, second);
	}
}

template <typename T, typename I>
void merge(List<T, I> const& l1, List<T, I> const& l2, List<T, I>& l) {
	I i1 = l1.begin(), i2 = l2.begin();
	while (i1 && i2) {
		if (*i1 < *i2)
			l.insertEnd(*(i1++));
		else
			l.insertEnd(*(i2++));
	}
	// !i1 || !i2
	while (i1)
		l.insertEnd(*i1++);
	while (i2)
		l.insertEnd(*i2++);
}

typedef DoubleLinkedList<int> TestList;

TestList sort(TestList const& l) {
	if (!++l.begin())
		return l;
	// 1. разделяме
	TestList l1, l2;
	split(l, l1, l2);

	// 2. рекурсивно сортираме
	// 3. сливаме сортираните списъци

	TestList result;
	merge(sort(l1), sort(l2), result);
	return result;
}
