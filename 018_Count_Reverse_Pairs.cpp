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

void merge(vector<int> &A, int start, int mid, int end)
{
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0, j = 0;
    for (int k = start; k <= end; k++)
    {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

int mergesort_and_count(vector<int> &A, int start, int end)
{
    if (start < end)
    {
        //calculate mid and split into two
        int mid = (start + end) / 2;
        int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);

        //count reverse pairs in split array
        int j = mid + 1;
        for (int i = start; i <= mid; i++)
        {
            while (j <= end && A[i] > A[j] * 2)
                j++;
            count += j - (mid + 1);
        }

        //merge after counting is complete (backtracking)
        merge(A, start, mid, end);
        return count;
    }
    else
        return 0;
}

int reversePairs(vector<int> &nums)
{
    return mergesort_and_count(nums, 0, nums.size() - 1);
}

// DRIVER CODE //

int main() {
    return 0;
}