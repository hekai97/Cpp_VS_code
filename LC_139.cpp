#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1);
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        dp[0]=true;
        for (int i=1;i<=n;i++){
            for (int j=0;j<i;j++){
                if (dp[j]&&m.find(s.substr(j,i-j))!=m.end()){
                    dp[i] = true;
                    break;
                } 
            }
        }
        return dp[n];
    }
};
int main()
{
    string s="leetcode";
    vector<string> wordDict={"leet","code"};
    Solution sol;
    cout<<sol.wordBreak(s,wordDict);
    return 0;
}