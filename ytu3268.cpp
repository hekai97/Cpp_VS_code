#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=1;
    int i=0;
    while(n>0&&n>i)
    {
        i++;
        n=n-i;
    }
    cout<<i;
    return 0;
}