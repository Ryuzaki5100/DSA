#include<bits/stdc++.h>
using namespace std;
void towerSolution(int n,string a="Rod 1",string b="Rod 2",string c="Rod 3")
{
    if(n==1)
    cout<<"Move "<<a<<" to "<<c<<endl;
    else
    {
        towerSolution(n-1,a,c,b);
        cout<<"Move "<<a<<" to "<<c<<endl;
        towerSolution(n-1,b,a,c);
    }
}
int main()
{
    int n;
    cin>>n;
    towerSolution(n);
}