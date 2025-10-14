/*
    Write a program to find size of
        i. Doubly Linked List.
        ii. Circular Linked List.
*/
#include <iostream>
using namespace std;

// Doubly Linked List Class
class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DNode *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        DNode *newNode = new DNode(val);
        if (!head)
        {
            head = newNode;
            return;
        }

        DNode *temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    int size()
    {
        int count = 0;
        DNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display()
    {
        DNode *temp = head;
        cout << "Doubly Linked List: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear()
    {
        while (head)
        {
            DNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~DoublyLinkedList()
    {
        clear();
    }
};

// Circular Linked List Class
class CNode
{
public:
    int data;
    CNode *next;

    CNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    CNode *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        CNode *newNode = new CNode(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
            return;
        }

        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int size()
    {
        if (!head)
            return 0;

        int count = 0;
        CNode *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void display()
    {
        if (!head)
        {
            cout << "Circular Linked List is empty.\n";
            return;
        }
        cout << "Circular Linked List: ";
        CNode *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void clear()
    {
        if (!head)
            return;

        CNode *current = head->next;
        while (current != head)
        {
            CNode *nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete head;
        head = nullptr;
    }

    ~CircularLinkedList()
    {
        clear();
    }
};

// Main Function
int main()
{
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);
    dll.display();
    cout << "Size of Doubly Linked List: " << dll.size() << endl;

    CircularLinkedList cll;
    cll.insert(5);
    cll.insert(15);
    cll.insert(25);
    cll.insert(35);
    cll.display();
    cout << "Size of Circular Linked List: " << cll.size() << endl;

    return 0;
}
