#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(res,temp,k,n,1);
        return res;
    }
private:
    void backtracking(vector<vector<int>>& res,vector<int>& temp,int k,int n,int start)
    {
        if(temp.size()==k)
        {
            if(n==0)
            {
                res.push_back(temp);
                return;
            }
            else
            {
                return;
            }
        }
        for(int i=start;i<=9;++i)
        {
            temp.push_back(i);
            backtracking(res,temp,k,n-i,i+1);
            temp.pop_back();
        }
    }
};
int main()
{
    int k,n;
    cin>>k>>n;
    Solution s;
    vector<vector<int>> res=s.combinationSum3(k,n);
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}