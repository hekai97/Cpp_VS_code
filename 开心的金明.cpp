#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 30001;
const int maxM = 26;
int dp[maxM][maxN],value[maxM],important[maxM];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>value[i]>>important[i];
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(value[i]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-value[i]]+value[i]*important[i]);
            }
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}
