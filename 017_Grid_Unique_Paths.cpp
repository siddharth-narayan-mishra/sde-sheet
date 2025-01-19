#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// SOLUTION STARTS HERE //

//this is an approach using maths, other approaches include use of recursion and dynamic programming
int uniquePaths(int m, int n)
{
    int r = min(m - 1, n - 1);
    long long int result = 1;
    for (int i = 0; i < r; ++i)
    {
        result *= (m + n - 2 - i);
        result /= (i + 1);
    }
    return (int)result;
}

// DRIVER CODE //

int main() {
    int m = 3;
    int n = 7;
    int ans = uniquePaths(m,n);
    cout<<"Number of unique paths = "<<ans;
    return 0;
}