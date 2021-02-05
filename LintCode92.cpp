#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        if(m==0||A.size()==0)
        {
            return 0;
        }
        vector<vector<int>> dp(A.size()+1,vector<int>(m+1,0));
        A.push_back(-1);
        sort(A.begin(),A.end());
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(j>=A[i])
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i]]+A[i]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
                
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
int main()
{
    vector<int> A={3,4,8,5};
    Solution s;
    cout<<s.backPack(10,A);
    return 0;
}