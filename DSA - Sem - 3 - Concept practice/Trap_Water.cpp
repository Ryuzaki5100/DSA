#include <bits/stdc++.h>
using namespace std;
int trapWater(vector<int> &height)
{
    vector<int> x, y;
    int max = 0, n = height.size(),volume = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < height[i])
            max = height[i];
        x.push_back(max);
    }
    max = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (max < height[i])
            max = height[i];
        y.push_back(max);
    }
    for (int i = 0; i < n; i++)
        volume += min(x[i], y[n - i - 1]) - height[i];
    return volume;
}
int main()
{
    vector<int> height = {3};
    cout << trapWater(height);
}