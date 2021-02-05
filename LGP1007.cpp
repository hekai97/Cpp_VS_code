/*
解题思路就是从最后一张地毯开始找，如果x，y属于这个范围，那就输出这个编号，否则，继续往下找
*/
#include<iostream>
using namespace std;
int tmp[10000][4];
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>tmp[i][j];
        }
    }
    cin>>x>>y;
    for(int i=n-1;i>=0;i--)
    {
        int a,b,g,k;
        a=tmp[i][0];
        b=tmp[i][1];
        g=tmp[i][2];
        k=tmp[i][3];
        if(!(x>=a&&x<=a+g&&y>=b&&y<=b+k))
        {
            continue;
        }
        else
        {
            cout<<i+1;
            return 0;
        }
        
    }
    cout<<-1;
    return 0;
}