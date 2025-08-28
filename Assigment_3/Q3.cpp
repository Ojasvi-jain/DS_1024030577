/*
   Write a program that checks if an expression has balanced parentheses.
   Example:
   Input  : (a+b) * (c+d)
   Output : Balanced

   Input  : (a+b)) * (c+d
   Output : Not Balanced
*/

#include <iostream>
using namespace std;

#define MAX 100 // maximum size of stack

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char c)
    {
        if (!isFull())
        {
            arr[++top] = c;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            return arr[top--];
        }
        return '\0';
    }

    char peek()
    {
        if (!isEmpty())
            return arr[top];
        return '\0';
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
};

// Function to check if expression is balanced
bool isBalanced(string expr)
{
    Stack s;

    for (char c : expr)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c); // push opening bracket
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.isEmpty())
                return false; // no matching opening

            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false; // mismatched pair
            }
        }
    }

    return s.isEmpty(); // stack should be empty if balanced
}

int main()
{
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
