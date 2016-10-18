#ifndef STACK_H_
#define STACK_H_

int const MAX = 100;
template <typename TYPE>
class Stack {
private:
	TYPE a[MAX];	// ���������� �� �����
	int topIndex;	// ������ �� ��������� �������

				// �������� ���� ���� � �����
	bool full() const;

public:

	// ��������� �� ������ ����
	Stack();

	// ���������

	// �������� ���� ���� � ������
	bool empty() const;

	// �������� �� �������� �� ����� �� �����
	TYPE top() const;

	// ��������

	// ��������� �� �������
	void push(TYPE const&);

	// ���������� �� �������
	int pop();
};

int const EMPTY_STACK = -1; // ����������� ������ ����

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
		std::cout << "������: ���� �� ���������� � ������ ����!\n";
		return 0;
	}

	return a[topIndex];
}

template <typename TYPE>
inline void Stack<TYPE>::push(TYPE const& x) {
	if (full()) {
		std::cout << "������: ���� �� ��������� � ����� ����!\n";
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
		std::cout << "������: ���� �� ���������� �� ������ ����!\n";
		return 0;
	}
	return a[topIndex--];
}

#endif /* STACK_H_ */