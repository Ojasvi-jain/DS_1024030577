/*
    2) Write a program to count the number of occurrences of a given key in a singly linked
    list and then delete all the occurrences.
    Input: Linked List : 1->2->1->2->1->3->1 , key: 1
    Output: Count: 4 , Updated Linked List: 2->2->3.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int val)
    {
        Node *n = new Node(val);
        if (!head)
            head = n;
        else
        {
            Node *t = head;
            while (t->next)
                t = t->next;
            t->next = n;
        }
    }

    int deleteKeyOccurrences(int key)
    {
        int count = 0;

        // Delete occurrences at the beginning
        while (head && head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        // Delete remaining occurrences
        Node *current = head;
        while (current && current->next)
        {
            if (current->next->data == key)
            {
                Node *temp = current->next;
                current->next = temp->next;
                delete temp;
                count++;
            }
            else
            {
                current = current->next;
            }
        }

        return count;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.";
            return;
        }
        Node *t = head;
        while (t)
        {
            cout << t->data;
            if (t->next)
                cout << " -> ";
            t = t->next;
        }
        cout << endl;
    }

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~SinglyLinkedList() { clear(); }
};

int main()
{
    SinglyLinkedList list;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int val : arr)
        list.insert(val);

    cout << "Original Linked List: ";
    list.display();

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    int count = list.deleteKeyOccurrences(key);
    cout << "Count: " << count << endl;

    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
