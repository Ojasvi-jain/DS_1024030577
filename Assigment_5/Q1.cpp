/*
    1) Develop a menu driven program for the following operations on a Singly Linked
    List.
        (a) Insertion at the beginning.
        (b) Insertion at the end.
        (c) Insertion in between (before or after a node having a specific value, say 'Insert a
        new Node 35 before/after the Node 30').
        (d) Deletion from the beginning.
        (e) Deletion from the end.
        (f) Deletion of a specific node, say 'Delete Node 60').
        (g) Search for a node and display its position from head.
        (h) Display all the node values.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int val) // (a) Insert at the beginning
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at the beginning.\n";
    }

    void insertAtEnd(int val) // (b) Insert at the end
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            cout << val << " inserted as the first node.\n";
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        cout << val << " inserted at the end.\n";
    }

    void insertBefore(int key, int val) // (c) Insert before or after a specific node value
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == key)
        {
            insertAtBeginning(val);
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;

        if (!temp->next)
        {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted before " << key << ".\n";
    }

    void insertAfter(int key, int val) // (c) Insert before or after a specific node value
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp)
        {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted after " << key << ".\n";
    }

    void deleteFromBeginning() // (d) Delete from beginning
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        cout << "Deleted node " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() // (e) Delete from end
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        if (!head->next)
        {
            cout << "Deleted node " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next)
            temp = temp->next;

        cout << "Deleted node " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int key) // (f) Delete a specific node by value
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == key)
        {
            deleteFromBeginning();
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;

        if (!temp->next)
        {
            cout << "Node " << key << " not found.\n";
            return;
        }

        Node *delNode = temp->next;
        temp->next = delNode->next;
        cout << "Deleted node " << key << ".\n";
        delete delNode;
    }

    void search(int key) // (g) Search for a node and display its position
    {
        int pos = 1;
        Node *temp = head;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Node " << key << " not found in the list.\n";
    }

    void display() // (h) Display all node values
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "List: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear() // Free all nodes at the end
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~SinglyLinkedList()
    {
        clear();
    }
};

int main()
{
    SinglyLinkedList list;
    int choice, val, key;

    do
    {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;

        case 3:
            cout << "Insert before which node? ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            list.insertBefore(key, val);
            break;

        case 4:
            cout << "Insert after which node? ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            list.insertAfter(key, val);
            break;

        case 5:
            list.deleteFromBeginning();
            break;

        case 6:
            list.deleteFromEnd();
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteSpecific(key);
            break;

        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;

        case 9:
            list.display();
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 10);

    return 0;
}