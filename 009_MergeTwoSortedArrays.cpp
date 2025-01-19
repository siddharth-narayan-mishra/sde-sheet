#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

void printVector(vector<int> v) {
    for (auto a : v) {
        cout << a << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> matrix){
    for (auto a : matrix)
    {
        printVector(a);
    }
    cout<<endl;
}

void reverseVector(vector<int> &nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

// SOLUTION STARTS HERE //

void mergeBruteForce(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] >= nums2[j])
        {
            ans.push_back(nums2[j]);
            j++;
        }
        else
        {
            ans.push_back(nums1[i]);
            i++;
        }
    }
    while (i < m)
    {
        ans.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(nums2[j]);
        j++;
    }
    nums1 = ans;
}

//explain this man
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int j = 0, i = m; j < n; j++)
    {
        nums1[i] = nums2[j];
        i++;
    }
    sort(nums1.begin(), nums1.end());
}

// DRIVER CODE //

int main() {
    return 0;
}