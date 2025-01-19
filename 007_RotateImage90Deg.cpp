#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void printVector(vector<int> v)
{
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> matrix)
{
    for (auto a : matrix)
    {
        printVector(a);
    }
    cout << endl;
}

void reverseVector(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

// SOLUTION STARTS HERE //

void transposeMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i+1; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotate(vector<vector<int>> &matrix)
{
    transposeMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        reverseVector(matrix[i], 0, matrix[i].size() - 1);
    }
}

// DRIVER CODE //

int main()
{
    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    cout << "Original Matrix: " << endl;
    printMatrix(matrix);
    cout << "Rotated Matrix:" << endl;
    rotate(matrix);
    printMatrix(matrix);
    return 0;
}