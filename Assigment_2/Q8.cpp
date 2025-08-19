/*
    Write a program to count the total number of distinct elements in an array of length n.
*/

#include <iostream>
using namespace std;

// Function to count distinct elements
int countDistinct(int arr[], int n)
{
    int distinctCount = 0;

    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;

        // Check if arr[i] appeared before
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }
        // If no duplicate found, it's a new distinct element
        if (!isDuplicate)
        {
            distinctCount++;
        }
    }

    return distinctCount;
}

void inputArray(int arr[], int n)
{
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    inputArray(arr, n);

    int result = countDistinct(arr, n);
    cout << "Total distinct elements: " << result << endl;

    return 0;
}
