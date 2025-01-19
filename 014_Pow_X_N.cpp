#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// SOLUTION STARTS HERE //

double myPow(double x, int n)
{
    double ans = 1;
    long long nn = n;
    if (nn < 0)
        nn = (-1) * nn;
    while (nn)
    {
        if (nn & 1)
        {
            ans = ans * x;
            nn--;
        }
        else
        {
            x = x * x;
            nn /= 2;
        }
    }
    if (n < 0)
        ans = (double)1 / double(ans);
    return ans;
}

// DRIVER CODE //

int main()
{
    double x;
    int n;
    cout << "Enter x : ";
    cin >> x;
    cout << "Enter n : ";
    cin >> n;
    double ans = myPow(x, n);
    cout << "x^n = " << ans << endl;
    return 0;
}