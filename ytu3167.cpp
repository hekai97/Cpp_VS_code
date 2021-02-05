#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,temp;
    int res1=0,res2=0;
    cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        b.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            res1+=a[i]+1;
        }
        else
        {
            res1+=a[i];
        }
        if(b[i]%2!=0)
        {
            res2+=b[i]+1;
        }
        else
        {
            res2+=b[i];
        }
    }
    if(res1>res2)
    {
        cout<<"doudou";
    }
    else if(res1<res2)
    {
        cout<<"niuniu";
    }
    else
    {
        cout<<"parallel";
    }
    return 0;
}