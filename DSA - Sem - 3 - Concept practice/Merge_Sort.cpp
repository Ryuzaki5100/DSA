#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &array, int l, int mid, int h)
{
    vector<int> temp(h - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= h)
    {
        if (array[i] > array[j])
            temp[k++] = array[j++];
        else
            temp[k++] = array[i++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= h)
        temp[k++] = array[j++];
    for (int p = 0; p < temp.size(); p++)
        array[p + l] = temp[p];
}
void mergeSort(vector<int> &array, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(array, l, mid);
        mergeSort(array, mid + 1, h);
        merge(array, l, mid, h);
    }
}
int main()
{
    vector<int> array = {1, 6, 3, 2, 4, 6, 8, 5, 2, 58, 63, 2, 2, 5, 6, 8};
    mergeSort(array, 0, array.size() - 1);
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
}