#include <iostream>
#include <vector>

using namespace std;

// Function to calculate a specific row of Pascal's Triangle
vector<int> getPascalRow(int row)
{
    vector<int> currentRow(row + 1, 1); // Initialize row with 1s
    for (int i = 1; i < row; i++)
    {
        currentRow[i] = (long long)currentRow[i - 1] * (row - i + 1) / i;
    }
    return currentRow;
}

// Function to print Pascal's Triangle up to a given number of rows
void printPascalTriangle(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        // Print leading spaces for alignment
        for (int j = 0; j < rows - i - 1; j++)
        {
            cout << " ";
        }
        // Get the current row and print it
        vector<int> currentRow = getPascalRow(i);
        for (int num : currentRow)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    printPascalTriangle(n);

    return 0;
}