/*
    Write a program to count the total number of distinct elements in an array of length n.
*/

#include <iostream>
using namespace std;

// Function to count distinct elements
int countDistinct(int arr[], int n)
{
    int distinctCount = 0;

    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;

        // Check if arr[i] appeared before
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }
        // If no duplicate found, it's a new distinct element
        if (!isDuplicate)
        {
            distinctCount++;
        }
    }

    return distinctCount;
}

void inputArray(int arr[], int n)
{
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    inputArray(arr, n);

    int result = countDistinct(arr, n);
    cout << "Total distinct elements: " << result << endl;

    return 0;
}

// ---------------------------------

// ---------------- STACK USING ARRAY ----------------
#include <iostream>
using namespace std;

class StackArray
{
    static const int MAX = 100; // max size
    int arr[MAX];
    int top; // index of top element
public:
    StackArray() { top = -1; }

    void push(int x)
    {
        if (top == MAX - 1)
        {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() { return top == -1; }

    void print()
    {
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------------- STACK USING LINKED LIST ----------------
struct StackNode
{
    int data;
    StackNode *next;
};

class StackLL
{
    StackNode *top;

public:
    StackLL() { top = nullptr; }

    void push(int x)
    {
        StackNode *newNode = new StackNode;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return;
        }
        StackNode *temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() { return top == nullptr; }

    void print()
    {
        cout << "Stack (top to bottom): ";
        StackNode *temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~StackLL()
    {
        while (!isEmpty())
            pop();
    }
};

// ---------------- QUEUE USING ARRAY ----------------
class QueueArray
{
    static const int MAX = 100;
    int arr[MAX];
    int front, rear; // indices
public:
    QueueArray() { front = rear = -1; }

    bool isEmpty() { return (front == -1 || front > rear); }

    bool isFull() { return (rear == MAX - 1); }

    int size() { return (isEmpty() ? 0 : rear - front + 1); }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        front++;
        // optionally reset if last element removed:
        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------------- QUEUE USING LINKED LIST ----------------
struct QueueNode
{
    int data;
    QueueNode *next;
};

class QueueLL
{
    QueueNode *front; // points to first element
    QueueNode *rear;  // points to last element
public:
    QueueLL()
    {
        front = rear = nullptr;
    }

    bool isEmpty() { return front == nullptr; }

    void enqueue(int x)
    {
        QueueNode *newNode = new QueueNode;
        newNode->data = x;
        newNode->next = nullptr;

        if (rear == nullptr)
        { // empty queue
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        QueueNode *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr; // queue became empty
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents: ";
        QueueNode *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~QueueLL()
    {
        while (!isEmpty())
            dequeue();
    }
};

int main()
{
    // --- Stack using array ---
    StackArray sa;
    sa.push(5);
    sa.push(3);
    sa.print();
    sa.pop();
    sa.print();

    // --- Stack using linked list ---
    StackLL sl;
    sl.push(10);
    sl.push(20);
    sl.print();
    sl.pop();
    sl.print();

    // --- Queue using array ---
    QueueArray qa;
    qa.enqueue(5);
    qa.enqueue(3);
    qa.dequeue();
    qa.enqueue(7);
    qa.print();
    cout << "Front = " << qa.getFront() << endl;
    cout << "Size = " << qa.size() << endl;

    // --- Queue using linked list ---
    QueueLL ql;
    ql.enqueue(9);
    ql.enqueue(3);
    ql.enqueue(1);
    ql.print();
    ql.dequeue();
    ql.print();
    cout << "Front = " << ql.getFront() << endl;

    return 0;
}
