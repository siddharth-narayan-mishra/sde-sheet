#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
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

vector<vector<int>> mergeOverlappingSubintervals(vector<vector<int>> intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

// DRIVER CODE //

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    cout << "Intervals : " << endl;
    printMatrix(intervals);
    vector<vector<int>> ans = mergeOverlappingSubintervals(intervals);
    cout << "Output :" << endl;
    printMatrix(ans);
    return 0;
}