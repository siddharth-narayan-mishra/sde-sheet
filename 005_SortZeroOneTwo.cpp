#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void printVector(vector<int> v) {
    for (auto a : v) {
        cout << a << " ";
    }
    cout << endl;
}

void sortColors(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        if (nums[left] == 0)
        {
            left++;
            continue;
        }
        if (nums[right] == 2)
        {
            right--;
            continue;
        }
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

int main() {
    return 0;
}