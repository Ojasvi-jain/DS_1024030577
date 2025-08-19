/*
    [1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
    if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
    of inversions in an array.
*/
#include <iostream>
using namespace std;

// Function to count inversions in an array
int countInversions(int arr[], int n)
{
    int invCount = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                invCount++;
            }
        }
    }

    return invCount;
}

// Function to input array
void inputArray(int arr[], int n)
{
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

// Function to display array
void displayArray(int arr[], int n)
{
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    inputArray(arr, n);

    displayArray(arr, n);

    int result = countInversions(arr, n);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
