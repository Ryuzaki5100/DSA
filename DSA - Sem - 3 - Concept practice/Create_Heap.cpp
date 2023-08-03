#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr={1,2,3};
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j&&arr[j]>arr[(j-1)/2])
        {
            int temp=arr[j];
            arr[j]=arr[(j-1)/2];
            arr[(j-1)/2]=temp;
            j=(j-1)/2;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}