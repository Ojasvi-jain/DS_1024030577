/*
    4) Write a program to reverse a linked list.
    Input: 1->2->3->4->NULL
    Output: 4->3->2->1->NULL
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

    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr)
        {
            next = curr->next; // save next node
            curr->next = prev; // reverse pointer
            prev = curr;       // move prev forward
            curr = next;       // move curr forward
        }
        head = prev; // new head is the last node
    }

    void display()
    {
        Node *t = head;
        while (t)
        {
            cout << t->data;
            if (t->next)
                cout << " -> ";
            t = t->next;
        }
        cout << " -> NULL\n";
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
    int arr[] = {1, 2, 3, 4};
    for (int val : arr)
        list.insert(val);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
