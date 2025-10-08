/*
    3) Write a program to find the middle of a linked list.
    Input: 1->2->3->4->5
    Output: 3
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

    int findMiddle()
    {
        if (!head)
            throw runtime_error("List is empty");
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
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
    int arr[] = {1, 2, 3, 4, 5};
    for (int val : arr)
        list.insert(val);

    cout << "Linked List: ";
    list.display();

    try
    {
        cout << "Middle Element: " << list.findMiddle() << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
