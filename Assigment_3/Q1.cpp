/*
   Develop a menu driven program demonstrating the following operations
   on a Stack using array:
   (i) push(),
   (ii) pop(),
   (iii) isEmpty(),
   (iv) isFull(),
   (v) display(),
   (vi) peek()
*/

#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of stack

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Push operation
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << value << endl;
        }
        else
        {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop operation
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Peek operation
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Nothing at top." << endl;
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return top == MAX - 1;
    }

    // Display all elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 6:
            s.display();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
