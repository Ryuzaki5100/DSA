#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> array = {4, 3, 2, 5, 1, 6, 7, 5, 4};
    for (int i = 1; i < array.size(); i++)
    {
        int j = i;
        int key = array[j];
        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
    for (auto i : array)
        cout << i << " ";
}