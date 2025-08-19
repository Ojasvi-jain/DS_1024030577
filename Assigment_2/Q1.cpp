/*
   Binary Search Algorithm
   Time Complexity: O(log n) compared to Linear Search O(n)
*/

#include <iostream>
using namespace std;

// Binary search function (array must be sorted)
int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

// Linear search for comparison
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter number to search: ";
    cin >> target;

    // Binary Search
    int resultBinary = binarySearch(arr, size, target);
    if (resultBinary != -1)
    {
        cout << "Binary Search: Found " << target << " at index " << resultBinary << endl;
    }
    else
    {
        cout << "Binary Search: " << target << " not found." << endl;
    }

    // Linear Search
    int resultLinear = linearSearch(arr, size, target);
    if (resultLinear != -1)
    {
        cout << "Linear Search: Found " << target << " at index " << resultLinear << endl;
    }
    else
    {
        cout << "Linear Search: " << target << " not found." << endl;
    }

    return 0;
}
