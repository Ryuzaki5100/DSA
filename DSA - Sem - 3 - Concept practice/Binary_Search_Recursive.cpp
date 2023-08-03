#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr, int key, int i, int j)
{
    if (i > j)
        return -1;
    int mid = (i + j) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return binarySearch(arr, key, i, mid - 1);
    return binarySearch(arr, key, mid + 1, j);
}
int main()
{
    vector<int> temp = {1, 2, 3, 4, 5, 6, 7};
    int n;
    cin>>n;
    cout << binarySearch(temp, n, 0, temp.size());
}