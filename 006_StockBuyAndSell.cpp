#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main()
{
    return 0;
}