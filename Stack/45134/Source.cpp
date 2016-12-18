#include "stack.h"
#include <string>

void zad1();
void zad2();

int main()
{
    // zad1();
    // zad2();

    return 0;
}

void zad1()
{
    char str[100] = {NULL};
    cin >> str;

    bool done = false;

    Stack<int> braces1; // Counting spaces for each type of brace
    Stack<int> braces2;
    Stack<int> braces3;

    for(unsigned int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '(')
            braces1.push(i);
        if(str[i] == ')')
            if(braces1.empty())
            {
                cout << "The expression has too many or closing braces in incorrect places!\n";
                done = true;
                break;
            }
            else
                cout << braces1.pop() + 1 << '-' << i + 1 << ", ";

        if(str[i] == '[')
            braces2.push(i);
        if(str[i] == ']')
            if(braces2.empty())
            {
                cout << "The expression has too many or closing braces in incorrect places!\n";
                done = true;
                break;
            }
            else
                cout << braces2.pop() + 1 << '-' << i + 1 << ", ";

        if(str[i] == '{')
            braces3.push(i);
        if(str[i] == '}')
            if(braces3.empty())
            {
                cout << "The expression has too many or closing braces in incorrect places!\n";
                done = true;
                break;
            }
            else
                cout << braces3.pop() + 1 << '-' << i + 1 << ", ";

    }

    cout << "\n";

    if(done == false)
    {
        if(braces1.empty() && braces2.empty() && braces3.empty())
            cout << "The expression has a correct number of opening and closing braces!\n";
        else
            cout << "The expression has too many opening braces!\n";
    }
}

void zad2()
{
    char num1[10001] = {NULL};
    char num2[10001] = {NULL};

    cin >> num1;
    cin >> num2;

    int maxNum1 = strlen(num1);
    int maxNum2 = strlen(num2);

    for(int i = 0; i < maxNum1; i++) // 'Convert' char to int
        num1[i] -= '0';
    for(int i = 0; i < maxNum2; i++)
        num2[i] -= '0';

    Stack<char> finalNum; // Will keep the final num here

    int i = 0; // i and j are index counters
    int j = 0;
    int rest = 0; // ??????? ???? ????????

    i = maxNum1 - 1; // Starting from the back
    j = maxNum2 - 1;

    while(1)
    {
        if(i >= 0 && j >= 0)
        {
            finalNum.push((num1[i] + num2[j] + rest) % 10);
            rest = (num1[i] + num2[i] + rest) / 10;

            i--;
            j--;
        }
        else if(i >= 0)
        {
            finalNum.push((num1[i] + rest) % 10);
            rest = (num1[i] + rest) / 10;

            i--;
        }
        else if(j >= 0)
        {
            finalNum.push((num2[j] + rest) % 10);
            rest = (num2[j] + rest) / 10;

            j--;
        }
        else
        {
            if(rest != 0)
                finalNum.push(rest);
            break;
        }
    }

    while(finalNum.empty() == false)
        cout << (int)finalNum.pop();

    cout << endl;
}