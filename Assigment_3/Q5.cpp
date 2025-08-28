/*
   Write a program for the evaluation of a Postfix expression.
   Example:
   Input  : 23*54*+9-
   Steps  : (2*3) + (5*4) - 9
   Output : 17
*/

#include <iostream>
#include <cmath> // for pow()
using namespace std;

#define MAX 100

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int val)
    {
        if (!isFull())
            arr[++top] = val;
    }

    int pop()
    {
        if (!isEmpty())
            return arr[top--];
        return 0;
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
};

// Function to evaluate postfix expression
int evaluatePostfix(string expr)
{
    Stack s;

    for (char c : expr)
    {
        if (isdigit(c))
        {
            // convert char digit to int and push
            s.push(c - '0');
        }
        else
        {
            // operator: pop two operands
            int val2 = s.pop();
            int val1 = s.pop();

            switch (c)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            }
        }
    }

    return s.pop(); // final result
}

int main()
{
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
