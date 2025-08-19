/*
    Space required to store any two-dimensional array is number of rows × number of columns.
    Assuming array is used to store elements of the following matrices, implement an
    efficient way that reduces the space requirement.
    (a) Diagonal Matrix.
    (b) Tri-diagonal Matrix.
    (c) Lower triangular Matrix.
    (d) Upper triangular Matrix.
    (e) Symmetric Matrix
*/

#include <iostream>
using namespace std;

void displayDiagonal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << arr[i] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

void displayLower(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

void displayUpper(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

void displaySymmetric(int arr[], int n)
{
    int k = 0;
    int *mat = new int[n * n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            mat[i * n + j] = arr[k++];
            mat[j * n + i] = mat[i * n + j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i * n + j] << " ";
        }
        cout << "\n";
    }

    delete[] mat;
}

void displayTriDiagonal(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i == j + 1 || i + 1 == j)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

int main()
{
    int choice, n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    cout << "\nChoose storage method (input in row-major order):\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";
    cout << "Enter choice: ";
    cin >> choice;

    int size = 0;
    switch (choice)
    {
    case 1:
        size = n;
        break;
    case 2:
        size = 3 * n - 2;
        break;
    case 3:
        size = n * (n + 1) / 2;
        break;
    case 4:
        size = n * (n + 1) / 2;
        break;
    case 5:
        size = n * (n + 1) / 2;
        break;
    default:
        cout << "Invalid choice\n";
        return 0;
    }

    int *arr = new int[size];

    cout << "Enter " << size << " elements (row-major order of the compact storage):\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "\nMatrix:\n";
    switch (choice)
    {
    case 1:
        displayDiagonal(arr, n);
        break;
    case 2:
        displayTriDiagonal(arr, n);
        break;
    case 3:
        displayLower(arr, n);
        break;
    case 4:
        displayUpper(arr, n);
        break;
    case 5:
        displaySymmetric(arr, n);
        break;
    }

    delete[] arr;
    return 0;
}
