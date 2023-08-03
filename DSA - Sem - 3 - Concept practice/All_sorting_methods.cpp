#include <bits/stdc++.h>
using namespace std;
void Merge(vector<string> &array, int l, int mid, int h)
{
    vector<string> temp(h - l + 1);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= h)
        if (array[i] > array[j])
            temp[k++] = array[j++];
        else
            temp[k++] = array[i++];
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= h)
        temp[k++] = array[j++];
    for (int p = 0; p < h - l + 1; p++)
        array[p + l] = temp[p];
}
void MergeSort(vector<string> &array, int l, int h)
{
    if (h > l)
    {
        int mid = (l + h) / 2;
        MergeSort(array, l, mid);
        MergeSort(array, mid + 1, h);
        Merge(array, l, mid, h);
    }
}
void BubbleSort(vector<string> &array)
{
    int n = array.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (array[j + 1] < array[j])
            {
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}
void SelectionSort(vector<string> &array)
{
    int n = array.size();
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
            if (array[min] > array[j])
                min = j;
        string temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}
void InsertionSort(vector<string> &array)
{
    int n = array.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j - 1] > array[j])
            {
                string temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}
int Partition(vector<string> &array, int l, int h)
{
    int i = l, j = h;
    while (i < j)
    {
        while (i>h&&array[++i] <= array[l])
            ;
        while (array[--j] > array[l])
            ;
        if (i < j)
        {
            string temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    string temp = array[j];
    array[j] = array[l];
    array[l] = temp;
    return j;
}
void QuickSort(vector<string> &array, int l, int h)
{
    if (l < h)
    {
        int j = Partition(array, l, h);
        QuickSort(array, l, j);
        QuickSort(array, j + 1, h);
    }
}
void printArray(vector<string> array)
{
    cout << "\n\t\tThe sorted array is --> ";
    for (auto i : array)
        cout << i << " ";
    cout << endl;
}
vector<string> input(int n)
{
    vector<string> temp(n);
    for (int i = 0; i < n; i++)
        cin >> temp[i];
    return temp;
}
int main()
{
    do
    {
        int n;
        cout << "Enter the number of elements to be entered into the array -- > ";
        cin >> n;
        cout << "Enter the elements of the array -- > ";
        vector<string> array(n);
        for(int i=0;i<n;i++)
        cin>>array[i];
        int choice;
        cout << "\n\tSorting choices  --> \n\t1.Bubble Sort\n\t2.Selection Sort\n\t3.Insertion Sort\n\t4.Merge Sort\n\t5.Quick Sort\n\t6.Exit\n\n\tEnter your choice -- > ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            BubbleSort(array);
            printArray(array);
            break;
        case 2:
            SelectionSort(array);
            printArray(array);
            break;
        case 3:
            InsertionSort(array);
            printArray(array);
            break;
        case 4:
            MergeSort(array, 0, n - 1);
            printArray(array);
            break;
        case 5:
            QuickSort(array, 0, n);
            printArray(array);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice!! Try again!!\n";
        }
    } while (true);
}