#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &arr, int l, int h)
{
    int i = l, j = h;
    while (i < j)
    {
        while (arr[++i] <= arr[l]);
        while (arr[--j] > arr[l]);
        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[l];
    arr[l] = temp;
    return j;
}
void QuickSort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int j = Partition(arr, l, h);
        QuickSort(arr, l, j);
        QuickSort(arr, j + 1, h);
    }
}
int main()
{
    vector<int> temp = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    QuickSort(temp, 0, temp.size());
    for (auto i : temp)
        cout << i << " ";
}