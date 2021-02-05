#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<vector<int>> dp(A.size()+1,vector<int>(m+1,0));
        A.insert(A.begin(),-1);
        V.insert(V.begin(),-1);
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(A[i]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i]]+V[i]);
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
int main()
{
    vector<int> A={2,3,5,7};
    vector<int> V={1,5,2,4};
    Solution s;
    cout<<s.backPackII(10,A,V);
    return 0;
}