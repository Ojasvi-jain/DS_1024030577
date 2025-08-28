/*
   Given a string, reverse it using STACK (array implementation).
   For example:
   Input  : "DataStructure"
   Output : "erutcurtSataD"
*/

#include <iostream>
using namespace std;

#define MAX 100 // max size for stack (enough for string length)

class Stack
{
    char arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char c)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << c << endl;
        }
        else
        {
            arr[++top] = c;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return '\0';
        }
        else
        {
            return arr[top--];
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }
};

// Function to reverse string using stack
string reverseString(string str)
{
    Stack s;

    // Push all characters into stack
    for (char c : str)
    {
        s.push(c);
    }

    // Pop all characters to build reversed string
    string reversed = "";
    while (!s.isEmpty())
    {
        reversed += s.pop();
    }

    return reversed;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string output = reverseString(input);
    cout << "Reversed string: " << output << endl;

    return 0;
}
