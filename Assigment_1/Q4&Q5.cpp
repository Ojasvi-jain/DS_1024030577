/*
    4) Implement the logic to
    a. Reverse the elements of an array
    b. Find the matrix multiplication
    c. Find the Transpose of a Matrix
*/

#include <iostream>
using namespace std;

int mat[10][10];
int rows = 0, cols = 0;

void reverseArray(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void inputMatrix()
{
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void displayMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixMultiplication()
{
    int r2, c2, B[10][10], result[10][10] = {0};

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    if (cols != r2)
    {
        cout << "Matrix multiplication not possible (columns of first != rows of second).\n";
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++)
            {
                result[i][j] += mat[i][k] * B[k][j];
            }
        }
    }

    cout << "Result of multiplication:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix()
{
    int trans[10][10];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }
    cout << "Transpose:\n";
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
}

void sumRowsAndCols()
{
    cout << "Matrix:\n";
    displayMatrix();

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += mat[i][j];
        }
        cout << "Sum of row " << i + 1 << " = " << sum << endl;
    }

    for (int j = 0; j < cols; j++)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            sum += mat[i][j];
        }
        cout << "Sum of column " << j + 1 << " = " << sum << endl;
    }
}

// ===== Main =====
int main()
{
    int choice;
    do
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Input Matrix\n";
        cout << "2. Reverse Array\n";
        cout << "3. Matrix Multiplication\n";
        cout << "4. Transpose Matrix\n";
        cout << "5. Sum of Each Row and Column\n";
        cout << "6. Display Matrix\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            inputMatrix();
        }
        else if (choice == 2)
        {
            int n;
            cout << "Enter number of elements: ";
            cin >> n;
            int arr[100];
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            reverseArray(arr, n);
            cout << "Reversed array: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else if (choice == 3)
        {
            matrixMultiplication();
        }
        else if (choice == 4)
        {
            transposeMatrix();
        }
        else if (choice == 5)
        {
            sumRowsAndCols();
        }
        else if (choice == 6)
        {
            displayMatrix();
        }
        else if (choice == 7)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}