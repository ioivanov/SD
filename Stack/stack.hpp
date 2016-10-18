#ifndef STACK_H_
#define STACK_H_

int const MAX = 100;
template <typename TYPE>
class Stack {
private:
	TYPE a[MAX];	// елементите на стека
	int topIndex;	// индекс на последния елемент

				// проверка дали стек е пълен
	bool full() const;

public:

	// създаване на празен стек
	Stack();

	// селектори

	// проверка дали стек е празен
	bool empty() const;

	// намиране на елемента на върха на стека
	TYPE top() const;

	// мутатори

	// включване на елемент
	void push(TYPE const&);

	// изключване на елемент
	int pop();
};

int const EMPTY_STACK = -1; // отбелязваме празен стек

template <typename TYPE>
inline Stack<TYPE>::Stack() {
	topIndex = EMPTY_STACK;
}

template <typename TYPE>
inline bool Stack<TYPE>::empty() const {
	return topIndex == EMPTY_STACK;
}

template <typename TYPE>
inline TYPE Stack<TYPE>::top() const {
	if (empty()) {
		std::cout << "Грешка: опит за поглеждане в празен стек!\n";
		return 0;
	}

	return a[topIndex];
}

template <typename TYPE>
inline void Stack<TYPE>::push(TYPE const& x) {
	if (full()) {
		std::cout << "Грешка: опит за включване в пълен стек!\n";
	}
	else
		a[++topIndex] = x;
}

template <typename TYPE>
inline bool Stack<TYPE>::full() const {
	return topIndex == MAX - 1;
}

template <typename TYPE>
inline int Stack<TYPE>::pop() {
	if (empty()) {
		std::cout << "Грешка: опит за изключване от празен стек!\n";
		return 0;
	}
	return a[topIndex--];
}

#endif /* STACK_H_ */