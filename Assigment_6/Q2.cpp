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

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            head->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "Circular List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }

    // Delete all nodes and free memory
    void clear()
    {
        if (!head)
            return;

        Node *current = head->next;
        while (current != head)
        {
            Node *nextNode = current->next;
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

int main()
{
    CircularLinkedList clist;

    clist.insert(20);
    clist.insert(100);
    clist.insert(40);
    clist.insert(80);
    clist.insert(60);

    clist.display(); // Output: 20 100 40 80 60 20

    // When main() ends, destructor calls clear() and frees memory
    return 0;
}
