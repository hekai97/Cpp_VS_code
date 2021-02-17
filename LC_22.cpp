#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="";
        dfs(res,temp,0,0,n);
        return res;
    }
private:
    void dfs(vector<string>& res,string temp,int left,int right,int n){
        if(left>n||right>n||right>left)
        {
            return;
        }
        if(left==n&&right==n)
        {
            res.push_back(temp);
            return;
        }
        dfs(res,temp+"(",left+1,right,n);
        dfs(res,temp+")",left,right+1,n);
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<string> res=s.generateParenthesis(n);
    for(auto& i:res)
    {
        cout<<i<<endl;
    }
    return 0;
}