#include<iostream>
using namespace std;
int main()
{
    int dp[102][1002]={0};
    int T[102],V[102];
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>T[i]>>V[i];
    }
    for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=t;j++)
		{
			if (T[i]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				int value1=dp[i-1][j-T[i]]+V[i];
				int value2=dp[i-1][j];
				dp[i][j]=value1>value2?value1:value2;
			}
		}
	}
    cout<<dp[m][t];
    return 0;

}