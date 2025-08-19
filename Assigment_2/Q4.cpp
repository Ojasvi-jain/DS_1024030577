/*
    4) String Related Programs
    (a) Write a program to concatenate one string to another string.
    (b) Write a program to reverse a string.
    (c) Write a program to delete all the vowels from the string.
    (d) Write a program to sort the strings in alphabetical order.
    (e) Write a program to convert a character from uppercase to lowercase.
*/

#include <iostream>
#include <string>
using namespace std;

string concatenate(const string &s1, const string &s2)
{
    string result = s1;
    for (int i = 0; i < s2.length(); i++)
    {
        result += s2[i];
    }
    return result;
}

string reverseString(const string &s)
{
    string result = s;
    int n = result.length();
    for (int i = 0; i < n / 2; i++)
    {
        char temp = result[i];
        result[i] = result[n - 1 - i];
        result[n - 1 - i] = temp;
    }
    return result;
}

string removeVowels(const string &s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        char lower = (c >= 'A' && c <= 'Z') ? (c + 32) : c; // convert to lowercase manually
        if (!(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'))
        {
            result += c;
        }
    }
    return result;
}

void sortStrings(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32; // ASCII trick: 'A' (65) + 32 = 'a' (97)
    }
    return c; // already lowercase or non-alphabet
}

int main()
{
    int choice;
    do
    {
        cout << "\nString Operations Menu:\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Remove vowels from a string\n";
        cout << "4. Sort strings alphabetically\n";
        cout << "5. Convert uppercase character to lowercase\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string s1, s2;
            cout << "Enter first string: ";
            getline(cin, s1);
            cout << "Enter second string: ";
            getline(cin, s2);
            cout << "Concatenated: " << concatenate(s1, s2) << endl;
            break;
        }
        case 2:
        {
            string s;
            cout << "Enter string: ";
            getline(cin, s);
            cout << "Reversed: " << reverseString(s) << endl;
            break;
        }
        case 3:
        {
            string s;
            cout << "Enter string: ";
            getline(cin, s);
            cout << "Without vowels: " << removeVowels(s) << endl;
            break;
        }
        case 4:
        {
            int n;
            cout << "How many strings? ";
            cin >> n;
            cin.ignore();
            string arr[n];
            cout << "Enter " << n << " strings:\n";
            for (int i = 0; i < n; i++)
                getline(cin, arr[i]);
            sortStrings(arr, n);
            cout << "Sorted strings:\n";
            for (int i = 0; i < n; i++)
                cout << arr[i] << endl;
            break;
        }
        case 5:
        {
            char c;
            cout << "Enter an uppercase character: ";
            cin >> c;
            cout << "Lowercase: " << toLowerCase(c) << endl;
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
