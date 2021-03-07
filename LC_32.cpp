#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        deque<bool> mark(s.size(),false);
        int temp=0,res=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else
            {
                if(stk.empty())
                {
                    mark[i]=true;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        while(!stk.empty())
        {
            mark[stk.top()]=1;
            stk.pop();
        }
        for(int i=0;i<mark.size();++i)
        {
            if(mark[i]==1)
            {
                res=max(res,temp);
                temp=0;
            }
            else
            {
                temp++;
            }
        }
        res=max(res,temp);
        return res;
    }
};
int main()
{
    string s="((((())))))()()()()))(((()))";
    Solution sol;
    cout<<sol.longestValidParentheses(s);
    return 0;
}