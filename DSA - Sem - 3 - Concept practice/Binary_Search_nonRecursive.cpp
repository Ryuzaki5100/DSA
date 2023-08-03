#include <bits/stdc++.h>
using namespace std;
int Binary_Search(vector<int> a, int x)
{
    int i = 0, j = a.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (a[mid] == x)
            return mid;
        else if (x < a[mid])
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
int main()
{
    vector<int> a = {1, 3, 4, 2, 6, 7, 4, 12, 10, 9};
    sort(a.begin(), a.end());
    for(auto i:a)
    cout<<i<<" ";
    cout<<endl;
    int x;
    cin >> x;
    cout << Binary_Search(a, x);
}