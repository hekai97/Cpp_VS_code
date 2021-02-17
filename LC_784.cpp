
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtracking(res,S,0);
        return res;
    }
private:
    void backtracking(vector<string>& res,string s,int start)
    {
        if(start==s.size())
        {
            res.push_back(s);
            return;
        }
        if(!isalpha(s[start]))
        {
            backtracking(res,s,start+1);
        }
        else
        {
            s[start]=toupper(s[start]);
            backtracking(res,s,start+1);
            s[start]=tolower(s[start]);
            backtracking(res,s,start+1);
        } 
    }
};
int main()
{
    string s="a1b2";
    Solution sol;
    vector<string> res=sol.letterCasePermutation(s);
    for(auto a:res)
    {
        cout<<a<<endl;
    }
    return 0;
}