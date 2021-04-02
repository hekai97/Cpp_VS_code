#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        backtracking(res,temp,s,0,s.size()-1);
        return res;
    }
private:
    void backtracking(vector<vector<string>>& res,vector<string>& temp,string s,int start,int end)
    {
        if(start>end)
        {
            res.push_back(temp);
            return;
        }
        for(int i=1;i<=end-start+1;++i)
        {
            if(isPal(s.substr(start,i)))
            {
                temp.push_back(s.substr(start,i));
                backtracking(res,temp,s,start+i,end);
                temp.pop_back();
            }
        }
    }
    bool isPal(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
int main()
{
    string str="aab";
    Solution s;
    vector<vector<string>> res=s.partition(str);
    for(auto a:res)
    {
        for(auto b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}