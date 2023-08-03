#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int x)
{
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = m * n - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        int p = matrix[mid / n][mid % n];
        if (p == x)
            return true;
        else if (p > x)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> array = {{1}};
    cout << searchMatrix(array, 1);
}