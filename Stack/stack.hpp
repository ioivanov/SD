const int MAX = 100;
const int EMPTY_STACK = -1;
template <class T>
class Stack
{
	T a[MAX];
	int topIndex;
public:
	Stack();
	bool empty() const;
	bool full() const;

	T top() const;
	void push(T const&);
	T pop();
};

template <class T>
Stack<T>::Stack() : topIndex(EMPTY_STACK) {}

template <class T>
bool Stack<T>::empty() const
{
	return topIndex == EMPTY_STACK;
}

template <class T>
bool Stack<T>::full() const
{
	return topIndex == MAX - 1;
}
template <class T>
T Stack<T>::pop()
{
	if (empty()) {
		std::cout << "Грешка: опит за изключване от празен стек!\n";
		return 0;
	}
	return a[topIndex--];
}
template <class T>
void Stack<T>::push(T const& rhs)
{
	if (full()) {
		std::cout << "full stack!\n";
	}
	else
		a[++topIndex] = rhs;
}

template <class T>
T Stack<T>::top() const
{
	if (empty()) {
		std::cout << "Грешка: опит за поглеждане в празен стек!\n";
		return 0;
	}

	return a[topIndex];
}
