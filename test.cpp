#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	int MaxNum(vector<vector<int>>& nums)
	{
		int n=nums.size(),m=nums[0].size();
		vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
		int dx[]={0,0,0,-1,-1,-1,-2,-2,-3};
		int dy[]={-1,-2,-3,0,-1,-2,0,-1,0};
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(i==0&&j==0)
				{
					dp[i][j]=nums[i][j];
				}
				else
				{
					for(int k=0;k<9;++k)
					{
						if(i+dx[k]>=0&&i+dx[k]<nums.size()&&j+dy[k]>=0&&j+dy[k]<nums[0].size())
						{
							dp[i][j]=max(dp[i][j],dp[i+dx[k]][j+dy[k]]+nums[i][j]);
						}
					}
				}
			}
		}
		return dp[n-1][m-1];
	}	
};
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> nums(n,vector<int>(m));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			int temp;
			cin>>temp;
			nums[i][j]=temp;
		}
	}
	Solution s;
	cout<<s.MaxNum(nums);
	return 0;
}