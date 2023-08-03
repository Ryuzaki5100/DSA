#include<bits/stdc++.h>
using namespace std;
void print_array(vector<int> temp, int i, int j,int l, int h)
{
    for(auto x:temp)
    cout<<x<<' ';
    cout<<" i = "<<i<<" j = "<<j<<" l = "<<l<<" h = "<<h;
    cout<<endl;
}
int Partition(vector<int> &arr,int l, int h)
{
    int i = l,j=h;
    while(i<j)
    {
        while(i<h&&arr[++i]<=arr[l]);
        while(arr[--j]>arr[l]);
        print_array(arr,i,j,l,h);
        if(i<j)
        {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    print_array(arr,i,j,l,h);
    int temp = arr[l];
    arr[l]=arr[j];
    arr[j]=temp;
    return j;
}
void QuickSort(vector<int> &arr, int l , int h)
{
    if(l<h)
    {
        int j = Partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}
int main()
{
    vector<int> temp = {81, 43, 31, 57, 75, 13, 92, 65, 26, 0};
    QuickSort(temp,0,temp.size());
    for(auto i:temp)
    cout<<i<<" ";
}