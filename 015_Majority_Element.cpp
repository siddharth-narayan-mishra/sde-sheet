#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// SOLUTION STARTS HERE //

int majorityElement(vector<int> &nums)
{
    int count = 0;
    int ele = nums[0];

    for (auto a : nums)
    {
        if (count == 0)
        {
            ele = a;
            count = 1;
        }
        else if (a == ele)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return ele;
}

// DRIVER CODE //

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(nums);
    cout << "Majority element = " << ans;
    return 0;
}