#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param weights: An array of n integers, where the value of each element weights[i] is the weight of each plate i
     * @param maxCapacity: An integer, the capacity of the barbell
     * @return: an integer denoting the maximum capacity of items that she can lift.
     */
    int weightCapacity(vector<int> &weights, int maxCapacity) {
        // Write your code here
        vector<bool> dp(maxCapacity+1);
        dp[0]=true;
        int answer=0;
        
        for (int i=0;i<weights.size();++i) {
            int weight=weights[i];
            for (int j=maxCapacity; j>=weight;--j) {
                if (dp[j-weight]) {
                    dp[j]=true;
                    answer=max(answer, j);
                }
            }
        }
        
        return answer;
    }
};
int main()
{
    vector<int> weights={1,3,5};
    Solution s;
    cout<<s.weightCapacity(weights,7);
    return 0;
}