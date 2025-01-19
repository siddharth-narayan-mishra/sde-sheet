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

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int low = 0;
    int high = (numRows * numCols) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / numCols;
        int col = mid % numCols;
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            high = (mid) - 1;
        }
        else
        {
            low = (mid) + 1;
        }
    }
    return false;
}

// DRIVER CODE //

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    if (searchMatrix(matrix, target))
    {
        cout << "target found";
    }
    else
    {
        cout << "target NOT found";
    }
    return 0;
}