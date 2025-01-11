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
//solved using maths
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    long long n = grid.size();
    n = n * n;
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            S += grid[i][j];
            S2 += (long long)grid[i][j] * (long long)grid[i][j];
        }
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

// DRIVER CODE //

int main() {
    return 0;
}