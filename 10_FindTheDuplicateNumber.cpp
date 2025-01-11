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

//floyd's haire and tortoise algorithm

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

// DRIVER CODE //

int main()
{
    vector<int> v = {1, 3, 4, 2, 2};
    int ans = findDuplicate(v);
    cout<<"answer = "<<ans<<endl;
    return 0;
}