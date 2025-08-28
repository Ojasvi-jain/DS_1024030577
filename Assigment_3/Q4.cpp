/*
   Write a program to convert an Infix expression into a Postfix expression.
   Example:
   Input  : A+B*C
   Output : ABC*+

   Input  : (A+B)*C
   Output : AB+C*
*/

#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char c)
    {
        if (!isFull())
            arr[++top] = c;
    }

    char pop()
    {
        if (!isEmpty())
            return arr[top--];
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

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// function to check if operator is right-associative
bool isRightAssociative(char op)
{
    return (op == '^'); // ^ is right associative
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for (char c : infix)
    {
        if (!isOperator(c))
        {
            // if operand, add to postfix
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            // pop until '('
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop(); // remove '('
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && isOperator(s.peek()) &&
                   ((precedence(s.peek()) > precedence(c)) ||
                    (precedence(s.peek()) == precedence(c) && !isRightAssociative(c))))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    // pop remaining operators
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
