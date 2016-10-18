//������ 1
//
//��������� �� ���� ����� ��� �������� � ��������� �����()
//
//�� �� ������� ���� ������� �� ��������� ��������, �.�.���� �� ����� �������� ����� ��� ������� ������������� ��������� �����
//���� ������� ������� � ����� ������ ����� <> [] {}.
//��� � ����� �������� �����, �� �� ������� ��� ���� ������ ������ ������� �� ��������� ������ �����.
//
//������: (a + (b - c)*((d + e) / f)).�� �� ������ : 0 - 18, 3 - 7, 9 - 17, 10 - 14

#include "stack.hpp"
#include <iostream>

char brakets[4][2] = 
{
	{ '(', ')', },
	{ '[', ']' },
	{ '<', '>' },
	{ '{','}' }
};

bool checkOCT(char* text)
{
	Stack<char> stk;
	int i = 0;
	while (text[i])
	{
		for (int j = 0; j < 4; ++j)
		{
			if (text[i] == brakets[j][0])
			{
				stk.push(text[i]);
			}
			else if (text[i] == brakets[j][1])
			{
				if (stk.top() == brakets[j][0])
					stk.pop();
				else
					return false;
			}
		}
		++i;
	}
	if (stk.empty())
		return true;
	else
		return false;
}

void printOCTP(char* text)
{
	Stack<int> stk;
	int i = 0;
	while (text[i])
	{
		for (int j = 0; j < 4; ++j)
		{
			if (text[i] == brakets[j][0])
			{
				stk.push(i);
			}
			else if (text[i] == brakets[j][1])
			{
				std::cout << stk.top() << "-" << i << ", ";
				stk.pop();
			}
		}
		++i;
	}
}

int main()
{
	std::cout << checkOCT("{a+(b-c)*((d+e)/f)}") << std::endl;
	printOCTP("{a+(b-c)*((d+e)/f)}");
	
	return 0;
}