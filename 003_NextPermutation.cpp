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

void reverseVector(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

// solution starts here

int findBreakPoint(vector<int> nums)
{
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            return i;
        }
    }
    return -1;
}

int findNextGreatestToTheRight(vector<int> nums, int target)
{
    for (int i = nums.size()-1; i > target; i--)
    {
        if (nums[i]>nums[target])
        {
            return i;
        }        
    }
    return -1;
}

void nextPermutation(vector<int> &nums)
{
    int breakingPoint = findBreakPoint(nums);
    if (breakingPoint == -1)
    {
        reverseVector(nums, 0, nums.size() - 1);
    }
    else
    {
        int nextGreatestToRight = findNextGreatestToTheRight(nums, breakingPoint);
        swap(nums[breakingPoint],nums[nextGreatestToRight]);
        reverseVector(nums,breakingPoint+1,nums.size()-1);
    }
}

int main()
{
    vector<int> num = {2, 1, 5, 4, 3, 0, 0};
    // vector<int> num = {5, 4, 3, 2, 1, 0, 0};
    cout << "Original Vector: " << endl;
    printVector(num);
    nextPermutation(num);
    cout << "Modified Vector: " << endl;
    printVector(num);
}