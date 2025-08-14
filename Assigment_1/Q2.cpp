/*
2) Design the logic to remove the duplicate elements from an Array and after the
deletion the array should contain the unique elements.
*/

#include <iostream>
using namespace std;

#define MAX 100 // maximum array
int arr[MAX];
int n = 0;

// Function to create the array
void createArray()
{
    cout << "Enter number of elements: ";
    cin >> n;

    if (n > MAX)
    {
        cout << "Max limit exceeded! Limit is " << MAX << endl;
        n = 0;
        return;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}

// Function to display the array
void displayArray()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to remove duplicates
void remDupe()
{
    if (n == 0)
    {
        cout << "Array is empty, nothing to remove.\n";
        return;
    }

    int newSize = 0;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < newSize; j++)
        {
            if (arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            arr[newSize++] = arr[i];
        }
    }
    n = newSize;
    cout << "Duplicates removed. New size is " << n << ".\n";
}

int main()
{
    createArray();
    displayArray();
    remDupe();
    displayArray();
    return 0;
}