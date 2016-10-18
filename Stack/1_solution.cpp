//Задача 1
//
//Прочетете от файл израз със отварящи и затварящи скоби()
//
//Да се провери дали скобите са поставени правилно, т.е.дали на всяка отваряща скоба има отделна съответстваща затваряща скоба
//Нека изразът съдържа и други видове скоби <> [] {}.
//Ако е даден коректен израз, да се запишат във файл всички двойки позиции на съответни двойки скоби.
//
//Пример: (a + (b - c)*((d + e) / f)).Да се изведе : 0 - 18, 3 - 7, 9 - 17, 10 - 14

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