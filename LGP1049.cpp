#include<iostream>
using namespace std;
int main()
{
    int bag[50000];
    int tmp[40];
    int V,N;
    cin>>V>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>tmp[i];
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=V;j>=tmp[i];j--)
        {
            bag[j]=max(bag[j],bag[j-tmp[i]]+tmp[i]);
        }
    }
    cout<<V-bag[V]<<endl;
    return 0;
}