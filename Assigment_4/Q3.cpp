/*
    Write a program interleave the first half of the queue with second half.
    Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
*/

#include <iostream>
#include <queue>
using namespace std;

class interleaveQueue
{
private:
    queue<int> q;
    int size;

public:
    interleaveQueue(int s) : size(s) {}

    void enqueue(int value)
    {
        if (q.size() < size)
        {
            q.push(value);
            cout << value << " enqueued into queue." << endl;
        }
        else
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
        }
    }

    void display()
    {
        if (q.empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        queue<int> temp = q; // Create a copy to display elements
        cout << "Queue elements (front to rear): ";
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void interleave()
    {
        if (q.size() % 2 != 0)
        {
            cout << "Queue size must be even to interleave." << endl;
            return;
        }

        queue<int> firstHalf, secondHalf;
        int halfSize = q.size() / 2;

        // Split the queue into two halves
        for (int i = 0; i < halfSize; i++)
        {
            firstHalf.push(q.front());
            q.pop();
        }
        while (!q.empty())
        {
            secondHalf.push(q.front());
            q.pop();
        }

        // Interleave the two halves
        while (!firstHalf.empty() && !secondHalf.empty())
        {
            q.push(firstHalf.front());
            firstHalf.pop();
            q.push(secondHalf.front());
            secondHalf.pop();
        }

        cout << "Queue interleaved successfully." << endl;
    }
};

int main()
{
    int size;
    cout << "Enter size of queue (even number): ";
    cin >> size;
    if (size % 2 != 0)
    {
        cout << "Size must be an even number." << endl;
        return 1;
    }

    interleaveQueue iq(size);
    int choice, value;
    do
    {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Display" << endl;
        cout << "3. Interleave" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            iq.enqueue(value);
            break;
        case 2:
            iq.display();
            break;
        case 3:
            iq.interleave();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}