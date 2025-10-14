/*
    1. Develop a menu driven program for the following operations of on a Circular as well
    as a Doubly Linked List.
    (a) Insertion anywhere in the linked list (As a first node, as a last node, and
    after/before a specific node).
    (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
    deleted may appear as a head node, last node or a node in between.
    (c) Search for a node.
*/

#include <iostream>
using namespace std;

class DllNode
{
public:
    int data;
    DllNode *next;
    DllNode *prev;

    DllNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
private:
    DllNode *head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value)
    {
        DllNode *temp = new DllNode(value);
        if (head)
        {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
    }

    void insertAtEnd(int value)
    {
        DllNode *newNode = new DllNode(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        DllNode *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int value)
    {
        DllNode *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp)
        {
            cout << "Node with value " << key << " not found.\n";
            return;
        }

        DllNode *newNode = new DllNode(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) // If temp is not the last node
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int value)
    {
        DllNode *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp)
        {
            cout << "Node with value " << key << " not found.\n";
            return;
        }

        DllNode *newNode = new DllNode(value);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;

        temp->prev = newNode;
    }

    void deleteNode(int value)
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        DllNode *temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp)
        {
            cout << "Value not found.\n";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Node with value " << value << " deleted.\n";
    }

    bool search(int value)
    {
        DllNode *temp = head;
        while (temp)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        DllNode *temp = head;
        cout << "Linked List: ";
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    LinkedList myList;
    int choice, value, key;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            myList.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            myList.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter key after which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            myList.insertAfter(key, value);
            break;

        case 4:
            cout << "Enter key before which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            myList.insertBefore(key, value);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            myList.deleteNode(value);
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (myList.search(value) ? "Node found.\n" : "Node not found.\n");
            break;

        case 7:
            myList.display();
            break;

        case 8:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
