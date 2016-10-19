#include <iostream>
#include "stack.hpp"

void numIntoStack(Stack<int>& stack, const char* num)
{
	int digit;

	while (*num)
	{
		digit = *num-'0';
		stack.push(digit);
		++num;
	}
}

int main()
{
	Stack<int> num1, num2, newNum;

	const char* number1 = "74094882455";
	const char* number2 = "71152761423221";

	numIntoStack(num1,number1);
	numIntoStack(num2, number2);

	int sum, residue=0;

	while (!num1.empty() && !num2.empty())
	{
		//ако сборът на 2 цифри е по-голям от 9, текущият елемент е sum % 10,
		// а допълнителна единица отива при следващия елемент.
		sum = residue;
		sum += ( num1.pop() + num2.pop() );	
		newNum.push(sum % 10);
		residue = sum / 10;
	}

	if (num1.empty())
	{
		if (!num2.empty())
		{
			newNum.push(residue + num2.pop());
			residue = 0;
		}
			

		while(!num2.empty())
		 newNum.push(num2.pop());
	}
		
	else
	{
		if (!num1.empty())
		{
			newNum.push(residue + num1.pop());
			residue = 0;
		}
			
		while(!num1.empty())
			newNum.push(num1.pop());
	}
	if (residue)
		newNum.push(residue);
	
	while(!newNum.empty())
		std::cout << newNum.pop();

	std::cout<<std::endl;

	return 0;
}
