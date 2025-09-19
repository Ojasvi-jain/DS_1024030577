/*
    Develop a menu driven program demonstrating the following operations on simple
    Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/
#include <iostream>
using namespace std;

class queue
{
private:
    int front, rear, size;
    int *arr;

public:
    queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    ~queue()
    {
        delete[] arr;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = value;
            cout << value << " enqueued into queue." << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
        }
        else
        {
            cout << arr[front] << " dequeued from queue." << endl;
            front++;
            if (front > rear) // Reset queue if it becomes empty
                front = rear = -1;
        }
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Nothing at front." << endl;
        }
        else
        {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue elements (front to rear): ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Menu driven program
    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    queue q(size);
    int choice, value;
    do
    {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is full." << endl;
            else
                cout << "Queue is not full." << endl;
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
}